#include <density.hpp>
#include <fstream>

int main() {
  std::ifstream input("input/input.txt");
  Traffic_Density density;
  density.input_parser(input);
  density.display();
  return 0;
}
