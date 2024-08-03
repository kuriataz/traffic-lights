/**
 * @file out.hpp
 * @license MIT
 * @date 03-08-2024
 * @author Zofia Kuriata
 */

#ifndef OUT_HPP
#define OUT_HPP
#include <map>
#include <string>
#include <vector>

struct out_interface {
  out_interface() = default;
  virtual ~out_interface() = default;

  virtual void parse_output(std::vector<std::map<int, int>> &cycles,
                            std::string info) = 0;
};
#endif // OUT_HPP