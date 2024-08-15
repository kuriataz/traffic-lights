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
#include <light_set.hpp>
#include <vector>

class CrossingTest_SetLightsTest_Test;
class CrossingTest_CountSumsTest_Test;
class CrossingTest_UpdateSetsTest_Test;

struct crossing {

  friend class CrossingTest_SetLightsTest_Test;
  friend class CrossingTest_CountSumsTest_Test;
  friend class CrossingTest_UpdateSetsTest_Test;

private:
  density d;
  std::vector<light> lights;

  friend class controler;

public:
  double all_load; // sum of all lights' probabilities
  std::vector<light_set>
      sets; // sets of lights that can be green at the same time

  crossing() : d() { make_sets(); }

private:
  void
  make_sets(); // creates 10 sets of lights that can be green at the same time
  void set_lights();  // gets probabilities from this->d (density struct)
  void count_sums();  // adds sums of probabilities for each set of lights
  void update_sets(); // updates priority, time and order for each set of
                      // lights, sorts sets by their sums
};

#endif // CROSSING.HPP
