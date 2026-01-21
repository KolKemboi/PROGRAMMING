#include <iostream>

struct myStruct{
  const char* myName;
};

int main() {
	myStruct miStruct;
	miStruct.myName = "Holl";
	std::cout << miStruct.myName << std::endl;
}
