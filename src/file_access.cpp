#include <constants.hpp>
#include <cstddef>
#include <file_access.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

void file_access::parse_input(std::map<int, double> &cars,
                              std::map<int, double> &pedestrians,
                              std::string url) {
  std::ifstream input(url);
  if (!input.is_open()) {
    throw std::runtime_error("Error: could not open input file: " + url);
  }

  std::string line;
  std::string direction;
  std::istringstream iss(line);
  int i = 0;
  int j = 0;

  while (j != c_lights) {
    j += ways;
    std::getline(input, line);
    if (input.fail()) {
      throw std::runtime_error("Error: failed to read from input file: " + url);
    }
    iss.clear();
    iss.str(line);
    for (; i != j; ++i) {
      iss >> cars[i];
    }
  }

  std::getline(input, line);
  std::getline(input, line);
  if (input.fail()) {
    throw std::runtime_error("Error: failed to read from input file: " + url);
  }
  iss.clear();
  iss.str(line);
  for (; i != c_lights + p_lights; ++i) {
    iss >> pedestrians[i];
  }
}

void file_access::save(std::vector<light_set> sets, std::string url) {
  std::ofstream output(url);
  if (!output.is_open()) {
    throw std::runtime_error("Error: could not open output file: " + url);
  }

  int counter = 0;
  for (size_t i = 0; i < sets.size(); ++i) {
    output << "Green for entry " << counter << ". : ";
    counter += sets[i].time;
    for (size_t j = 0; j < sets[i].lights_ids.size(); ++j) {
      output << sets[i].lights_ids[j] << " ";
    }
    output << std::endl;
  }
  if (output.fail()) {
    throw std::runtime_error("Error: failed to write to output file: " + url);
  }
  output.close();
}

void file_access::save_detail(std::vector<light_set> sets, std::string url) {
  std::ofstream output(url);
  if (!output.is_open()) {
    throw std::runtime_error("Error: could not open output file: " + url);
  }

  int counter = 0;
  for (size_t i = 0; i < sets.size(); ++i) {
    for (int k = 0; k < sets[i].time; ++k) {
      output << "Green for entry " << counter << ". : ";
      ++counter;
      for (size_t j = 0; j < sets[i].lights_ids.size(); ++j) {
        output << sets[i].lights_ids[j] << " ";
      }
      output << std::endl;
    }
  }

  if (output.fail()) {
    throw std::runtime_error("Error: failed to write to output file: " + url);
  }

  output.close();
}
