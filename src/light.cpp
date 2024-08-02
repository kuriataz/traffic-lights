/**
 * @file light.cpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#include <algorithm>
#include <light.hpp>

light::STATE light::get_state() const { return state; }

void light::change_state() {
  if (state == RED) {
    state = GREEN;
  } else {
    state = RED;
  }
}

void light::set_cross_cars() {
  int direction = id % 3; // 0 = straight, 1 = left, 2 = right
  switch (direction) {
  case 0:
    cross.push_back((id + 3) % 12);
    cross.push_back((id + 4) % 12);
    cross.push_back((id + 7) % 12);
    cross.push_back((id + 9) % 12);
    cross.push_back((id + 10) % 12);
    cross.push_back((id + 11) % 12);
    break;
  case 1:
    cross.push_back((id + 2) % 12);
    cross.push_back((id + 3) % 12);
    cross.push_back((id + 5) % 12);
    cross.push_back((id + 6) % 12);
    cross.push_back((id + 7) % 12);
    cross.push_back((id + 8) % 12);
    cross.push_back((id + 9) % 12);
    break;
  case 2:
    cross.push_back((id + 1) % 12);
    cross.push_back((id + 5) % 12);
    break;
  }
}

void light::set_cross_pedestrians() {
  int direction = id % 4; // 0 = north, 1 = east, 2 = south, 3 = west
  cross.push_back(direction * 3);
  cross.push_back(direction * 3 + 1);
  cross.push_back(direction * 3 + 2);
  cross.push_back((direction * 3 + 6) % 12);
  cross.push_back((((direction * 3 + 6) % 12) + 4) % 12);
  cross.push_back((((((direction * 3 + 6) % 12) + 4) % 12) + 7) % 12);
}

void crossing::set_cross() {
  for (int i = 0; i < 12; ++i) {
    lights[i].set_cross_cars();
  }
  for (int i = 12; i != 16; ++i) {
    lights[i].set_cross_pedestrians();
    for (int id : lights[i].cross) {
      lights[id].cross.push_back(i);
    }
  }
}

bool crossing::is_safe(int id) {
  for (int i : lights[id].cross) {
    if (lights[i].state == light::GREEN) {
      return false;
    }
  }
  return true;
}

void controler::change_lights() {
  std::sort(c.lights.begin(), c.lights.end(),
            [](auto &a, auto &b) { return a.queue < b.queue; });

  for (auto &light : c.lights) {
    if (c.is_safe(light.id)) {
      light.change_state();
    }
  }
}
