/* 
 * Camille van Ginkel u0953582 Jan 31, 2022
 */

#ifndef SPIRAL_H
#define SPIRAL_H

class Spiral {
private:
    double initialX; // data member or instance variable   
    double initialY;
    double initialR;
    double textX;
    double textY;
    double angle;
    double radius;

    double cotan(double i);
public:
    Spiral(double centerX, double centerY, double startAngle, double startRadius);

    double getTextX();
    double getTextY();
    double getLetterAngle();

    // Operators
    void operator++();
};

#endif // include guard for Spiral.h
