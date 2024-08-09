// /**
//  * @file test.cpp
//  * @license MIT
//  * @date 30-07-2024
//  * @author Zofia Kuriata
//  */

#include "gmock/gmock.h"
#include <crossing.hpp>
#include <density.hpp>
#include <file_access.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <light.hpp>
#include <set.hpp>
#include <utility>

TEST(FileAccessTest, ParseTest) {
  file_access fa;
  std::map<int, double> cars;
  std::map<int, double> pedestrians;
  fa.parse_input(cars, pedestrians,
                 std::string(CMAKE_SOURCE_DIR) + "/docs/input.txt");

  ASSERT_DOUBLE_EQ(cars[0], 0.0);
  ASSERT_DOUBLE_EQ(cars[8], 0.15);
  ASSERT_DOUBLE_EQ(pedestrians[13], 0.3);
}

TEST(DensityTest, CreateTest) {
  density d;
  ASSERT_THAT(d.ids, testing::UnorderedElementsAre(
                         std::pair<int, const std::string>(0, "n_straight"),
                         std::pair<int, const std::string>(1, "n_left"),
                         std::pair<int, const std::string>(2, "n_right"),
                         std::pair<int, const std::string>(3, "e_straight"),
                         std::pair<int, const std::string>(4, "e_left"),
                         std::pair<int, const std::string>(5, "e_right"),
                         std::pair<int, const std::string>(6, "s_straight"),
                         std::pair<int, const std::string>(7, "s_left"),
                         std::pair<int, const std::string>(8, "s_right"),
                         std::pair<int, const std::string>(9, "w_straight"),
                         std::pair<int, const std::string>(10, "w_left"),
                         std::pair<int, const std::string>(11, "w_right"),
                         std::pair<int, const std::string>(12, "n_crossing"),
                         std::pair<int, const std::string>(13, "e_crossing"),
                         std::pair<int, const std::string>(14, "s_crossing"),
                         std::pair<int, const std::string>(15, "w_crossing")));

  ASSERT_THAT(d.cars,
              testing::UnorderedElementsAre(
                  std::pair<int, double>(0, 0), std::pair<int, double>(1, 0),
                  std::pair<int, double>(2, 0), std::pair<int, double>(3, 0),
                  std::pair<int, double>(4, 0), std::pair<int, double>(5, 0),
                  std::pair<int, double>(6, 0), std::pair<int, double>(7, 0),
                  std::pair<int, double>(8, 0), std::pair<int, double>(9, 0),
                  std::pair<int, double>(10, 0),
                  std::pair<int, double>(11, 0)));

  ASSERT_THAT(d.pedestrians,
              testing::UnorderedElementsAre(std::pair<int, double>(12, 0),
                                            std::pair<int, double>(13, 0),
                                            std::pair<int, double>(14, 0),
                                            std::pair<int, double>(15, 0)));
}

TEST(DensityTest, DisplayTest) {
  density d;

  // some values for testing
  d.cars[0] = 1.1;
  d.cars[1] = 2.2;
  d.cars[2] = 3.3;
  d.cars[3] = 4.4;
  d.cars[4] = 5.5;
  d.cars[5] = 6.6;
  d.cars[6] = 7.7;
  d.cars[7] = 8.8;
  d.cars[8] = 9.9;
  d.cars[9] = 10.10;
  d.cars[10] = 11.11;
  d.cars[11] = 12.12;
  d.pedestrians[12] = 13.13;
  d.pedestrians[13] = 14.14;
  d.pedestrians[14] = 15.15;
  d.pedestrians[15] = 16.16;

  testing::internal::CaptureStdout();
  d.display();
  std::string output = testing::internal::GetCapturedStdout();

  std::string expected_output = "North: 1.1 2.2 3.3 \n"
                                "East: 4.4 5.5 6.6 \n"
                                "South: 7.7 8.8 9.9 \n"
                                "West: 10.1 11.11 12.12 \n"
                                "Crossing: 13.13 14.14 15.15 16.16 ";

  ASSERT_EQ(output, expected_output);
}

TEST(SetTest, SetPriorityTest) {
  set s({0, {15, 1, 0, 5, 8}});
  s.sum = 100;
  s.set_priority(0.5);
  ASSERT_EQ(s.priority, 0.5);
}

TEST(CrossingTest, SetLightsTest) {
  crossing c;
  c.d.cars = {{0, 10.0}, {1, 20.0},  {2, 30.0},   {3, 40.0},
              {4, 50.0}, {5, 60.0},  {6, 70.0},   {7, 80.0},
              {8, 90.0}, {9, 100.0}, {10, 110.0}, {11, 120.0}};
  c.d.pedestrians = {{12, 5.0}, {13, 10.0}, {14, 15.0}, {15, 20.0}};
  c.set_lights();

  ASSERT_EQ(c.lights[0].id, 0);
  ASSERT_EQ(c.lights[0].load, 10);
  ASSERT_EQ(c.lights[5].id, 5);
  ASSERT_EQ(c.lights[5].load, 60);
}

TEST(CrossingTest, CountSumsTest) {
  crossing c;
  c.d.cars = {{0, 10.0}, {1, 20.0},  {2, 30.0},   {3, 40.0},
              {4, 50.0}, {5, 60.0},  {6, 70.0},   {7, 80.0},
              {8, 90.0}, {9, 100.0}, {10, 110.0}, {11, 120.0}};
  c.d.pedestrians = {{12, 5.0}, {13, 10.0}, {14, 15.0}, {15, 20.0}};
  c.set_lights();
  c.count_sums();

  // ({0, {15, 1, 0, 5, 8}});
  ASSERT_EQ(c.sets[0].sum, (20 + 20 + 10 + 60 + 90));
  // ({5, {14, 10, 9, 2, 5}});
  ASSERT_EQ(c.sets[5].sum, (15 + 110 + 100 + 30 + 60));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
