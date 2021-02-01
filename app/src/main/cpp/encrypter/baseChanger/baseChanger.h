#ifndef BASE_CHANGER_H
#define BASE_CHANGER_H

#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <bitset>
#include <stdexcept>

//converters to
std::string toDeca(const std::string& s);
std::string toHex(const std::string& s);
std::string toBinary(const std::string& s);
std::string toCaesar(const std::string& s, short key);

//converters from
std::string fromHex(std::string s);
std::string fromBinary(const std::string& s);
std::string fromDeca(std::string s);

#endif