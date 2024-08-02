/**
 * @file density.hpp
 * @license MIT
 * @date 24-07-2024
 * @author Zofia Kuriata
 */

#ifndef DENSITY_HPP
#define DENSITY_HPP

#include <in.hpp>
#include <map>
#include <string>

// a struct to store the traffic density of each direction
struct density {

  // a map to store the id of each light
  std::map<std::string, int> ids;
  // maps to store density at each light by id
  std::map<int, double> cars;
  std::map<int, double> pedestrians;

  in_interface *in;

  density(in_interface *input) : in(input) {
    set_ids();
    set_cars();
    set_pedestrians();
  }

  friend std::ostream &operator<<(std::ostream &os, const density &d);

  void display();

  void parse(std::string file) {
    in->parse(this->cars, this->pedestrians, file);
  }

private:
  void set_ids();
  void set_cars();
  void set_pedestrians();
};

std::ostream &operator<<(std::ostream &os, const density &d);

#endif // DENSITY_HPP