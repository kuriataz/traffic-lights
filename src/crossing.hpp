/**
 * @file crossing.hpp
 * @license MIT
 * @date 08-08-2024
 * @author Zofia Kuriata
 */

#ifndef CROSSING_HPP
#define CROSSING_HPP

#include <density.hpp>
#include <light.hpp>
#include <set.hpp>
#include <vector>

struct crossing {
  // private:
  density d;
  std::vector<light> lights;

  friend class controler;

public:
  double all_load;
  std::vector<set> sets;

  crossing() : d() { make_sets(); }

  // private:
  void make_sets();
  void count_sums();
  void update_sets();
  void set_lights();

public:
  void display();
};

#endif // CROSSING.HPP
