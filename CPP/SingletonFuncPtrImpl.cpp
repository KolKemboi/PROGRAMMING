#include <iostream>

namespace FUNC_PTR
{
    int operation(int x, int (*operation)(int))
    {
        return operation(x);
    }
}


class Singleton
{
public:
    static Singleton& getInst()
    {
        static Singleton inst;
        return inst;
    }

    int Print(int value)
    {
        FUNC_PTR::operation(value, sum);
    }

private:
    bool keys[10];
    
    Singleton()
    {
        std::fill(std::begin(keys), std::end(keys), false);
        std::cout << "THIS IS A SINGLETON" << std::endl;
    }
    static int sum(int x)
    {
        return x*x;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
};

int main()
{
    Singleton& singleton = Singleton::getInst();
    int b = singleton.Print(100);
    std::cout << b << std::endl;

    Singleton& singleton2 = Singleton::getInst();
    int c = singleton2.Print(10);
    std::cout << c << std::endl;
}