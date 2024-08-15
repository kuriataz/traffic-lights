/**
 * @file out.hpp
 * @license MIT
 * @date 03-08-2024
 * @author Zofia Kuriata
 */

#ifndef OUT_HPP
#define OUT_HPP

#include <light_set.hpp>
#include <string>
#include <vector>

struct out_interface {
  out_interface() = default;
  virtual ~out_interface() = default;

  virtual void save(std::vector<light_set> sets, std::string url) = 0;
  virtual void save_detail(std::vector<light_set> sets, std::string url) = 0;
};

#endif // OUT_HPP