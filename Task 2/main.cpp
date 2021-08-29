#include <stdio.h>
#include "myString.h"

int main() {
    char str0[10] = {'f', 'o', 'o', '\0'};
    char str1[10] = {'h', 'i', '\0'};
    char str2[10] = {'h', 'e', 'y', ' ', '\0'};
    char str3[10] = {};
    myPuts(str1);
    printf("%c\n", *myStrchr(str2, 'e'));
    printf("%zd\n", myStrlen(str1));
    printf("%s\n", myStrcat(str2, str1));
    myStrcpy(str1, str3);
    printf("%s\n", str3);
    myStrncpy(str0, str3, 2);
    printf("%s\n", str3);
    printf("%s\n", myStrncat(str1, str3, 1));
    myFgets(stdin, str3, 10);
    printf("%s", str3);
    char* ptr = myStrdup(str3);
    printf("%s", ptr);
    myGetline(stdin, str3, 'o');
    printf("%s", str3);
    return 0;
}
