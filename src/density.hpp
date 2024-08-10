/**
 * @file density.hpp
 * @license MIT
 * @date 24-07-2024
 * @author Zofia Kuriata
 */

#ifndef DENSITY_HPP
#define DENSITY_HPP

#include <constants.hpp>
#include <file_access.hpp>
#include <in.hpp>
#include <map>
#include <string>

// a struct to store the traffic density at each light
struct density {
private:
public:
  // maps to store density at each light by id
  std::map<int, double> cars;
  std::map<int, double> pedestrians;
  std::map<int, std::string> ids; // a map to store the id of each light

  density() {
    set_ids();
    set_cars();
    set_pedestrians();
  }

  void display();

private:
  void set_ids();  // gives id for every light in specific and unchangable order
  void set_cars(); // prepares a map to store probabilities with ids as keys for
                   // cars' lights
  void set_pedestrians(); // prepares a map to store probabilities with ids as
                          // keys for pedestrians' lights

public:
  std::string get_name(
      int id); // gives the direction and the way of the light with given id
};

std::ostream &operator<<(std::ostream &os, const density &d);

#endif // DENSITY_HPP