#include <iostream>

namespace PTR_FUNCS
{
    void executor(int x, int b, int(*operation)(int, int))
    {
        int res = operation(x, b);
        std::cout << res << std::endl;
    }
}

namespace ENTITY_2
{
    class Entity
    {
    public:
        Entity()
        {
            instance = this;
        }

        static void outVar()
        {
            std::cout << "FUCK THIS" << std::endl;
        }

        void run()
        {
            PTR_FUNCS::executor(3, 10, multiply);
        }

    private:
        static Entity* instance;

        static int multiply(int x, int y)
        {
            return x + y;
        }
    };

    Entity* Entity::instance = nullptr;
}

int sum(int x, int y)
{
    return x + y;
}
    

int main(int argc, const char** argv) {

    ENTITY_2::Entity entity;
    
    entity.run();

    return 0;
}




