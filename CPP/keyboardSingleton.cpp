#include <iostream>

namespace FUNC_PTR
{
    void main(int a, int(*op)(int))
    {
        int res = op(a);
        std::cout << res << std::endl;
    }
}


namespace KEYBOARD
{
    class Keyboard
    {
    public:
        static Keyboard& getInst()
        {
            static Keyboard inst;
            return inst;
        }
        bool setBoolfalse()
        {
            keys = false;
            return keys;
        }

        bool setBoolTrue()
        {
            keys = true;
            return keys;
        }
    private:
        bool keys;

        Keyboard()
        {
            std::cout << "KEYBOARD INST" << std::endl;
            keys = false;
        }

        Keyboard(const Keyboard&) = delete;
        Keyboard& operator = (const Keyboard&) = delete;

    };

}

namespace CAMERA
{
    class Camera
    {
    public:
        Camera()
        {
            
        }
        void show(bool bull)
        {
            if (bull) std::cout << "BOOL IS TRUE" << std::endl;
            else std::cout << "BOOL IS FALSE" << std::endl;
        }
    private:
    };
}

int main()
{
    KEYBOARD::Keyboard& keyboard = KEYBOARD::Keyboard::getInst();

    CAMERA::Camera cam;
    
    bool key = keyboard.setBoolfalse();
    cam.show(key);

    key = keyboard.setBoolTrue();
    cam.show(key);


}