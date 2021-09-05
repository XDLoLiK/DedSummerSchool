/**
 * @file main.cpp
 *
 * @author Stas Goryainov
 * @date 04/09/2021
 * @version 1.2
 */

#include <stdio.h>
#include "HamletSort.h"

int main() {

    char filePath[100] = {};
    printf("Enter the file path (to read): ");

    if (!scanf("%s", filePath)) {
        printf("Ooops.. Something went wrong( Try again");
    }

    int nStrings = countStrings(filePath);
    int maxString = findMaxString(filePath);

    char** textHamlet = readHamlet(filePath, nStrings, maxString);
    bubbleHamletSort(textHamlet, nStrings, maxString);

    printf("Enter the file path (to write in): ");

    if (!scanf("%s", filePath)) {
        printf("Ooops.. Something went wrong( Try again");
    }

    writeHamlet(filePath, textHamlet, nStrings);

    return 0;
}
