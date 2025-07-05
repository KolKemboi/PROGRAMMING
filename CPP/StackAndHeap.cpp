#include <iostream>
#include <memory>

class Entity
{
public:
	Entity();
	~Entity();
	int compLarge(int, int);
private:
	int larger;
};

Entity::Entity()
{
	std::cout << "Entity created" << std::endl;
	this->larger = 0;
}

Entity::~Entity()
{
	std::cout << "Entity " << this->larger << " destroyed" << std::endl;
}

int Entity::compLarge(int a, int b)
{
	this->larger = ((a > b) ? (a) : (b));
	return larger;
}

int main() 
{
	//stack allocation
	{
		Entity a;
		std::cout << a.compLarge(1, 2) << std::endl;
	}

	//heap allocation using smart pointers 
	{
		std::unique_ptr<Entity> New_Entt;
		New_Entt = std::make_unique<Entity>();
		std::cout << New_Entt->compLarge(3, 4) << std::endl;
	}

	//using the new keyword
	{
		Entity* Entt_2 = new Entity();
		std::cout << Entt_2->compLarge(5, 6) << std::endl;
		delete Entt_2;
	}
}