#include <iostream>
#include <string>

void out();
void vars();
void intOps();

int main() {
  // out();
  // vars();
	intOps();
}

void intOps(){
	int a = 5, b = 10;
	std::swap(a, b);

	std::cout << a << "  " << b << std::endl;
	int c = a >> 1;
	std::cout << a << "  " << c << std::endl;
}


void vars() {
  using namespace std;
  int number = 5;
  float f = 0.95;
  double PI = 3.146;
  char yes = 'Y';
  std::string s = "Me";
  bool isRight = true;

  cout << number << endl;
  cout << f << endl;
  cout << yes << endl;
  cout << s << endl;
  cout << isRight << endl;
}

void out() { std::cout << "Hello World" << std::endl; }
