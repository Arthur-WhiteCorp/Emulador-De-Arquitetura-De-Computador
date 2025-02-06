#include "BinaryUtils.hpp"


template<>
Binary BinaryUtils<Binary>::Add(const Binary& binary_a, const Binary& binary_b) {
    bool a_greater = false;
    a_greater = binary_a.size() >= binary_b.size(); // a e maior que b
    size_t size_max = 0;
    size_t size_min = 0;
    if (a_greater) {
        size_max = binary_a.size();
        size_min = binary_b.size();
    } else {
        size_max = binary_b.size();
        size_min = binary_a.size();
    }

    std::vector<uint8_t> result(size_max, 0); // inicialização com 0

    if (a_greater) {
        for (size_t i = 0; i < size_min; ++i) {
            result[size_max - i - 1] = binary_a[size_max - i] + binary_b[size_min - i];
        }
        for (size_t i = size_min; i < size_max; ++i) {
            result[size_max - i - 1] = binary_a[size_max - i];
        }
    } else {
        for (size_t i = 0; i < size_min; ++i) {
            result[size_max - i - 1] = binary_b[size_max - i] + binary_a[size_min - i];
        }
        for (size_t i = size_min; i < size_max; ++i) {
            result[size_max - i - 1] = binary_b[size_max - i];
        }
    }
    std::cout << "magia" << std::endl;
    return result;
}