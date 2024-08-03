/**
 * @file test.cpp
 * @license MIT
 * @date 30-07-2024
 * @author Zofia Kuriata
 */

#include "gmock/gmock.h"
#include <density.hpp>
#include <file_access.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <light.hpp>
#include <utility>

// TEST(FileAccessTest, ParseTest) {
//   file_access fa;
//   std::map<int, double> cars;
//   std::map<int, double> pedestrians;
//   fa.parse(cars, pedestrians,
//            std::string(CMAKE_SOURCE_DIR) + "/docs/input.txt");

//   ASSERT_DOUBLE_EQ(cars[0], 0.12);
//   ASSERT_DOUBLE_EQ(cars[8], 0.15);
//   ASSERT_DOUBLE_EQ(pedestrians[13], 0.3);
// }

// TEST(DensityTest, ParseTest) {
//   file_access in;
//   density d(&in);

//   d.parse(std::string(CMAKE_SOURCE_DIR) + "/docs/input.txt");

//   ASSERT_DOUBLE_EQ(d.cars[0], 0.12);
//   ASSERT_DOUBLE_EQ(d.cars[8], 0.15);
//   ASSERT_DOUBLE_EQ(d.pedestrians[13], 0.3);
// }

TEST(DensityTest, CreateTest) {
  file_access in;
  density d(&in);
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
  file_access in;
  density d(&in);

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

TEST(LightTest, SetCrossCarsTest) {
  light n_straight(0);
  n_straight.set_cross_cars();
  ASSERT_THAT(n_straight.cross, testing::ElementsAre(3, 4, 7, 9, 10, 11));

  light e_left(4);
  e_left.set_cross_cars();
  ASSERT_THAT(e_left.cross, testing::ElementsAre(6, 7, 9, 10, 11, 0, 1));

  light s_right(8);
  s_right.set_cross_cars();
  ASSERT_THAT(s_right.cross, testing::ElementsAre(9, 1));

  light w_left(10);
  w_left.set_cross_cars();
  ASSERT_THAT(w_left.cross, testing::ElementsAre(0, 1, 3, 4, 5, 6, 7));
}

TEST(LightTest, SetCrossPedestriansTest) {
  light n_crossing(12);
  n_crossing.set_cross_pedestrians();
  ASSERT_THAT(n_crossing.cross, testing::ElementsAre(0, 1, 2, 6, 10, 5));

  light s_crossing(14);
  s_crossing.set_cross_pedestrians();
  ASSERT_THAT(s_crossing.cross, testing::ElementsAre(6, 7, 8, 0, 4, 11));
}

TEST(LightTest, ChangeStateTest) {
  light l(0);
  light::STATE state = l.get_state();
  ASSERT_EQ(state, light::RED);
  l.change_state();
  state = l.get_state();
  ASSERT_EQ(state, light::GREEN);
  l.change_state();
  state = l.get_state();
  ASSERT_EQ(state, light::RED);
}

TEST(CrossingTest, CreateTest) {
  file_access in;
  density d(&in);
  crossing c(&d);

  ASSERT_THAT(c.lights[0].cross,
              testing::ElementsAre(3, 4, 7, 9, 10, 11, 12, 14));
  ASSERT_THAT(c.lights[12].cross, testing::ElementsAre(0, 1, 2, 6, 10, 5));
}

TEST(CrossingTest, IsSafeTest) {
  file_access in;
  density d(&in);
  crossing c(&d);

  ASSERT_TRUE(c.is_safe(0));
  c.lights[0].change_state();
  ASSERT_FALSE(c.is_safe(3));
  ASSERT_FALSE(c.is_safe(12));
  ASSERT_TRUE(c.is_safe(13));
}

TEST(ControlerTest, MainTest) {
  file_access in;
  density d(&in);
  d.parse(std::string(CMAKE_SOURCE_DIR) + "/docs/input.txt");
  crossing c(&d);
  controler ctrl(&c, &in);
  ctrl.go(10);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
