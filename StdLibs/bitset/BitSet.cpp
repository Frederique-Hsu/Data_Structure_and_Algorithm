#include "BitSet.h"

#include <bitset>
#include <string>
#include <iostream>

using namespace std;

void execute_test_cases(void)
{
    // initialize_bitset_object();
    access_bits_on_bitset_object();
}

void initialize_bitset_object(void)
{
    bitset<32> bitvec32;    /* 32 bits, all zero */
    bitset<32> bits(0xFFFF);    /* bits 0...15 are set to 1; 16...31 are 0 */

    string binaryStr("1101101101110101");
    bitset<16> bitstr(binaryStr, 7, 9);     /* 8 bits, starting from str[7](L->R), including str[7] */

    for (int index = bitstr.size()-1; index >= 0; --index)
    {
        cout << "bitstr[" << index << "] = " << bitstr[index] << endl;
    }

    cout << "The bitstr has existed any one bit set? " << (bitstr.any() ? "True" : "False") << endl;
    cout << "The bitstr all bits are reset? " << (bitstr.none() ? "True" : "False") << endl;
    cout << "How many bits are set 1? " << bitstr.count() << endl;
}

void access_bits_on_bitset_object(void)
{
    bitset<32> bits32(0x5F8DB7AC);
    cout << "bits32 = ";
    for (int index = bits32.size() - 1; index >= 0; --index)
    {
        cout << bits32[index];
        if (index % 4 == 0)
        {
            if (index == 0)
            {
                ;
            }
            else
            {
                cout << ",";
            }
        }
        cout << " ";
    }
    cout << endl;

    bits32.operator<<=(4);
    cout << "Now the bits32 becomes to " << bits32 << endl;

    bits32.flip();    /* reverses value of all bits */
    unsigned long ulong = bits32.to_ulong();
    cout << "After reverse bits, now the bits32 = " << ulong << endl;
    cout << "And we convert it to string: " << bits32.to_string() << endl;
}