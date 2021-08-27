/**
 * @file
 * @brief Random test SolveQuadratic
 *
 * Contains random test functions definitions
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "quadratic.h"
#include "random_tests.h"

/**
 * Provides random numbers tests
 * @return Number of failed tests
 */

int RandomQuadraticTests()
{
    srand(time(NULL));

    int nTests = 0;
    printf("Enter the number of tests: ");
    scanf("%d", &nTests);

    int count = 1;
    int testsFailed = 0;

    while (count <= nTests) {
        if (!RandomTest(count)) {
            testsFailed++;
        }
        count++;
    }

    return testsFailed;
}

/**
 * Does one separate random test
 * @param[in] testN test number
 * @return 1 if test succeeded, 0 otherwise
 */

int RandomTest(int testN)
{
    double a = rand() * ((rand() % 2) ? 1 : -1);
    double b = rand() * ((rand() % 2) ? 1 : -1);
    double c = rand() * ((rand() % 2) ? 1 : -1);

    double x1 = NAN, x2 = NAN;

    int rootsN = SolveQuadratic(a, b, c, &x1, &x2);

    if (AnswerIsRight(rootsN, x1, x2, a, b, c)) {
        printf("a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);
        printf("TEST #%d PASSED\n\n", testN);
        return 1;
    } else {
        printf("TEST #%d FAILED\n", testN);
        printf("COEFFICIENTS: %.2lf, %.2lf, %.2lf\n", a, b, c);
        printf("ANSWERS: %d roots, x1 = %.2lf, x2 = %.2lf\n\n", rootsN, x1, x2);
        return 0;
    }
}

/**
 * Checks if answer given by function is right
 * @param[in] nRoots number of roots the function found
 * @param[in] root1 the first root function found
 * @param[in] root2 the second root function found
 * @param[in] aCoeff current a coefficient
 * @param[in] bCoeff current b coefficient
 * @param[in] cCoeff current c coefficient
 * @return whether answer is correct or not
 */

bool AnswerIsRight(int nRoots, double root1, double root2,
                   double aCoeff, double bCoeff, double cCoeff) {
    if (nRoots == INF_ROOTS) {
        return (EqualsZero(aCoeff) and EqualsZero(bCoeff) and EqualsZero(cCoeff));
    } else if (nRoots == NO_REAL_ROOTS) {
        return (!EqualsZero(root1*root1*aCoeff + bCoeff*root1 + cCoeff) and
                !EqualsZero(root2*root2*aCoeff + bCoeff*root2 + cCoeff));
    } else if (nRoots == ONE_ROOT) {
        return (EqualsZero(root1*root1*aCoeff + bCoeff*root1 + cCoeff) xor
                EqualsZero(root2*root2*aCoeff + bCoeff*root2 + cCoeff));
    } else if (nRoots == TWO_ROOTS) {
        return (EqualsZero(root1*root1*aCoeff + bCoeff*root1 + cCoeff) and
                EqualsZero(root2*root2*aCoeff + bCoeff*root2 + cCoeff));
    }

    printf("Incompatible number of roots");
    return false;
}
