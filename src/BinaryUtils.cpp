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
template<>
Binary BinaryUtils<Binary>::And(const Binary& binary_a, const Binary& binary_b){
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 and_union;
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

    and_union.num = num_a & num_b;

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = and_union.bytes[max_size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::Or(const Binary& binary_a, const Binary& binary_b){
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 or_union;
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

    or_union.num = num_a | num_b;

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = or_union.bytes[max_size - i - 1];
    }
    return result;
}   

template<>
Binary BinaryUtils<Binary>::Xor(const Binary& binary_a, const Binary& binary_b){
    uint8_t max_size = std::max(binary_a.size(), binary_b.size());
    uint8_t min_size = std::min(binary_a.size(), binary_b.size());
    bool a_bigger = binary_a.size() >= binary_b.size();
    const Binary& bigger = (a_bigger) ? binary_a : binary_b;
    const Binary& smaller = (a_bigger) ? binary_b : binary_a;
    BitUnion_128 xor_union;
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

    xor_union.num = num_a ^ num_b;

    for (uint8_t i = 0; i < max_size; ++i) {
        result[i] = xor_union.bytes[max_size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::Not(const Binary& binary_a){
    uint8_t size = binary_a.size();
    BitUnion_128 not_union;
    __uint128_t num_a = 0;

    Binary result(size, 0);
    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < size; ++i) {
        num_a = (num_a << 8) + binary_a[i];
    }   

    not_union.num = ~num_a;

    for (uint8_t i = 0; i < size; ++i) {
        result[i] = not_union.bytes[size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::ShiftLeft(const Binary& binary_a, const unsigned int& number){
    uint8_t size = binary_a.size();
    BitUnion_128 shift_union;
    __uint128_t num_a = 0;

    Binary result(size, 0);
    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < size; ++i) {
        num_a = (num_a << 8) + binary_a[i];
    }   

    shift_union.num = num_a << number;

    for (uint8_t i = 0; i < size; ++i) {
        result[i] = shift_union.bytes[size - i - 1];
    }
    return result;
}

template<>
Binary BinaryUtils<Binary>::ShiftRight(const Binary& binary_a, const unsigned int& number){
    uint8_t size = binary_a.size();
    BitUnion_128 shift_union;
    __uint128_t num_a = 0;

    Binary result(size, 0);
    // a seção a seguir não é uma função pois acho que chamar uma
    // função teria um custo de tempo alto
    for (uint8_t i = 0; i < size; ++i) {
        num_a = (num_a << 8) + binary_a[i];
    }   

    shift_union.num = num_a >> number;

    for (uint8_t i = 0; i < size; ++i) {
        result[i] = shift_union.bytes[size - i - 1];
    }
    return result;
}