/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/5/16
 */
#include <iostream>

class Spiral {

    //Private member variables of the class
    double center_X;
    double center_Y;
    double radius_;
    double text_X;
    double text_Y;
    double angle2;
    double rad1;
    double rad2;

public:
    Spiral(double, double, double);

    //Prefix
    friend Spiral& operator++(Spiral&);
    //Postfix
    friend Spiral& operator++(Spiral&, int);

    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();

    //Overload ostream <<
    friend std::ostream& operator<<(std::ostream& os, Spiral sp);
};
