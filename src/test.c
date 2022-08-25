/*
 * TEST FILE
 */

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "my_math.h"

#define my_M6 1e-06
#define my_16 1e16

START_TEST(my_abs_test) {
  for (int i = -5000; i < 5000; i++) ck_assert_int_eq(abs(i), my_abs(i));
  ck_assert_int_eq(abs(INT_MIN), my_abs(INT_MIN));
  ck_assert_int_eq(abs(INT_MAX), my_abs(INT_MAX));
}
END_TEST

START_TEST(my_acos_test) {
  for (double x = -1.0; x <= 1.0; x += 0.15)
    ck_assert_ldouble_le_tol(fabsl(acos(x) - my_acos(x)), my_M6, my_M6);
  ck_assert_ldouble_eq_tol(acos(1), my_acos(1), my_M6);
  ck_assert_ldouble_eq_tol(acos(0), my_acos(0), my_M6);
  ck_assert_ldouble_nan(my_acos(my_INFINITY));
  ck_assert_ldouble_eq_tol(acos(0.7071067811865475244), my_acos(0.7071067811865475244), my_M6);
  ck_assert_ldouble_eq_tol(acos(-0.7071067811865475244), my_acos(-0.7071067811865475244), my_M6);
}
END_TEST

START_TEST(my_asin_test) {
  for (double x = -1.0; x <= 1.0; x += 0.15)
    ck_assert_ldouble_le_tol(fabsl(asin(x) - my_asin(x)), my_M6, my_M6);
  ck_assert_ldouble_eq_tol(asin(1), my_asin(1), my_M6);
  ck_assert_ldouble_nan(my_asin(my_INFINITY));
  ck_assert_ldouble_eq_tol(asin(0.7071067811865475244), my_asin(0.7071067811865475244), my_M6);
  ck_assert_ldouble_eq_tol(asin(-0.7071067811865475244), my_asin(-0.7071067811865475244), my_M6);
}
END_TEST

START_TEST(my_atan_test) {
  for (double x = -100.4; x <= 100.4; x += 0.3123)
    ck_assert_ldouble_le_tol(fabsl(atan(x) - my_atan(x)), my_M6, my_M6);
  ck_assert_ldouble_eq_tol(atan(1), my_atan(1), my_M6);
  ck_assert_ldouble_eq_tol(atan(-1), my_atan(-1), my_M6);
  ck_assert_ldouble_eq_tol(atan(my_PI / 2), my_atan(my_PI / 2), my_M6);
  ck_assert_ldouble_eq_tol(atan(-my_PI / 2), my_atan(-my_PI / 2), my_M6);
}
END_TEST

START_TEST(my_ceil_test) {
  for (double x = -14567; x <= -14567; x += 0.01)
    ck_assert_ldouble_eq_tol(ceil(x), my_ceil(x), my_M6);
  ck_assert_ldouble_eq_tol(ceil(DBL_MIN), my_ceil(DBL_MIN), my_M6);
  ck_assert_ldouble_eq_tol(ceil(DBL_MAX - 1), my_ceil(DBL_MAX - 1), my_M6);
}
END_TEST

START_TEST(my_cos_test) {
  for (double x = -my_PI * 8; x <= my_PI * 8; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(cos(x) - my_cos(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_cos(my_INFINITY));
}
END_TEST

START_TEST(my_exp_test) {
  for (double x = -20; x <= 20; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(exp(x) - my_exp(x)), my_M6, my_M6);
  ck_assert_ldouble_infinite(my_exp(my_INFINITY));
  ck_assert_ldouble_eq_tol(exp(-my_INFINITY), my_exp(-my_INFINITY), my_M6);
}
END_TEST

START_TEST(my_fabs_test) {
  for (double x = -500.123; x <= 500.123; x += 0.5)
    ck_assert_ldouble_le_tol(fabsl(fabs(x) - my_fabs(x)), my_M6, my_M6);
  ck_assert_ldouble_eq_tol(fabs(DBL_MIN), my_fabs(DBL_MIN), my_M6);
  ck_assert_ldouble_eq_tol(fabs(DBL_MAX), my_fabs(DBL_MAX), my_M6);
}
END_TEST

START_TEST(my_floor_test) {
  for (double x = -500.0; x <= 500.0; x += 0.5)
    ck_assert_ldouble_eq_tol(floor(x), my_floor(x), my_M6);
  ck_assert_ldouble_eq_tol(floor(DBL_MIN - 1), my_floor(DBL_MIN - 1), my_M6);
  ck_assert_ldouble_eq_tol(floor(DBL_MAX), my_floor(DBL_MAX), my_M6);
}
END_TEST

START_TEST(my_fmod_test) {
  for (double x = -500.123; x <= 500.123; x += 0.5)
    for (double y = -1000.246; x <= 1000.246; x += 0.5)
      ck_assert_ldouble_le_tol(fabsl(fmod(x, y) - my_fmod(x, y)), my_M6,
                               my_M6);
  ck_assert_ldouble_nan(my_fmod(2, 0.0));
}
END_TEST

START_TEST(my_log_test) {
  for (double x = 0.0001; x <= 200.555; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(log(x) - my_log(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_log(-2.0));
  ck_assert_ldouble_infinite(my_log(0));
}
END_TEST

START_TEST(my_pow_test) {
  for (double x = -10.12; x <= 10.12; x += 0.1) {
    for (double y = 0.0; y <= 5.0; y += 1) {
      ck_assert_ldouble_le_tol(fabsl(pow(x, y) - my_pow(x, y)), my_M6,
                               my_M6);
    }
  }
  for (double x = -10.0; x <= 10.0; x += 1.0) {
    for (double y = -10.0; y <= 10.0; y += 1.0) {
      if (!(x == 0.0 && y < 0.0)) {
        ck_assert_ldouble_le_tol(fabsl(pow(x, y) - my_pow(x, y)), my_M6,
                                 my_M6);
      }
    }
  }
  ck_assert_ldouble_nan(my_pow(-1.123, -1.123));
  ck_assert_ldouble_nan(my_pow(-1, 2.2));
  ck_assert_ldouble_infinite(my_pow(0, -1));
  ck_assert_ldouble_eq_tol(pow(-11, 2), my_pow(-11, 2), my_M6);
  ck_assert_ldouble_eq_tol(pow(-1.1, 3), my_pow(-1.1, 3), my_M6);
  ck_assert_ldouble_eq_tol(pow(5, -2.2), my_pow(5, -2.2), my_M6);
}
END_TEST

START_TEST(my_sin_test) {
  for (double x = -my_PI * 8; x <= my_PI * 8; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(sin(x) - my_sin(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_sin(my_INFINITY));
  ck_assert_ldouble_eq_tol(sin(my_PI), my_sin(my_PI), my_M6);
  ck_assert_ldouble_eq_tol(sin(-my_PI), my_sin(-my_PI), my_M6);
}
END_TEST

START_TEST(my_sqrt_test) {
  for (double x = 0.0; x <= 57.154623; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(sqrt(x) - my_sqrt(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_sqrt(-2.0));
}
END_TEST

START_TEST(my_tan_test) {
  for (double x = -my_PI / 2 + 0.1; x <= my_PI / 2 - 0.1; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - my_tan(x)), my_M6, my_M6);
  for (double x = 8.0 * -my_PI / 2 + 0.1; x <= -6 * my_PI / 2 - 0.1;
       x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - my_tan(x)), my_M6, my_M6);
  for (double x = -5.0 * -my_PI / 2 + 0.1; x <= 6.0 * my_PI / 2 - 0.1;
       x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - my_tan(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_tan(my_INFINITY));
  ck_assert_ldouble_eq_tol(tan(my_PI / 2), my_tan(my_PI / 2), my_M6);
  ck_assert_ldouble_eq_tol(tan(-my_PI / 2), my_tan(-my_PI / 2), my_M6);
  ck_assert_ldouble_eq_tol(tan(0), my_tan(0), my_M6);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("my_math.h tests");
  TCase *tc1_1 = tcase_create("Comparsions with math.h functions");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, my_abs_test);
  tcase_add_test(tc1_1, my_acos_test);
  tcase_add_test(tc1_1, my_asin_test);
  tcase_add_test(tc1_1, my_atan_test);
  tcase_add_test(tc1_1, my_ceil_test);
  tcase_add_test(tc1_1, my_cos_test);
  tcase_add_test(tc1_1, my_exp_test);
  tcase_add_test(tc1_1, my_fabs_test);
  tcase_add_test(tc1_1, my_floor_test);
  tcase_add_test(tc1_1, my_fmod_test);
  tcase_add_test(tc1_1, my_log_test);
  tcase_add_test(tc1_1, my_pow_test);
  tcase_add_test(tc1_1, my_sin_test);
  tcase_add_test(tc1_1, my_sqrt_test);
  tcase_add_test(tc1_1, my_tan_test);

  srunner_set_log(sr, "tests.txt");
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
