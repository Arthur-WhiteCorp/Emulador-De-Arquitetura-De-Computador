#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>


template<typename T>
class BinaryUtils {      

public:
   T Add(const T& binary_a, const T& binary_b); // soma
   T Subtract(const T& binary_a, const T& binary_b); // subtração
   T Multiply(const T& binary_a, const T& binary_b); // multiplicação
   T Divide(const T& binary_a, const T& binary_b); // divisao
   T And(const T& binary_a, const T& binary_b); // and bit a bit
   T Or(const T& binary_a, const T& binary_b); // or bit a bit
   T Xor(const T& binary_a, const T& binary_b); // xor bit a bit
   T Not(const T& binary_a); // not bit a bit
   T ShiftLeft(const T& binary_a, const unsigned int& number); // Bugado
   T ShiftRight(const T& binary_a, const unsigned int& number); // Bugado
}; 

template<typename T>
T BinaryUtils<T>::Add(const T& binary_a, const T& binary_b) {
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] + binary_b[i]);
        }
        return result;
    }

    return binary_a + binary_b; 
}

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
    /* Bugado
    if (std::is_same<std::vector<typename T::value_type>, T>::value) {
        size_t size = std::min(binary_a.size(), binary_b.size());    

        T result;
        result.reserve(binary_a.size());
        for (size_t i = 0; i < size; ++i) {
            result.push_back(binary_a[i] << number);
        }
        return result;
    }
    return binary_a << binary_b;
    */
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