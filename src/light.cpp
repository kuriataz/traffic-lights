/**
 * @file light.cpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#include <algorithm>
#include <iostream>
#include <light.hpp>
#include <map>
#include <vector>

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

void crossing::accept_traffic() {
  for (int i = 0; i != 12; ++i) {
    if (dis(mt) < d->cars[i]) {
      lights[i].queue++;
    }
  }
  for (int i = 12; i != 16; ++i) {
    if (dis(mt) < d->pedestrians[i]) {
      lights[i].queue++;
    }
  }
}

void crossing::reduce_traffic() {
  int i = 0;
  for (; i != 12; ++i) {
    if (lights[i].state == light::GREEN) {
      lights[i].queue = std::max(0, lights[i].queue - GREEN_LOAD);
    }
  }
  for (; i != 16; ++i) {
    if (lights[i].state == light::GREEN) {
      lights[i].queue = 0;
    }
  }
}

std::map<int, int> crossing::change_lights() {
  std::map<int, int> greens;
  std::sort(lights.begin(), lights.end(),
            [](auto &a, auto &b) { return a.queue > b.queue; });

  for (light &light : lights) {
    if (is_safe(light.id)) {
      light.change_state();
      greens[light.id] = light.queue;
    }
  }
  return greens;
}

void crossing::set_red() {
  for (light &light : lights) {
    light.state = light.RED;
  }
}

std::vector<int> crossing::get_greens() {
  std::vector<int> greens;
  for (light &light : lights) {
    if (light.state == light::GREEN) {
      greens.push_back(light.id);
    }
  }
  return greens;
}
void crossing::cycle() {
  accept_traffic();
  change_lights();
  display();
  reduce_traffic();
  display();
  set_red();
}

void crossing::display() {
  for (light &light : lights) {
    std::cout << "Light " << light.id << " " << d->ids[light.id] << " is ";
    if (light.state == light::RED) {
      std::cout << "red";
    } else {
      std::cout << "green";
    }
    std::cout << " with queue " << light.queue << std::endl;
  }
}

void controler::go(int rounds) {
  cycles.resize(rounds);
  for (int i = 0; i != rounds; ++i) {
    // c->cycle();
    c->accept_traffic();
    cycles[i] = c->change_lights();
    c->display();
    c->reduce_traffic();
    c->display();
    c->set_red();
  }
}
