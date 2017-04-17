#include "pe_problem14.h"
/**
 * try initializing a vector with onw million elements
 * then any time a number is reached in a collatz sequence
 * remove it from the vector of possible root values
 * since it cant ever be longer than the current sequence.
 *
 * also switch over to chrono for better time resolution.
 */

void pe_problem14(void){
    std::cout << "Problem #14" << std::endl;
    clock_t myTime;
    myTime = clock();
    unsigned int maxLength = 0;
    unsigned int curLength = 0;
    unsigned int maxN = 1;
    unsigned int curN = 1;
    unsigned int n;

    for (int i=1; i<1000000; ++i){
        n = i;
	curN = i;
	curLength = 1;
	while (n != 1 and curLength < 1000000){
		if (n % 2 == 0){
			n /= 2;
			++curLength;
		} else {
			n = 3*n + 1;
			++curLength;
		}
	}
	if (curLength > maxLength){
		maxLength = curLength;
		maxN = curN;
		std::cout << "new max " << maxLength << " found at " << maxN << std::endl;
	}
    }

    myTime = clock() - myTime;
    std::cout << "value: " << maxN << std::endl;
    std::cout << "time: " << ((float)myTime)/CLOCKS_PER_SEC << std::endl;
};
