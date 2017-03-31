#include "pe_problem22.h"

void pe_problem22(void){
    std::cout << "Problem #22" << std::endl;
    clock_t myTime;
    myTime = clock();
    std::ofstream fileOut;
    std::ifstream fileIn;
    string p = "~/Downloads/p022_names.txt";
    string line;

    if (boost::filesystem::exists(p)){
	    if (boost::filesystem::is_regular_file(p)){
		    fileIn.open(p);
		    if (fileIn.is_open()){
			    while(std::getline(fileIn,line)){

			    }
			    fileIn.close();
		    }
	    }
    }
    myTime = clock()-myTime;

    std::cout << "time: " << ((float)myTime)/CLOCKS_PER_SEC << std::endl;
};
