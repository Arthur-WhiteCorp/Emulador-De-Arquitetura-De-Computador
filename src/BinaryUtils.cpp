#include "BinaryUtils.hpp"
#include <iostream>
#include <bitset>



std::ostream& operator<<(std::ostream& os, const Binary& binary) {
    for (const auto& byte : binary) {
        os << std::bitset<8>(byte);
    }
    return os;
}


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
    
    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
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

template<>
Binary BinaryUtils<Binary>::Subtract(const Binary& binary_a, const Binary& binary_b) {
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 sub_union;
    __uint128_t num_a = 0;
    __uint128_t num_b = 0;

    Binary result(max_size, 0);
    

    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < max_size; ++i) {
        num_a = (num_a << 8) + bigger[i];
    }   


    for (uint8_t i = 0; i < min_size; ++i) {
        num_b = (num_b << 8) + smaller[i];
    }

    if (a_bigger){
        sub_union.num = num_a - num_b;
    } else {
        sub_union.num = num_b - num_a;
    }


    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = sub_union.bytes[max_size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::Multiply(const Binary& binary_a, const Binary& binary_b) {
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 mul_union;
    __uint128_t num_a = 0;
    __uint128_t num_b = 0;

    Binary result(max_size, 0);
    

    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < max_size; ++i) {
        num_a = (num_a << 8) + bigger[i];
    }   


    for (uint8_t i = 0; i < min_size; ++i) {
        num_b = (num_b << 8) + smaller[i];
    }

    mul_union.num = num_a * num_b;

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = mul_union.bytes[max_size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::Divide(const Binary& binary_a, const Binary& binary_b) {
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 div_union;
    __uint128_t num_a = 0;
    __uint128_t num_b = 0;

    Binary result(max_size, 0);
    

    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < max_size; ++i) {
        num_a = (num_a << 8) + bigger[i];
    }      


    for (uint8_t i = 0; i < min_size; ++i) {
        num_b = (num_b << 8) + smaller[i];
    }

    if (a_bigger){
        div_union.num = num_a / num_b;
    } else {
        div_union.num = num_b / num_a;
    }

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = div_union.bytes[max_size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::Remainder(const Binary& binary_a, const Binary& binary_b) {
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 rem_union;
    __uint128_t num_a = 0;
    __uint128_t num_b = 0;

    Binary result(max_size, 0);
    

    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < max_size; ++i) {
        num_a = (num_a << 8) + bigger[i];
    }   


    for (uint8_t i = 0; i < min_size; ++i) {
        num_b = (num_b << 8) + smaller[i];
    }

    if (a_bigger){
        rem_union.num = num_a % num_b;
    } else {
        rem_union.num = num_b % num_a;
    }

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = rem_union.bytes[max_size - i - 1];
    }
    return result;  
}