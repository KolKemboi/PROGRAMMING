#include <iostream>

void refs();

int main() {
  refs();
  std::cout << "Pointers\n";
	const char* food = "Pizza";
	std::cout << &food;
}

void refs() {
  std::cout << "RefPoint\n";

  const char *food = "Pizza";
  const char *&meal = food;

  std::cout << food << "\n";
  std::cout << meal << "\n";

  meal = "OChaps";
  std::cout << food << "\n";
  std::cout << meal << "\n";
}
