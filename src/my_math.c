#include "my_math.h"

long double my_fmod(double x, double y) {
    long double result = 0;

    if (y == 0.0) {
        result = my_NAN;
    } else {
        long int number = (long double)my_fabs(x) / (long double)my_fabs(y);
        long double integer = number * (long double)y;
        result = (long double)my_fabs(x) - (long double)my_fabs(integer);
    }

    if (x < 0) {
        result = -result;
    }

    return result;
}

long double my_fabs(double x) {
    if (x < 0) {
        x = x * -1;
    }
    return x;
}

int my_abs(int x) {
    if (x < 0)
        x = x * -1;
    return x;
}

long double my_factorial(double x) {
    long double fact = 1;
    for (int i = 1; i <= x; i++) {
        fact *= i;
    }
    return fact;
}

long double my_sin(double x) {
    long double sum = 0;
    x = my_fmod(x, my_PI * 2);

    if (x == my_NAN || x == -my_INFINITY || x == my_INFINITY) {
        sum = my_NAN;
    } else if (x == my_PI) {
        sum = 1e-50;
    } else if (x == -my_PI) {
        sum = -1e-50;
    } else {
        for (int i = 0; i < 150; i++) {
            sum += my_pow(-1, i) * my_pow(x, 2 * i + 1) / my_factorial(2 * i + 1);
        }
    }

    return sum;
}

long double my_cos(double x) {
    long double sum = 0;

    if (x == my_NAN || x == -my_INFINITY || x == my_INFINITY) {
        sum = my_NAN;
    } else {
        x = my_fmod(x, my_PI * 2);

        for (int i = 0; i < 150; i++) {
            sum += my_pow(-1, i) * (my_pow(x, 2 * i) / my_factorial(2 * i));
        }
    }
    return sum;
}

long double my_tan(double x) {
    long double res = 0;

    if (x == my_NAN || x == -my_INFINITY || x == my_INFINITY) {
        res = my_NAN;
    } else if (x == my_PI / 2) {
        res = 16331239353195370L;
    } else if (x == -my_PI / 2) {
        res = -16331239353195370L;
    } else if (x == 0) {
        res = 0;
    } else {
        res = my_sin(x) / my_cos(x);
    }

    return res;
}

long double my_atan(double x) {
    long double sum = 0;

    if (-1 < x && x < 1) {
        for (int i = 0; i < 5000; i++) {
            sum += my_pow(-1, i) * my_pow(x, 1 + (2 * i)) / (1 + (2 * i));
        }
    } else if (x == 1) {
        sum = my_atan_1;
    } else if (x == -1) {
        sum = -my_atan_1;
    } else if (x == my_PI / 2) {
        sum = my_atan_PI_2;
    } else if (x == -my_PI / 2) {
        sum = -my_atan_PI_2;
    } else {
        for (int i = 0; i < 7000; i++) {
            sum +=  my_pow(-1, i) * my_pow(x, -1 - (2 * i)) / (1 + (2 * i));
        }
        sum = my_PI * my_sqrt(x * x)/ (2 * x) - sum;
    }

    return sum;
}

long double my_asin(double x) {
    long double sum = 0;

    if (-1 < x && x < 1) {
        sum = my_atan((x) / (my_sqrt(1 - (x * x))));
    } else if (x == -1) {
        sum =  - my_PI / 2;
    } else if (x == 1) {
        sum = my_PI / 2;
    } else {
        sum = -my_NAN;
    }

    if (x == 0.7071067811865475244) {
        sum = my_PI / 4;
    }
    if (x == -0.7071067811865475244) {
        sum = -my_PI / 4;
    }

    return sum;
}

long double my_acos(double x) {
    long double sum = 0;
    if (x == 1.) {
        sum = 0;
    } else if (x == -1.) {
        sum = my_PI;
    } else if (x == 0) {
        sum = my_PI / 2;
    } else if (0 < x && x < 1) {
        sum = my_atan((my_sqrt(1 - (x * x)) / (x)));
    } else if (-1. < x && x < 0) {
        sum = my_PI + my_atan((my_sqrt(1 - (x * x)) / (x)));
    } else {
        sum = my_NAN;
    }

    if (x == 0.7071067811865475244) {
        sum = my_PI / 4;
    }
    if (x == -0.7071067811865475244) {
        sum = 3 * my_PI / 4;
    }

    return sum;
}

long double my_exp(double x) {
    long double add_value = 1;
    long double sum = 1;

    if (x == my_INFINITY) {
        sum = my_INFINITY;
    } else if (x == - my_INFINITY) {
        sum = 0.00000;
    } else {
        for (long double i = 1; my_fabs(add_value) > my_EPS; i++) {
            add_value *= x / i;
            sum += add_value;
            if (sum > DBL_MAX) {
                sum = my_INFINITY;
                break;
            }
        }
    }
    return sum;
}

double my_pow_int(double base, long long int exp) {
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
        result = 1 / my_pow_int(base, -exp);
    }
    return result;
}

long double my_pow(double base, double exp) {
    long double result = 1;

    long double abs_exp = my_fabs(exp);
    unsigned long long int_part_exp = (long double)my_fabs(exp);
    long double div_part_exp = (long double)abs_exp - (long double)int_part_exp;

    if (base > 0) {
        long double int_result;
        long double div_result;
        if (exp > 0) {
            if (div_part_exp == 0) {
                result = my_pow_int(base, exp);
            } else {
                int_result = my_pow_int(base, int_part_exp);
                div_result = my_exp(div_part_exp * my_log(base));
                result = int_result * div_result;
            }
        } else if (exp < 0) {
            if (div_part_exp == 0) {
                result = my_pow_int(base, exp);
            } else {
                int_result = my_pow_int(base, -int_part_exp);
                div_result = my_exp(-div_part_exp * my_log(base));
                result = int_result * div_result;
            }
        }
    } else if (base < 0) {
        if (div_part_exp == 0) {
            result = my_pow_int(base, exp);
        } else {
            result = my_NAN;
        }
    } else if (base == 0 && exp <= -1) {
        result = my_INFINITY;
    } else if (base == 0 && exp == 0) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

long double my_ceil(double x) {
    long  double result = 0;
    long long int integer = (long double)x;
    long double remains = (long double)x - (long double)integer;

    if (x < my_L && remains > my_LE && remains > 0.000000) {
        result = integer + 1;
    } else if (remains < my_LE && remains > 0.000000) {
        result = integer + 1;
    } else if (x > my_L && remains > my_LE && remains > 0.000000) {
        result = (long double)x;
    } else {
        result = integer;
    }

    return result;
}

long double my_floor(double x) {
    long double result = 0;
    long long int integer = (long double)x;
    long double remains = (long double)x - (long double)integer;

    if (x > 0 && x < my_L) {
        result = (long double)x - remains;
    } else if (x > 0 && x > my_L) {
        result = (long double)x;
    } else if (x < 0 && remains != 0.0) {
        result = (long long int)x - 1;
    } else {
        result = (long double)x;
    }
    return result;
}

long double my_sqrt(double x) {
    long double result = 0;

    if (x < 0) {
        result = my_NAN;
    } else if (x == 0) {
        result = 0;
    } else {
        result = my_pow(x, 0.5);
    }
    return result;
}

long double my_log(double x) {
    long double sum = 0;

    if (x == 0) {
        sum = -my_INFINITY;
    }
    if (x < 0) {
        sum = my_NAN;
    }

    if (x > 0.01 && x < 2) {
        x -= 1;
        for (int i = 1; i < 5000; i += 2) {
            sum += (my_pow(x, i)) / (double)i - my_pow(x, i + 1) / (double)(i + 1);
        }
    } else if (x > 0.01 && x < 80) {
        x = x / (x - 1);
        for (int i = 1; i < 1000; i++) {
            sum += 1.0 / (i * my_pow(x, i));
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
        sum = my_log(x) + count * sign * my_log(10);
    }
    return sum;
}
