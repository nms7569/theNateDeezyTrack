#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "pe_problem6.h"
#include "pe_problem14.h"
#include "pe_problem22.h"
#include "EOM.h"
#include "RK45.h"

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

    ThreeD_Pendulum three4_pen(1.0,2.0);
    std::vector<double> state(4,1.0);

    RK45 rk45(&three4_pen, 0.0, 1.0, 0.001, state);

    std::vector<double> end_state = rk45.integrate();


    return 0;
}
