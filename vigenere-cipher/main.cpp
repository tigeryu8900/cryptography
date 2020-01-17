#include <iostream>
#include "vigenere.h"

int main() {
//    std::cout << "Enter the keyword: ";
//    std::string keyword;
//    std::cin >> keyword;
//    std::cin.clear();
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    std::cout << "Enter the text: ";
//    std::string text;
//    std::getline(std::cin, text);
//    std::cout << "Encrypted: " << vigenere::encrypt(keyword, text) << std::endl;
//    std::cout << "Decrypted: " << vigenere::decrypt(keyword, text) << std::endl;

    std::cout << "Enter the keyword: ";
    std::string keyword;
    std::cin >> keyword;
    std::ifstream inf("plaintext.txt");
    std::ofstream outf("decrypted.txt");
    vigenere::encrypt(keyword, inf, outf);
    inf.close();
    outf.close();
    inf.open("ciphertext.txt");
    outf.open("decrypted.txt");
    std::string key = vigenere::crack(inf);
    inf.seekg(0, std::ifstream::beg);
    std::cout << "retrieved key: " << key << std::endl;
    vigenere::decrypt(key, inf, outf);

//    std::cout << "Enter the keyword: ";
//    std::string keyword;
//    std::cin >> keyword;
//    std::ifstream inf("plaintext.txt");
//    std::ofstream outf("decrypted.txt");
//    std::string plaintext((std::istreambuf_iterator<char>(inf)), std::istreambuf_iterator<char>());
//    std::string ciphertext = vigenere::encrypt(keyword, plaintext);
//    std::string key = vigenere::crack(ciphertext);
//    std::cout << "retrieved key: " << key << std::endl;
//    std::string decrypted = vigenere::decrypt(key, ciphertext);
//    outf << decrypted;
    return 0;
}
