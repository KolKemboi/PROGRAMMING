#include <iostream>


class Singleton
{
public:
    static Singleton& getInst()
    {
        static Singleton inst;
        return inst;
    }

    void showMsg()
    {
        std::cout << "THIS IS A SINGLETON" << std::endl;
    }
private:
    Singleton ()
    {
        std::cout << "SINGLETON CREATED" << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;

};


int main()
{
    Singleton& singleton = Singleton::getInst();
    singleton.showMsg();

    Singleton& singleton2 = Singleton::getInst();
    singleton2.showMsg();
}


