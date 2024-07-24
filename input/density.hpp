#pragma once

#include <fstream>

struct Traffic_Density {
  double n_straight = 0;
  double n_left = 0;
  double n_right = 0;

  double e_straight = 0;
  double e_left = 0;
  double e_right = 0;

  double s_straight = 0;
  double s_left = 0;
  double s_right = 0;

  double w_straight = 0;
  double w_left = 0;
  double w_right = 0;

  double n_crossing = 0;
  double e_crossing = 0;
  double s_crossing = 0;
  double w_crossing = 0;

  void display();

  void input_parser(std::ifstream &input);
};