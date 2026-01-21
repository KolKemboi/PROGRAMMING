#include <iostream>

enum Level {
  LOW,
  MEDIUM,
  HIGH,
};

int main() {
  enum Level myVar = MEDIUM;

  switch (myVar) {
  case LOW:
    std::cout << "Low\n";
    break;
  case MEDIUM:
    std::cout << "Medium\n";
    break;
  case HIGH:
    std::cout << "Height\n";
    break;
  }

  return 0;
}
