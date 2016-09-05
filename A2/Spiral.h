/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/3/16
 */

class Spiral {
public:
    Spiral(double, double, double);
    //Prefix
    // friend const Spiral& operator++(Spiral&);
    //Postfix
    //friend Spiral& operator++(Spiral&, int);

    double get_text_x();
    double get_text_y();
    double get_spiral_angle();
    double get_text_angle();

    /*
    //Overload ostream <<
    friend std::ostream& operator<<(std::ostream& os, Spiral sp);
    */
};
