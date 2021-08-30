#include <stdio.h>
#include "HamletSort.h"

int main() {

    char filePath[100] = {};
    printf("Enter the file path: ");
    scanf("%s", filePath);

    int nStrings = countStrings(filePath);
    int maxString = findMaxString(filePath);

    char** textHamlet = readHamlet(filePath, nStrings, maxString);
    bubbleHamletSort(textHamlet, nStrings, maxString);

    printf("Enter the file path (to write): ");
    scanf("%s", filePath);
    writeHamlet(filePath, textHamlet, nStrings);

//    FILE* file = fopen(filePath, "w");
//    fputs("Hello, World!", file);
//    fclose(file);

    printf("%s", textHamlet[1002]);
    return 0;
}
