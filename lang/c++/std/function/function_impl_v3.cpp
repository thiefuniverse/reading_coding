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
    NumGenerator(const NumGenerator &another) {
        std::cout << "copy generator constructed." << std::endl;
        num_ = another.num_;
    }
    NumGenerator(NumGenerator &&another) {
        std::cout << "rvalue generator constructed." << std::endl;
        num_ = another.num_;
    }

    operator int() const {
        return num_;
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
    int operator()(int a, NumGenerator b) {
        std::cout << "here now " << std::endl;
        return a + b.getNum();
    }
};

int getRef(int a, NumGenerator &b) {
    return a + b.getNum();
}

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
    Ret (*call_func)(Function *, Args &&...);
    void *(*copy_func)(const Function &);
    void (*destruct_func)(const Function &);

    template < typename T >
    static Ret call(Function *f, Args &&... args) {
        T *call_obj = static_cast< T * >(f->any_callable);
        return (*call_obj)(std::forward< Args >(args)...);
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
        return call_func(this, std::forward< Args >(args)...);
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

    NumGenerator gen(8);
    // class which override operator()
    std::cout << "*** get number 2 start" << std::endl;
    class Function< int(int, NumGenerator) > getNumber2(getTwo{});
    int num2 = 2;
    std::cout << getNumber2(2, gen) << std::endl;
    std::cout << "*** get number 2 end" << std::endl;

    // compare with std::function
    std::cout << "*** get number2 std::function start" << std::endl;
    std::function< int(int, NumGenerator) > funGetNumber2(getTwo{});
    std::cout << funGetNumber2(2, gen) << std::endl;
    std::cout << "*** get number2 std::function end" << std::endl;

    // function with reference
    std::cout << "---get number 3 start" << std::endl;
    class Function< int(int, NumGenerator &) > getNumber3(getRef);
    std::cout << getNumber3(num2, gen) << std::endl;
    std::cout << getNumber3(2, gen) << std::endl;
    std::cout << "---get number 3 end" << std::endl;

    // compare with std::function
    std::cout << "---get number3 std::function start" << std::endl;
    std::function< int(int, NumGenerator &) > funGetNumber3(getRef);
    std::cout << funGetNumber3(2, gen) << std::endl;
    std::cout << "---number3 std::function end" << std::endl;

    // non static member function
    class getNumber n;
    Function< int(int) > getNumber4(std::bind(&getNumber::getThree, &n, 9));

    // static member function
    Function< int(int) > getNumber5(&getNumber::getFour);
    std::cout << getNumber5(5) << std::endl;

    // lambda
    Function< int(int) > getNumber6 = [](int one) -> int { return 5 + one; };
    std::cout << getNumber6(5) << std::endl;
    return 0;
}
