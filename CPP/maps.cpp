#include <iostream>
#include <unordered_map>
#include <memory>

namespace glfw
{
    int square(int val)
    {
        float sqr = val * val;
        return static_cast<float>(sqr);
    }
}

namespace MAPS{
    class maps
    {
    public:
        maps()
        {
            this->squares[1] = glfw::square(1);
            this->squares[2] = glfw::square(2);
            this->squares[3] = glfw::square(3);
            this->squares[4] = glfw::square(4);
        }

        int getSquare(int num)
        {
            return this->squares[num];
        }
    private:
        std::unordered_map<int, int> squares;

    };
}

namespace Window
{
    class window
    {
    public:
        window()
        {
            this->myMap = std::make_unique<MAPS::maps>();

        }
        
        void runner(int num)
        {
            this->sqr = this->myMap->getSquare(num);
            std::cout << this->sqr << std::endl;
        }
    private:
        int sqr;
        std::unique_ptr<MAPS::maps> myMap;
    };
}

int main(int argc, const char** argv)
{
    std::unique_ptr<Window::window> myWindow = std::make_unique<Window::window>();
    myWindow->runner(1);
    myWindow->runner(2);
    myWindow->runner(3);
}