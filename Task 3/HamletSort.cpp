//
// Created by Stas on 29.08.2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HamletSort.h"

char** readHamlet(char* filePath, int nStrings, int maxString)
{
    FILE* fileHamlet = fopen(filePath, "r");

    printf("%d %d\n", nStrings, maxString);

    char** textHamlet = (char**) calloc(nStrings, sizeof (char*));

    for (int string = 0; string < nStrings; ++string) {
        textHamlet[string] = (char*) calloc(maxString, sizeof (char));
        fgets(textHamlet[string], maxString, fileHamlet);
    }

    fclose(fileHamlet);
    return textHamlet;
}

void writeHamlet(char* filePath, char** textHamlet, int nStrings)
{
    FILE* outputHamlet = fopen(filePath, "w");

    for (int string = 0; string < nStrings; ++string) {
        fputs(textHamlet[string], outputHamlet);
    }

    free(textHamlet);
    fclose(outputHamlet);
}

void swapStrings(char* firstString, char* secondString, int maxString)
{
    char tempStr[maxString] = {};

    strcpy(tempStr, firstString);
    strcpy(firstString, secondString);
    strcpy(secondString, tempStr);
}

int countStrings(char* filePath)
{
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

int findMaxString(char* filePath)
{
    FILE* fileHamlet = fopen(filePath, "r");

    int maxString = 0;
    int curString = 0;
    char currentSymbol = 0;

    while ((currentSymbol = fgetc(fileHamlet)) != EOF) {
        if (currentSymbol == '\n') {
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

void bubbleHamletSort(char** textHamlet, int nStrings, int maxString)
{
    for (int i = 0; i < nStrings; ++i) {
        for (int j = i + 1; j < nStrings; ++j) {
            if (strcmp(textHamlet[i], textHamlet[j]) > 0) {
                swapStrings(textHamlet[i], textHamlet[j], maxString);
            }
        }
    }
}
