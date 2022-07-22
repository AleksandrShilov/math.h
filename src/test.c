/*
 * TEST FILE
 */

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "s21_math.h"

#define s21_M6 1e-06
#define s21_16 1e16

START_TEST(s21_abs_test) {
  for (int i = -5000; i < 5000; i++) ck_assert_int_eq(abs(i), s21_abs(i));
  ck_assert_int_eq(abs(INT_MIN), s21_abs(INT_MIN));
  ck_assert_int_eq(abs(INT_MAX), s21_abs(INT_MAX));
}
END_TEST

START_TEST(s21_acos_test) {
  for (double x = -1.0; x <= 1.0; x += 0.15)
    ck_assert_ldouble_le_tol(fabsl(acos(x) - s21_acos(x)), s21_M6, s21_M6);
  ck_assert_ldouble_eq_tol(acos(1), s21_acos(1), s21_M6);
  ck_assert_ldouble_eq_tol(acos(0), s21_acos(0), s21_M6);
  ck_assert_ldouble_nan(s21_acos(s21_INFINITY));
  ck_assert_ldouble_eq_tol(acos(0.7071067811865475244), s21_acos(0.7071067811865475244), s21_M6);
  ck_assert_ldouble_eq_tol(acos(-0.7071067811865475244), s21_acos(-0.7071067811865475244), s21_M6);
}
END_TEST

START_TEST(s21_asin_test) {
  for (double x = -1.0; x <= 1.0; x += 0.15)
    ck_assert_ldouble_le_tol(fabsl(asin(x) - s21_asin(x)), s21_M6, s21_M6);
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), s21_M6);
  ck_assert_ldouble_nan(s21_asin(s21_INFINITY));
  ck_assert_ldouble_eq_tol(asin(0.7071067811865475244), s21_asin(0.7071067811865475244), s21_M6);
  ck_assert_ldouble_eq_tol(asin(-0.7071067811865475244), s21_asin(-0.7071067811865475244), s21_M6);
}
END_TEST

START_TEST(s21_atan_test) {
  for (double x = -100.4; x <= 100.4; x += 0.3123)
    ck_assert_ldouble_le_tol(fabsl(atan(x) - s21_atan(x)), s21_M6, s21_M6);
  ck_assert_ldouble_eq_tol(atan(1), s21_atan(1), s21_M6);
  ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), s21_M6);
  ck_assert_ldouble_eq_tol(atan(s21_PI / 2), s21_atan(s21_PI / 2), s21_M6);
  ck_assert_ldouble_eq_tol(atan(-s21_PI / 2), s21_atan(-s21_PI / 2), s21_M6);
}
END_TEST

START_TEST(s21_ceil_test) {
  for (double x = -14567; x <= -14567; x += 0.01)
    ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), s21_M6);
  ck_assert_ldouble_eq_tol(ceil(DBL_MIN), s21_ceil(DBL_MIN), s21_M6);
  ck_assert_ldouble_eq_tol(ceil(DBL_MAX - 1), s21_ceil(DBL_MAX - 1), s21_M6);
}
END_TEST

START_TEST(s21_cos_test) {
  for (double x = -s21_PI * 8; x <= s21_PI * 8; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(cos(x) - s21_cos(x)), s21_M6, s21_M6);
  ck_assert_ldouble_nan(s21_cos(s21_INFINITY));
}
END_TEST

START_TEST(s21_exp_test) {
  for (double x = -20; x <= 20; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(exp(x) - s21_exp(x)), s21_M6, s21_M6);
  ck_assert_ldouble_infinite(s21_exp(s21_INFINITY));
  ck_assert_ldouble_eq_tol(exp(-s21_INFINITY), s21_exp(-s21_INFINITY), s21_M6);
}
END_TEST

START_TEST(s21_fabs_test) {
  for (double x = -500.123; x <= 500.123; x += 0.5)
    ck_assert_ldouble_le_tol(fabsl(fabs(x) - s21_fabs(x)), s21_M6, s21_M6);
  ck_assert_ldouble_eq_tol(fabs(DBL_MIN), s21_fabs(DBL_MIN), s21_M6);
  ck_assert_ldouble_eq_tol(fabs(DBL_MAX), s21_fabs(DBL_MAX), s21_M6);
}
END_TEST

START_TEST(s21_floor_test) {
  for (double x = -500.0; x <= 500.0; x += 0.5)
    ck_assert_ldouble_eq_tol(floor(x), s21_floor(x), s21_M6);
  ck_assert_ldouble_eq_tol(floor(DBL_MIN - 1), s21_floor(DBL_MIN - 1), s21_M6);
  ck_assert_ldouble_eq_tol(floor(DBL_MAX), s21_floor(DBL_MAX), s21_M6);
}
END_TEST

START_TEST(s21_fmod_test) {
  for (double x = -500.123; x <= 500.123; x += 0.5)
    for (double y = -1000.246; x <= 1000.246; x += 0.5)
      ck_assert_ldouble_le_tol(fabsl(fmod(x, y) - s21_fmod(x, y)), s21_M6,
                               s21_M6);
  ck_assert_ldouble_nan(s21_fmod(2, 0.0));
}
END_TEST

START_TEST(s21_log_test) {
  for (double x = 0.0001; x <= 200.555; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(log(x) - s21_log(x)), s21_M6, s21_M6);
  ck_assert_ldouble_nan(s21_log(-2.0));
  ck_assert_ldouble_infinite(s21_log(0));
}
END_TEST

START_TEST(s21_pow_test) {
  for (double x = -10.12; x <= 10.12; x += 0.1) {
    for (double y = 0.0; y <= 5.0; y += 1) {
      ck_assert_ldouble_le_tol(fabsl(pow(x, y) - s21_pow(x, y)), s21_M6,
                               s21_M6);
    }
  }
  for (double x = -10.0; x <= 10.0; x += 1.0) {
    for (double y = -10.0; y <= 10.0; y += 1.0) {
      if (!(x == 0.0 && y < 0.0)) {
        ck_assert_ldouble_le_tol(fabsl(pow(x, y) - s21_pow(x, y)), s21_M6,
                                 s21_M6);
      }
    }
  }
  ck_assert_ldouble_nan(s21_pow(-1.123, -1.123));
  ck_assert_ldouble_nan(s21_pow(-1, 2.2));
  ck_assert_ldouble_infinite(s21_pow(0, -1));
  ck_assert_ldouble_eq_tol(pow(-11, 2), s21_pow(-11, 2), s21_M6);
  ck_assert_ldouble_eq_tol(pow(-1.1, 3), s21_pow(-1.1, 3), s21_M6);
  ck_assert_ldouble_eq_tol(pow(5, -2.2), s21_pow(5, -2.2), s21_M6);
}
END_TEST

START_TEST(s21_sin_test) {
  for (double x = -s21_PI * 8; x <= s21_PI * 8; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(sin(x) - s21_sin(x)), s21_M6, s21_M6);
  ck_assert_ldouble_nan(s21_sin(s21_INFINITY));
  ck_assert_ldouble_eq_tol(sin(s21_PI), s21_sin(s21_PI), s21_M6);
  ck_assert_ldouble_eq_tol(sin(-s21_PI), s21_sin(-s21_PI), s21_M6);
}
END_TEST

START_TEST(s21_sqrt_test) {
  for (double x = 0.0; x <= 57.154623; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(sqrt(x) - s21_sqrt(x)), s21_M6, s21_M6);
  ck_assert_ldouble_nan(s21_sqrt(-2.0));
}
END_TEST

START_TEST(s21_tan_test) {
  for (double x = -s21_PI / 2 + 0.1; x <= s21_PI / 2 - 0.1; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - s21_tan(x)), s21_M6, s21_M6);
  for (double x = 8.0 * -s21_PI / 2 + 0.1; x <= -6 * s21_PI / 2 - 0.1;
       x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - s21_tan(x)), s21_M6, s21_M6);
  for (double x = -5.0 * -s21_PI / 2 + 0.1; x <= 6.0 * s21_PI / 2 - 0.1;
       x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - s21_tan(x)), s21_M6, s21_M6);
  ck_assert_ldouble_nan(s21_tan(s21_INFINITY));
  ck_assert_ldouble_eq_tol(tan(s21_PI / 2), s21_tan(s21_PI / 2), s21_M6);
  ck_assert_ldouble_eq_tol(tan(-s21_PI / 2), s21_tan(-s21_PI / 2), s21_M6);
  ck_assert_ldouble_eq_tol(tan(0), s21_tan(0), s21_M6);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_math.h tests");
  TCase *tc1_1 = tcase_create("Comparsions with math.h functions");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_abs_test);
  tcase_add_test(tc1_1, s21_acos_test);
  tcase_add_test(tc1_1, s21_asin_test);
  tcase_add_test(tc1_1, s21_atan_test);
  tcase_add_test(tc1_1, s21_ceil_test);
  tcase_add_test(tc1_1, s21_cos_test);
  tcase_add_test(tc1_1, s21_exp_test);
  tcase_add_test(tc1_1, s21_fabs_test);
  tcase_add_test(tc1_1, s21_floor_test);
  tcase_add_test(tc1_1, s21_fmod_test);
  tcase_add_test(tc1_1, s21_log_test);
  tcase_add_test(tc1_1, s21_pow_test);
  tcase_add_test(tc1_1, s21_sin_test);
  tcase_add_test(tc1_1, s21_sqrt_test);
  tcase_add_test(tc1_1, s21_tan_test);

  srunner_set_log(sr, "tests.txt");
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
