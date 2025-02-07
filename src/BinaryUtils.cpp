#include "BinaryUtils.hpp"




template<>
Binary BinaryUtils<Binary>::Add(const Binary& binary_a, const Binary& binary_b) {
    uint8_t max_size = std::max(binary_a.size(), binary_b.size()); 
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = (binary_a.size() > binary_b.size()); // true se a for maior
    uint8_t carry = 0; // 0 ou 1
    uint16_t sum_with_carry = 0; 
    uint8_t sum_without_carry = 0;

    __uint128_t result;

    if (max_size > NATIVE_MAX_BINARY_SIZE && max_size <= MAX_BINARY_SIZE) {
        //return Add256(); TODO
    }

    for (size_t i = 0; i < min_size; i++) { 
        result = result + (carry << 7); // adiciona o carry
        sum_with_carry = binary_a[max_size - i - 1] + binary_b[min_size - i - 1]; // soma dois bytes
        sum_without_carry = binary_a[max_size - i - 1] + binary_b[min_size - i - 1];
        carry = sum_with_carry >> 8; // calcula novo carry 
        result = result + ( (result << 8) + sum_without_carry); // adiciona a soma sem o carry        
    }



}