/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/3/16
 */
#define _USE_MATH_DEFINES
#include <math.h>
#include "Spiral.h"


Spiral::Spiral(double centerX, double centerY, double radius){
    center_X = centerX;
    center_Y = centerY;
    radius_ = radius;

    /*  Text along circle */
    angle2 = 180;

    rad1 = (angle2 - 90) / 180 * M_PI;
    rad2 = angle2 / 180 * M_PI;

    if(radius_ < 2){
        radius_ = 2.0;
    }

    text_X = (center_X) + cos(rad2) * 150;
    text_Y = (center_Y) + sin(rad2) * 150;

    radius_ += 1;
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

std::ostream& operator<<(std::ostream& output, Spiral sp){
    output << "Spiral Angle: " << sp.rad2 << " Radius: " << sp.radius_ << std::endl;
    return output;
}

// Prefix
Spiral& operator++(Spiral& sp){

    sp.rad1 = (sp.angle2 - 90) / 180 * M_PI;
    sp.rad2 = sp.angle2 / 180 * M_PI;

    sp.text_X = sp.radius_ + sp.center_X + cos(sp.rad2) * 150;
    sp.text_Y = sp.radius_ + sp.center_Y + sin(sp.rad2) * 150;

    sp.radius_ += 1;
    sp.angle2 -= 10;

    return sp;
}

// Postfix
Spiral& operator++(Spiral& sp, int){

    Spiral& spBefore = sp;

    sp.rad1 = (sp.angle2 - 90) / 180 * M_PI;
    sp.rad2 = sp.angle2 / 180 * M_PI;

    sp.text_X = sp.radius_ + sp.center_X + cos(sp.rad2) * 150;
    sp.text_Y = sp.radius_ + sp.center_Y + sin(sp.rad2) * 150;

    //sp.radius_ += 1;
    sp.angle2 -= 10.0;

    return spBefore;
}
