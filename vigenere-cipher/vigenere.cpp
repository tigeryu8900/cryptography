//
// Created by tiger on 1/10/2020.
//

#include <vector>
#include "vigenere.h"
#define MIN_KEY_LENGTH 2
#define MAX_KEY_LENGTH 20

namespace vigenere {

    namespace {
        std::vector<int> getKeyArray(std::string keyword) {
            std::vector<int> keyArray;
            for (auto it = keyword.begin(); it < keyword.end(); it++) {
                keyArray.emplace_back(islower(*it)
                      ? ((*it - 'a') % ('z' - 'a' + 1))
                      : ((*it - 'A') % ('Z' - 'A' + 1)));
            }
            return keyArray;
        }

        char encrypt(char plainChar, std::vector<int> keyArray, int shift) {
            return islower(plainChar)
                   ? (((plainChar - 'a' + keyArray[shift % keyArray.size()])
                       % ('z' - 'a' + 1)) + 'a')
                   : (((plainChar - 'A' + keyArray[shift % keyArray.size()])
                       % ('Z' - 'A' + 1)) + 'A');
        }

        char decrypt(char cipherChar, std::vector<int> keyArray, int shift) {
            return islower(cipherChar)
                   ? (((cipherChar - 'a' + 26 - keyArray[shift % keyArray.size()])
                       % ('z' - 'a' + 1)) + 'a')
                   : (((cipherChar - 'A' + 26 - keyArray[shift % keyArray.size()])
                       % ('Z' - 'A' + 1)) + 'A');
        }

        int charToInt(char c) {
            return islower(c) ? c - 'a' : c - 'A';
        }

        char intToChar(int i) {
            return 'a' + i;
        }
    }

    std::string encrypt(std::string keyword, std::string plaintext) {

        // retrieve key array
        std::vector<int> keyArray = getKeyArray(keyword);

        std::string ciphertext;

        // encrypt
        int j = 0;
        for (auto it = plaintext.begin(); it < plaintext.end(); it++) {
            if (isalpha(*it)) {
                ciphertext.push_back(encrypt(*it, keyArray, j));
                j++;
            } else {
                ciphertext.push_back(*it);
            }
        }

        return ciphertext;
    }

    void encrypt(std::string keyword, std::ifstream plaintext, std::ofstream ciphertext) {

        plaintext >> std::noskipws;

        // retrieve key array
        std::vector<int> keyArray = getKeyArray(keyword);

        // encrypt
        int j = 0;
        char plainChar;
        while (plaintext >> plainChar) {
            if (isalpha(plainChar)) {
                ciphertext << encrypt(plainChar, keyArray, j);
                j++;
            } else {
                ciphertext << plainChar;
            }
        }
    }

    std::string decrypt(std::string keyword, std::string ciphertext) {

        // retrieve key array
        std::vector<int> keyArray = getKeyArray(keyword);

        std::string plaintext;

        // encrypt
        int j = 0;
        for (auto it = ciphertext.begin(); it < ciphertext.end(); it++) {
            if (isalpha(*it)) {
                plaintext.push_back(decrypt(*it, keyArray, j));
                j++;
            } else {
                plaintext.push_back(*it);
            }
        }

        return plaintext;
    }

    void decrypt(std::string keyword, std::ifstream ciphertext, std::ofstream plaintext) {

        ciphertext >> std::noskipws;

        // retrieve key array
        std::vector<int> keyArray = getKeyArray(keyword);

        // encrypt
        int j = 0;
        char cipherChar;
        while (ciphertext >> cipherChar) {
            if (isalpha(cipherChar)) {
                plaintext << decrypt(cipherChar, keyArray, j);
                j++;
            } else {
                plaintext << cipherChar;
            }
        }
    }

    std::string crack(std::string ciphertext) {

    }

    std::string crack(std::ifstream ciphertext) {

    }
}  // namespace vigenere
