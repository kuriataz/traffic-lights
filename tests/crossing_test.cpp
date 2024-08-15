/**
 * @file crossing_test.cpp
 * @license MIT
 * @date 15-08-2024
 * @author Zofia Kuriata
 */

#include <constants.hpp>
#include <crossing.hpp>
#include <gtest/gtest.h>

TEST(CrossingTest, MakeSetsTest) {
  crossing c;

  EXPECT_EQ(c.sets.size(), 10);

  EXPECT_EQ(c.sets[set0].lights_ids.size(), 5);
  EXPECT_EQ(c.sets[set8].lights_ids.size(), 4);

  EXPECT_EQ(c.sets[set0].lights_ids[0], w_crossing);
  EXPECT_EQ(c.sets[set8].lights_ids[3], s_straight);
}

TEST(CrossingTest, SetLightsTest) {
  crossing c;

  for (int i = 0; i < c_lights; ++i) {
    c.d.cars[i] = i * 1.1;
  }

  for (int i = 0; i < p_lights; ++i) {
    c.d.pedestrians[i + c_lights] = i * 0.5;
  }

  c.set_lights();

  EXPECT_EQ(c.lights.size(), c_lights + p_lights);

  for (int i = 0; i < c_lights; ++i) {
    EXPECT_EQ(c.lights[i].id, i);
    EXPECT_EQ(c.lights[i].load, i * 1.1);
  }

  for (int i = 0; i < p_lights; ++i) {
    EXPECT_EQ(c.lights[i + c_lights].id, i + c_lights);
    EXPECT_EQ(c.lights[i + c_lights].load, i * 0.5);
  }
}

TEST(CrossingTest, CountSumsTest) {
  crossing c;

  for (int i = 0; i < c_lights; ++i) {
    c.d.cars[i] = 0.1;
  }

  for (int i = 0; i < p_lights; ++i) {
    c.d.pedestrians[i + c_lights] = 0.5;
  }

  c.set_lights();

  c.count_sums();

  double expected_all_load = 0.0;
  for (const auto &set : c.sets) {
    expected_all_load += set.sum;
  }

  EXPECT_DOUBLE_EQ(c.all_load, expected_all_load);

  EXPECT_DOUBLE_EQ(c.sets[set0].sum, 0.9);
  EXPECT_DOUBLE_EQ(c.sets[set8].sum, 1.2);
}

TEST(CrossingTest, UpdateSetsTest) {
  crossing c;

  for (int i = 0; i < c_lights; ++i) {
    c.d.cars[i] = 0.1;
  }

  for (int i = 0; i < p_lights; ++i) {
    c.d.pedestrians[i + c_lights] = 0.5;
  }

  c.set_lights();
  c.count_sums();

  c.update_sets();

  // test sorting
  for (int i = 0; i < c.sets.size() - 1; ++i) {
    EXPECT_GE(c.sets[i].sum, c.sets[i + 1].sum);
  }

  for (int i = 0; i < c.sets.size(); ++i) {
    EXPECT_DOUBLE_EQ(c.sets[i].priority, c.sets[i].sum / c.all_load);
    EXPECT_EQ(c.sets[i].time,
              static_cast<int>(c.sets[i].priority * CYCLE_TIME));
    EXPECT_EQ(c.sets[i].order, i);
  }
}
