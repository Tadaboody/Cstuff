#pragma once
#include <vector>
#include <iostream>
using bit_array = std::vector<bool>;
using byte = unsigned char;
using index = unsigned int;

template<class T>
class HammingCode
{
    T payload;
    bit_array encoding;
    const bit_array encode(const bit_array &message);

  public:
    HammingCode(const T& Payload);
    HammingCode(const bit_array& encoding);
    const bit_array& get_encoding();
    const T& get_decoding();
};   

std::ostream& operator<<(std::ostream& out,bit_array arr);
bit_array byte_to_bit_array(byte* byte_array, int length);