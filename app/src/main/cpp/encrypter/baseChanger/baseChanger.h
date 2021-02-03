#ifndef BASE_CHANGER_H
#define BASE_CHANGER_H

#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <bitset>
#include <stdexcept>

//converters to
__attribute__((visibility("default"))) std::string toHex(const std::string& s);

//converters from
__attribute__((visibility("default"))) std::string fromHex(std::string s);

#endif