#ifndef RK45_INCLUDED
#define RK45_INCLUDED

#include <boost/numeric/ublas/vector.hpp>
#include <vector>
#include <iostream>
#include <fstream>

#include "EOM.h"

/**
 * Name:    callback_function
 * Feature: Type definition for function pointer to an integrable, linear ODE
 * Inputs:  
 *          - (double) current time
 *          - (vector<double>) vector of current state values
 * Outputs:
 *          - (vector<double>) vector of derivative values of states
 */
//typedef boost::numeric::ublas::vector<double> (*callback_function)(double, boost::numeric::ublas::vector<double>);

/**
 * Name:    RK45
 * Feature: class for numerical integration using the rk45 method
 */
class RK45{
	public:
		// callback_function zdot;

		// Constructors
		//RK45(const callback_function& new_zdot, const double& new_t0, const double& new_tf, const double& new_h, const boost::numeric::ublas::vector<double>& new_z0);
		RK45(EOM * new_eom, const double & new_t0, const double & new_tf, const double & new_h, const std::vector<double> & new_z0, const bool & new_report = false);
		
		// Destructor
		~RK45(){};

		// Member Variables 
		class EOM * eom;
		double t0;
		double tf;
		double h;
		std::vector<double> z0;
		bool print_report;

		//getter & setters
		//void set_zdot(callback_function& new_zdot);
		//callback_function get_zdot();
		void set_eom(EOM * new_eom);
		EOM * get_eom();

		void set_t0(double& new_t0);
		double get_t0();

		void set_tf(double& new_t0);
		double get_tf();

		void set_h(double& new_h);
		double get_h();

		void set_z0(std::vector<double>& new_z0);
		std::vector<double> get_z0();

		void set_report(bool& new_report);
		bool get_report();

		//behaviors
		std::vector<double> integrate();
		void report(void);

};
#endif
