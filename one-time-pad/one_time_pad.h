//
// Created by tiger on 1/11/2020.
//

#ifndef ONE_TIME_PAD_ONE_TIME_PAD_H
#define ONE_TIME_PAD_ONE_TIME_PAD_H

namespace one_time_pad {
    std::string genKey(int length);
    std::string enc(const std::string &key, const std::string &plaintext);
    std::string dec(const std::string &key, const std::string &ciphertext);
}  // namespace one_time_pad

#endif //ONE_TIME_PAD_ONE_TIME_PAD_H
