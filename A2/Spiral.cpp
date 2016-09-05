/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/3/16
 */
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Spiral.h"

double center_X;
double center_Y;
double radius_;
double text_X;
double text_Y;
double angle2;
double rad1;
double rad2;

Spiral::Spiral(double centerX, double centerY, double radius){
    center_X = centerX;
    center_Y = centerY;
    radius_ = radius;

    /*  Text along circle */
    angle2 = 180;

    if(radius_ < 10){
        radius_ = 10.0;
    }
}

double Spiral::get_spiral_angle(){
    return rad2;
}

double Spiral::get_text_angle(){
    return rad1;
}

double Spiral::get_text_x(){
    return text_X;
}

double Spiral::get_text_y(){
    return text_Y;
}

/*
std::ostream& Spiral::operator<<(std::ostream& output, Spiral sp){
    output << "Spiral Angle: " << rad2 << " Radius: " << radius_ << std::endl;
    return output;
}
*/

/* Prefix
const Spiral& Spiral::operator++(Spiral& sp, int){

    sp.rad1 = (sp.angle2 - 90) / 180 * M_PI;
    sp.rad2 = sp.angle2 / 180 * M_PI;

    sp.text_X = sp.center_X + cos(sp.rad2) * 150;
    sp.text_Y = sp.center_Y + sin(sp.rad2) * 150;


    sp.radius_ += 2.5;
    sp.angle2 -= 10.0;

    return sp;
}
*/

/* Postfix
Spiral& Spiral::operator++(Spiral& sp, int){

    Spiral spBefore = sp;

    sp.rad1 = (sp.angle2 - 90) / 180 * M_PI;
    sp.rad2 = sp.angle2 / 180 * M_PI;

    sp.text_X = sp.center_X + cos(sp.rad2) * 150;
    sp.text_Y = sp.center_Y + sin(sp.rad2) * 150;


    sp.radius_ += 2.5;
    sp.angle2 -= 10.0;

    return spBefore;
}
*/
