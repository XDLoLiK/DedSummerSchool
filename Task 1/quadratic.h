//
// Created by Stas on 25.08.2021.
//

#ifndef TEST_QUADRATIC_H
#define TEST_QUADRATIC_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <iso646.h>

enum RootsStatus {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

int SolveQuadratic(double a_coeff, double b_coeff, double c_coeff, double* root_1, double* root_2);
int SolveLinear(double b_coeff, double c_coeff, double* root);
void ShowRoots(int num_of_roots, double root_1, double root_2);
int ScanCoefficients(double* a_coeff_pointer, double* b_coeff_pointer, double* c_coeff_pointer);
bool DoubleIsZero(double num);

const double PRECISION = 1e-9;

#endif //TEST_QUADRATIC_H

