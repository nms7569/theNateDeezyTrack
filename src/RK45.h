#ifndef RK45_INCLUDED
#define RK45_INCLUDED
#include <boost/numeric/ublas/vector.hpp>

/**
 * Name:    callback_function
 * Feature: Type definition for function pointer to an integrable, linear ODE
 * Inputs:  
 *          - (double) current time
 *          - (vector<double>) vector of current state values
 * Outputs:
 *          - (vector<double>) vector of derivative values of states
 */
typedef boost::numeric::ublas::vector<double> (*callback_function)(double, boost::numeric::ublas::vector<double>);

/**
 * Name:    RK45
 * Feature: class for numerical integration using the rk45 method
 */
class RK45{
	public:
		//constructors
		RK45(const callback_function& new_zdot, const double& new_t0, const double& new_tf, const double& new_h, const boost::numeric::ublas::vector<double>& new_z0);

		//getter & setters
		void setFunc(callback_function& new_zdot);
		callback_function getFunc();

		void set_t0(double& new_t0);
		double get_t0();

		void set_tf(double& new_t0);
		double get_tf();

		void set_h(double& new_h);
		double get_h();

		void set_z0(boost::numeric::ublas::vector<double>& new_z0);
		boost::numeric::ublas::vector<double> get_z0();

		//behaviors
		boost::numeric::ublas::vector<double> integrate();

	private:
		callback_function zdot;
		double t0;
		double tf;
		double h;
		boost::numeric::ublas::vector<double> z0;
}
#endif
