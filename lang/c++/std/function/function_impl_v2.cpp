#include <functional>
#include <iostream>

int getOne(int a) {
    return 1;
}

struct getTwo {
    getTwo() {}
    int operator()(int a) {
        return 2;
    }
};

class getNumber {
public:
    int getThree(int a) {
        return 3;
    }
    static int getFour(int a) {
        return 4;
    }
};

// 默认特化不实现
template < typename T >
class Function;

template < typename Ret, typename Args0 >
class Function< Ret(Args0) > {
    // 不借助多态来存储各种类型的可调用对象，使用如下三个函数指针来调用.
    Ret (*call_func)(Function *, Args0);
    void *(*copy_func)(const Function &);
    void (*destruct_func)(const Function &);

    template < typename T >
    static Ret call(Function *f, Args0 args0) {
        T *call_obj = static_cast< T * >(f->any_callable);
        return (*call_obj)(args0);
    }
    template < typename T >
    static void *copy(const Function &f) {
        return new T(*static_cast< T * >(f.any_callable));
    }
    template < typename T >
    static void destruct(const Function &f) {
        delete static_cast< T * >(f.any_callable);
    }
    void *any_callable;

public:
    // 对于可调用对象，Function在构造时会根据fuctor的类型来实例化 call, copy和destruct三个函数.
    template < typename T >
    Function(T functor) : call_func(call< T >), copy_func(copy< T >), destruct_func(destruct< T >), any_callable(new T(functor)) {}
    Function() : any_callable(nullptr) {}
    // 实际调用存储的函数
    Ret operator()(Args0 arg0) {
        return call_func(this, arg0);
    }

    Function(const Function &f) : call_func(f.call_func), copy_func(f.copy_func), destruct_func(f.destruct_func), any_callable(copy_func(f)) {}
    Function &operator=(const Function &f) {
        std::cout << "asign construct" << std::endl;
        destruct_func(*this);
        any_callable = copy_func(f);
        return *this;
    }

    ~Function() {
        std::cout << "delete current base callable object" << std::endl;
        destruct_func(*this);
    }
};

int main() {
    // basic function
    class Function< int(int) > getNumber(getOne);
    std::cout << getNumber(3) << std::endl;

    // class which override operator()
    class Function< int(int) > getNumber2(getTwo{});
    std::cout << getNumber2(2) << std::endl;

    class Function< int(int) > getNumber7 = getNumber2;
    //    getNumber3 = getNumber;

    // non static member function
    // class getNumber n;
    // Function< int(int) > getNumber3(&getNumber::getThree);
    // std::cout << getNumber3(&n) << std::endl;

    // Function< int(int) > getNumber4 = std::bind(&getNumber::getThree, &n);
    // std::cout << getNumber4(&n) << std::endl;

    // Function< int(int) > getNumber5(&getNumber::getThree);
    // std::cout << getNumber5(&n) << std::endl;

    // // static member function
    // Function< int(int) > getNumber6(&getNumber::getFour);
    // std::cout << getNumber6() << std::endl;
    return 0;
}
