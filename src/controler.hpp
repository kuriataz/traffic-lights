/**
 * @file controler.hpp
 * @license MIT
 * @date 08-08-2024
 * @author Zofia Kuriata
 */

#ifndef CONTROLER_HPP
#define CONTROLER_HPP

#include <crossing.hpp>

struct controler {
private:
  crossing c;
  // they must be pointers beacuse they are set in parse and save methods
  in_interface *in = nullptr;
  out_interface *out = nullptr;

public:
  controler() : c() {}

  void parse(std::string url); // get probabilities from input

  void go();

  void save(std::string url); // store the output
};

#endif // CONTROLER.HPP