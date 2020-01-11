//
// Created by tiger on 1/11/2020.
//

#include <random>
#include "one_time_pad.h"

namespace one_time_pad {
    namespace {
        std::default_random_engine randomGenerator;
        std::uniform_int_distribution<char> charDistribution(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
    }

    std::string genKey(int length) {
        std::string key;
        for (int i = 0; i < length; ++i)
            key.push_back(charDistribution(randomGenerator));
        return key;
    }

    std::string enc(const std::string &key, const std::string &plaintext) {
        std::string ciphertext;
        for (auto pit = plaintext.begin(), kit = key.begin(); pit < plaintext.end(); ++pit, ++kit) {
            ciphertext.push_back((*pit) ^ (*kit));
        }
        return ciphertext;
    }

    std::string dec(const std::string &key, const std::string &ciphertext) {
        std::string plaintext;
        for (auto cit = ciphertext.begin(), kit = key.begin(); cit < ciphertext.end(); ++cit, ++kit) {
            plaintext.push_back((*cit) ^ (*kit));
        }
        return plaintext;
    }

}  // namespace one_time_pad
