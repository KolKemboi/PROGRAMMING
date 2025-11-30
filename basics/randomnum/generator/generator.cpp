#include <cstdlib>
#include <ctime>

int generate_number(){
	std::srand(std::time(nullptr));
	return std::rand() % 100;
}
