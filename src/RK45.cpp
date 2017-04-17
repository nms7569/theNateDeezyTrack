#include "RK45.h"
/**
 * Name:    RK45
 * Feature: constructor
 * Inputs:  
 *          - (callback_function) function pointer to statespace equation to evaluate
 *          - (double) initial time
 *          - (double) final time
 *          - (double) step size
 *          - (vector<double>) state values at initial time
 * Outputs:
 *          - void
 */
RK45::RK45(callback_function new_zdot, double new_t0, double new_tf, double new_h, boost::numeric::ublas::vector<double> new_z0){
 	this->zdot = new_zdot;
	this->t0 = new_t0;
	this->tf = new_tf;
	this->h = new_h;
	this->z0 = new_z0;
}

/**
 * Name:    rk45::integrate
 * Feature: integrates the state-space equation held by the rk45 object over the given interval using the specified step-size and intial states
 * Inputs:  
 *          - void
 * Outputs: 
 *          - (vector<double>) derivative values of the state vector at the end of the interval
 */
boost::numeric::ublas::vector<double> RK45::integrate(){
	double tn = this->t0;
	boost::numeric::ublas::vector<double> zn = this->z0;
	boost::numeric::ublas::vector<double> k1, k2, k3, k4;

	while(tn <= this->tf){
		k1 = this->zdot(tn, zn);
		k2 = this->zdot(tn + (this->h/2), zn + (this->h/2)*k1);
		k3 = this->zdot(tn + (this->h/2), zn + (this->h/2)*k2);
		k4 = this->zdot(tn + this->h, zn + this->h*k3);

		zn += (this->h/6)*(k1 + 2*k2 + 2*k3 + k4);
		tn += this->h;
	}
	return zn;
}
