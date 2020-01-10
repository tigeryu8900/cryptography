//
// Created by tiger on 1/10/2020.
//

#ifndef VIGENERE_CIPHER_VIGENERE_H
#define VIGENERE_CIPHER_VIGENERE_H

#include <string>
#include <fstream>

namespace vigenere {
    std::string encrypt(std::string keyword, std::string plaintext);
    void encrypt(std::string keyword, std::ifstream plaintext, std::ofstream ciphertext);
    std::string decrypt(std::string keyword, std::string ciphertext);
    void decrypt(std::string keyword, std::ifstream ciphertext, std::ofstream plaintext);
    std::string crack(std::string ciphertext);
    std::string crack(std::ifstream ciphertext);
}  // namespace vigenere

#endif //VIGENERE_CIPHER_VIGENERE_H
