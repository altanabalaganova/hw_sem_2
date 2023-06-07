#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    float grav_par = 398600.4, orbital_incl = 1.107, angular_vel = 0.000072921159, radius_p, geo_breadth, a_vel, v_apogee, v_omega;
    int count = 0, check;

    radius_p = (pow(angular_vel, 2)*pow(45000, 4)*pow(cos(orbital_incl), 2))/(2*grav_par - pow(angular_vel, 2)*pow(45000, 3)*pow(cos(orbital_incl), 2));

    FILE* file = fopen("laba8.txt", "w+");

    for(int radius_a; radius_a < 60000; radius_a += 10){

        v_apogee = sqrt((2*radius_p*grav_par)/(radius_a*(radius_a+radius_p)));
        v_omega = angular_vel*radius_a*cos(orbital_incl);

        if(v_apogee > v_omega){
             fprintf(file, "%f\n", v_apogee);
             fprintf(file, "%f\n", v_omega);
        }
        else if (v_apogee <= v_omega){
            while (count > 0){
                check = radius_a - count;
                count = count - 1;
                v_apogee = sqrt((2*grav_par*radius_p)/(check*(check + radius_p)));
                v_omega = angular_vel * check*cos(orbital_incl);
                if (v_apogee > v_omega){
                    fprintf(file, "%f\n", v_apogee);
                    fprintf(file, "%f\n", v_omega);
                }
            }
            break;
        }
    }
    fclose(file);
    return 0;

}
