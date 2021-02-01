#include "baseChanger.h"

using namespace std;

//Declarations for dependent function
int hex_value(unsigned char hex_digit);
//////////////////////////////////////

string toDeca(const string& s){
    string deca;
    stringstream ss;
    for (char i : s)
        ss << (int)i;
    ss >> deca;
    return deca;
}

string toHex(const string& s){
    static const char hex_digits[] = "0123456789ABCDEF";
    string output;
    output.reserve(s.length() * 2);
    for (unsigned char c : s){
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

string toBinary(const string& s){
    string binary;
    for (int i = 0; i < s.size(); i++){
        stringstream ss;
        ss << bitset<8>(s.c_str()[i]);
        string news, s2;
        ss >> news;
        s2 = binary + news;
        binary = s2;
    }
    return binary;
}

string toCaesar(const string& s, short key){
    string result;
    for (char i : s){
        if (i == *" ")
            result += " ";
        else if (isupper(i))
            result += char(int(i+key-65)%26 + 65);
        else if (islower(i))
            result += char(int(i+key-97)%26 + 97);
        else
            result += i;
    } 
    return result;
}

string fromHex(string s){
    const auto len = s.length();
    if (len & 1) throw std::invalid_argument("odd length");
    string output;
    output.reserve(len / 2);
    for (auto it = s.begin(); it != s.end(); ){
        int hi = hex_value(*it++);
        int lo = hex_value(*it++);
        output.push_back(hi << 4 | lo);
    }
    return output;
}

string fromBinary(const string& s){
    string text;
    stringstream stream(s);
    while (stream.good()) {
        bitset<8> bits;
        stream >> bits;
        text += char(bits.to_ulong());
    }
    return text.substr(0, text.size()-1);
}

string fromDeca(string s){
    string output;
    for (int i = 0; i < s.length();){
        if (s[i] == *"1"){
            string m(s.substr(i, 3));
            stringstream number(m);
            int n = 0;
            number >> n;
            output += (char)n;
            i += 3;
        } else {
            string m(s.substr(i, 2));
            stringstream number(m);
            int n = 0;
            number >> n;
            output += (char)n;
            i += 2;
        }
    }
    return output;
}

/************ Dependent functions *************/


int hex_value(unsigned char hex_digit){
    static const signed char hex_values[256] = {
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
             0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
            -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int value = hex_values[hex_digit];
    if (value == -1) throw std::invalid_argument("invalid hex digit");
    return value;
}
