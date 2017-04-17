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
//RK45::RK45(const callback_function& new_zdot, const double& new_t0, const double& new_tf, const double& new_h, const boost::numeric::ublas::vector<double>& new_z0){
 	//this->zdot = new_zdot;
	RK45::RK45(const EOM& new_eom, const double& new_t0, const double& new_tf, const double& new_h, const boost::numeric::ublas::vector<double>& new_z0, const bool& new_report){
	this->eom = new_eom;
	this->t0 = new_t0;
	this->tf = new_tf;
	this->h = new_h;
	this->z0 = new_z0;
	this->print_report = new_report;
	//this->state_history
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
//	boost::numeric::ublas::vector<double> zn = this->z0;
//	boost::numeric::ublas::vector<double> k1, k2, k3, k4;
	std::vector<double> zn = this->z0;
	std::vector<double> k1 (zn.size(),0), k2(zn.size(),0), k3(zn.size(),0), k4(zn.size(),0), kbuffer(zn.size(),0), zbuffer(zn.size(),0);
	
	/*
	while(tn <= this->tf){
		k1 = this->zdot(tn, zn);
		k2 = this->zdot(tn + (this->h/2), zn + (this->h/2)*k1);
		k3 = this->zdot(tn + (this->h/2), zn + (this->h/2)*k2);
		k4 = this->zdot(tn + this->h, zn + this->h*k3);

		zn += (this->h/6)*(k1 + 2*k2 + 2*k3 + k4);
		tn += this->h;
	}
	*/
	
	while(tn <= this->tf){
		this->eom::evaluate(zn, kbuffer);
		k1 = kbuffer;

		for (int i = 0; i < zn.size(); ++i){
			zbuffer[i] = zn[i] + (this->h/2)*k1[1];
		}
		this->eom::evaluate(zbuffer, kbuffer);
		k2 = kbuffer;

		for (int i = 0; i < zn.size(); ++i){
			zbuffer[i] = zn[i] + (this->h/2)*k2[1];
		}
		this->eom::evaluate(zbuffer, kbuffer);
		k3 = kbuffer;

		for (int i = 0; i < zn.size(); ++i){
			zbuffer[i] = zn[i] + (this->h)*k3[1];
		}
		this->eom::evaluate(zbuffer, kbuffer);
		k4 = kbuffer;

		for (int i = 0; i < zn.size(); ++i){
			zbuffer[i] = zn[i] + (this->h/6.0)*(k1[i] + 2.0*k2[i] + 2.0*k3[i] +k4[i]);
		zn = zbuffer;
		tn += this->h;
		}
	}
	return zn;
}

//void RK45::set_zdot(callback_function& new_zdot){
	//this->zdot = new_zdot;
//}
//callback_function RK45::get_zdot(){
	//return this->zdot;
//}
void RK45::set_eom(EOM& new_eom){
	this->eom = new_eom;
}
EOM RK45::get_eom(){
	return this->eom;
}
void RK45::set_t0(double& new_t0){
	this->t0 = new_t0;
}
double RK45::get_t0(){
	return this->t0;
}
void RK45::set_tf(double& new_tf){
	this->tf = new_tf;
}
double RK45::get_tf(){
	return this->tf;
}
void RK45::set_h(double& new_h){
	this->h = new_h;
}
double RK45::get_h(){
	return this->h;
}
void RK45::set_z0(boost::numeric::ublas::vector<double>& new_z0){
	this->z0 = new_z0;
}
boost::numeric::ublas::vector<double> RK45::get_z0(){
	return this->z0;
}
void RK45::set_report(bool& new_report){
	this->print_report = new_report;
}
bool RK45::get_report(){
	return this->print_report;
}

/*
void RK45::report(void){
	std::ofstream outfile ("results.txt",std::ofstream::binary);
	outfile << "t0: " << this->t0 << "\ttf: " << this->tf << "\th: " << this->h << std::endl;
	outfile << "with states: " << std::endl;
	for (int i = 0; i < this->z0.size(); ++i){
		outfile << "\tz(" << i << ") = " << z0[i] << std::endl;
	}
	outfile << "evaluates to: " << std::endl;
	boost::numeric::ublas::vector<double> zf = this->integrate();
	for (int i = 0; i <this->z0.size(); ++i){
		outfile << "\tzf(" << i << ") = " << zf[i] << std::endl;
	}
	outfile.close();
}
*/
