// /**
//  * @file main.cpp
//  * @license MIT
//  * @date 03-08-2024
//  * @author Zofia Kuriata
//  */

// #include <controler.hpp>
// #include <density.hpp>
// #include <file_access.hpp>
// #include <iostream>
// #include <light.hpp>
// #include <ui.hpp>

// int main() {
//   user_interface ui;
//   ui.hello();
//   std::string input = "docs/innput.txt";
//   std::string output = "docs/output.txt";
//   // std::string input = ui.input_url();
//   // std::string output = ui.output_url();
//   controler ctrl;
//   try {
//     ctrl.parse(input);
//     ctrl.go();
//     ctrl.save(output);
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << std::endl;
//     return 1;
//   }
//   return 0;
// }
#include <controler.hpp>
#include <density.hpp>
#include <file_access.hpp>
#include <iostream>
#include <light.hpp>
#include <ui.hpp>

int main() {
  user_interface ui;
  ui.hello();
  std::string input, output;
  controler ctrl;

  while (true) {
    try {
      input = ui.input_url();
      ctrl.parse(input);
      break; // Exit loop if parsing is successful
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      std::cerr << "Please enter a valid input file." << std::endl;
    }
  }

  while (true) {
    try {
      output = ui.output_url();
      ctrl.go();
      ctrl.save(output);
      break; // Exit loop if saving is successful
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      std::cerr << "Please enter a valid output file." << std::endl;
    }
  }

  return 0;
}
