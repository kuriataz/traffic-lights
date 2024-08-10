/**
 * @file controler.cpp
 * @license MIT
 * @date 08-08-2024
 * @author Zofia Kuriata
 */

#include <controler.hpp>
#include <stdexcept>

void controler::parse(std::string url) {
  if (url.find(".txt") != std::string::npos) {
    in = new file_access;
  } else {
    throw std::runtime_error("Error: input file must be a .txt file");
  }
  in->parse_input(c.d.cars, c.d.pedestrians, url);
}
void controler::go() {
  c.set_lights();
  c.count_sums();
  c.update_sets();
}

void controler::save(std::string url) {
  if (url.find(".txt") != std::string::npos) {
    out = new file_access;
  } else {
    throw std::runtime_error("Error: output file must be a .txt file");
  }
  out->save(c.sets, url);
}
