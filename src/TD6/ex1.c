// Leibniz method to calculate pi
#include "TD6.h"

double leibniz_pi(double __precision) {

    double plus_tolerance = sin(__precision); // sin(0) and sin(pi) are equal to 0.
    double minus_tolerance = sin(-__precision); // sin(0) and sin(pi) are equal to 0.

    double pi_4 = 0;
    int index = 0;

    while (true) {

        pi_4 += pow(-1.0, index)/((2 * index) + 1);
        index++;

        if( sin(pi_4 * 4.0) < plus_tolerance && sin(pi_4 * 4.0) > minus_tolerance) {
            if ( (pi_4 * 4.0) < 4 && (pi_4 * 4.0) > 3 ) {
                return pi_4;
            }
        }

        if ( index > MAX_ITERATIONS ) {
            break;
        }

    }
}




