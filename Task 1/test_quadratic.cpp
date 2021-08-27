/**
 * @file
 * @brief Provides Unit Tests
 *
 * Contains definitions of all the test functions
 */

#include <math.h>
#include <assert.h>

#include "test_quadratic.h"
#include "quadratic.h"

/**
 * Tests SolveQuadratic function
 * @return number of failed tests or file error
 */

int QuadraticUnitTests()
{
    char file_path[100] = "";

    if (not ScanFilePath(file_path)) {
        return SCAN_FAIL;
    }

    FILE* TestData = fopen(file_path, "r");

    if (not TestData) {
        printf("Can't access the file %s. Try again.\n", file_path);
        return NOT_EXISTING_FILE;
    }

    int testsFailed = 0;
    int testNumber = 1;

    while (not feof(TestData)) {
        if (not UnitTest(TestData, testNumber)) {
            testsFailed++;
        }
        testNumber++;
    }

    fclose(TestData);
    return testsFailed;
}

/**
 * Get test file path
 * @param[in,out] path file path container (pointer)
 * @return number of successfully scanned variables
 */

int ScanFilePath(char* path)
{
    assert(path != nullptr);

    printf("Enter the file path to test: ");
    return scanf("%s", path);
}

/**
 * Results the work of QuadraticUnitTests function
 * @param[in] nFailed the number of test failed
 */

void ShowTestsResults(int nFailed)
{
    switch (nFailed) {
        case SCAN_FAIL:
            printf("Program was unable to scan the path. Please, try again\n");
            break;
        case NOT_EXISTING_FILE:
            printf("There's no such directory. Check if everything is correct\n");
            break;
        default:
            printf("%d tests failed\n\n", nFailed);
            break;
    }
}

/**
 * Checks if two variables are equal (considering NANs and precision)
 * @param correctAns the expected result
 * @param realAns result the function got
 * @return the whether teo variables are equal or not
 */

bool areEqual(double correctAns, double realAns)
{
    if (isnan(correctAns)) {
        if (isnan(realAns)) {
            return true;
        }
        return false;
    }
    return (fabs(correctAns - realAns) < PRECISION);
}

/**
 * Provides the test
 * @param test_file test file path
 * @param testN the number of the current test
 * @return the whether test is failed or passed
 */

int UnitTest(FILE* testFile, int testN)
{
    printf("Running test #%d\n", testN);
    // Coefficients
    double a = NAN, b = NAN, c = NAN;
    if (getCoeffs(testFile, &a, &b, &c) != 3) {
        printf("Scan faield");
        return TEST_FAILED;
    }

    // Real answers
    double x1 = NAN, x2 = NAN; ///x1 and x2 get their values from Solve Quadratic
    int rootsN = SolveQuadratic(a, b, c, &x1, &x2);

    // Reference args
    double x1_ref = NAN, x2_ref = NAN;
    int rootsN_ref = 0;
    getRefArgs(testFile, &rootsN_ref, &x1_ref, &x2_ref);

    if (CorrectAnswer(rootsN, x1, x2, rootsN_ref, x1_ref, x2_ref)) {
        printf("PASSED\n\n");
        return TEST_PASSED;
    } else {
        printf("FAILED\n");
        printf("COEFFICIENTS: %.2lf, %.2lf, %.2lf\n", a, b, c);
        printf("EXPECTED: %d roots, x1 = %.2lf, x2 = %.2lf\n", rootsN_ref, x1_ref, x2_ref);
        printf("GOT: %d roots, x1 = %.2lf, x2 = %.2lf\n\n", rootsN, x1, x2);
        return TEST_FAILED;
    }
}

/**
 * Gets new coefficients from the file
 * @param a a coefficient of the equation
 * @param b b coefficient of the equation
 * @param c c coefficient of the equation
 */

int getCoeffs(FILE* file, double* a, double* b, double* c)
{
    return fscanf(file, "%lf %lf %lf", a, b, c);
}

/**
 * Gets reference data from the file
 * @param roots_n reference roots number
 * @param x1 reference first root value
 * @param x2 reference second root value
 */

void getRefArgs(FILE* file, int* rootsN, double* x1, double* x2)
{
    // Get roots number
    fscanf(file, "%d", rootsN);

    // Get roots
    if (*rootsN == 0 or *rootsN == INF_ROOTS) {
        *x1 = NAN;
        *x2 = NAN;
        return;
    } else if (*rootsN == 1) {
        fscanf(file, "%lf", x1);
        *x2 = NAN;
    } else {
        fscanf(file, "%lf", x1);
        fscanf(file, "%lf", x2);
    }
}

/**
 * Checks if real answers match expected ones
 * @param nRoots real number of roots
 * @param root1 real value of root 1
 * @param root2  real value of root 2
 * @param nRoots_ref reference number of roots
 * @param root1_ref reference value of the first root
 * @param root2_ref reference value of the second root
 * @return whether the answer is correct or not
 */

bool CorrectAnswer(int nRoots, double root1, double root2,
                   int nRoots_ref, double root1_ref, double root2_ref)
{
    return (nRoots_ref == nRoots and areEqual(root1, root1_ref) and areEqual(root2, root2_ref)) or
           (nRoots_ref == nRoots and areEqual(root1, root2_ref) and areEqual(root2, root1_ref));
}
