/**
 * @file constants.hpp
 * @license MIT
 * @date 09-08-2024
 * @author Zofia Kuriata
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

constexpr int directions = 4;               // north, east, south, west
constexpr int ways = 3;                     // straight, left, right
constexpr int p_lights = 4;                 // lights for pedestrians
constexpr int c_lights = directions * ways; // lights for cars (12)
constexpr int CYCLE_TIME = 90;              // how many seconds lasts the cycle

// ids of each light
// it goes: straight, left, right for each direction (order: n, e, s, w)

constexpr int n_straight = 0;
constexpr int n_left = 1;
constexpr int n_right = 2;
constexpr int e_straight = 3;
constexpr int e_left = 4;
constexpr int e_right = 5;
constexpr int s_straight = 6;
constexpr int s_left = 7;
constexpr int s_right = 8;
constexpr int w_straight = 9;
constexpr int w_left = 10;
constexpr int w_right = 11;
constexpr int n_crossing = 12;
constexpr int e_crossing = 13;
constexpr int s_crossing = 14;
constexpr int w_crossing = 15;

// ids of the sets

constexpr int set0 = 0;
constexpr int set1 = 1;
constexpr int set2 = 2;
constexpr int set3 = 3;
constexpr int set4 = 4;
constexpr int set5 = 5;
constexpr int set6 = 6;
constexpr int set7 = 7;
constexpr int set8 = 8;
constexpr int set9 = 9;

#endif // CONSTANTS_HPP
