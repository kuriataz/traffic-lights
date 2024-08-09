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
constexpr int CYCLE_TIME = 90;

#endif // CONSTANTS_HPP
