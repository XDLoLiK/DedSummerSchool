/**
 * @author Stas Goryainov
 * @date 29/08/2021
 * @version 1.0
 *
 * @file
 * @short Library for working with strings
 */

#include <stdio.h>
#include <assert.h>
#include "myString.h"

/**
 * Puts a string and a new line symbol on the screen
 * @param[in] stringPtr pointer to the string to print
 * @return 0 if printing is successful, EOF otherwise
 */

int myPuts(const char* string)
{
    if (!string) return EOF;

    while (*string) printf("%c", *string++); //!! мистер Принтфец
    printf("\n");

    return 0;
}

/**
 * Finds the first location of a character in a string
 * @param[in] stringPtr pointer to the string to search in
 * @param[in] symbol a symbol to find
 * @return pointer to the symbol if found, nullptr otherwise
 */

char* myStrchr(char* stringPtr, char symbol)
{
    assert(stringPtr != nullptr);

    while (!stringEnd(stringPtr)) {
        if (*stringPtr == symbol) return stringPtr;
        ++stringPtr;
    }

    return nullptr;
}

/**
 * Computes the length of the string including the null-terminator
 * @param[in] stringPtr a pointer to the string
 * @return the length of the string
 */

size_t myStrlen(const char* stringPtr)
{
    assert(stringPtr != nullptr);

    size_t nSymbols = 0;

    while (!stringEnd(stringPtr++)) nSymbols++;

    return nSymbols + 1; // number of printable symbols + '\0' symbol
}

/**
 * Copies a string to the chosen location
 * @param[in] srcString pointer to the string to copy
 * @param[in,out] destString pointer to the future copied string location
 * @return pointer to the destination string
 */

char* myStrcpy(const char* srcString, char* destString)
{
    assert(srcString  != nullptr);
    assert(destString != nullptr);

    while (!stringEnd(srcString))
        *destString++ = *srcString++;

    *destString = '\0';
    return destString;
}

/**
 * Copies first n symbols of the string
 * @param[in] srcString pointer to the string to copy
 * @param[in,out] destString pointer to the future copied string location
 * @param[in] nSymbols the number of symbols to copy
 * @return pointer to the destination string
 */

char* myStrncpy(const char* srcString, char* destString, size_t nSymbols)
{
    assert(srcString != nullptr);
    assert(destString != nullptr);

    int offset = 0;

    for (; offset < nSymbols; ++offset) {

        if (stringEnd(&srcString[offset]))
            break;
        else
            destString[offset] = srcString[offset];
    }

    destString[offset] = '\0';
    return destString;
}

/**
 * Concatenates two strings (adds the first one to the end of the second)
 * @param[in] srcString pointer to the source string
 * @param[in,out] destString pointer to the destination string
 * @return pointer to the destination string
 */

char* myStrcat(char* destString, const char* srcString)
{
    assert(srcString != nullptr);
    assert(destString != nullptr);

    myStrcpy(srcString, destString + myStrlen(destString) - 1);
    return destString;
}

/**
 * Puts first n symbols of the first string to the end of the second
 * @param[in] srcString pointer to the source string
 * @param[in,out] destString pointer to the destination string
 * @param[in] nSymbols number of symbols to concatenate
 * @return pointer to the destination string
 */

char* myStrncat(char* destString, const char* srcString, size_t nSymbols)
{
    assert(srcString  != nullptr);
    assert(destString != nullptr);

    myStrncpy(srcString, destString + myStrlen(destString) - 1, nSymbols);
    return destString;
}

/**
 * Scans string from a file (until it meets new line sign)
 * @param[in,out] stringPtr pointer to the container string
 * @param[in] nSymbols max number of symbols to read
 * @param[in] sourceFile source file path
 * @return pointer to the destination string
 */

char* myFgets(FILE* sourceFile, char* stringPtr, int nSymbols)
{
    assert(stringPtr != nullptr);
    assert(sourceFile != nullptr);

    int offset = 0;
    char curSymbol = 0;
    fscanf(sourceFile, "%c", &curSymbol);

    for (; offset < nSymbols; ++offset) {

        if (curSymbol == EOF) {
            break;
        }
        else if(curSymbol == '\n') {
            stringPtr[offset++] = curSymbol;
            break;
        }
        else {
            stringPtr[offset] = curSymbol;
            fscanf(sourceFile, "%c", &curSymbol);
        }
    }

    stringPtr[offset] = '\0';
    return stringPtr;
}

/**
 * Duplicates a string
 * @param[in] stringPtr pointer to the source string
 * @return pointer to the duplicate's location
 */

char* myStrdup(const char* stringPtr)
{
    char* duplicatePtr = (char*) calloc(myStrlen(stringPtr), sizeof (char));
    myStrcpy(stringPtr, duplicatePtr);
    return duplicatePtr;
}

/**
 * Scans the data from the file until the separator is met
 * @param[in] sourceFile pointer to the file to scan
 * @param[in,out] destPtr the pointer to the destination string
 * @param[in] separator the separator symbol
 * @return pointer to the destination string
 */

char* myGetline(FILE* sourceFile, char* destPtr, char separator)
{
    assert(destPtr    != nullptr);
    assert(sourceFile != nullptr);

    int offset = 0;
    char curSymbol = 0;
    fscanf(sourceFile, "%c", &curSymbol);

    while (curSymbol != separator) {

        if (curSymbol == EOF) {
            break;
        }
        else {
            destPtr[offset++] = curSymbol;
            fscanf(sourceFile, "%c", &curSymbol);
        }
    }

    destPtr[offset] = '\0';
    return destPtr;
}

/**
 * Checks if it's the end of the string or not
 * @param[in] stringPtr
 * @return whether if it's the end of string or not
 */

bool stringEnd(const char* symbolPtr)
{
    return !*symbolPtr;
}

