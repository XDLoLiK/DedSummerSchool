/**
 * @file
 * @brief Header file for test_quadratic.cpp
 *
 * This file contains constants, functions prototypes and standard libraries includes
 * mainly used in test_quadratic.cpp
 */

#ifndef TEST_TEST_QUADRATIC_H
#define TEST_TEST_QUADRATIC_H

#include <stdio.h>

/// A group of possible test conditions
enum TestStatus {
    SCAN_FAIL         = -2, ///< If the program failed to scan the file
    NOT_EXISTING_FILE = -1, ///< If the file doesn't exist
    TEST_FAILED       =  0, ///< If test is failed
    TEST_PASSED       =  1  ///< If test has succeeded
};

int QuadraticUnitTests();
void ShowTestsResults(int nFailed);
int UnitTest(FILE* testFile,int testN);

int ScanFilePath(char* path);
bool areEqual(double correctAns, double realAns);

void getRefArgs(FILE* file, int* rootsN, double* x1, double* x2);
int getCoeffs(FILE* file, double* a, double* b, double* c);

bool CorrectAnswer(int nRoots, double root1, double root2,
                   int nRoots_ref, double root1_ref, double root2_ref);

#endif //TEST_TEST_QUADRATIC_H
