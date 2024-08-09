/**
 * @file crossing.cpp
 * @license MIT
 * @date 08-08-2024
 * @author Zofia Kuriata
 */

#include <algorithm>
#include <crossing.hpp>
#include <vector>

void crossing::make_sets() {

  // is it possible to do it without magic numbers?
  // {id, {ids of lights that can be green together}}
  sets.push_back({0, {15, 1, 0, 5, 8}});
  sets.push_back({1, {15, 4, 0, 5, 8}});
  sets.push_back({2, {12, 4, 3, 8, 11}});
  sets.push_back({3, {12, 7, 3, 8, 11}});
  sets.push_back({4, {14, 1, 9, 2, 5}});
  sets.push_back({5, {14, 10, 9, 2, 5}});
  sets.push_back({6, {13, 10, 6, 2, 11}});
  sets.push_back({7, {13, 7, 6, 2, 11}});
  sets.push_back({8, {13, 15, 0, 6}});
  sets.push_back({9, {12, 14, 3, 9}});
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
