//
// Created by tiger on 1/10/2020.
//

#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
//#include <iostream>
#include "vigenere.h"
#define MIN_KEY_LENGTH 2
#define MAX_KEY_LENGTH 20
#define FREQUENCY_THRESHOLD 0.1

namespace vigenere {

    namespace {

        int charToInt(char c) {
            return islower(c) ? c - 'a' : c - 'A';
        }

        char intToChar(int i) {
            return 'a' + i;
        }

        std::vector<int> getKeyArray(std::string &keyword) {
            std::vector<int> keyArray;
            for (char c : keyword) {
                keyArray.emplace_back(charToInt(c));
            }
            return keyArray;
        }

        char encrypt(char plainChar, std::vector<int> &keyArray, int shift) {
            return islower(plainChar)
                   ? (((plainChar - 'a' + keyArray[shift % keyArray.size()])
                       % ('z' - 'a' + 1)) + 'a')
                   : (((plainChar - 'A' + keyArray[shift % keyArray.size()])
                       % ('Z' - 'A' + 1)) + 'A');
        }

        char decrypt(char cipherChar, std::vector<int> &keyArray, int shift) {
            return islower(cipherChar)
                   ? (((cipherChar - 'a' + 26 - keyArray[shift % keyArray.size()])
                       % ('z' - 'a' + 1)) + 'a')
                   : (((cipherChar - 'A' + 26 - keyArray[shift % keyArray.size()])
                       % ('Z' - 'A' + 1)) + 'A');
        }
    }

    std::string encrypt(std::string &keyword, std::string &plaintext) {

        // retrieve key array
        std::vector<int> keyArray = getKeyArray(keyword);

        std::string ciphertext;

        // encrypt
        int j = 0;
        for (char c : plaintext) {
            if (isalpha(c)) {
                ciphertext.push_back(encrypt(c, keyArray, j));
                j++;
            } else {
                ciphertext.push_back(c);
            }
        }

        return ciphertext;
    }

    void encrypt(std::string &keyword, std::istream &plaintext, std::ostream &ciphertext) {

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

    std::string decrypt(std::string &keyword, std::string &ciphertext) {

        // retrieve key array
        std::vector<int> keyArray = getKeyArray(keyword);

        std::string plaintext;

        // encrypt
        int j = 0;
        for (char c : ciphertext) {
            if (isalpha(c)) {
                plaintext.push_back(decrypt(c, keyArray, j));
                j++;
            } else {
                plaintext.push_back(c);
            }
        }

        return plaintext;
    }

    void decrypt(std::string &keyword, std::istream &ciphertext, std::ostream &plaintext) {

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


    std::string crack(std::string &ciphertext) {
        std::array<int, 26> charCount{};
        std::string key;
        bool keyLengthFound = false;
        int keyLength = MIN_KEY_LENGTH;
//        int keyLength = 10;
        for (; keyLength <= MAX_KEY_LENGTH; ++keyLength) {
            charCount = {};
            for (auto it = ciphertext.begin(); it < ciphertext.end();) {
//                while (!isalpha(*it) && it < ciphertext.end())
//                    it++;
//                if (it >= ciphertext.end())
//                    break;
//                std::cout << *it;
                charCount[charToInt(*it)]++;
                for (int i = 0; i < keyLength;) {
                    it++;
                    if (it >= ciphertext.end())
                        break;
                    if (isalpha(*it))
                        i++;
                }
            }
            int sum = std::accumulate(charCount.begin(), charCount.end(), 0);
            auto maxElement = std::max_element(charCount.begin(), charCount.end());
//            auto minElement = std::min_element(charCount.begin(), charCount.end());
//            if (keyLength == 10) {
//                std::cout << static_cast<double>(*maxElement) / sum << std::endl;
//            }
            if (*maxElement >= FREQUENCY_THRESHOLD * sum) {
//                std::cout << keyLength << std::endl;
                key.push_back(intToChar((maxElement - charCount.begin() + 22) % 26));
                keyLengthFound = true;
                break;
            }
        }
        if (!keyLengthFound)
            return key;
//        std::cout << keyLength << std::endl;
//        keyLength = 10;
        for (int i = 2; i <= keyLength; ++i) {
//            std::cout << i << std::endl;
            charCount = {};
            for (auto it = ciphertext.begin() + i/*, limit = ciphertext.begin() + ((ciphertext.size() - (ciphertext.size() % keyLength)) + i) % ciphertext.size()*/; it < ciphertext.end();) {
//                while (!isalpha(*it) && it < ciphertext.end())
//                    it++;
//                if (it >= ciphertext.end())
//                    break;
                charCount[charToInt(*it)]++;
                for (int j = 0; j < keyLength;) {
                    it++;
                    if (it >= ciphertext.end())
                        break;
                    if (isalpha(*it))
                        j++;
                }
            }
//            std::cout << 2 << std::endl;
            auto maxElement = std::max_element(charCount.begin(), charCount.end());
//            std::cout << 3 << std::endl;
            key.push_back(intToChar((maxElement - charCount.begin() + 22) % 26));
//            std::cout << 4 << std::endl;
//std::cout << intToChar((maxElement - charCount.begin() + 22) % 26) << std::endl;
        }
        return key;
    }


//    std::string crack(std::string &ciphertext) {
//        std::array<std::vector<int>, 26 * 26 * 26> sequenceRepeatCounts;
//        for (int i = 0, limit = ciphertext.size() - 3; i < limit; ++i) {
//            sequenceRepeatCounts[26 * 26 * charToInt(ciphertext[i]) + 26 * charToInt(ciphertext[i + 1])
//                    + charToInt(ciphertext[i + 2])].emplace_back(i);
//        }
//        std::array<std::pair<int, int>, MAX_KEY_LENGTH> possibleKeyLengths{};
//        for (int i = 0; i < possibleKeyLengths.size(); ++i) {
//            possibleKeyLengths[i].second = i;
//        }
//        for (std::vector<int> sequenceRepeatCount : sequenceRepeatCounts) {
//            for (int i = 0, limit = sequenceRepeatCount.size() - 1; i < limit; ++i) {
//                for (int j = i + 1; j <= limit; ++j) {
//                    int diff = sequenceRepeatCount[j] - sequenceRepeatCount[i];
//                    for (int k = 0, limit = diff / 2; k <= limit; ++k)
//                        if (diff % k == 0)
//                            possibleKeyLengths[k].first++;
//                }
//            }
//        }
//        std::sort(possibleKeyLengths.begin(), possibleKeyLengths.end());
//    }

    std::string crack(std::istream &ciphertext) {
        ciphertext >> std::noskipws;
        std::array<int, 26> charCount{};
        std::string key;
        ciphertext.seekg(0, std::istream::end);
        int ciphertext_size = ciphertext.tellg();
//        ciphertext.seekg(0, std::istream::beg);
        bool keyLengthFound = false;
        int keyLength = MIN_KEY_LENGTH;
        char buf;
        auto posBookmark = ciphertext.tellg();
        for (; keyLength <= MAX_KEY_LENGTH; ++keyLength) {
            charCount = {};
            ciphertext.seekg(0, std::istream::beg);
            /*
            while (ciphertext.tellg() < ciphertext_size) {
                ciphertext >> buf;
                ciphertext.seekg(-1, std::istream::cur);
//                while (!isalpha(buf) && ciphertext.tellg() < ciphertext_size)
//                    ciphertext >> buf;
//                if (ciphertext.tellg() >= ciphertext_size)
//                    break;
                charCount[charToInt(buf)]++;
                for (int i = 0; i < keyLength;) {
                    ciphertext >> buf;
                    if (ciphertext.tellg() >= ciphertext_size)
                        break;
                    ciphertext >> buf;
                    ciphertext.seekg(-1, std::istream::cur);
                    if (isalpha(buf))
                        i++;
                }
//                ciphertext.seekg(-1, std::istream::cur);
//                for (int i = 0; i < keyLength;) {
//                    ciphertext >> buf;
//                    if (ciphertext.tellg() >= ciphertext_size)
//                        break;
//                    if (isalpha(buf))
//                        i++;
//                }
            }
             */
            while (ciphertext.tellg() < ciphertext_size) {
//                std::cout << buf;
                charCount[charToInt(ciphertext.peek())]++;
                for (int i = 0; i < keyLength;) {
                    ciphertext >> buf;
                    if (ciphertext.tellg() >= ciphertext_size)
                        break;
                    if (isalpha(ciphertext.peek()))
                        i++;
                }
            }
//            for (auto it = ciphertext.begin(); it < ciphertext.end();) {
//                charCount[charToInt(*it)]++;
//                for (int i = 0; i < keyLength;) {
//                    it++;
//                    if (it >= ciphertext.end())
//                        break;
//                    if (isalpha(*it))
//                        i++;
//                }
//            }
            int sum = std::accumulate(charCount.begin(), charCount.end(), 0);
            auto maxElement = std::max_element(charCount.begin(), charCount.end());
//            std::cout << keyLength << ' ' << (static_cast<double>(*maxElement) / sum) << std::endl;
            if (*maxElement >= FREQUENCY_THRESHOLD * sum) {
                key.push_back(intToChar((maxElement - charCount.begin() + 22) % 26));
                keyLengthFound = true;
                break;
            }
        }
        if (!keyLengthFound)
            return key;
        for (int i = 2; i <= keyLength; ++i) {
            charCount = {};
            ciphertext.seekg(i, std::istream::beg);
            while (ciphertext.tellg() < ciphertext_size) {
//                std::cout << buf;
                charCount[charToInt(ciphertext.peek())]++;
                for (int i = 0; i < keyLength;) {
                    ciphertext >> buf;
                    if (ciphertext.tellg() >= ciphertext_size)
                        break;
                    if (isalpha(ciphertext.peek()))
                        i++;
                }
            }
            auto maxElement = std::max_element(charCount.begin(), charCount.end());
            key.push_back(intToChar((maxElement - charCount.begin() + 22) % 26));
        }
        return key;
    }
}  // namespace vigenere
