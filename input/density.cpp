#include <density.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void Traffic_Density::display() {
  std::cout << "North: " << n_straight << " " << n_left << " " << n_right
            << std::endl;
  std::cout << "East: " << e_straight << " " << e_left << " " << e_right
            << std::endl;
  std::cout << "South: " << s_straight << " " << s_left << " " << s_right
            << std::endl;
  std::cout << "West: " << w_straight << " " << w_left << " " << w_right
            << std::endl;
  std::cout << "\nCrossing: " << n_crossing << " " << e_crossing << " "
            << s_crossing << " " << w_crossing << std::endl;
}

void Traffic_Density::input_parser(std::ifstream &input) {
  std::string line;
  std::string direction;
  std::string way;

  std::getline(input, line);
  std::istringstream iss(line);
  iss >> this->n_straight >> this->n_left >> this->n_right;

  std::getline(input, line);
  iss.clear();
  iss.str(line);
  iss >> this->e_straight >> this->e_left >> this->e_right;

  std::getline(input, line);
  iss.clear();
  iss.str(line);
  iss >> this->s_straight >> this->s_left >> this->s_right;

  std::getline(input, line);
  iss.clear();
  iss.str(line);
  iss >> this->w_straight >> this->w_left >> this->w_right;

  std::getline(input, line);
  std::getline(input, line);
  iss.clear();
  iss.str(line);
  iss >> this->n_crossing >> this->e_crossing >> this->s_crossing >>
      this->w_crossing;
}