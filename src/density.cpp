/**
 * @file density.cpp
 * @license MIT
 * @date 24-07-2024
 * @author Zofia Kuriata
 */

#include <density.hpp>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const density &d) {
  int i = 0;
  int j = 3;
  os << "North: ";
  for (; i != 3; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += 3;
  os << "\nEast: ";
  for (; i != j; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += 3;
  os << "\nSouth: ";
  for (; i != j; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += 3;
  os << "\nWest: ";
  for (; i != j; ++i) {
    os << d.cars.at(i) << " ";
  }
  j += 4;
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
  for (int i = 0; i != 12; ++i) {
    cars.insert(std::make_pair(i, 0));
  }
}

void density::set_pedestrians() {
  for (int i = 12; i != 16; ++i) {
    pedestrians.insert(std::make_pair(i, 0));
  }
}
