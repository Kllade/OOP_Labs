#include "../include/Eleven.hpp"
#include <iostream>

int main() {
    Eleven a{"A0"}; // 10*11 + 0 = 110
    Eleven b{"1A"}; // 1*11 + 10 = 21

    Eleven sum = a.add(b);
    Eleven diff = a.sub(b);

    std::cout << a.toString() << " + " << b.toString() << " = " << sum.toString() << "\n";
    std::cout << a.toString() << " - " << b.toString() << " = " << diff.toString() << "\n";
    return 0;
}


