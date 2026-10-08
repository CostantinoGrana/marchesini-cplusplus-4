#include "mv.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Mean01: " << Mean01(numbers) << std::endl;
    std::cout << "Mean02: " << Mean02(numbers) << std::endl;
    std::cout << "Mean03: " << Mean03(numbers) << std::endl;
    std::cout << "Mean04: " << Mean04(numbers) << std::endl;
    std::cout << "Mean05: " << Mean05(numbers) << std::endl;
    std::cout << "Mean06: " << Mean06(numbers) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Variance01: " << Variance01(numbers) << std::endl;
    std::cout << "Variance02: " << Variance02(numbers) << std::endl;
    std::cout << "Variance03: " << Variance03(numbers) << std::endl;
    
    return 0;
}
