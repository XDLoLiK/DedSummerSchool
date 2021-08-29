/**
 * @file
 * @brief Header file for myString.cpp
 */

#ifndef STDSTRING_MYSTRING_H
#define STDSTRING_MYSTRING_H

int myPuts(const char* string);
char* myStrchr(char* stringPtr, char symbol);
size_t myStrlen(const char* stringPtr);
char* myStrcpy(const char* srcString, char* destString);
char* myStrncpy(const char* srcString, char* destString, size_t nSymbols);
char* myStrcat(char* destString, const char* srcString);
char* myStrncat(char* destString, const char* srcString, size_t nSymbols);
bool stringEnd(const char* symbolPtr);
char* myFgets(FILE* sourceFile, char* stringPtr, int nSymbols);
char* myStrdup(const char* stringPtr);
char* myGetline(FILE* sourceFile, char* destPtr, char separator);

#endif // STDSTRING_MYSTRING_H
