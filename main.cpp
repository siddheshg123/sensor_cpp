#include "fun.h"
#include "rpy.h"

using json = nlohmann::json;
using namespace std;

int main() {
  ifstream fin("simple1.json"); /** Parsing from json file*/
  json j_com = json::parse(fin);

  vector<sensor*> new_gyro_vector = gyro(j_com);
  vector<sensor*> new_acc_vector = accele(j_com);
  vector<sensor*> new_mag_vector = mag(j_com);
  vector<sensor*> new_light_vector = lights(j_com);
  cout << "NUMBER OF STREET LIGHTS:";
  int No = no_of_street_lights(new_light_vector);
  cout << No << endl;
  vector<sensor*> new_sound_vector = sounds(j_com);
  double maximum_sound = max_volume(new_sound_vector);
  cout<<"MAXIMUM SOUND INTENSITY:";
  cout << maximum_sound << endl;

  std::vector<std::vector<double>> r_p_y;

  r_p_y.push_back(roll(new_acc_vector));
  r_p_y.push_back(pitch(new_acc_vector));

  r_p_y.push_back(magnet(new_mag_vector, "x"));
  r_p_y.push_back(magnet(new_mag_vector, "y"));
  r_p_y.push_back(magnet(new_mag_vector, "z"));

  r_p_y.push_back(yaw(r_p_y));
  /**Leakage memory released*/
  for (auto it = new_gyro_vector.begin(); it != new_gyro_vector.end(); it++)
    delete *it;
  for (auto it = new_acc_vector.begin(); it != new_acc_vector.end(); it++)
    delete *it;
  for (auto it = new_mag_vector.begin(); it != new_mag_vector.end(); it++)
    delete *it;
  for (auto it = new_light_vector.begin(); it != new_light_vector.end(); it++)
    delete *it;
  for (auto it = new_sound_vector.begin(); it != new_sound_vector.end(); it++)
    delete *it;

  return 0;
}
