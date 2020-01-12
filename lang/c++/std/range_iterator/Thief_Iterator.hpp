#include <cstring>
#include <stdexcept>


// implement a range iterator
// ep: range(4)= 0 1 2 3
//     range(2,6)= 2,3,4,5
//     range(3,7,2)=3,5
//     range(2.5,5.0,0.5)=2.5 3 3.5 4 4.5
//     range(7,3,-1)= 7,6,5,4


namespace detail_range{
  
template <typename T>
class Thief_Iterator
{
public:
  using value_type=T;
  using size_type=size_t;
  
  Thief_Iterator(size_type cur_start,value_type begin_val,value_type step_val):cursor_(cur_start),step_(step_val),value_(begin_val)
  {
    value_+=(step_ * cursor_);
  }
  
  
  // implement *,!=,++ operations for iterators
  value_type operator*() const
  {
    return value_;
  }
  
  bool operator!=(const Thief_Iterator& rhs) const
  {
    return cursor_!=rhs.cursor_;
  }
  
  Thief_Iterator& operator++(void)
  {
      value_+=step_;
      ++cursor_;
      return (*this);
  }
  
private:
  size_type cursor_;
  const value_type step_;
  value_type value_;
};



template <typename T>
class Impl
{
public:
  using value_type=T;
  using reference=const value_type&;
  using const_reference = const value_type&;
  using Thief_Iterator = const detail_range::Thief_Iterator<value_type>;
  using const_Thief_Iterator = const detail_range::Thief_Iterator<value_type>;
  using size_type = typename Thief_Iterator::size_type;
  
private:
  const value_type begin_;
  const value_type end_;
  const value_type step_;
  const size_type max_count_;
  
  
  // get max size
  size_type get_adjusted_count(void) const
  {
    if(step_>0 && begin_>=end_)
    {
      throw std::logic_error("End value must be greater than begin value.");
    }
    else if(step_<0 && begin_<=end_)
    {
      throw std::logic_error("End value must be less than begin value.");
    }
    size_type x=static_cast<size_type>((end_-begin_)/step_);
    if(begin_+(step_*x)!=end_) ++x;
    return x;
  }
public:
  Impl(value_type begin_val,value_type end_val,value_type step_val):begin_(begin_val),end_(end_val),step_(step_val),
  max_count_(get_adjusted_count()){}
  
  size_type size(void) const
  {
    return max_count_;
  }
  
  
  // create new begin, end iterator
  const_Thief_Iterator begin(void) const
  {
    return {0,begin_,step_};
  }
  
  const_Thief_Iterator end(void) const
  {
    return {max_count_,begin_,step_};
  }
};

template <typename T>
detail_range::Impl<T> range(T end)
{
  return {{},end,1};
}

template <typename T>
detail_range::Impl<T> range(T begin, T end)
{
  return {begin,end,1};
}

template <typename T, typename U>
auto range(T begin, T end, U step)
-> detail_range::Impl<decltype(begin+step)>
{
  using rt=detail_range::Impl<decltype(begin+step)>  ;
  return rt(begin,end,step);
}

}