#ifndef HAMMING1_H_INCLUDED
#define HAMMING1_H_INCLUDED
#include <vector>

namespace hamming1
{
    std::string EncodeString(std::string byte);
    std::vector<std::string> Encode(const std::vector<std::string> bytes);
    std::vector<std::string> Encode2(const std::vector<std::string> bytes);
    std::string DecodeString(std::string byte);
    std::vector<std::string> Decode(const std::vector<std::string> bytes);
    std::vector<std::string> ChangeBit(std::vector<std::string> encoded_message,int element_index,int bit_index);

}

#endif // HAMMING1_H_INCLUDED
