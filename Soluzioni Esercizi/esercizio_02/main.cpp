#include "mv.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> int_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<double> double_numbers = {1.5, 2.5, 3.5, 4.5, 5.5};
    
    std::cout << "========== MEAN IMPLEMENTATIONS (int) ==========" << std::endl;
    std::cout << "Mean01: " << Mean01(int_numbers) << std::endl;
    //std::cout << "Mean01_SFINAE: " << Mean01_SFINAE(int_numbers) << std::endl;
    //std::cout << "Mean01_SFINAE_Float: " << Mean01_SFINAE_Float(int_numbers) << std::endl;
    std::cout << "Mean01_Plus: " << Mean01_Plus(int_numbers) << std::endl;
    std::cout << "Mean02: " << Mean02(int_numbers) << std::endl;
    std::cout << "Mean03: " << Mean03(int_numbers) << std::endl;
    std::cout << "Mean04: " << Mean04(int_numbers) << std::endl;
    std::cout << "Mean05: " << Mean05(int_numbers) << std::endl;
    std::cout << "Mean06: " << Mean06(int_numbers) << std::endl;
    
    std::cout << "\n========== VARIANCE IMPLEMENTATIONS (int) ==========" << std::endl;
    std::cout << "Variance01: " << Variance01(int_numbers) << std::endl;
    std::cout << "Variance02: " << Variance02(int_numbers) << std::endl;
    std::cout << "Variance03: " << Variance03(int_numbers) << std::endl;
    
    std::cout << "\n========== MEAN IMPLEMENTATIONS (double) ==========" << std::endl;
    std::cout << "Mean01: " << Mean01(double_numbers) << std::endl;
    std::cout << "Mean01_SFINAE: " << Mean01_SFINAE(double_numbers) << std::endl;
    std::cout << "Mean01_SFINAE_Float: " << Mean01_SFINAE_Float(double_numbers) << std::endl;
    std::cout << "Mean01_Plus: " << Mean01_Plus(double_numbers) << std::endl;
    std::cout << "Mean02: " << Mean02(double_numbers) << std::endl;
    std::cout << "Mean03: " << Mean03(double_numbers) << std::endl;
    std::cout << "Mean04: " << Mean04(double_numbers) << std::endl;
    std::cout << "Mean05: " << Mean05(double_numbers) << std::endl;
    std::cout << "Mean06: " << Mean06(double_numbers) << std::endl;
    
    std::cout << "\n========== VARIANCE IMPLEMENTATIONS (double) ==========" << std::endl;
    std::cout << "Variance01: " << Variance01(double_numbers) << std::endl;
    std::cout << "Variance02: " << Variance02(double_numbers) << std::endl;
    std::cout << "Variance03: " << Variance03(double_numbers) << std::endl;
    
    return 0;
}
