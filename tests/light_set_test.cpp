/**
 * @file light_test.cpp
 * @license MIT
 * @date 13-08-2024
 * @author Zofia Kuriata
 */

#include <gtest/gtest.h>
#include <light_set.hpp>
#include <vector>

TEST(LightSetTest, ConstructorInitializesFieldsCorrectly) {
  int id = 1;
  std::vector<int> lights_ids = {1, 2, 3};

  light_set ls(id, lights_ids);

  EXPECT_EQ(ls.id, id);
  EXPECT_EQ(ls.lights_ids, lights_ids);
  EXPECT_EQ(ls.sum, 0);
  EXPECT_EQ(ls.priority, 0);
  EXPECT_EQ(ls.time, 0);
  EXPECT_EQ(ls.order, 0);
}

TEST(LightSetTest, SetPriorityAssignsCorrectValue) {
  light_set ls(1, {1, 2, 3});
  double expected_priority = 0.75;

  ls.set_priority(expected_priority);

  EXPECT_EQ(ls.priority, expected_priority);
}

TEST(LightSetTest, SetTimeCalculatesCorrectValue) {
  light_set ls(1, {1, 2, 3});
  double priority = 0.5;
  int cycle_time = 60;
  int expected_time = static_cast<int>(priority * cycle_time);

  ls.set_priority(priority);
  ls.set_time(cycle_time);

  EXPECT_EQ(ls.time, expected_time);
}

TEST(LightSetTest, SetOrderAssignsCorrectValue) {
  light_set ls(1, {1, 2, 3});
  int expected_order = 2;

  ls.set_order(expected_order);

  EXPECT_EQ(ls.order, expected_order);
}

TEST(LightSetTest, EmptyLightsIds) {
  light_set ls(1, {});

  EXPECT_TRUE(ls.lights_ids.empty());
  EXPECT_EQ(ls.sum, 0);
  EXPECT_EQ(ls.priority, 0);
  EXPECT_EQ(ls.time, 0);
  EXPECT_EQ(ls.order, 0);
}

TEST(LightSetTest, SetMethodsWorkCorrectly) {
  light_set ls(1, {1, 2, 3});

  ls.set_priority(0.3);
  ls.set_time(100);
  ls.set_order(5);

  EXPECT_EQ(ls.priority, 0.3);
  EXPECT_EQ(ls.time, 30); // 0.3 * 100
  EXPECT_EQ(ls.order, 5);
}

TEST(LightSetTest, LightIdsAreCorrectlyStored) {
  std::vector<int> lights_ids = {1, 2, 3};
  light_set ls(1, lights_ids);

  EXPECT_EQ(ls.lights_ids.size(), lights_ids.size());
  for (size_t i = 0; i < lights_ids.size(); ++i) {
    EXPECT_EQ(ls.lights_ids[i], lights_ids[i]);
  }
}
