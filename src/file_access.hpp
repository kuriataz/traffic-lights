/**
 * @file file_access.hpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#ifndef FILE_ACCESS_HPP
#define FILE_ACCESS_HPP

#include <in.hpp>
#include <light_set.hpp>
#include <map>
#include <out.hpp>
#include <string>

struct file_access : public in_interface, public out_interface {
  virtual void parse_input(std::map<int, double> &cars,
                           std::map<int, double> &pedestrains,
                           std::string url) override;

  virtual void save(std::vector<light_set> sets, std::string url)
      override; // shows only the entries when the lights are changed
  virtual void save_detail(std::vector<light_set> sets,
                           std::string url) override; // shows every entry
};

#endif // FILE_ACCESS_HPP