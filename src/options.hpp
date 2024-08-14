/**
 * @file options.hpp
 * @license MIT
 * @date 13-08-2024
 * @author Zofia Kuriata
 */

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <cstdio>
#include <string>
#include <vector>

struct option_definition {
  std::string short_name;
  std::string long_name;
  int id = 0;
  bool mandatory_argument = false;
};

struct option {
  int id = 0;
  std::string argument;

  option(int id) { this->id = id; }

  option(int id, std::string argument) {
    this->id = id;
    this->argument = argument;
  }
};

struct parse_result {
  std::vector<option> options;
  std::vector<std::string> arguments;
};

parse_result parse_arguments(int argc, char **argv, option_definition defs[],
                             int size);

#endif // OPTIONS_HPP
