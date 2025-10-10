#pragma once

#include <string>
#include <string_view>
#include <vector>

class Eleven {
public:
    // Конструкторы
    Eleven();
    explicit Eleven(const std::vector<unsigned char>& digits);
    explicit Eleven(std::initializer_list<unsigned char> digits);
    explicit Eleven(std::string_view str);

    Eleven(const Eleven& other);
    Eleven(Eleven&& other) noexcept;
    ~Eleven() noexcept;

    Eleven& operator=(const Eleven& other) = default;
    Eleven& operator=(Eleven&& other) noexcept = default;

    // Фабрика
    static Eleven fromString(std::string_view str);

    // Преобразование
    std::string toString() const;

    // Операции (иммутабельные)
    Eleven add(const Eleven& rhs) const;
    Eleven sub(const Eleven& rhs) const; // бросает, если результат отрицателен

    // Сравнение (-1, 0, 1)
    int compare(const Eleven& rhs) const;

    // «С присваиванием», но иммутабельно — возвращают новый экземпляр
    Eleven added(const Eleven& rhs) const;    // эквивалент +=
    Eleven subtracted(const Eleven& rhs) const; // эквивалент -=

private:
    std::vector<unsigned char> digits; // младший разряд — индекс 0

    static unsigned char charToDigit(char c);
    static char digitToChar(unsigned char d);

    static void validateDigit(unsigned char d);
    static void trimLeadingZeros(std::vector<unsigned char>& v);
};


