#include "pe_problem6.h"

void pe_problem6(void){
    std::cout << "Problem #6" << std::endl;
    clock_t my_time;
    my_time = clock();

    unsigned long int finalValue;
    unsigned long int sumOfSquares = 0;
    unsigned long int squareSum = 0;

    for (int i; i <= 100; ++i){
	    sumOfSquares += i*i;
	    squareSum += i;
    }
    squareSum = squareSum * squareSum;
    finalValue = squareSum - sumOfSquares;

    my_time = clock() - my_time;
    std::cout << "value: " << finalValue << std::endl;
    std::cout << "time: " << ((float)my_time)/CLOCKS_PER_SEC << std::endl;
};
