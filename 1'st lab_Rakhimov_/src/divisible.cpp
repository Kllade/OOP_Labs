#include "divisible.h"
#include <stdexcept>

using namespace std;

int findMaxDivisible(int divider, int bound) {
    if (bound <= 0 || divider <= 0) {
        return 0;
    }
    
    if (divider > bound) {
        return 0;
    }
    
    int result = (bound / divider) * divider;

    if (result <= 0) {
        throw runtime_error("Результат не может быть найден");
    }
    
    return result;
}
