/**
 * @file ui.hpp
 * @license MIT
 * @date 04-08-2024
 * @author Zofia Kuriata
 */

#ifndef UI_HPP
#define UI_HPP

#include "in.hpp"
#include "out.hpp"
#include <string>

struct data {
  int cycles = 0;
  int light_id = -1;
  in_interface *in;
  out_interface *out;
  std::string input;
  std::string output;
};

struct user_interface {
private:
  int hello();
  int cycles();
  int two();
  int output_form();
  int input_form();
  std::string file_path();

public:
  data process();
};

#endif // UI_HPP
