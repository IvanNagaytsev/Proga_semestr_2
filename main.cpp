#include <iostream>

int CountSimilarBytes(long long int byte);

char WhatByte(long long int byte, int i);

void SwapBytes(unsigned short* byte);

unsigned char GetMaxByte(const unsigned int* ar, size_t size);

int main()
{
    long long int byte1 = 0x0000006789ABCDEF;
    printf("Zadacha 1: %d\n", CountSimilarBytes(byte1));

    unsigned short byte2 = 0xFF01;
    unsigned short byte2_first = byte2;
    SwapBytes(&byte2);
    printf("Zadacha 2: %x -> %x\n", byte2_first, byte2);

    size_t size = 3;
    const unsigned int *ar =  new unsigned int[size]{0x010201ff, 0x07890909, 0x8899AABB};
    printf("Zadacha 3: %x", GetMaxByte(ar, size));
    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Задача 1:

char WhatByte(long long int byte, int i)
{
    byte = byte << (60 - i*4);
    byte = byte >> (60 - i*4);
    byte = byte >> i*4;
    byte &= 0b1111;
    char byte_char = byte;
    return byte_char;
}

int CountSimilarBytes(long long int byte)
{    
    char nums[16];
    int max_reps = 0;
    int bf_max_reps = 0;

    for(int i = 16; i>=0; i--)
        nums[i] = WhatByte(byte, i);

    for(int i = 0; i<16; i++)
    {
        bf_max_reps = 0;
        for(int k = 0; k<16; k += 2)
            if(nums[i] == nums[k] && nums[i+1] == nums[k+1] && ((nums[i] == 0)^(nums[i+1] == 0)))
                bf_max_reps++;
        if(bf_max_reps > max_reps)
            max_reps = bf_max_reps;
    }
    return max_reps;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Задача 2:

void SwapBytes(unsigned short* byte)
{
    unsigned short a = *byte;
    a = a << 8;
    *byte = *byte >> 8;
    *byte = *byte | a;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Задача 3:

unsigned char GetMaxByte(const unsigned int* ar, size_t size)
{
    unsigned char max_byte = 0x00;
    for(int i = 0; i<size; i++)
    {
        for(int k = 0; k<8; k = k+2)
        {

            if((ar[i] >> 24 - k*4)&0b11111111 > max_byte)
                max_byte = (ar[i] >> 24 - k*4)&0b11111111;
        }
    }
    return max_byte;
}
