/**
 * @file
 * @brief Header file for quadratic.cpp
 *
 * This file contains constants, functions prototypes and standard libraries includes
 * mainly used in quadratic.cpp
 */

#ifndef TEST_QUADRATIC_H
#define TEST_QUADRATIC_H

#include <stdbool.h>
#include <math.h>

/// A group of all the possible roots quantity conditions
enum RootsStatus {
    INF_ROOTS      = -1, ///< Indicates the infinite number of roots
    NO_REAL_ROOTS  = 0, ///< Indicates the lack of real roots
    ONE_ROOT       = 1, ///< Shows if the equation has only ine root
    TWO_ROOTS      = 2 ///< Shows if the equation has two roots
};

extern const int ROOTS_NUM_ERROR;
extern const double PRECISION;

int SolveQuadratic(double a_coeff, double b_coeff, double c_coeff, double* root_1, double* root_2);
int SolveLinear(double b_coeff, double c_coeff, double* root);
void ShowRoots(int num_of_roots, double root_1, double root_2);
int ScanCoefficients(double* a_coeff_pointer, double* b_coeff_pointer, double* c_coeff_pointer);
bool EqualsZero(double value);

#endif //TEST_QUADRATIC_H

