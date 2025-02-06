#ifndef BINARY_UTILS_HPP
#define BINARY_UTILS_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using Byte = uint8_t;
using Binary = std::vector<Byte>; // tamanho minimo 8 bits (1 byte)

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