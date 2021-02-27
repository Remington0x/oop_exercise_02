#include "angle.hpp"

double Angle::radian() {
    return (deg * PI / 180 + min * PI / (180 * 60));
}

int Angle::convTo360() {
    deg = deg % 360;
    return 0;
}

double Angle::sin() {
    return std::sin(radian());
}

double Angle::cos() {
    return std::cos(radian());
}

Angle operator + (Angle& lv, Angle& rv) {
    return Angle(lv.deg + rv.deg + (lv.min + rv.min) / 60, fmod(lv.min + rv.min, 60));
}

// Angle operator - (Angle& lv, Angle& rv) {
//     double d, m;
//     //same signs
//     if (((lv.deg < 0) && (rv.deg < 0)) || ((lv.deg >= 0) && (rv.deg >= 0))) {
//         m = std::abs(lv.min - rv.min);
//         if (lv.min < rv.min) {
//             d = (lv.deg >= 0) ? (lv.deg - rv.deg - 1) : (lv.deg - rv.deg + 1);
//         } else {
//             d = lv.deg - rv.deg;
//         }
//     } else {    //different signs
//         m = fmod(lv.min + rv.min, 60);
//         d = (lv.deg < 0) ? (lv.deg - rv.deg - (lv.min + rv.min) / 60) : (lv.deg - rv.deg + (lv.min + rv.min) / 60);
//     }
//
//     return Angle(d, m);
// }

Angle operator - (Angle& lv, Angle& rv) {
    int d;
    double m;
    unsigned int sign = ((lv > rv) || (lv == rv)) ? 1 : -1;

    if (((lv.deg < 0) && (rv.deg < 0)) || ((lv.deg >= 0) && (rv.deg >= 0))) {
        if (lv.min < rv.min) {
            d = sign * (std::abs(lv.deg - rv.deg) - 1);
            m = lv.min + 60.0 - rv.min;
        } else {
            d = sign * (std::abs(lv.deg - rv.deg));
            m = lv.min - rv.min;
        }
    } else {
        if (lv.min + rv.min >= 60.0) {
            d = sign * (std::abs(lv.deg - rv.deg) + 1);
            m = lv.min + rv.min - 60.0;
        } else {
            d = sign * (std::abs(lv.deg - rv.deg));
            m = lv.min + rv.min;
        }
    }

    return Angle(d, m);
}


Angle operator / (Angle& lv, double& n) {
    return Angle(lv.deg / n + (lv.min / n) / 60, fmod(lv.min / n, 60));
}

bool operator < (Angle& lv, Angle& rv) {
    bool flag = true;
    if (rv.deg < lv.deg) {
        flag = false;
    } else
    if (rv.deg == lv.deg) {
        if (rv.min < lv.min) {
            flag = false;
        }
    }
    return flag;
}

bool operator > (Angle& lv, Angle& rv) {
    bool flag = true;
    if (rv.deg > lv.deg) {
        flag = false;
    } else
    if (rv.deg == lv.deg) {
        if (rv.min > lv.min) {
            flag = false;
        }
    }
    return flag;
}

bool operator==(Angle& lv, Angle& rv) {
    bool flag = false;
    if ((rv.deg == lv.deg) && (rv.min == lv.min)) {
        flag = true;
    }

    return flag;
}

std::ostream& operator << (std::ostream &out, const Angle& ang) {
    out << ang.deg << "°" << ang.min << '\'';
    return out;
}

Angle operator "" _angle(const char* str, size_t size) {
    //std::cout << size << std::endl;
    int deg = 0;
    double min = 0;
    bool flag = true;
    for (int i = 0; i < size; ++i) {
        if (flag) {
            if (str[i] != ',') {
                deg = deg * 10 + str[i] - '0';
            } else {
                flag = false;
            }
        } else {
            min = min * 10 + str[i] - '0';
        }
    }
    return Angle(deg, min);
}
