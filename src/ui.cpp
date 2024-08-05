/**
 * @file ui.cpp
 * @license MIT
 * @date 04-08-2024
 * @author Zofia Kuriata
 */

#include "file_access.hpp"
#include <iostream>
#include <ui.hpp>

int user_interface::hello() {
  std::cout
      << "TRAFFIC LIGHTS\n A PROGRAM TO MANAGE TRAFFIC JAM AT CROSSINGS\n\n\n";

  std::cout << "CHOOSE WHAT YOU WANT TO DO (insert the number):\n";

  std::cout
      << "1. Get information about each cycle (which lights are green and how "
         "many cars/people are passing)\n2. Get information about the "
         "specyfic light(when it turns green and how many cars / people are "
         "passing)\n";
  int option = 0;
  std::cin >> option;
  std::cout << std::endl;
  return option;
}

int user_interface::cycles() {
  std::cout << "INSERT THE NUMBER OF CYCLES: ";
  int number = 0;
  std::cin >> number;
  std::cout << std::endl;
  return number;
}

int user_interface::two() {
  std::cout << "INSERT THE ID OF THE LIGHT: ";
  int id = 0;
  std::cin >> id;
  std::cout << std::endl;
  return id;
}

int user_interface::input_form() {
  std::cout << "SELECT THE FORM OF THE INPUT: \n";
  std::cout << "1. .txt file\n";
  int option = 0;
  std::cin >> option;
  std::cout << std::endl;
  return option;
}

int user_interface::output_form() {
  std::cout << "SELECT THE FORM OF THE OUTPUT: \n";
  std::cout << "1. .txt file\n";
  int option = 0;
  std::cin >> option;
  std::cout << std::endl;
  return option;
}

std::string user_interface::file_path() {
  std::cout << "Inesrt the path to the file (from CMakeLists.txt directory): ";
  std::string input;
  std::cin >> input;
  return input;
}

data user_interface::process() {
  data d;
  int option = hello();
  d.cycles = cycles();

  switch (option) {
  case 1:
    // No additional data needed for this option
    break;
  case 2:
    d.light_id = two();
    break;
  default:
    std::cerr << "Error: insert a valid number.\n";
    return process();
  }

  int input = input_form();
  file_access *fa = nullptr;
  switch (input) {
  case 1:
    fa = new file_access();
    d.in = fa;
    d.input = file_path();
    break;
  default:
    std::cerr << "Error: insert a valid number.\n";
    return process();
  }

  int output = output_form();
  file_access *fa_out = nullptr;
  switch (output) {
  case 1:
    fa_out = new file_access();
    d.out = fa_out;
    d.output = file_path();
    break;
  default:
    std::cerr << "Error: insert a valid number.\n";
    return process();
  }

  return d;
}