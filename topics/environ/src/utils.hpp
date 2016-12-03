//
// Created by Jonathan Gerber on 12/3/16.
//
#pragma once

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <sstream>

using Stringpair = std::pair<std::string, std::string>;
using Stringvec = std::vector<std::string>;

/*!
 * @brief function which splits up a string into a vector of strings, based on a supplied delimiting character.
 *
 * @param s The input string.
 * @param delim  the delimiting character
 * @param elems a vector of strings, returned by the function.
 */
void split(const std::string &s, char delim, std::vector<std::string> & elems);

/*!
 * @brief an alternative form of split which returns a vector of strings.
 *
 * @param s The constant input string
 * @param delim The character delimiter to split on.
 * @return a vector of strings.
 */
std::vector<std::string> split(const std::string &s, char delim);

/*!
 * @brief separate a string of the form KEY=VALUE into a pair of <KEY,VALUE> stringsl
 *
 * @param var an input string of the form KEY=VALUE ( eg PATH=/usr/bin/ )
 * @return pair<string, string>
 */
Stringpair toPair(const std::string& var);
