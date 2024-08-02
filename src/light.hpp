/**
 * @file light.hpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <density.hpp>
#include <vector>

struct light {
  int id = 0;
  int queue = 0;
  double time = 0;
  enum STATE { RED, GREEN } state;
  std::vector<int> cross; // ids of lights that can't be green at the same time

  light(int id) : id(id), state(RED) {}

  void set_cross_cars();        // for id 0-11
  void set_cross_pedestrians(); // for id 12-15

  void change_state();

  STATE get_state() const;
};

struct crossing {
  density d;
  std::vector<light> lights;

  crossing(density d) : d(d) {

    for (auto &car : d.cars) {
      lights.push_back(light(car.first));
    }
    for (auto &pedestrian : d.pedestrians) {
      lights.push_back(light(pedestrian.first));
    }
    set_cross();
  }

private:
  void set_cross();

public:
  bool is_safe(int id);
};

struct controler {
  crossing c;

  controler(crossing c) : c(c) {}

  void change_lights();
};

#endif // LIGHT_HPP