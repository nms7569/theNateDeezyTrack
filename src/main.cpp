#include <iostream>
#include <string>
#include <cstdlib>

#include "pe_problem6.h"
#include "pe_problem14.h"
#include "pe_problem22.h"

int main(int argc, char *argv[]){
    if(argc==2){
        switch(std::atoi(argv[1])){
            case 6:
                pe_problem6();
                break;
            case 14:
                pe_problem14();
                break;
            case 22:
                pe_problem22();
                break;
            default:
                std::cout << "not a valid/solved problem number." << std::endl;
                break;
        }
    }
    return 0;
}
