/**
 * @file in.hpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#ifndef IN_HPP
#define IN_HPP
#include <map>
#include <string>

struct in_interface {
  in_interface() = default;
  virtual ~in_interface() = default;

  virtual void parse(std::map<int, double> &cars,
                     std::map<int, double> &pedestrains, std::string) = 0;
};
#endif // IN_HPP