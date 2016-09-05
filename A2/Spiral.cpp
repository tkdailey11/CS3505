/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/3/16
 */
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Spiral.h"

int main(){
    return 0;
}

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

std::ostream& operator<<(std::ostream& output, Spiral sp){
    output << "Spiral Angle: " << rad2 << " Radius: " << radius_ << std::endl;
    return output;
}

void Spiral::operator++(){

    rad1 = (angle2 - 90) / 180 * M_PI;
    rad2 = angle2 / 180 * M_PI;

    text_X = center_X + cos(rad2) * 150;
    text_Y = center_Y + sin(rad2) * 150;


    radius_ += 2.5;
    angle2 -= 10.0;
}
