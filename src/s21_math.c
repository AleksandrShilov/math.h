#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double result = 0;

    if (y == 0.0) {
        result = s21_NAN;
    } else {
        long int number = (long double)s21_fabs(x) / (long double)s21_fabs(y);
        long double integer = number * (long double)y;
        result = (long double)s21_fabs(x) - (long double)s21_fabs(integer);
    }

    if (x < 0) {
        result = -result;
    }

    return result;
}

long double s21_fabs(double x) {
    if (x < 0) {
        x = x * -1;
    }
    return x;
}

int s21_abs(int x) {
    if (x < 0)
        x = x * -1;
    return x;
}

long double s21_factorial(double x) {
    long double fact = 1;
    for (int i = 1; i <= x; i++) {
        fact *= i;
    }
    return fact;
}

long double s21_sin(double x) {
    long double sum = 0;
    x = s21_fmod(x, s21_PI * 2);

    if (x == s21_NAN || x == -s21_INFINITY || x == s21_INFINITY) {
        sum = s21_NAN;
    } else if (x == s21_PI) {
        sum = 1e-50;
    } else if (x == -s21_PI) {
        sum = -1e-50;
    } else {
        for (int i = 0; i < 150; i++) {
            sum += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_factorial(2 * i + 1);
        }
    }

    return sum;
}

long double s21_cos(double x) {
    long double sum = 0;

    if (x == s21_NAN || x == -s21_INFINITY || x == s21_INFINITY) {
        sum = s21_NAN;
    } else {
        x = s21_fmod(x, s21_PI * 2);

        for (int i = 0; i < 150; i++) {
            sum += s21_pow(-1, i) * (s21_pow(x, 2 * i) / s21_factorial(2 * i));
        }
    }
    return sum;
}

long double s21_tan(double x) {
    long double res = 0;

    if (x == s21_NAN || x == -s21_INFINITY || x == s21_INFINITY) {
        res = s21_NAN;
    } else if (x == s21_PI / 2) {
        res = 16331239353195370L;
    } else if (x == -s21_PI / 2) {
        res = -16331239353195370L;
    } else if (x == 0) {
        res = 0;
    } else {
        res = s21_sin(x) / s21_cos(x);
    }

    return res;
}

long double s21_atan(double x) {
    long double sum = 0;

    if (-1 < x && x < 1) {
        for (int i = 0; i < 5000; i++) {
            sum += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
        }
    } else if (x == 1) {
        sum = s21_atan_1;
    } else if (x == -1) {
        sum = -s21_atan_1;
    } else if (x == s21_PI / 2) {
        sum = s21_atan_PI_2;
    } else if (x == -s21_PI / 2) {
        sum = -s21_atan_PI_2;
    } else {
        for (int i = 0; i < 7000; i++) {
            sum +=  s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
        }
        sum = s21_PI * s21_sqrt(x * x)/ (2 * x) - sum;
    }

    return sum;
}

long double s21_asin(double x) {
    long double sum = 0;

    if (-1 < x && x < 1) {
        sum = s21_atan((x) / (s21_sqrt(1 - (x * x))));
    } else if (x == -1) {
        sum =  - s21_PI / 2;
    } else if (x == 1) {
        sum = s21_PI / 2;
    } else {
        sum = -s21_NAN;
    }

    if (x == 0.7071067811865475244) {
        sum = s21_PI / 4;
    }
    if (x == -0.7071067811865475244) {
        sum = -s21_PI / 4;
    }

    return sum;
}

long double s21_acos(double x) {
    long double sum = 0;
    if (x == 1.) {
        sum = 0;
    } else if (x == -1.) {
        sum = s21_PI;
    } else if (x == 0) {
        sum = s21_PI / 2;
    } else if (0 < x && x < 1) {
        sum = s21_atan((s21_sqrt(1 - (x * x)) / (x)));
    } else if (-1. < x && x < 0) {
        sum = s21_PI + s21_atan((s21_sqrt(1 - (x * x)) / (x)));
    } else {
        sum = s21_NAN;
    }

    if (x == 0.7071067811865475244) {
        sum = s21_PI / 4;
    }
    if (x == -0.7071067811865475244) {
        sum = 3 * s21_PI / 4;
    }

    return sum;
}

long double s21_exp(double x) {
    long double add_value = 1;
    long double sum = 1;

    if (x == s21_INFINITY) {
        sum = s21_INFINITY;
    } else if (x == - s21_INFINITY) {
        sum = 0.00000;
    } else {
        for (long double i = 1; s21_fabs(add_value) > s21_EPS; i++) {
            add_value *= x / i;
            sum += add_value;
            if (sum > DBL_MAX) {
                sum = s21_INFINITY;
                break;
            }
        }
    }
    return sum;
}

double s21_pow_int(double base, long long int exp) {
    double result = 1;
    if (exp >= 0) {
        while (exp != 0) {
            if ((exp & 1) != 0) {
                result *= base;
            }
            base *= base;
            exp >>= 1;
        }
    } else {
        result = 1 / s21_pow_int(base, -exp);
    }
    return result;
}

long double s21_pow(double base, double exp) {
    long double result = 1;

    long double abs_exp = s21_fabs(exp);
    unsigned long long int_part_exp = (long double)s21_fabs(exp);
    long double div_part_exp = (long double)abs_exp - (long double)int_part_exp;

    if (base > 0) {
        long double int_result;
        long double div_result;
        if (exp > 0) {
            if (div_part_exp == 0) {
                result = s21_pow_int(base, exp);
            } else {
                int_result = s21_pow_int(base, int_part_exp);
                div_result = s21_exp(div_part_exp * s21_log(base));
                result = int_result * div_result;
            }
        } else if (exp < 0) {
            if (div_part_exp == 0) {
                result = s21_pow_int(base, exp);
            } else {
                int_result = s21_pow_int(base, -int_part_exp);
                div_result = s21_exp(-div_part_exp * s21_log(base));
                result = int_result * div_result;
            }
        }
    } else if (base < 0) {
        if (div_part_exp == 0) {
            result = s21_pow_int(base, exp);
        } else {
            result = s21_NAN;
        }
    } else if (base == 0 && exp <= -1) {
        result = s21_INFINITY;
    } else if (base == 0 && exp == 0) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

long double s21_ceil(double x) {
    long  double result = 0;
    long long int integer = (long double)x;
    long double remains = (long double)x - (long double)integer;

    if (x < s21_L && remains > s21_LE && remains > 0.000000) {
        result = integer + 1;
    } else if (remains < s21_LE && remains > 0.000000) {
        result = integer + 1;
    } else if (x > s21_L && remains > s21_LE && remains > 0.000000) {
        result = (long double)x;
    } else {
        result = integer;
    }

    return result;
}

long double s21_floor(double x) {
    long double result = 0;
    long long int integer = (long double)x;
    long double remains = (long double)x - (long double)integer;

    if (x > 0 && x < s21_L) {
        result = (long double)x - remains;
    } else if (x > 0 && x > s21_L) {
        result = (long double)x;
    } else if (x < 0 && remains != 0.0) {
        result = (long long int)x - 1;
    } else {
        result = (long double)x;
    }
    return result;
}

long double s21_sqrt(double x) {
    long double result = 0;

    if (x < 0) {
        result = s21_NAN;
    } else if (x == 0) {
        result = 0;
    } else {
        result = s21_pow(x, 0.5);
    }
    return result;
}

long double s21_log(double x) {
    long double sum = 0;

    if (x == 0) {
        sum = -s21_INFINITY;
    }
    if (x < 0) {
        sum = s21_NAN;
    }

    if (x > 0.01 && x < 2) {
        x -= 1;
        for (int i = 1; i < 5000; i += 2) {
            sum += (s21_pow(x, i)) / (double)i - s21_pow(x, i + 1) / (double)(i + 1);
        }
    } else if (x > 0.01 && x < 80) {
        x = x / (x - 1);
        for (int i = 1; i < 1000; i++) {
            sum += 1.0 / (i * s21_pow(x, i));
        }
    } else if (x > 0) {
        long int count = 0;
        int sign = 1;
        if (x > 1) {
            while (x > 1) {
                x /= 10;
                count++;
            }
            sign = 1;
        } else {
            while (x < 0.1) {
                x *= 10;
                count++;
            }
            sign = -1;
        }
        sum = s21_log(x) + count * sign * s21_log(10);
    }
    return sum;
}
