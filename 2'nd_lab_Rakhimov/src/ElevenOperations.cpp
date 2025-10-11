#include "../include/Eleven.hpp"

#include <algorithm>
#include <stdexcept>

namespace {
    constexpr unsigned int BASE = 11u;
}


// Операции сравнения
int Eleven::compare(const Eleven& rhs) const {
    // Сравнение по длине
    if (digits.size() != rhs.digits.size()) {
        return digits.size() < rhs.digits.size() ? -1 : 1;
    }

    // Лексикографическое сравнение от старших разрядов
    for (std::size_t i = digits.size(); i-- > 0;) {
        if (digits[i] != rhs.digits[i]) {
            return digits[i] < rhs.digits[i] ? -1 : 1;
        }
    }

    return 0;
}

// Арифметические операции
Eleven Eleven::add(const Eleven& rhs) const {
    const std::size_t n = std::max(digits.size(), rhs.digits.size());
    std::vector<unsigned char> res;
    res.resize(n + 1, 0);  // +1 если перенос

    unsigned int carry = 0u;
    for (std::size_t i = 0; i < n; ++i) {
        unsigned int a = i < digits.size() ? digits[i] : 0u;
        unsigned int b = i < rhs.digits.size() ? rhs.digits[i] : 0u;
        unsigned int sum = a + b + carry;
        res[i] = static_cast<unsigned char>(sum % BASE);
        carry = sum / BASE;
    }

    if (carry) {
        res[n] = static_cast<unsigned char>(carry);
    }

    trimLeadingZeros(res);
    return Eleven(res);
}


Eleven Eleven::sub(const Eleven& rhs) const {
    if (compare(rhs) < 0) {
        throw std::invalid_argument("Negative result in Eleven::sub");
    }

    std::vector<unsigned char> res;
    res.resize(digits.size(), 0);

    int borrow = 0;
    for (std::size_t i = 0; i < digits.size(); ++i) {
        int a = static_cast<int>(digits[i]);
        int b = static_cast<int>(i < rhs.digits.size() ? rhs.digits[i] : 0);
        int cur = a - b - borrow;

        if (cur < 0) {
            cur += static_cast<int>(BASE);
            borrow = 1;
        } else {
            borrow = 0;
        }

        res[i] = static_cast<unsigned char>(cur);
    }
    // После завершения borrow должен быть 0, потому что this >= rhs

    trimLeadingZeros(res);
    return Eleven(res);
}

// Иммутабельные аналоги += и -=
Eleven Eleven::added(const Eleven& rhs) const {
    return add(rhs);
}

Eleven Eleven::subtracted(const Eleven& rhs) const {
    return sub(rhs);
}
