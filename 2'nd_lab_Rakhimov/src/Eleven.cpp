#include "../include/Eleven.hpp"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace {
    constexpr unsigned int BASE = 11u;
}

// Конструкторы
Eleven::Eleven() : digits{0} {}

Eleven::Eleven(const std::vector<unsigned char>& inDigits) : digits(inDigits) {
    for (unsigned char d : digits) validateDigit(d);
    trimLeadingZeros(digits);
}

Eleven::Eleven(std::initializer_list<unsigned char> inDigits) : digits(inDigits) {
    for (unsigned char d : digits) validateDigit(d);
    trimLeadingZeros(digits);
}

Eleven::Eleven(std::string_view str) : digits{} {
    if (str.empty()) {

        digits.clear();
        digits.push_back(0);
        return;
    }
    digits.reserve(str.size());
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        unsigned char d = charToDigit(*it);
        digits.push_back(d);
    }
    trimLeadingZeros(digits);
}

Eleven::Eleven(const Eleven& other) = default;
Eleven::Eleven(Eleven&& other) noexcept = default;
Eleven::~Eleven() noexcept = default;

// Фабрика
Eleven Eleven::fromString(std::string_view str) {
    return Eleven(str);  // Делегируем конструктору
}

// Преобразование в строку
std::string Eleven::toString() const {
    if (digits.empty()) return "0";
    
    // старший разряд печатаем первым
    std::string out;
    out.reserve(digits.size());
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        out.push_back(digitToChar(*it));
    }
    if (out.empty()) return std::string("0");
    return out;
}




