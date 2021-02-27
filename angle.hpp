#ifndef ANGLE_HPP
#define ANGLE_HPP

#include <iostream>
#include <cmath>

const double PI = 3.1415;

class Angle {
private:
    int deg;
    double min;
public:
    Angle(int d, int m) : deg(d), min(m) {}
    double radian();
    int convTo360();
    double sin();
    double cos();
    friend Angle operator + (Angle& lv, Angle& rv);
    friend Angle operator - (Angle& lv, Angle& rv);
    friend Angle operator / (Angle& lv, double& n);
    friend bool operator < (Angle& lv, Angle& rv);
    friend bool operator > (Angle& lv, Angle& rv);
    friend bool operator == (Angle& lv, Angle& rv);
    friend std::ostream& operator << (std::ostream &out, const Angle& ang);
    ~Angle() {}
};

Angle operator "" _angle(const char* str, size_t size);

#endif
