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
    this->encoding = encode(bit_array);
}

template <class T>
static const bit_array &HammingCode<T>::encode(const bit_array& message)
{
    bit_array encoded_message(bit_array.length + log2(bit_array.length))
    return message;
}

template <class T>
const bit_array &HammingCode<T>::get_encoding() { return encoding; }

bit_array byte_to_bit_array(byte *byte_array, int length)
{
    bit_array converted_array = bit_array();
    for (int i = 0; i < length; i++)
    {
        cout << i << converted_array << endl;
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
    HammingCode<short> coder(5);
    cout << coder.get_encoding() << endl;
}