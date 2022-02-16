/* 
 * Camille van Ginkel u0953582 Jan 31, 2022
 */

#include "Spiral.h"
#include <math.h>

Spiral::Spiral(double centerX, double centerY, double startAngle, double startRadius) : 
initialX(centerX), initialY(centerY), textX(centerX), textY(centerY), angle(startAngle), initialR(startRadius), radius(startRadius){}

void Spiral::operator++() {
        //rad1((startAngle - 90) / 180 * 3.141592), rad2(startAngle / 180 * 3.141592),

        // rad1 determines the angle of the letter on the page. rad2 is how far
        // around the circle you are. Notice that they are perpendicular and
        // thus not independent.
        //
        // Pay careful attention to what wants radians and what is degrees
        // between haru and spiral and math functions.

        double rad2 = angle / 180 * 3.141592;
        radius = initialR + 2*rad2;
        angle += 10.0;
        // The position of the character depends on the center point
        // plus the angle and the radius.
        textX = initialX + cos(rad2) * radius;
        textY = initialY - sin(rad2) * radius;
         // change the angle around the circle

        // This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotationcle
        // matrix.

}
double Spiral::cotan(double i) { return(1 / tan(i)); }

double Spiral::getTextX(){
    return textX;
}
double Spiral::getTextY(){
    return textY;
}
double Spiral::getLetterAngle(){
    return (180 - angle + 90) / 180 * 3.141592;;
}


