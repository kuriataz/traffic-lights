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
#include <out.hpp>
#include <string>

struct file_access : public in_interface, out_interface {
  // a function to parse the input file in a specific format
  virtual void parse_input(std::map<int, double> &cars,
                           std::map<int, double> &pedestrains,
                           std::string file) override;

  virtual void parse_output(std::vector<std::map<int, int>> &cycles,
                            std::string file) override;

  virtual void parse_output_id(std::map<int, int> &cycles,
                               std::string file) override;
};

#endif // FILE_ACCESS_HPP