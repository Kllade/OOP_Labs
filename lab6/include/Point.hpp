#pragma once
#include <ostream>
#include <istream>
#include <type_traits>
#include <cmath>

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point {
public:
    T x{0};
    T y{0};

    Point() = default;
    Point(T x, T y) : x(x), y(y) {}
    
    Point(const Point&) = default;
    Point(Point&&) noexcept = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) noexcept = default;
    
    double distance(const Point<T>& other) const {
        double dx = static_cast<double>(x) - static_cast<double>(other.x);
        double dy = static_cast<double>(y) - static_cast<double>(other.y);
        return std::sqrt(dx * dx + dy * dy);
    }
};

template<Scalar T>
inline bool operator==(const Point<T>& a, const Point<T>& b) {
    return a.x == b.x && a.y == b.y;
}

template<Scalar T>
inline std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

template<Scalar T>
inline std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p.x >> p.y;
    return is;
}

