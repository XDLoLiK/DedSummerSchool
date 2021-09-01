#ifndef HAMLET_HAMLETSORT_H
#define HAMLET_HAMLETSORT_H

char** readHamlet(char* filePath, int nStrings, int maxString);
int findMaxString(char* filePath);
int countStrings(char* filePath);
void bubbleHamletSort(char** textHamlet, int nStrings, int maxString);
void writeHamlet(char* filePath, char** textHamlet, int nStrings);

#endif //HAMLET_HAMLETSORT_H
