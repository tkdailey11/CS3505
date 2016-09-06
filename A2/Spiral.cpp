/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/5/16
 */
#define _USE_MATH_DEFINES
#include <math.h>
#include "Spiral.h"

/*
 * Takes in a double centerX and centerY for the coordinates of the center of the spiral, and a double radius which forms the starting
 * radius. Enforces a minimum radius of 45.
 */
Spiral::Spiral(double centerX, double centerY, double radius){
    center_X = centerX;
    center_Y = centerY;
    radius_ = radius;

    // Allows the text to move in a circular pattern.
    angle2 = 180;

    // rad1 is the angle of the character, while rad2 is the angle around the circle. Both are represented in radians.
    rad1 = (angle2 - 90) / 180 * M_PI;
    rad2 = angle2 / 180 * M_PI;

    if(radius_ < 45){
        radius_ = 45.0;
    }

    text_X = (center_X) + cos(rad2) * radius_;
    text_Y = (center_Y) + sin(rad2) * radius_;

    //Add a little buffer to the starting Y value, so the text doesn't overlap.
    center_Y += 7;

    radius_ += 1;
}

/* Return the angle (as a double) around the spiral of the current position, in radians. */
double Spiral::get_spiral_angle(){
    return rad2;
}

/* Return the angle (as a double) of the character on the page. */
double Spiral::get_text_angle(){
    return rad1;
}

/* Return the X-Value of the current position of the spiral, as a double. */
double Spiral::get_text_x(){
    return text_X;
}

/* Return the Y-Value of the current position of the spiral, as a double. */
double Spiral::get_text_y(){
    return text_Y;
}

/* Overload the << operator for Spiral objects. Displays the Spiral Angle and Radius of the current position of the spiral. */
std::ostream& operator<<(std::ostream& output, Spiral sp){
    output << "Spiral Angle: " << sp.rad2 << " Radius: " << sp.radius_ << std::endl;
    return output;
}

/* Overload the ++ pre-increment operator to advance the position of the spiral on which it was called. */
Spiral& operator++(Spiral& sp){

    sp.rad1 = (sp.angle2 - 90) / 180 * M_PI;
    sp.rad2 = sp.angle2 / 180 * M_PI;

    sp.text_X = sp.center_X + cos(sp.rad2) * sp.radius_;
    sp.text_Y = sp.center_Y + 4 + sin(sp.rad2) * sp.radius_;

    sp.radius_ += 1;
    sp.angle2 -= 10;

    return sp;
}

/* Overload the ++ post-increment operator to advance the position of the spiral on which it was called. */
Spiral& operator++(Spiral& sp, int){

    Spiral& spBefore = sp;

    sp.rad1 = (sp.angle2 - 90) / 180 * M_PI;
    sp.rad2 = sp.angle2 / 180 * M_PI;

    sp.text_X = sp.center_X + cos(sp.rad2) * sp.radius_;
    sp.text_Y = sp.center_Y + 4 + sin(sp.rad2) * sp.radius_;

    sp.radius_ += 1;
    sp.angle2 -= 10;

    return spBefore;
}
