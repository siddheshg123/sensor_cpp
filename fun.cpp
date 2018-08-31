#include "fun.h"

void display(vector<double> v) {
  /**Display function of sensor class*/
  for (auto i : v) cout << i << endl;
}

vector<sensor*> gyro(json j_com) {
  /**Extracting GYROMETER parameters*/
  vector<sensor*> myvector_gyro;
  for (auto entry : j_com) {
    sensor* gyro = new rpy(entry.value("GYROSCOPE X (rad/s)", 0.0l),
                           entry.value("GYROSCOPE Y (rad/s)", 0.0l),
                           entry.value("GYROSCOPE Z (rad/s)", 0.0l));
    myvector_gyro.push_back(gyro);
  }
  return myvector_gyro;
}

vector<sensor*> accele(json j_com) {
  /**Extracting ACCELEROMETER parameters*/
  vector<sensor*> myvector_acc;
  for (auto entry : j_com) {
    sensor* acc = new rpy(entry.value("ACCELEROMETER X (m/s²)", 0.0l),
                          entry.value("ACCELEROMETER Y (m/s²)", 0.0l),
                          entry.value("ACCELEROMETER Z (m/s²)", 0.0l));
    myvector_acc.push_back(acc);
  }
  return myvector_acc;
}

vector<sensor*> mag(json j_com) {
  /**Extracting MAGNETOMETER parameters*/
  vector<sensor*> myvector_mag;
  for (auto entry : j_com) {
    sensor* mag = new rpy(entry.value("MAGNETIC FIELD X (μT)", 0.0l),
                          entry.value("MAGNETIC FIELD Y (μT)", 0.0l),
                          entry.value("MAGNETIC FIELD Z (μT)", 0.0l));
    myvector_mag.push_back(mag);
  }
  return myvector_mag;
}

vector<double> roll(vector<sensor*> new_acc_vector) {
  /**Calculating roll*/
  vector<double> roll_v;

  for (auto iter : new_acc_vector) {
    double tx = iter->get_value("x");
    double ty = iter->get_value("y");
    double tz = iter->get_value("z");
    auto roll = (atan2(-tx, (sqrt((ty * ty) + (tz * tz))))) * 57.6;
    roll_v.push_back(roll);
  }
  return roll_v;
}

vector<double> pitch(vector<sensor*> new_acc_vector) {
  /**Calculating pitch*/
  vector<double> pitch_v;
  for (auto iter : new_acc_vector) {
    double tx = iter->get_value("x");
    double ty = iter->get_value("y");
    double tz = iter->get_value("z");
    auto pitch = (atan2(ty, (sqrt((tx * tx) + (tz * tz))))) * 57.6;
    pitch_v.push_back(pitch);
  }
  return pitch_v;
}

vector<double> magnet(vector<sensor*> new_mag_vector, string s) {
  vector<double> mag;
  for (auto iter : new_mag_vector) {
    double m = iter->get_value(s);
    mag.push_back(m);
  }

  return mag;
}

vector<double> yaw(vector<std::vector<double>> r_p_y) {
  /**Calculating yaw*/
  vector<double> yaw_v;
  for (auto i = 0; i < r_p_y[0].size(); ++i) {
    double Yh =
        (r_p_y[3][i] * cos(r_p_y[0][i])) - (r_p_y[4][i] * sin(r_p_y[0][i]));

    double Xh = double(r_p_y[2][i] * cos(r_p_y[1][i])) +
                double(r_p_y[3][i] * sin(r_p_y[0][i]) * sin(r_p_y[1][i])) +
                double(r_p_y[4][i] * cos(r_p_y[0][i]) * sin(r_p_y[1][i]));

    double yaw = (atan2(Yh, Xh)) * 57.6;

    yaw_v.push_back(yaw);
  }
  return yaw_v;
}

vector<sensor*> lights(json j_com) {
  vector<sensor*> myvector_light;
  for (auto entry : j_com) {
    sensor* lit = new light(entry.value("LIGHT (lux)", 0.0));
    myvector_light.push_back(lit);
  }
  return myvector_light;
}
int no_of_street_lights(vector<sensor*> new_light_vector) {
  /**Calculating NO. OF STREET LIGHTS*/
  int number1 = 0;
  for (auto iter : new_light_vector) {
    double lv = iter->get_value1();
    if (lv > 100) {
      number1 += 1;
    }
  }

  return int(number1 / 7);
}

vector<sensor*> sounds(json j_com) {
  vector<sensor*> myvector_sound;
  for (auto entry : j_com) {
    sensor* vol = new sound(entry.value("SOUND LEVEL (dB)", 0.0l));
    myvector_sound.push_back(vol);
  }
  return myvector_sound;
}

double max_volume(vector<sensor*> new_sound_vector) {
  /**Calculating maximum volume*/
  double Max = -1.0f;
  for (auto it : new_sound_vector) {
    if (it->get_value2() >= Max) Max = it->get_value2();
  }
  return Max;
}
