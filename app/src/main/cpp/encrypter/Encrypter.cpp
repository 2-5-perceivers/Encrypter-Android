#include "Encrypter.h"

using namespace std;

//constructor
Encrypter::Encrypter(string encryptionKey){
    key = encryptionKey;
    if (key.size() < 5){
        key += generateRandomKey(5-key.size());
    }
}

string Encrypter::encrypt(string s){ //returns the encrypted text
    string encryptedText = s;
    textTransformer::merge(encryptedText, key);
    encryptedText = toCaesar(encryptedText, textTransformer::asciiAccumulate(key));
    textTransformer::reverse(encryptedText);
    if ((int)key[0]%2 == 0){
        encryptedText = toHex(encryptedText);
        if ((int)key[1]%2 == 0){
            encryptedText = toDeca(encryptedText);
            textTransformer::reverse(encryptedText);
            encryptedText = toBinary(encryptedText);
        } else {
            encryptedText = toBinary(encryptedText);
            textTransformer::reverse(encryptedText);
            encryptedText = toDeca(encryptedText);
        }
    } else {
        encryptedText = toBinary(encryptedText);
        if ((int)key[1]%2 == 0){
            encryptedText = toDeca(encryptedText);
            textTransformer::reverse(encryptedText);
            encryptedText = toHex(encryptedText);
        } else {
            encryptedText = toHex(encryptedText);
            textTransformer::reverse(encryptedText);
            encryptedText = toDeca(encryptedText);
        }
    }
    return encryptedText;
}

string Encrypter::decrypt(string s){ //returns the decrypted text //TODO: still in progress
    string decryptedText = s;
    if ((int)key[0]%2 == 0){
        if ((int)key[1]%2 == 0){
            decryptedText = fromBinary(decryptedText);
            textTransformer::reverse(decryptedText);
            decryptedText = fromDeca(decryptedText);
        } else {
            decryptedText = fromDeca(decryptedText);
            textTransformer::reverse(decryptedText);
            decryptedText = fromBinary(decryptedText);
        }
        decryptedText = fromHex(decryptedText);
    } else {
        if ((int)key[1]%2 == 0){
            decryptedText = fromHex(decryptedText);
            textTransformer::reverse(decryptedText);
            decryptedText = fromDeca(decryptedText);
        } else {
            decryptedText = fromDeca(decryptedText);
            textTransformer::reverse(decryptedText);
            decryptedText = fromHex(decryptedText);
        }
        decryptedText = fromBinary(decryptedText);
    }
    textTransformer::reverse(decryptedText);
    decryptedText = toCaesar(decryptedText, 26-(textTransformer::asciiAccumulate(key)%26));
    textTransformer::unmerge(decryptedText);
    return decryptedText;
}

string Encrypter::generateRandomKey(int keyLength){
    int random;
    string rndKey;
    for (int i = 0; i < keyLength; i++){
        random = rand() % 95 + 32;
        rndKey.push_back((char)random);
    }
    return rndKey;
}