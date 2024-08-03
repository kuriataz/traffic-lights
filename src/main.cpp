/**
 * @file main.cpp
 * @license MIT
 * @date 03-08-2024
 * @author Zofia Kuriata
 */

#include <density.hpp>
#include <file_access.hpp>
#include <iostream>
#include <light.hpp>

int main() {
  std::cout
      << "Inesrt the path to the input file (from CMakeLists.txt directory): ";
  std::string input;
  std::cin >> input;

  file_access fa;
  density d(&fa);
  d.parse(input);
  crossing c(&d);
  controler ctrl(&c, &fa);

  std::cout << "\nInsert the number of cycles: ";
  int cycles = 0;
  std::cin >> cycles;
  std::cout << std::endl;
  ctrl.go(cycles);
  std::cout
      << "Inesrt the path to the output file (from CMakeLists.txt directory): ";
  std::string output;
  std::cin >> output;
  ctrl.parse(output);
}