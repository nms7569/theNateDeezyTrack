#include "EOM.h"
#include <cmath>
#include <iostream>

ThreeD_Pendulum::ThreeD_Pendulum(const double & m, const double & L){
	this->L = L;
	this->m = m;
};


void ThreeD_Pendulum::evaluate(const std::vector<double> & initial_state, std::vector<double> & derivatives){
// initial state is [theta, theta_dot, phi, phi_dot] and the derivatives function is one time derivative
	derivatives[0] = initial_state[1];
	derivatives[1] = initial_state[3]*initial_state[3]*std::cos(initial_state[0])*std::sin(initial_state[0]) - (this->g/this->L)*sin(initial_state[0]);
	derivatives[2] = initial_state[3];
	derivatives[3] = -2.0*initial_state[3]*initial_state[1]*std::cos(initial_state[0])/std::sin(initial_state[0]);

};

void ThreeD_Pendulum::set_length(const double & L){
	this->L = L;
};

void ThreeD_Pendulum::set_mass(const double & m){
	this->m = m;
};
