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
    if (str.empty()) {
        return Eleven();
    }

    std::vector<unsigned char> v;
    v.reserve(str.size());

    // читаем с конца, чтобы младший разряд оказался в индексе 0
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        unsigned char d = charToDigit(*it);
        v.push_back(d);
    }

    trimLeadingZeros(v);
    return Eleven(v);
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

// Сравнение
int Eleven::compare(const Eleven& rhs) const {
    if (digits.size() != rhs.digits.size()) {
        return digits.size() < rhs.digits.size() ? -1 : 1;
    }
    for (std::size_t i = digits.size(); i-- > 0;) {
        if (digits[i] != rhs.digits[i]) {
            return digits[i] < rhs.digits[i] ? -1 : 1;
        }
    }
    return 0;
}

// Сложение (иммутабельно)
Eleven Eleven::add(const Eleven& rhs) const {
    const std::size_t n = std::max(digits.size(), rhs.digits.size());
    std::vector<unsigned char> res;
    res.resize(n + 1, 0);

    unsigned int carry = 0u;
    for (std::size_t i = 0; i < n; ++i) {
        unsigned int a = i < digits.size() ? digits[i] : 0u;
        unsigned int b = i < rhs.digits.size() ? rhs.digits[i] : 0u;
        unsigned int sum = a + b + carry;
        res[i] = static_cast<unsigned char>(sum % BASE);
        carry = sum / BASE;
    }
    if (carry) res[n] = static_cast<unsigned char>(carry);
    trimLeadingZeros(res);
    return Eleven(res);
}

// Вычитание (иммутабельно). Бросает, если rhs > this
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
    // здесь borrow должен быть 0, так как this >= rhs
    trimLeadingZeros(res);
    return Eleven(res);
}

// Иммутабельные аналоги «с присваиванием»
Eleven Eleven::added(const Eleven& rhs) const { return add(rhs); }
Eleven Eleven::subtracted(const Eleven& rhs) const { return sub(rhs); }

// Вспомогательные
unsigned char Eleven::charToDigit(char c) {
    if (c >= '0' && c <= '9') return static_cast<unsigned char>(c - '0');
    if (c == 'A' || c == 'a') return 10u;
    throw std::invalid_argument("Invalid character for base-11");
}

char Eleven::digitToChar(unsigned char d) {
    validateDigit(d);
    if (d < 10) return static_cast<char>('0' + d);
    return 'A'; // 10
}

void Eleven::validateDigit(unsigned char d) {
    if (d >= BASE) throw std::invalid_argument("Digit out of range for base-11");
}

void Eleven::trimLeadingZeros(std::vector<unsigned char>& v) {
    // удаляем старшие нули
    while (v.size() > 1 && v.back() == 0) v.pop_back();
    if (v.empty()) v.push_back(0);
}


