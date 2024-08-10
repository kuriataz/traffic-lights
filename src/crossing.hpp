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
private: // comment out for tests
  density d;
  std::vector<light> lights;

  friend class controler;

public:
  double all_load;       // sum of all lights' probabilities
  std::vector<set> sets; // stes of lights that can be green at the same time

  crossing() : d() { make_sets(); }

private: // comment out for tests
  void
  make_sets(); // creates 10 sets of lights that can be green at the same time
  void set_lights();  // gets probabilities from density
  void count_sums();  // adds sums of probabilities for each set of lights
  void update_sets(); // updates priority, time and order for each set of
                      // lights, sorts sets by their sums
};

#endif // CROSSING.HPP
