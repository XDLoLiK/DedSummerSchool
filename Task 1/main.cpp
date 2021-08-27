/**
 * @author Stas Goryainov
 * @version 1.0
 * @date 27/08/2021
 */

#include "quadratic.h"
#include "random_tests.h"
#include "test_quadratic.h"

#define TESTING
#ifdef TESTING

int main(int argc, char* argv[])
{
    ShowTestsResults(QuadraticUnitTests());

    int failedTests = RandomQuadraticTests();
    printf("%d tests failed\n", failedTests);

    return 0;
}

#else

/**
 * The main function of the program
 * @param[in] argc number of arguments the main function gets (1 at least)
 * @param argv array of arguments pointers
 * @return 0
 */

int main(int argc, char* argv[])
{
    printf("Quadratic solver by Stas\n");

    printf("Enter the coefficients in the following order (a, b, c): ");
    double a = NAN, b = NAN, c = NAN;

    if (!ScanCoefficients(&a, &b, &c)) {
        return 0;
    }

    double x1 = NAN, x2 = NAN;
    int nRoots = SolveQuadratic(a, b, c, &x1, &x2);

    ShowRoots(nRoots, x1, x2);
    printf("\n");

    return 0;
}

#endif // TESTING
