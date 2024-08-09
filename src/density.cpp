/**
 * @file density.cpp
 * @license MIT
 * @date 24-07-2024
 * @author Zofia Kuriata
 */

#include "constants.hpp"
#include <density.hpp>
#include <file_access.hpp>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const density &d) {
  int i = 0;
  int j = ways;
  os << "North: ";
  for (; i != ways; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += ways;
  os << "\nEast: ";
  for (; i != j; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += ways;
  os << "\nSouth: ";
  for (; i != j; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += ways;
  os << "\nWest: ";
  for (; i != j; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += p_lights;
  os << "\nCrossing: ";
  for (; i != j; ++i) {
    os << d.pedestrians.at(i) << " ";
  }
  return os;
}

void density::display() { std::cout << *this; }

void density::set_ids() {
  ids.insert({0, "n_straight"});
  ids.insert({1, "n_left"});
  ids.insert({2, "n_right"});
  ids.insert({3, "e_straight"});
  ids.insert({4, "e_left"});
  ids.insert({5, "e_right"});
  ids.insert({6, "s_straight"});
  ids.insert({7, "s_left"});
  ids.insert({8, "s_right"});
  ids.insert({9, "w_straight"});
  ids.insert({10, "w_left"});
  ids.insert({11, "w_right"});
  ids.insert({12, "n_crossing"});
  ids.insert({13, "e_crossing"});
  ids.insert({14, "s_crossing"});
  ids.insert({15, "w_crossing"});
}

void density::set_cars() {
  for (int i = 0; i != c_lights; ++i) {
    cars.insert(std::make_pair(i, 0));
  }
}

void density::set_pedestrians() {
  for (int i = 0; i != p_lights; ++i) {
    pedestrians.insert(std::make_pair(i + c_lights, 0));
  }
}

std::string density::get_name(int id) { return ids.at(id); }
