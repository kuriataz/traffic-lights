/**
 * @file file_access_test.cpp
 * @license MIT
 * @date 13-08-2024
 * @author Zofia Kuriata
 */

#include <constants.hpp>
#include <file_access.hpp>
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <light_set.hpp>
#include <map>
#include <string>

// Helper function to create a mock input file
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

// Helper function to create a mock output file
std::string create_mock_output_file() { return "mock_output.txt"; }

// Helper function to remove a file
void remove_file(const std::string &filename) { std::remove(filename.c_str()); }

// Helper function to verify the content of an output file
void verify_output_file_content(const std::string &filename,
                                const std::string &expected_content) {
  std::ifstream file(filename);
  std::stringstream buffer;
  buffer << file.rdbuf();
  EXPECT_EQ(buffer.str(), expected_content);
}

// Test for parse_input method
TEST(FileAccessTest, ParseInput_Success) {
  std::string filename = create_mock_input_file();
  file_access fa;

  std::map<int, double> cars;
  std::map<int, double> pedestrians;

  ASSERT_NO_THROW(fa.parse_input(cars, pedestrians, filename));

  EXPECT_EQ(cars[n_straight], 0.1);
  EXPECT_EQ(cars[e_left], 0.21);
  EXPECT_EQ(cars[s_right], 0.32);

  EXPECT_EQ(pedestrians[n_crossing], 0.5);
  EXPECT_EQ(pedestrians[s_crossing], 0.52);

  remove_file(filename);
}

// Test for parse_input method when file is not found
TEST(FileAccessTest, ParseInput_FileNotFound) {
  file_access fa;
  std::map<int, double> cars;
  std::map<int, double> pedestrians;

  EXPECT_THROW(fa.parse_input(cars, pedestrians, "non_existent_file.txt"),
               std::runtime_error);
}

// Test for parse_input method when file has wrong format - data is missing
TEST(FileAccessTest, ParseInput_WrongInputFormat) {
  file_access fa;
  std::map<int, double> cars;
  std::map<int, double> pedestrians;

  std::string wrong = "wrong_input.txt";
  std::ofstream file(wrong);

  if (file.is_open()) {
    file << "0.1 0.11 0.12\n";
    file << "0.2 0.21 0.22\n";
    file << "0.3 0.31 \n";
    file << "0.4 0.41 0.42\n";
    file << "\n";
    file << "0.5 0.51 0.52\n";
    file.close();
  }

  EXPECT_THROW(fa.parse_input(cars, pedestrians, wrong), std::runtime_error);

  remove_file(wrong);
}

// Test for save method
TEST(FileAccessTest, Save_Success) {
  std::string filename = create_mock_output_file();
  file_access fa;

  std::vector<light_set> sets = {{0, {0, 1}}, {1, {2, 3, 4, 5}}};
  sets[0].time = 3;
  sets[1].time = 1;

  ASSERT_NO_THROW(fa.save(sets, filename));

  std::string expected_content = "Green for entry 0. : 0 1 \n"
                                 "Green for entry 3. : 2 3 4 5 \n";

  verify_output_file_content(filename, expected_content);

  remove_file(filename);
}

// Test for save method when file is not found
TEST(FileAccessTest, Save_FileNotFound) {
  file_access fa;

  std::vector<light_set> sets = {{0, {0, 1}}, {1, {2, 3, 4, 5}}};
  sets[0].time = 3;
  sets[1].time = 1;

  EXPECT_THROW(fa.save(sets, "/invalid_path/output.txt"), std::runtime_error);
}

// Test for save_detail method
TEST(FileAccessTest, SaveDetail_Success) {
  std::string filename = create_mock_output_file();
  file_access fa;

  std::vector<light_set> sets = {{0, {0, 1}}, {1, {2, 3, 4, 5}}};
  sets[0].time = 3;
  sets[1].time = 1;

  ASSERT_NO_THROW(fa.save_detail(sets, filename));

  std::string expected_content = "Green for entry 0. : 0 1 \n"
                                 "Green for entry 1. : 0 1 \n"
                                 "Green for entry 2. : 0 1 \n"
                                 "Green for entry 3. : 2 3 4 5 \n";

  verify_output_file_content(filename, expected_content);

  remove_file(filename);
}

// Test for save_detail method when file is not found
TEST(FileAccessTest, SaveDetail_FileNotFound) {
  file_access fa;

  std::vector<light_set> sets = {{0, {0, 1}}, {1, {2, 3, 4, 5}}};
  sets[0].time = 3;
  sets[1].time = 1;

  EXPECT_THROW(fa.save_detail(sets, "/invalid_path/output.txt"),
               std::runtime_error);
}
