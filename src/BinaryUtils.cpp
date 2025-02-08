#include "BinaryUtils.hpp"
#include <iostream>
#include <bitset>

template<>
Binary BinaryUtils<Binary>::Add(const Binary& binary_a, const Binary& binary_b) {
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 sum_union;
    __uint128_t num_a = 0;
    __uint128_t num_b = 0;

    Binary result(max_size, 0);
    
    for (uint8_t i = 0; i < max_size; ++i) {
        num_a = (num_a << 8) + bigger[i];
    }


    for (uint8_t i = 0; i < min_size; ++i) {
        num_b = (num_b << 8) + smaller[i];
    }

    sum_union.num = num_a + num_b;

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = sum_union.bytes[max_size - i - 1];
    }
    return result;

}