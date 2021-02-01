#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <filesystem>
#include "baseChanger/baseChanger.h"
#include "textTransform/text_transform.h"

class Encrypter {
    public:
        Encrypter(std::string encryptionKey);

        __attribute__((visibility("default"))) std::string encrypt(std::string s); //returns the encrypted text
        __attribute__((visibility("default"))) std::string decrypt(std::string s); //returns the decrypted text

        //setters and getters
        __attribute__((visibility("default"))) std::string getkey() { return key; }
        __attribute__((visibility("default"))) void setkey(std::string val) { key = val; }

        //Useful functions
        //static function
        __attribute__((visibility("default"))) static std::string generateRandomKey(int keyLength);

    protected:
        std::string key;
};

#endif // ENCRYPTER_H
