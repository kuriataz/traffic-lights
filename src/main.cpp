// /**
//  * @file main.cpp
//  * @license MIT
//  * @date 03-08-2024
//  * @author Zofia Kuriata
//  */

// #include <density.hpp>
// #include <file_access.hpp>
// #include <iostream>
// #include <light.hpp>
// #include <ui.hpp>

// int main() {
//   user_interface ui;
//   data data;

//   data = ui.process();

//   std::cout << "HERE1\n";
//   density d(data.in);
//   std::cout << "HERE2\n";
//   d.parse(data.input);
//   std::cout << "HERE3\n";
//   crossing c(&d);
//   std::cout << "HERE4\n";
//   controler ctrl(&c, data.out);
//   std::cout << "HERE5\n";
//   ctrl.go(data.cycles);
//   std::cout << "HERE6\n";
//   ctrl.parse(data.output);
//   std::cout << "HERE7\n";
// }

/**
 * @file main.cpp
 * @license MIT
 * @date 03-08-2024
 * @author Zofia Kuriata
 */

#include "in.hpp"
#include <density.hpp>
#include <file_access.hpp>
#include <iostream>
#include <light.hpp>
#include <map>
#include <ui.hpp>
#include <vector>

int main() {
  // user_interface ui;
  // data data;

  // data = ui.process();

  // density d(&(*data.in));
  // d.parse(data.input);
  // crossing c(&d);
  // controler ctrl(&c, &(*data.out));
  // ctrl.go(data.cycles);
  // if (data.light_id != -1) {
  //   std::map<int, int> cycles = ctrl.get_light_info(data.light_id);
  //   ctrl.parse_id(cycles, data.output);
  // } else {
  //   ctrl.parse(data.output);
  // }
  file_access fa;
  density d(&fa);
  d.parse("docs/input.txt");
  crossing c(&d);
  controler ctrl(&c, &fa);
  ctrl.go(5);
  std::map<int, int> cycles = ctrl.get_light_info(0);

  return 0;
}
