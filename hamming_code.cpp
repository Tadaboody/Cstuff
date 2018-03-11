#include "hamming_code.hpp"
#include <iostream>
#include <math.h>

using namespace std;

template <class T>
HammingCode<T>::HammingCode(const T &payload) : payload(payload)
{
    int byte_length = sizeof(payload);
    byte *byte_array = reinterpret_cast<byte *>(&(this->payload));
    bit_array converted_array = byte_to_bit_array(byte_array, byte_length);
    this->encoding = encode(converted_array);
}

template <class T>
const bit_array HammingCode<T>::encode(const bit_array& message)
{
    int powers = (int)log2(message.size());
    bit_array encoded_message(message.size() + powers);
    bit_array parity_bits(powers);
    for (index i = 0; i < message.size(); i++)
    {
        for (index j = 0; j < parity_bits.size(); j++)
        {
            if ((i & (1 << j)) == 1)
            {
                parity_bits[j] = parity_bits[j] ^ message[i];
            }
        }
    }
    // for (int i = 0, next_pow = 0; i < encoded_message.size(); i++)
    // {
    //     if (i == ((1 << next_pow) - 1))
    //     {
    //     }
    // }

    return parity_bits;
}

template <class T>
const bit_array &HammingCode<T>::get_encoding() { return encoding; }

bit_array byte_to_bit_array(byte *byte_array, int length)
{
    bit_array converted_array = bit_array();
    for (int i = 0; i < length; i++)
    {
        byte current_byte = byte_array[i];
        for (unsigned int j = 0; j<sizeof(byte)*8; j++)
        {
            converted_array.push_back((current_byte & 1) == 1);
            current_byte >>= 1;
        }
    }
    return converted_array;
}

ostream &operator<<(ostream &out, bit_array arr)
{
    out << '[';
    for(auto i: arr)
    {
        out << i << ',';
    }
    out << ']';
    return out;
}

int main()
{
    HammingCode<short> coder(3);
    cout << coder.get_encoding() << endl;
}