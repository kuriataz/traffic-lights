/**
 * @file light.hpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "out.hpp"
#include <density.hpp>
#include <map>
#include <random>
#include <vector>

#define GREEN_LOAD 10 // how many cars can pass on green light in one cycle

static std::random_device rd;
static std::mt19937 mt(rd());
static std::uniform_real_distribution<double> dis(0.0, 1.0);

struct light {
  int id = 0;
  int queue = 0;
  enum STATE { RED, GREEN } state;
  std::vector<int> cross; // ids of lights that can't be green at the same time

  light(int id) : id(id), state(RED) {}

  void set_cross_cars();        // for id 0-11
  void set_cross_pedestrians(); // for id 12-15

  void change_state();

  STATE get_state() const;
};

struct crossing {
  density *d;
  std::vector<light> lights;

  crossing(density *d) : d(d) {

    for (auto &car : d->cars) {
      lights.push_back(light(car.first));
    }
    for (auto &pedestrian : d->pedestrians) {
      lights.push_back(light(pedestrian.first));
    }
    set_cross();
  }

private:
  void set_cross();

public:
  bool is_safe(int id);

  void accept_traffic();
  void reduce_traffic();

  std::map<int, int> change_lights();
  void set_red();
  std::vector<int> get_greens();

  void cycle();

  void display();
};

struct controler {

  crossing *c;
  // stores ids of lights that are green and their queue for every cycle
  std::vector<std::map<int, int>> cycles;
  out_interface *out;

  controler(crossing *c, out_interface *out) : c(c), out(out) {}

  void go(int rounds);

  void parse(std::string file) { out->parse_output(this->cycles, file); }
  void parse_id(std::map<int, int> cycles, std::string file) {
    out->parse_output_id(cycles, file);
  }

  std::map<int, int> get_light_info(int light_id);
};

#endif // LIGHT_HPP