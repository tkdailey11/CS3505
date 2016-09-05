/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/3/16
 */

class Spiral {
public:
    Spiral(double, double, double);
    //What should be the parameter and return type here???
    void operator++();
    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();
    //Overload ostream <<
    friend std::ostream& operator<<(std::ostream& output, Spiral sp);
};
