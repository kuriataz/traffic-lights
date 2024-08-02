/**
 * @file file_access.cpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#include <file_access.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

void file_access::parse(std::map<int, double> &cars,
                        std::map<int, double> &pedestrians, std::string info) {
  std::ifstream input(info);
  if (!input.is_open()) {
    std::cerr << "Error: could not open input file" << std::endl;
    exit(1);
  }

  std::string line;
  std::string direction;
  std::string way;
  std::istringstream iss(line);
  int i = 0;
  int j = 0;

  while (j != 12) {
    j += 3;
    std::getline(input, line);
    iss.clear();
    iss.str(line);
    for (; i != j; ++i) {
      iss >> cars[i];
    }
  }
  std::getline(input, line);
  std::getline(input, line);
  iss.clear();
  iss.str(line);
  for (; i != 16; ++i) {
    iss >> pedestrians[i];
  }
}