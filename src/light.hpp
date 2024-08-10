/**
 * @file light.hpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <density.hpp>

struct light {
  int id = 0;
  double load = 0; // probability that the car will show up
  light(const int id, double load) : id(id), load(load) {}
};

#endif // LIGHT_HPP