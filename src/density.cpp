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
  ids.insert({"n_straight", 0});
  ids.insert({"n_left", 1});
  ids.insert({"n_right", 2});
  ids.insert({"e_straight", 3});
  ids.insert({"e_left", 4});
  ids.insert({"e_right", 5});
  ids.insert({"s_straight", 6});
  ids.insert({"s_left", 7});
  ids.insert({"s_right", 8});
  ids.insert({"w_straight", 9});
  ids.insert({"w_left", 10});
  ids.insert({"w_right", 11});
  ids.insert({"n_crossing", 12});
  ids.insert({"e_crossing", 13});
  ids.insert({"s_crossing", 14});
  ids.insert({"w_crossing", 15});
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
