/**
 * @file density_test.cpp
 * @license MIT
 * @date 14-08-2024
 * @author Zofia Kuriata
 */

#include <constants.hpp>
#include <density.hpp>
#include <gtest/gtest.h>
#include <sstream>

TEST(DensityTest, ConstructorTest) {
  density d;

  EXPECT_EQ(d.cars.size(), c_lights);
  EXPECT_EQ(d.pedestrians.size(), p_lights);

  for (const auto &pair : d.cars) {
    EXPECT_EQ(pair.second, 0);
  }

  for (const auto &pair : d.pedestrians) {
    EXPECT_EQ(pair.second, 0);
  }
}

TEST(DensityTest, DisplayTest) {
  density d;

  for (int i = 0; i < c_lights; ++i) {
    d.cars[i] = i * 1.1;
  }

  for (int i = 0; i < p_lights; ++i) {
    d.pedestrians[i + c_lights] = i * 0.5;
  }

  std::ostringstream output;
  std::streambuf *oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
  d.display();
  std::cout.rdbuf(oldCoutBuffer);

  std::string expectedOutput = "North: 0 1.1 2.2 \n"
                               "East: 3.3 4.4 5.5 \n"
                               "South: 6.6 7.7 8.8 \n"
                               "West: 9.9 11 12.1 \n"
                               "Crossing: 0 0.5 1 1.5 ";

  EXPECT_EQ(output.str(), expectedOutput);
}

TEST(DensityTest, SetCarsTest) {
  density d;
  d.cars.clear();

  d.set_cars();

  EXPECT_EQ(d.cars.size(), c_lights);
  for (int i = 0; i < c_lights; ++i) {
    EXPECT_EQ(d.cars[i], 0);
  }
}

TEST(DensityTest, SetPedestriansTest) {
  density d;
  d.pedestrians.clear();

  d.set_pedestrians();

  EXPECT_EQ(d.pedestrians.size(), p_lights);
  for (int i = 0; i < p_lights; ++i) {
    EXPECT_EQ(d.pedestrians[i + c_lights], 0);
  }
}
