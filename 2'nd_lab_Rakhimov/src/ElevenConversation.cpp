#include "../include/Eleven.hpp"

#include <cctype>
#include <stdexcept>

// Вспомогательные функции преобразования символов
unsigned char Eleven::charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return static_cast<unsigned char>(c - '0');
    }

    if (c == 'A' || c == 'a') {
        return 10u;
    }

    // Ошибка, если символ не является допустимой цифрой
    throw std::invalid_argument("Invalid character for base-11");
}


char Eleven::digitToChar(unsigned char d) {
    validateDigit(d);
    if (d < 10) {
        return static_cast<char>('0' + d);
    }

    return 'A';  // d == 10

    // Ошибка, если цифра вне допустимого диапазона
    throw std::invalid_argument("Digit out of range for base-11");
}

// Вспомогательная функция для валидации цифр
void Eleven::validateDigit(unsigned char d) {
    if (d >= 11) {
        throw std::invalid_argument("Digit out of range for base-11");
    }
}

// Вспомогательная функция для удаления ведущих нулей
void Eleven::trimLeadingZeros(std::vector<unsigned char>& v) {
    // Удаляем старшие нули
    while (v.size() > 1 && v.back() == 0) {
        v.pop_back();
    }
    if (v.empty()) {
        v.push_back(0);
    }
}
