#include "quadratic.h"

int main(void)
{
    printf("# Quadratic solver by Stas\n");

    printf("# Enter the coefficients in the following order (a, b, c): ");
    double a = 0, b = 0, c = 0;

    if (not ScanCoefficients(&a, &b, &c)) {
        return 0;
    }

    double x1 = 0, x2 = 0;
    int nRoots = SolveQuadratic(a, b, c, &x1, &x2);

    ShowRoots(nRoots, x1, x2);

    return 0;
}

int SolveQuadratic(double a_coeff, double b_coeff, double c_coeff, double* root_1, double* root_2)
{
    if (DoubleIsZero(a_coeff)) {
        return SolveLinear(b_coeff, c_coeff, root_1);
    }

    double discriminant = b_coeff * b_coeff - 4 * a_coeff * c_coeff;

    if (discriminant < 0) {
        return NO_ROOTS;
    } else if (DoubleIsZero(discriminant)) {
        *root_1 = -b_coeff / (2 * a_coeff);
        return ONE_ROOT;
    } else {
        double d_sqrt = sqrt(b_coeff * b_coeff - 4 * a_coeff * c_coeff);
        *root_1 = (-b_coeff + d_sqrt) / (2 * a_coeff);
        *root_2 = (-b_coeff - d_sqrt) / (2 * a_coeff);
        return TWO_ROOTS;
    }
}

int SolveLinear(double k_coeff, double b_coeff, double* root)
{

    if (DoubleIsZero(k_coeff)) {
        if (DoubleIsZero(b_coeff)) {
            return INF_ROOTS;
        } else {
            return NO_ROOTS;
        }
    }

    *root = -b_coeff / k_coeff;
    return ONE_ROOT;
}

void ShowRoots(int num_of_roots, double root_1, double root_2)
{
    switch (num_of_roots) {
        case INF_ROOTS:
            printf("# There's an infinite number of roots");
            break;
        case ONE_ROOT:
            printf("# %.2lf is the only root\n", root_1);
            break;
        case TWO_ROOTS:
            printf("# Hey! I've found 2 roots. Here they are: %.2lf and %.2lf\n", root_1, root_2);
            break;
        case NO_ROOTS:
            printf("# There are no roots");
            break;
        default:
            printf("# main() : ERROR");
            break;
    }
}

int ScanCoefficients(double* a_coeff_pointer, double* b_coeff_pointer, double* c_coeff_pointer)
{
    if (scanf("%lf %lf %lf", a_coeff_pointer, b_coeff_pointer, c_coeff_pointer) != 3) {
        printf("# Don't try to trick me, prick\n");
        return 0;
    }

    return 1;
}

bool DoubleIsZero(double num)
{
    return (fabs(num - 0) < PRECISION);
}
