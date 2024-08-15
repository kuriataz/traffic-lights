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

class DensityTest_SetCarsTest_Test;
class DensityTest_SetPedestriansTest_Test;

// a struct to store the traffic density at each light
struct density {

  friend class DensityTest_SetCarsTest_Test;
  friend class DensityTest_SetPedestriansTest_Test;

  // maps to store density at each light by id
  std::map<int, double> cars;
  std::map<int, double> pedestrians;

  density() {
    set_cars();
    set_pedestrians();
  }

  void display();

private:
  void set_cars(); // prepares a map to store probabilities with ids as keys for
                   // cars' lights
  void set_pedestrians(); // prepares a map to store probabilities with ids as
                          // keys for pedestrians' lights

  friend std::ostream &operator<<(std::ostream &os, const density &d);
};

#endif // DENSITY_HPP