#include "file_access.hpp"
#include <density.hpp>

int main() {
  file_access f;
  density d(&f);
  d.parse("src/input.txt");
  d.display();
  return 0;
}
