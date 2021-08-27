/**
 * @file
 * @brief Definition of all the quadratic functions
 *
 * Contains definitions of all the functions needed to solve the quadratic equation
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "quadratic.h"

const int ROOTS_NUM_ERROR = 228;
const double PRECISION = 1e-5;

/**
 * Solves a quadratic equations ax^2 + bx + c = 0
 * @param[in] a_coeff the a coefficient of the equation
 * @param[in] b_coeff the b coefficient of the equation
 * @param[in] c_coeff the c coefficient of the equation
 * @param[in,out] root_1 a pointer to the first root
 * @param[in,out] root_2 a pointer to the second root
 * @return The number of roots
 * @throw AssertionFault in case of a failed asert
 */

int SolveQuadratic(double a_coeff, double b_coeff, double c_coeff, double* root_1, double* root_2)
{
    assert(isfinite(a_coeff));
    assert(isfinite(b_coeff));
    assert(isfinite(c_coeff));

    assert(root_1 != nullptr);
    assert(root_2 != nullptr);
    assert(root_2 != root_1);

    if (EqualsZero(a_coeff)) {
        // *root_2 = *root_1;
        return SolveLinear(b_coeff, c_coeff, root_1);
    }

    if (EqualsZero(c_coeff)) {
        *root_1 = 0;
        if (EqualsZero(b_coeff)) {
            return ONE_ROOT;
        }
        if (SolveLinear(a_coeff, b_coeff, root_2) == ONE_ROOT)
            return TWO_ROOTS;

        return ROOTS_NUM_ERROR;
    }

    double discriminant = b_coeff * b_coeff - 4 * a_coeff * c_coeff;

    if (EqualsZero(discriminant)) {
        *root_1 = -b_coeff / (2 * a_coeff);
        return ONE_ROOT;
    } else if (discriminant < 0) {
        return NO_REAL_ROOTS;
    } else {
        double d_sqrt = sqrt(discriminant);
        *root_1 = (-b_coeff + d_sqrt) / (2 * a_coeff);
        *root_2 = (-b_coeff - d_sqrt) / (2 * a_coeff);
        return TWO_ROOTS;
    }
}

/**
 * Solves a linear equation kx + b = 0
 * @param[in] k_coeff the k coefficient of the equation
 * @param[in] b_coeff the b coefficient of the equation
 * @param[in,out] root pointer to the only root
 * @return The number of roots
 */

int SolveLinear(double k_coeff, double b_coeff, double* root)
{

    if (EqualsZero(k_coeff)) {
        if (EqualsZero(b_coeff)) {
            return INF_ROOTS;
        } else {
            return NO_REAL_ROOTS;
        }
    }

    *root = (EqualsZero(b_coeff)) ? 0 : -b_coeff / k_coeff;
    return ONE_ROOT;
}

/**
 * Shows a number of roots and the roots themselves on the screen
 * @param[in] num_of_roots the number of roots in the equation
 * @param[in] root_1 first root by value
 * @param[in] root_2 second root by value
 */

void ShowRoots(int num_of_roots, double root_1, double root_2)
{
    switch (num_of_roots) {
        case INF_ROOTS:
            printf("There's an infinite number of roots\n");
            break;
        case ONE_ROOT:
            printf("%.2lf is the only root\n", root_1);
            break;
        case TWO_ROOTS:
            printf("Hey! I've found 2 roots. Here they are: %.2lf and %.2lf\n", root_1, root_2);
            break;
        case NO_REAL_ROOTS:
            printf("There are no real roots\n");
            break;


        case ROOTS_NUM_ERROR:
            printf("Incompatible number of roots when c = 0\n");
            break;
        default:
            printf("main() : ERROR : nRoots = %d\n", num_of_roots);
            break;
    }
}

/**
 * Sets the a, b, c coefficients of the quadratic equation (keyboard input)
 * @param[in,out] a_coeff_pointer the a coefficient pointer
 * @param[in,out] b_coeff_pointer the b coefficient pointer
 * @param[in,out] c_coeff_pointer the c coefficient pointer
 * @return 1 if scan is successful, 0 otherwise
 */

int ScanCoefficients(double* a_coeff_pointer, double* b_coeff_pointer, double* c_coeff_pointer)
{
    assert(a_coeff_pointer != nullptr);
    assert(b_coeff_pointer != nullptr);
    assert(c_coeff_pointer != nullptr);

    if (scanf("%lf %lf %lf", a_coeff_pointer, b_coeff_pointer, c_coeff_pointer) != 3) {
        fflush(stdin);
        printf("Don't try to trick me, prick\n");
        return 0;
    }

    return 1;
}

/**
 * Checks if a float number is close enough to zero to consider it zero
 * @param[in] value a value to check
 * @return true if the number evaluates at zero, false otherwise
 */

bool EqualsZero(double value)
{
    return (fabs(value) < PRECISION);
}
