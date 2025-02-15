#include <Hash128Bits.hpp>
#include <iostream>
#include <cstdint>

std::size_t Hash128Bits::hash(__uint128_t number){
    // Split the 128-bit value into two 64-bit parts
    uint64_t high = number >> 64;
    uint64_t low = number & ((__uint128_t) -1 >> 64);
    return  std::hash<__uint64_t>{}(high) ^ std::hash<__uint64_t>{}(low);
}
