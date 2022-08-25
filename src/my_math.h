#ifndef SRC_MY_MATH_H_
#define SRC_MY_MATH_H_

#include <stdio.h>
#include <float.h>

#define my_PI 3.14159265358979323846264338327950288
#define my_PI_2  3.14159265358979323846264338327950288L * 2

#define my_NAN (0.0L / 0.0L)
#define my_INFINITY (LDBL_MAX + LDBL_MAX)

#define my_EPS 1e-15L

#define my_M_E 2.71828182845904523536028747135266250L
#define my_L 10000000000000000
#define my_LE 0.00000000000000001
#define my_LOG2 0.693147180
#define my_atan_1 0.7853981633974480L
#define my_atan_PI_2 1.003884821853887214L



long double my_fmod(double x, double y);
long double my_fabs(double number);
int my_abs(int x);
long double my_factorial(double x);
long double my_sin(double x);
long double my_cos(double x);
long double my_tan(double x);
long double my_atan(double x);
long double my_asin(double x);
long double my_acos(double x);
long double my_exp(double x);
double my_pow_int(double base, long long int exp);
long double my_pow(double base, double exp);
long double my_ceil(double x);
long double my_floor(double x);
long double my_sqrt(double x);
long double my_log(double x);

#endif  //  SRC_MY_MATH_H_
