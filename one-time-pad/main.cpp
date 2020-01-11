#include <iostream>
#include <fstream>
#include <string>
#include "one_time_pad.h"

int main() {
    std::string key;
    std::string plainText;
    std::string cipherText;
    std::string decryptedText;

    plainText = "Hello world!";
    key = one_time_pad::genKey(plainText.size());
    cipherText = one_time_pad::enc(key, plainText);
    decryptedText = one_time_pad::dec(key, cipherText);

    std::cout << "One time pad algorithm demonstration: key generation, message encryption, and message decryption." << std::endl;
    std::cout << "plainText: " << plainText << std::endl;
    std::cout << "decryptedText: " << decryptedText << std::endl;

    std::cout << "Second test, read plain text from a file : plainText.txt" << std::endl;
    std::ifstream is("plainText.txt", std::ifstream::binary);
    is.seekg(0, is.end);
    int len = is.tellg();
    is.seekg(0, is.beg);
    plainText.resize(len);
    is.read(&plainText[0], len);

    key = one_time_pad::genKey(plainText.size());
    cipherText = one_time_pad::enc(key, plainText);
    decryptedText = one_time_pad::dec(key, cipherText);

    std::cout << "Write key to file : key.txt" << std::endl;
    std::ofstream oKey("key.txt", std::ifstream::binary);
    oKey.write(key.data(), key.size());
    std::cout << "Write cipherText to file : cipherText.txt" << std::endl;
    std::ofstream oCipher("cipherText.txt", std::ifstream::binary);
    oCipher.write(cipherText.data(), cipherText.size());
    std::cout << "Write decryptedText to file : decryptedText.txt" << std::endl;
    std::ofstream oDecrypted("decryptedText.txt", std::ifstream::binary);
    oDecrypted.write(decryptedText.data(), decryptedText.size());
}
