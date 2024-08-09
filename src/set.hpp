/**
 * @file set.hpp
 * @license MIT
 * @date 09-08-2024
 * @author Zofia Kuriata
 */

#ifndef SET_HPP
#define SET_HPP

#include <light.hpp>
#include <vector>

struct set {
  int id;
  std::vector<int> lights_ids;
  double sum = 0;
  double priority = 0;
  int time = 0;
  int order = 0;

  set(int id, std::vector<int> lights_ids) : id(id), lights_ids(lights_ids) {}

  void set_priority(double priority) { this->priority = priority; }
  void set_time(int cycle_time) { this->time = this->priority * cycle_time; }
  void set_order(int order) { this->order = order; }
};

#endif // SET_HPP
