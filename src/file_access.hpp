/**
 * @file file_access.hpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#ifndef FILE_ACCESS_HPP
#define FILE_ACCESS_HPP
#include <in.hpp>
#include <map>
#include <string>

struct file_access : public in_interface {
  // a function to parse the input file in a specific format
  virtual void parse(std::map<int, double> &cars,
                     std::map<int, double> &pedestrains, std::string) override;
};

#endif // FILE_ACCESS_HPP