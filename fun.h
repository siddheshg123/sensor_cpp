#include "rpy.h"
 /**Header file for functions*/

vector<sensor*> gyro(json);
void display (vector<double>);
vector<sensor*> accele(json);
vector<sensor*> mag(json);
vector<double> roll(vector<sensor*>);
vector<double> pitch(vector<sensor*>);
vector<double> magnet(vector<sensor*>, string);
vector<double> yaw(vector<std::vector<double>>);
vector<sensor*> lights(json);
int no_of_street_lights(vector<sensor*>);
vector<sensor*> sounds(json);
double max_volume(vector<sensor*>);
