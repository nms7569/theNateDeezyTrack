#ifndef __EQ_OF_Motion__
#define __EQ_OF_Motion__

#include <vector>


class EOM {
public:
	// constructor
	EOM(){};

	// destructor
	~EOM(){};

	// public member variables

	// public methods
	virtual void evaluate(const std::vector<double> & initial_state, std::vector<double> & derivatives) = 0;
};

class ThreeD_Pendulum: public EOM {
public:
	// constructor
	ThreeD_Pendulum(const double & m, const double & L);

	// destructor
	~ThreeD_Pendulum(){};

	// public member variables 
	double g = 9.80665; // units m/s^2
	double m;
	double L;

	// public methods
	void evaluate(const std::vector<double> & initial_state, std::vector<double> & derivatives);
	void set_length(const double & L);
	void set_mass(const double & m);
};

#endif