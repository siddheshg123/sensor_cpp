#include<iostream>
#include "json.hpp"
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
using json=nlohmann::json;
#ifndef light_H
#define light_H

class light
{
 private:
        
        double x;
          
 public:
         
        light(double);
        double get_value(std::string);
        void display(void);
        };
#endif
