/**
 * @file controler_test.cpp
 * @license MIT
 * @date 15-08-2024
 * @author Zofia Kuriata
 */

#include <constants.hpp>
#include <controler.hpp>
#include <file_access.hpp>
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <light_set.hpp>
#include <string>

std::string create_mock_input_file() {
  std::string filename = "mock_input.txt";
  std::ofstream file(filename);

  if (file.is_open()) {
    file << "0.1 0.11 0.12\n";
    file << "0.2 0.21 0.22\n";
    file << "0.3 0.31 0.32\n";
    file << "0.4 0.41 0.42\n";
    file << "\n";
    file << "0.5 0.51 0.52 0.53\n";
    file.close();
  }
  return filename;
}

std::string create_mock_output_file() { return "mock_output.txt"; }

void remove_file(const std::string &filename) { std::remove(filename.c_str()); }

void verify_output_file_content(const std::string &filename,
                                const std::string &expected_content) {
  std::ifstream file(filename);
  std::stringstream buffer;
  buffer << file.rdbuf();
  EXPECT_EQ(buffer.str(), expected_content);
}

TEST(ControlerTest, Parse_Success) {
  std::string filename = create_mock_input_file();
  controler ctrl;

  ASSERT_NO_THROW(ctrl.parse(filename));

  remove_file(filename);
}

TEST(ControlerTest, Parse_FileNotFound) {
  controler ctrl;
  EXPECT_THROW(ctrl.parse("non_existent_file.txt"), std::runtime_error);
}

TEST(ControlerTest, Save_Success) {
  std::string input_filename = create_mock_input_file();
  std::string output_filename = create_mock_output_file();
  controler ctrl;

  ctrl.parse(input_filename);
  ctrl.go();

  ASSERT_NO_THROW(ctrl.save(output_filename));

  std::string expected_content =
      "Green for entry 0. : 13 10 6 2 11 \nGreen for entry 10. : 12 7 3 8 11 "
      "\nGreen for entry 20. : 14 10 9 2 5 \nGreen for entry 29. : 13 7 6 2 11 "
      "\nGreen for entry 38. : 12 4 3 8 11 \nGreen for entry 47. : 12 14 3 9 "
      "\nGreen for entry 56. : 13 15 0 6 \nGreen for entry 64. : 15 4 0 5 8 "
      "\nGreen for entry 71. : 14 1 9 2 5 \nGreen for entry 78. : 15 1 0 5 8 "
      "\n";

  verify_output_file_content(output_filename, expected_content);

  remove_file(input_filename);
  remove_file(output_filename);
}

TEST(ControlerTest, Save_FileNotFound) {
  std::string input_filename = create_mock_input_file();
  controler ctrl;

  ctrl.parse(input_filename);
  ctrl.go();

  EXPECT_THROW(ctrl.save("/invalid_path/output.txt"), std::runtime_error);

  remove_file(input_filename);
}

TEST(ControlerTest, SaveDetail_Success) {
  std::string input_filename = create_mock_input_file();
  std::string output_filename = create_mock_output_file();
  controler ctrl;

  ctrl.parse(input_filename);
  ctrl.go();

  ASSERT_NO_THROW(ctrl.save_detail(output_filename));

  std::string expected_content =
      "Green for entry 0. : 13 10 6 2 11 \nGreen for entry 1. : 13 10 6 2 11 "
      "\nGreen for entry 2. : 13 10 6 2 11 \nGreen for entry 3. : 13 10 6 2 11 "
      "\nGreen for entry 4. : 13 10 6 2 11 \nGreen for entry 5. : 13 10 6 2 11 "
      "\nGreen for entry 6. : 13 10 6 2 11 \nGreen for entry 7. : 13 10 6 2 11 "
      "\nGreen for entry 8. : 13 10 6 2 11 \nGreen for entry 9. : 13 10 6 2 11 "
      "\nGreen for entry 10. : 12 7 3 8 11 \nGreen for entry 11. : 12 7 3 8 11 "
      "\nGreen for entry 12. : 12 7 3 8 11 \nGreen for entry 13. : 12 7 3 8 11 "
      "\nGreen for entry 14. : 12 7 3 8 11 \nGreen for entry 15. : 12 7 3 8 11 "
      "\nGreen for entry 16. : 12 7 3 8 11 \nGreen for entry 17. : 12 7 3 8 11 "
      "\nGreen for entry 18. : 12 7 3 8 11 \nGreen for entry 19. : 12 7 3 8 11 "
      "\nGreen for entry 20. : 14 10 9 2 5 \nGreen for entry 21. : 14 10 9 2 5 "
      "\nGreen for entry 22. : 14 10 9 2 5 \nGreen for entry 23. : 14 10 9 2 5 "
      "\nGreen for entry 24. : 14 10 9 2 5 \nGreen for entry 25. : 14 10 9 2 5 "
      "\nGreen for entry 26. : 14 10 9 2 5 \nGreen for entry 27. : 14 10 9 2 5 "
      "\nGreen for entry 28. : 14 10 9 2 5 \nGreen for entry 29. : 13 7 6 2 11 "
      "\nGreen for entry 30. : 13 7 6 2 11 \nGreen for entry 31. : 13 7 6 2 11 "
      "\nGreen for entry 32. : 13 7 6 2 11 \nGreen for entry 33. : 13 7 6 2 11 "
      "\nGreen for entry 34. : 13 7 6 2 11 \nGreen for entry 35. : 13 7 6 2 11 "
      "\nGreen for entry 36. : 13 7 6 2 11 \nGreen for entry 37. : 13 7 6 2 11 "
      "\nGreen for entry 38. : 12 4 3 8 11 \nGreen for entry 39. : 12 4 3 8 11 "
      "\nGreen for entry 40. : 12 4 3 8 11 \nGreen for entry 41. : 12 4 3 8 11 "
      "\nGreen for entry 42. : 12 4 3 8 11 \nGreen for entry 43. : 12 4 3 8 11 "
      "\nGreen for entry 44. : 12 4 3 8 11 \nGreen for entry 45. : 12 4 3 8 11 "
      "\nGreen for entry 46. : 12 4 3 8 11 \nGreen for entry 47. : 12 14 3 9 "
      "\nGreen for entry 48. : 12 14 3 9 \nGreen for entry 49. : 12 14 3 9 "
      "\nGreen for entry 50. : 12 14 3 9 \nGreen for entry 51. : 12 14 3 9 "
      "\nGreen for entry 52. : 12 14 3 9 \nGreen for entry 53. : 12 14 3 9 "
      "\nGreen for entry 54. : 12 14 3 9 \nGreen for entry 55. : 12 14 3 9 "
      "\nGreen for entry 56. : 13 15 0 6 \nGreen for entry 57. : 13 15 0 6 "
      "\nGreen for entry 58. : 13 15 0 6 \nGreen for entry 59. : 13 15 0 6 "
      "\nGreen for entry 60. : 13 15 0 6 \nGreen for entry 61. : 13 15 0 6 "
      "\nGreen for entry 62. : 13 15 0 6 \nGreen for entry 63. : 13 15 0 6 "
      "\nGreen for entry 64. : 15 4 0 5 8 \nGreen for entry 65. : 15 4 0 5 8 "
      "\nGreen for entry 66. : 15 4 0 5 8 \nGreen for entry 67. : 15 4 0 5 8 "
      "\nGreen for entry 68. : 15 4 0 5 8 \nGreen for entry 69. : 15 4 0 5 8 "
      "\nGreen for entry 70. : 15 4 0 5 8 \nGreen for entry 71. : 14 1 9 2 5 "
      "\nGreen for entry 72. : 14 1 9 2 5 \nGreen for entry 73. : 14 1 9 2 5 "
      "\nGreen for entry 74. : 14 1 9 2 5 \nGreen for entry 75. : 14 1 9 2 5 "
      "\nGreen for entry 76. : 14 1 9 2 5 \nGreen for entry 77. : 14 1 9 2 5 "
      "\nGreen for entry 78. : 15 1 0 5 8 \nGreen for entry 79. : 15 1 0 5 8 "
      "\nGreen for entry 80. : 15 1 0 5 8 \nGreen for entry 81. : 15 1 0 5 8 "
      "\nGreen for entry 82. : 15 1 0 5 8 \nGreen for entry 83. : 15 1 0 5 8 "
      "\nGreen for entry 84. : 15 1 0 5 8 \n";

  verify_output_file_content(output_filename, expected_content);

  remove_file(input_filename);
  remove_file(output_filename);
}

TEST(ControlerTest, SaveDetail_FileNotFound) {
  std::string input_filename = create_mock_input_file();
  controler ctrl;

  ctrl.parse(input_filename);
  ctrl.go();

  EXPECT_THROW(ctrl.save_detail("/invalid_path/output.txt"),
               std::runtime_error);

  remove_file(input_filename);
}
