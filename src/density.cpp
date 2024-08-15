/**
 * @file density.cpp
 * @license MIT
 * @date 24-07-2024
 * @author Zofia Kuriata
 */

#include <constants.hpp>
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

void density::set_cars() {
  for (int i = 0; i != c_lights; ++i) {
    cars.insert(std::make_pair(i, -1));
  }
}

void density::set_pedestrians() {
  for (int i = 0; i != p_lights; ++i) {
    pedestrians.insert(std::make_pair(i + c_lights, -1));
  }
}
