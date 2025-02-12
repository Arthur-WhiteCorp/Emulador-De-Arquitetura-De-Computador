#ifndef HASH128_H
#define HASH128_H

#include <cstdint>
#include <functional>

class Hash128Bits {
    public:
    static std::size_t hash(__uint128_t number);
};

#endif // HASH128_H