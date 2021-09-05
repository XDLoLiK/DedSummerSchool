/**
 * @file HamletSort.cpp
 *
 * Contains declarations of text sorting functions
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HamletSort.h"

/**
 * Scan the file with the source text and saves it in a buffer
 * @param[in] filePath path to the file
 * @param[in] nStrings number of strings in the file
 * @param[in] maxString max string length
 * @return pointer to the buffer
 */

char** readHamlet(char* filePath, int nStrings, int maxString)
{
    assert(filePath != nullptr);

    FILE* fileHamlet = fopen(filePath, "r");

    char** textHamlet = (char**) calloc(nStrings, sizeof (char*));

    for (int string = 0; string < nStrings; ++string) {
        textHamlet[string] = (char*) calloc(maxString, sizeof (char));
        fgets(textHamlet[string], maxString, fileHamlet);
    }

    fclose(fileHamlet);
    return textHamlet;
}

/**
 * Creates a new file where puts the sorted version of the source text
 * @param[in] filePath path to the file to write in
 * @param[in] textHamlet pointer to the buffer with the sorted text
 * @param[in] nStrings the number of strings in the file
 */

void writeHamlet(char* filePath, char** textHamlet, int nStrings)
{
    assert(textHamlet != nullptr);
    assert(filePath != nullptr);

    FILE* outputHamlet = fopen(filePath, "w");

    for (int string = 0; string < nStrings; ++string) {
        fprintf(outputHamlet, "%s", textHamlet[string]);
    }

    free(textHamlet);
    fclose(outputHamlet);
}

/**
 * Swaps two strings
 * @param[in,out] firstString pointer to the first string
 * @param[in,out] secondString pointer to the second string
 * @param[in] maxString the length of the longest string
 */

void swapStrings(char* firstString, char* secondString, int maxString)
{
    assert(firstString != nullptr);
    assert(secondString != nullptr);
    assert(maxString > 0);

    char tempStr[maxString] = {};

    strcpy(tempStr, firstString);
    strcpy(firstString, secondString);
    strcpy(secondString, tempStr);
}

/**
 * Counts the number of strings in a file
 * @param[in] filePath the path to the source file
 * @return the number of strings
 */

int countStrings(char* filePath)
{
    assert(filePath != nullptr);

    FILE* fileHamlet = fopen(filePath, "r");

    int counter = 0;
    char currentSymbol = 0;

    while ((currentSymbol = fgetc(fileHamlet)) != EOF) {
        if (currentSymbol == '\n') {
            ++counter;
        }
    }

    fclose(fileHamlet);
    return counter + 1; // the last line doesn't have the \n symbol
}

/**
 * Finds the largest string in the file
 * @param[in] filePath the path to the source file
 * @return the length of the largest string
 */

int findMaxString(char* filePath)
{
    assert(filePath != nullptr);

    FILE* fileHamlet = fopen(filePath, "r");

    int maxString = 0;
    int curString = 0;
    char currentSymbol = 0;

    while ((currentSymbol = fgetc(fileHamlet)) != EOF) {
        if (currentSymbol == '\n') {
            ++curString;
            maxString = (curString > maxString) ? curString : maxString;
            curString = 0;
        }
        else {
            ++curString;
        }
    }

    maxString = (curString > maxString) ? curString : maxString;
    fclose(fileHamlet);
    return maxString + 1; // + '\0' symbol
}

/**
 * Sorts the file using the bubble sort applied to the strings
 * @param[in,out] textHamlet the pointer to the buffer
 * @param[in] nStrings the number of the strings
 * @param[in] maxString the length of the largest string
 */

void bubbleHamletSort(char** textHamlet, int nStrings, int maxString)
{
    assert(textHamlet != nullptr);

    for (int i = 0; i < nStrings; ++i) {
        for (int j = i + 1; j < nStrings; ++j) {
            if (strcmp(textHamlet[i], textHamlet[j]) > 0) {
                swapStrings(textHamlet[i], textHamlet[j], maxString);
            }
        }
    }
}
