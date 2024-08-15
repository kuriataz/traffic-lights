/**
 * @file crossing.cpp
 * @license MIT
 * @date 08-08-2024
 * @author Zofia Kuriata
 */

#include <algorithm>
#include <constants.hpp>
#include <crossing.hpp>
#include <vector>

void crossing::make_sets() {
  // {set_id, {ids of lights that can be green together}}
  sets.push_back({set0, {w_crossing, n_left, n_straight, e_right, s_right}});
  sets.push_back({set1, {w_crossing, e_left, n_straight, e_right, s_right}});
  sets.push_back({set2, {n_crossing, e_left, e_straight, s_right, w_right}});
  sets.push_back({set3, {n_crossing, s_left, e_straight, s_right, w_right}});
  sets.push_back({set4, {s_crossing, n_left, w_straight, n_right, e_right}});
  sets.push_back({set5, {s_crossing, w_left, w_straight, n_right, e_right}});
  sets.push_back({set6, {e_crossing, w_left, s_straight, n_right, w_right}});
  sets.push_back({set7, {e_crossing, s_left, s_straight, n_right, w_right}});
  sets.push_back({set8, {e_crossing, w_crossing, n_straight, s_straight}});
  sets.push_back({set9, {n_crossing, s_crossing, e_straight, w_straight}});
}

void crossing::set_lights() {
  for (auto &car : d.cars) {
    lights.push_back(light(car.first, car.second));
  }
  for (auto &pedestrian : d.pedestrians) {
    lights.push_back(light(pedestrian.first, pedestrian.second));
  }
  std::sort(lights.begin(), lights.end(),
            [](auto &a, auto &b) { return a.id < b.id; });
}

void crossing::count_sums() {
  double temp_sum = 0;
  for (int i = 0; i < sets.size(); ++i) {
    temp_sum = 0;
    for (int j = 0; j < sets[i].lights_ids.size(); ++j) {
      temp_sum += lights[sets[i].lights_ids[j]].load;
    }
    all_load += temp_sum;
    sets[i].sum = temp_sum;
  }
}

void crossing::update_sets() {
  std::sort(sets.begin(), sets.end(),
            [](auto &a, auto &b) { return a.sum > b.sum; });

  for (int i = 0; i != sets.size(); ++i) {
    sets[i].set_priority(sets[i].sum / all_load);
    sets[i].set_time(CYCLE_TIME);
    sets[i].set_order(i);
  }
}
