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

// a struct to store info about lights that can be green at the same time
struct set {
  int id;
  std::vector<int> lights_ids; // ids of the lights in set
  double sum = 0;              // sum of each light's load
  double priority = 0; // what part of all probabilities is the set's sum
  int time = 0;        // how long will the set's lights be green
  int order = 0;       // when will the set's lights turn green

  set(int id, std::vector<int> lights_ids) : id(id), lights_ids(lights_ids) {}

  void set_priority(double priority) { this->priority = priority; }
  void set_time(int cycle_time) { this->time = this->priority * cycle_time; }
  void set_order(int order) { this->order = order; }
};

#endif // SET_HPP
