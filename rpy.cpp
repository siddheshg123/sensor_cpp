#include "rpy.h"

using json = nlohmann::json;
using namespace std;

rpy::rpy(double mag_x, double mag_y, double mag_z)
    : x(mag_x), y(mag_y), z(mag_z) {}
/**Constructor of rpy*/
double rpy::get_value(std::string s) {
  if (s == "x") {
    return x;
  } else if (s == "y") {
    return y;
  } else if (s == "z") {
    return z;
  }
}
void rpy::display(void) { cout << x << "\t" << y << "\t" << z << endl; }
light::light(double a) : lx(a) {} /** Constructor of light*/
double light::get_value1() { return lx; }
sound::sound(double b) : sx(b) {} /** Constructor of sound*/
double sound::get_value2() { return sx; }
