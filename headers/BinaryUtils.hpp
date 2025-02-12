#ifndef BINARY_UTILS_HPP
#define BINARY_UTILS_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <climits>
#include <bitset>
#include <functional>
#include <Hash128Bits.hpp>

constexpr size_t MAX_BINARY_SIZE = 128; // tamanho maximo de um binary
constexpr size_t NATIVE_MAX_BINARY_SIZE = 128; // tamanho maximo de um binary suportado pelço C++

constexpr bool IsPowerOfTwo(size_t value) {
    return (value > 0) && ((value & (value - 1)) == 0);
}

static_assert(MAX_BINARY_SIZE > 0, "MAX_BINARY_SIZE must be greater than 0");
static_assert(NATIVE_MAX_BINARY_SIZE > 0, "NATIVE_MAX_BINARY_SIZE must be greater than 0");
static_assert(MAX_BINARY_SIZE >= NATIVE_MAX_BINARY_SIZE, "MAX_BINARY_SIZE must be at least as large as NATIVE_MAX_BINARY_SIZE");
static_assert(IsPowerOfTwo(MAX_BINARY_SIZE), "MAX_BINARY_SIZE must be a power of two");
static_assert(IsPowerOfTwo(NATIVE_MAX_BINARY_SIZE), "NATIVE_MAX_BINARY_SIZE must be a power of two");

using Byte = uint8_t;
static_assert(sizeof(Byte) * CHAR_BIT == 8, "Byte must be exactly 8 bits");

using Binary = std::vector<Byte>; // tamanho minimo 8 bits (1 byte)
static_assert(std::is_same_v<Binary, std::vector<Byte>>, "Binary must be a std::vector<Byte>");

using BitUnion_128 = union {
    __uint128_t num;
    uint8_t bytes[16];
    };

struct BinaryHash {
    std::size_t operator()(const Binary& binary) const {
        uint8_t size = binary.size();
         __uint128_t num;

        for (uint8_t i = 0; i < size; ++i) {
            num = (num << 8) + binary[i];
        } 
            
        return Hash128Bits::hash(num);    
    }
};

struct BinaryEqual {
    bool operator()(const Binary& lhs, const Binary& rhs) const {
        BitUnion_128 hash_union;
        uint8_t size_lhs = lhs.size();
        uint8_t size_rhs = rhs.size();
        __uint128_t num_lhs;
        __uint128_t num_rhs;
        for (uint8_t i = 0; i < size_lhs; ++i) {
            num_lhs = (num_lhs << 8) + lhs[i];
        }
        for (uint8_t i = 0; i < size_rhs; ++i) {
            num_rhs = (num_rhs << 8) + rhs[i];
        }
        return num_lhs == num_rhs;
    }
};


std::ostream& operator<<(std::ostream& os, const Binary& binary);


template<typename T>
class BinaryUtils {      
    static_assert(std::is_unsigned<T>::value || (std::is_same<T, Binary>::value),
    "T must be an unsigned type or a vector of Byte"); // T precisa ser um tipo unsigned ou um vector de unsigned

    static_assert(std::is_same<T, Binary>::value ? sizeof(T) <= 128 : true, 
    "Binary size must be <= 128"); // checa o tamanho do Binary

public:
    static T Add(const T& binary_a, const T& binary_b); // soma
    static T Subtract(const T& binary_a, const T& binary_b); // subtração
    static T Multiply(const T& binary_a, const T& binary_b); // multiplicação
    static T Divide(const T& binary_a, const T& binary_b); // divisao
    static T Remainder(const T& binary_a, const T& binary_b); // resto da divisao
    static T And(const T& binary_a, const T& binary_b); // and bit a bit
    static T Or(const T& binary_a, const T& binary_b); // or bit a bit
    static T Xor(const T& binary_a, const T& binary_b); // xor bit a bit
    static T Not(const T& binary_a); // not bit a bit
    static T ShiftLeft(const T& binary_a, const unsigned int& number); // shiftLeft
    static T ShiftRight(const T& binary_a, const unsigned int& number); // shiftRight
    //static Binary ToUnsigned(const T& binary_a); // transforma Binary em __Uint128_t

private:
    BinaryUtils() = delete;
}; 



template<typename T>
T BinaryUtils<T>::Add(const T& binary_a, const T& binary_b) {
    return binary_a + binary_b;
}
template<>
Binary BinaryUtils<Binary>::Add(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Subtract(const T& binary_a, const T& binary_b) {
    return binary_a - binary_b;
}
template<>
Binary BinaryUtils<Binary>::Subtract(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Multiply(const T& binary_a, const T& binary_b) {
    return binary_a * binary_b;
}
template<>
Binary BinaryUtils<Binary>::Multiply(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Divide(const T& binary_a, const T& binary_b) {
    return binary_a / binary_b;
}
template<>
Binary BinaryUtils<Binary>::Divide(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Remainder(const T& binary_a, const T& binary_b) {
    return binary_a % binary_b;
}

template<>
Binary BinaryUtils<Binary>::Remainder(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::And(const T& binary_a, const T& binary_b) {
    return binary_a & binary_b;
}
template<>
Binary BinaryUtils<Binary>::And(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Or(const T& binary_a, const T& binary_b) {
    return binary_a | binary_b;
}
template<>
Binary BinaryUtils<Binary>::Or(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Xor(const T& binary_a, const T& binary_b) {
    return binary_a ^ binary_b;
}
template<>
Binary BinaryUtils<Binary>::Xor(const Binary& binary_a, const Binary& binary_b);

template<typename T>
T BinaryUtils<T>::Not(const T& binary_a) {
    return ~binary_a;
}
template<>
Binary BinaryUtils<Binary>::Not(const Binary& binary_a);

template<typename T>
T BinaryUtils<T>::ShiftLeft(const T& binary_a, const unsigned int& number) {
    return binary_a << number;  
}
template<>
Binary BinaryUtils<Binary>::ShiftLeft(const Binary& binary_a, const unsigned int& number);

template<typename T>
T BinaryUtils<T>::ShiftRight(const T& binary_a, const unsigned int& number) {
    return binary_a >> number;
}
template<>
Binary BinaryUtils<Binary>::ShiftRight(const Binary& binary_a, const unsigned int& number);


#endif