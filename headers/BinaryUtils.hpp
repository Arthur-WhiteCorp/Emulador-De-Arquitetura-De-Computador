#ifndef BINARY_UTILS_HPP
#define BINARY_UTILS_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <climits>

constexpr size_t MAX_BINARY_SIZE = 256; // tamanho maximo de um binary
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



template<typename T>
class BinaryUtils {      

public:
    static T Add(const T& binary_a, const T& binary_b); // soma
    static T Subtract(const T& binary_a, const T& binary_b); // subtração
    static T Multiply(const T& binary_a, const T& binary_b); // multiplicação
    static T Divide(const T& binary_a, const T& binary_b); // divisao
    static T And(const T& binary_a, const T& binary_b); // and bit a bit
    static T Or(const T& binary_a, const T& binary_b); // or bit a bit
    static T Xor(const T& binary_a, const T& binary_b); // xor bit a bit
    static T Not(const T& binary_a); // not bit a bit
    static T ShiftLeft(const T& binary_a, const unsigned int& number); // Bugado
    static T ShiftRight(const T& binary_a, const unsigned int& number); // Bugado

private:
    BinaryUtils() = delete;
    using BitUnion_128 = union {
    __uint128_t num;
    uint8_t bytes[16];
    };

}; 

template<typename T>
T BinaryUtils<T>::Add(const T& binary_a, const T& binary_b) {
    return binary_a + binary_b;
}

template<>
Binary BinaryUtils<Binary>::Add(const Binary& binary_a, const Binary& binary_b);
template<typename T>
T BinaryUtils<T>::Subtract(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] - binary_b[i]);
        }
        return result;
    }
    return binary_a - binary_b;
}

template<typename T>
T BinaryUtils<T>::Multiply(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] * binary_b[i]);
        }
        return result;
    }
    return binary_a * binary_b;
}

template<typename T>
T BinaryUtils<T>::Divide(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] / binary_b[i]);
        }
        return result;
    }
    return binary_a / binary_b;
}

template<typename T>
T BinaryUtils<T>::And(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] & binary_b[i]);
        }
        return result;
    }
    return binary_a & binary_b;
}

template<typename T>
T BinaryUtils<T>::Or(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] | binary_b[i]);
        }
        return result;
    }
    return binary_a | binary_b;
}

template<typename T>
T BinaryUtils<T>::Xor(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] ^ binary_b[i]);
        }
        return result;
    }
    return binary_a ^ binary_b;
}

template<typename T>
T BinaryUtils<T>::ShiftLeft(const T& binary_a, const unsigned int& number) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = binary_a.size(); 
        T result;
        
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] << number);
        }
        return result;
    }
    return binary_a << number;
    
}

template<typename T>
T BinaryUtils<T>::ShiftRight(const T& binary_a, const unsigned int& number) {
    /* Bugado
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] >> number);
        }
        return result;
    }
    return binary_a >> binary_b;
    */
}

#endif