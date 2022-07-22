#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <float.h>

#define s21_PI 3.14159265358979323846264338327950288
#define s21_PI_2  3.14159265358979323846264338327950288L * 2

#define s21_NAN (0.0L / 0.0L)
#define s21_INFINITY (LDBL_MAX + LDBL_MAX)

#define s21_EPS 1e-15L

#define s21_M_E 2.71828182845904523536028747135266250L
#define s21_L 10000000000000000
#define s21_LE 0.00000000000000001
#define s21_LOG2 0.693147180
#define s21_atan_1 0.7853981633974480L
#define s21_atan_PI_2 1.003884821853887214L



long double s21_fmod(double x, double y);
long double s21_fabs(double number);
int s21_abs(int x);
long double s21_factorial(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_exp(double x);
double s21_pow_int(double base, long long int exp);
long double s21_pow(double base, double exp);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_log(double x);

#endif  //  SRC_S21_MATH_H_
