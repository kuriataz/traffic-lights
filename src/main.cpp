/**
 * @file main.cpp
 * @license MIT
 * @date 03-08-2024
 * @author Zofia Kuriata
 */

#include <algorithm>
#include <controler.hpp>
#include <density.hpp>
#include <exception>
#include <file_access.hpp>
#include <iostream>
#include <light.hpp>
#include <options.hpp>

int main(int argc, char **argv) {
  constexpr int OPTION_INPUT = 0;
  constexpr int OPTION_OUTPUT = 1;
  constexpr int OPTION_DETAIL = 2;

  option_definition option_defs[] = {
      option_definition{"-i", "--input", OPTION_INPUT, true},
      option_definition{"-o", "--output", OPTION_OUTPUT, true},
      option_definition{"-d", "--detail", OPTION_DETAIL, false}};

  int size = sizeof(option_defs) / sizeof(option_definition);

  parse_result result = parse_arguments(argc, argv, option_defs, size);

  std::string input;
  std::string output;

  bool is_input = false;
  bool is_output = false;

  if (!(result.options.empty())) {
    for (option const &option : result.options) {
      switch (option.id) {
      case OPTION_INPUT:
        input = option.argument;
        is_input = true;
        break;
      case OPTION_OUTPUT:
        output = option.argument;
        is_output = true;
        break;
      }
    }
  }

  if (!is_input) {
    std::cerr << "Error: input option is required but not provided."
              << std::endl;
    return 1;
  }

  if (!is_output) {
    std::cerr << "Error: output option is required but not provided."
              << std::endl;
    return 1;
  }

  controler ctrl;
  try {
    ctrl.parse(input);
    ctrl.go();

    if (std::find_if(result.options.begin(), result.options.end(),
                     [](const option &opt) {
                       return opt.id == OPTION_DETAIL;
                     }) != result.options.end()) {
      ctrl.save_detail(output);
    } else {
      ctrl.save(output);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
