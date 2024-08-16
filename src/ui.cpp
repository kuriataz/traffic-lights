/**
 * @file ui.cpp
 * @license MIT
 * @date 04-08-2024
 * @author Zofia Kuriata
 */

#include <iostream>
#include <ui.hpp>

void user_interface::hello() {
  std::cout
      << "TRAFFIC LIGHTS\nA PROGRAM TO MANAGE TRAFFIC JAM AT CROSSINGS\n\n";

  std::cout << "It gives ids of lights that are green in every second.\n\n";
}

std::string user_interface::input_url() {
  std::cout << "Inesrt input url : ";
  std::string url;
  std::cin >> url;
  std::cout << std::endl;
  return url;
}

std::string user_interface::output_url() {
  std::cout << "Inesrt output url : ";
  std::string url;
  std::cin >> url;
  std::cout << std::endl;
  return url;
}