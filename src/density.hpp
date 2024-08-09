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
  // a map to store the id of each light
  std::map<int, std::string> ids;

  density() {
    set_ids();
    set_cars();
    set_pedestrians();
  }

  void display();

private:
  void set_ids();
  void set_cars();
  void set_pedestrians();

public:
  std::string get_name(int id);
};

std::ostream &operator<<(std::ostream &os, const density &d);

#endif // DENSITY_HPP