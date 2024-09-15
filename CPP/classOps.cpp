#include <iostream>
#include <memory>

int const var_1 = 10;
int const var_2 = 20; 

class Entity
{
private:
    int num1;
    int num2;
public:
    Entity()
    {
        this->num1 = var_1;
        this->num2 = var_2;
        std::cout << "Created" << std::endl;
    };
    ~Entity()
    {
        std::cout << "destroyed" << std::endl;
    };
    void Output()
    {
        std::cout << this->num1 << std::endl;
        std::cout << this->num2 << std::endl;
    }
};

int main()
{
    std::unique_ptr<Entity> Entt = std::make_unique<Entity>();
    Entt->Output();
}