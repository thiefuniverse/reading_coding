#include <functional>
#include <iostream>

int getOne(int a) {
    return 1;
}
class NumGenerator {
public:
    int num_;
    NumGenerator(int num) : num_(num) {
        std::cout << "generator constructed." << std::endl;
    }
    NumGenerator(NumGenerator &another) {
        std::cout << "copy generator constructed." << std::endl;
        num_ = another.num_;
    }
    NumGenerator(NumGenerator &&another) {
        std::cout << "rvalue generator constructed." << std::endl;
        num_ = another.num_;
    }
    int getNum() {
        return num_;
    }
    ~NumGenerator() {
        std::cout << "destruct now" << std::endl;
    }
};

struct getTwo {
    getTwo() {
        std::cout << "construct gettwo" << std::endl;
    }
    int operator()(int a, NumGenerator &b) {
        return a + b.getNum();
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

template < typename Ret, typename... Args >
class Function< Ret(Args...) > {
    // 不借助多态来存储各种类型的可调用对象，使用如下三个函数指针来调用.
    Ret (*call_func)(Function *, Args...);
    void *(*copy_func)(const Function &);
    void (*destruct_func)(const Function &);

    template < typename T >
    static Ret call(Function *f, Args... args) {
        T *call_obj = static_cast< T * >(f->any_callable);
        return (*call_obj)(args...);
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
    Ret operator()(Args... args) {
        std::cout << "h1 now" << std::endl;
        return call_func(this, args...);
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
    // class Function< int(int) > getNumber(getOne);
    // std::cout << getNumber(3) << std::endl;
// class Function< int(int) > getNumber(getOne);
    // std::cout << getNumber(3) << std::endl;

    // class which override operator()
    class Function< int(int, NumGenerator) > getNumber2(getTwo{});
    NumGenerator gen(8);
    std::cout << getNumber2(2, std::forward< NumGenerator >(gen)) << std::endl;
    std::cout << getNumber2(2, std::move(gen)) << std::endl;
    std::cout << getNumber2(1, gen) << std::endl;

    // std::cout << "forward before" << std::endl;
    // std::cout << "forward after" << std::endl;
    // std::cout << "done" << std::endl;

    //    std::cout << getNumber2(2, ge) << std::endl;

    // Function< int(int, NumGenerator) > getNumber7 = getNumber2;

    // non static member function
    // getNumber n;

    // Function< int(int) > getNumber3(std::bind(&getNumber::getThree, &n, 9));

    // static member function
    // Function< int(int) > getNumber6(&getNumber::getFour);
    // std::cout << getNumber6(5) << std::endl;

    // NumGenerator gen(8);
    // std::cout << getNumber2(1, std::forward< NumGenerator >(gen)) << std::endl;
    // std::cout << getNumber2(1, std::move(gen)) << std::endl;

    return 0;
}
