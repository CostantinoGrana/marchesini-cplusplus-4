#include "mv.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<double> lst = {1.5, 2.5, 3.5, 4.5, 5.5};
    std::deque<int> deq = {10, 20, 30, 40, 50};
    
    //std::cout << "Mean01: " << Mean01(1);

    std::cout << "========== CONTAINER-BASED MEAN (vector<int>) ==========" << std::endl;
    std::cout << "Mean01: " << Mean01(vec) << std::endl;
    std::cout << "Mean01Concept: " << Mean01Concept(vec) << std::endl;
    std::cout << "Mean02: " << Mean02(vec) << std::endl;
    std::cout << "Mean03: " << Mean03(vec) << std::endl;
    std::cout << "Mean04: " << Mean04(vec) << std::endl;
    std::cout << "Mean05: " << Mean05(vec) << std::endl;
    std::cout << "Mean06: " << Mean06(vec) << std::endl;
    
    std::cout << "\n========== ITERATOR-BASED MEAN (vector<int>) ==========" << std::endl;
    std::cout << "Mean07: " << Mean07(vec.begin(), vec.end()) << std::endl;
    std::cout << "Mean08: " << Mean08(vec.begin(), vec.end()) << std::endl;
    std::cout << "Mean09: " << Mean09(vec.begin(), vec.end()) << std::endl;
    std::cout << "Mean10: " << Mean10(vec.begin(), vec.end()) << std::endl;
    
    std::cout << "\n========== CONTAINER-BASED VARIANCE (vector<int>) ==========" << std::endl;
    std::cout << "Variance01: " << Variance01(vec) << std::endl;
    std::cout << "Variance02: " << Variance02(vec) << std::endl;
    std::cout << "Variance03: " << Variance03(vec) << std::endl;
    std::cout << "Variance04: " << Variance04(vec) << std::endl;
    
    std::cout << "\n========== ITERATOR-BASED VARIANCE (vector<int>) ==========" << std::endl;
    std::cout << "Variance05: " << Variance05(vec.begin(), vec.end()) << std::endl;
    std::cout << "Variance06: " << Variance06(vec.begin(), vec.end()) << std::endl;
    std::cout << "Variance07: " << Variance07(vec.begin(), vec.end()) << std::endl;
    std::cout << "Variance08: " << Variance08(vec.begin(), vec.end()) << std::endl;
    
    std::cout << "\n========== DIFFERENT CONTAINERS ==========" << std::endl;
    std::cout << "list<double> - Mean02: " << Mean02(lst) 
              << ", Variance02: " << Variance02(lst) << std::endl;
    std::cout << "deque<int> - Mean02: " << Mean02(deq) 
              << ", Variance02: " << Variance02(deq) << std::endl;
    
    std::cout << "\n========== ITERATOR-BASED WITH DIFFERENT CONTAINERS ==========" << std::endl;
    std::cout << "list<double> - Mean08: " << Mean08(lst.begin(), lst.end()) 
              << ", Variance05: " << Variance05(lst.begin(), lst.end()) << std::endl;
    std::cout << "deque<int> - Mean08: " << Mean08(deq.begin(), deq.end()) 
              << ", Variance05: " << Variance05(deq.begin(), deq.end()) << std::endl;
    
    return 0;
}
