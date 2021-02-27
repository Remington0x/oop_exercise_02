#include "angle.hpp"

int main() {
    int deg;
    double min;
    std::cout << "Enter angle\n";
    std::cin >> deg >> min;
    Angle ang1(deg, min);
    // std::cout << "Enter 2nd angle\n";
    // std::cin >> deg >> min;
    Angle ang2 = "137,44"_angle;

    std::cout << "ang2 is " << ang2 << std::endl;

    std::cout << "1st angle in radians is " << ang1.radian() << std::endl;
    std::cout << "2nd angle in radians is " << ang2.radian() << std::endl;

    std::cout << "ang1 + ang2 is " << ang1 + ang2 << std::endl;

    std::cout << "ang1 - ang2 is " << ang1 - ang2 << std::endl;

    std::cout << "Enter a number to divide the angle1 by\n";
    double n;
    std::cin >> n;
    std::cout << "ang1 / n is " << ang1 / n << std::endl;

    std::cout << "sin(ang1) is " << ang1.sin() << "\nsin(ang2) is " << ang2.sin() << std::endl;
    std::cout << "cos(ang1) is " << ang1.cos() << "\ncos(ang2) is " << ang2.cos() << std::endl;

    if (ang1 > ang2) {
        std::cout << "ang1 > ang2\n";
    } else
    if (ang1 == ang2) {
        std::cout << "ang1 = ang2\n";
    } else {
        std::cout << "ang1 < ang2\n";
    }

    ang1.convTo360();
    ang2.convTo360();
    std::cout << "ang1 in range 0-360 is " << ang1 << std::endl;
    std::cout << "ang2 in range 0-360 is " << ang2 << std::endl;

}
