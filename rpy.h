#include<iostream>
#include "json.hpp"
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
using json=nlohmann::json;
#ifndef rpy_H
#define rpy_H
class sensor
{ 
/**Base class sensor*/
public:
	/**Virtual functions from derived classes*/

	virtual double get_value(std::string){}
	virtual void display(void){}
	virtual double get_value1(){}
    virtual double get_value2(){}

};

class rpy:public sensor
{
 /**Derived class from base class sensor.Class to derive roll-pitch-yaw values.*/
 private:
     /** Attributes for class rpy*/   
        double x;
        double y;
        double z;
        
 public:
        /**Templates of sensor*/ 
        rpy(double ,double ,double );
        ~rpy();                      
        double get_value(std::string); 
        void display(void);            
};

class light:public sensor
{
 /**Derived class from base class sensor.Class to calculate no of street lights.*/
private:
	/**Attributes of light*/
	double lx;

public:
	/**Templates of light*/
    light(double);  
    ~light();       
    double get_value1();
};
class sound:public sensor
{
/**Derived class from base class sensor.Class to calculate maximum sound intensity.*/
private:
	/** Attributes of sound class*/
	double sx;
public:
	/**Templates of sound*/
	sound(double);
	~sound();
	double get_value2();
};
#endif
