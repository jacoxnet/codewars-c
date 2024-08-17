#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *incstringnum(char *stringnum) {
    int length = strlen(stringnum);
    char *newstring = (char *) malloc(length * sizeof(char) + 2);
    int incnum;
    if (length == 0) {
        incnum = 1;
        length = 1;
    } else {
        incnum = atoi(stringnum) + 1;
    }
    char *code = (char *) malloc(length * sizeof(char) + 2);
    sprintf(code, "%c%c%d%c", '%', '0', length, 'd');
    sprintf(newstring, code, incnum);
    free(code);
    return newstring;
}

char *incrementString(const char *str)
{
    int length = strlen(str);
    char *stringpart;
    char *numpart;
    numpart = (char *) malloc(length * sizeof(char) + 1);
    stringpart = (char *) malloc(length * sizeof(char) + 1);
    int numstart = length;
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] >= '0' && str[i] <= '9') {
            numstart = i;
        } else {
            break;
        }
    }
    strncpy(stringpart, str, numstart);
    stringpart[numstart] = '\0';
    strncpy(numpart, &str[numstart], length - numstart);
    numpart[length - numstart] = '\0';
    char *code = "string '%s', num '%s', incnum '%s'\n";
    // printf(code, stringpart, numpart, incstringnum(numpart));
    return strcat(stringpart, incstringnum(numpart));

}

void main() {
    char *answer;
    answer = incrementString("foo");
    printf("answer: %s\n", answer);
    answer = incrementString("foobar23");
    printf("answer: %s\n", answer);
    answer = incrementString("foo0042");
    printf("answer: %s\n", answer);
    answer = incrementString("foo9");
    printf("answer: %s\n", answer);
    answer = incrementString("foo099");
    printf("answer: %s\n", answer);
    answer = incrementString("foo34d067");

}