//
// Created by tiger on 1/10/2020.
//

#ifndef VIGENERE_CIPHER_VIGENERE_H
#define VIGENERE_CIPHER_VIGENERE_H

#include <string>
#include <fstream>

namespace vigenere {
    std::string encrypt(std::string &keyword, std::string &plaintext);
    void encrypt(std::string &keyword, std::istream &plaintext, std::ostream &ciphertext);
    std::string decrypt(std::string &keyword, std::string &ciphertext);
    void decrypt(std::string &keyword, std::istream &ciphertext, std::ostream &plaintext);
    std::string crack(std::string &ciphertext);
    std::string crack(std::istream &ciphertext);
}  // namespace vigenere

#endif //VIGENERE_CIPHER_VIGENERE_H
