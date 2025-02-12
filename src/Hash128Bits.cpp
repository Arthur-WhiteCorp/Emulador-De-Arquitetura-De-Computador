#include <Hash128Bits.hpp>

std::size_t Hash128Bits::hash(__uint128_t number){
    // Split the 128-bit value into two 64-bit parts
    __uint64_t high = number >> 64;
    __uint64_t low = number & ((__uint128_t) -1 >> 64);

    // Combine the two parts using a simple hash function
    return std::hash<__uint64_t>{}(high) ^ std::hash<__uint64_t>{}(low);
}