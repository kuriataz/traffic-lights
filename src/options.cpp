/**
 * @file options.cpp
 * @license MIT
 * @date 13-08-2024
 * @author Zofia Kuriata
 */

#include <cstring>
#include <options.hpp>

parse_result parse_arguments(int argc, char **argv, option_definition defs[],
                             int size) {
  parse_result result;
  if (argc < 2) {
    return result;
  }

  for (int i = 1; i < argc; i++) {
    int options_added = 0;
    for (int j = 0; j < size; j++) {
      if ((strcmp(argv[i], defs[j].long_name.c_str()) == 0) ||
          (strcmp(argv[i], defs[j].short_name.c_str()) == 0)) {
        if (defs[j].mandatory_argument == true && argc > i + 1) {
          option new_option = option(defs[j].id, argv[i + 1]);
          result.options.push_back(new_option);
          i++;
          options_added++;
          break;
        } else {
          option new_option = option(defs[j].id);
          result.options.push_back(new_option);
          options_added++;
          break;
        }
      }
    }
    if (options_added == 0) {
      result.arguments.push_back(argv[i]);
    }
  }
  return result;
}
