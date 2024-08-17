#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#define MAXLEN 254
char retS[MAXLEN];

// test whether char is letter
bool isLetter(const char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return true;
    }
    else if (letter >= 'A' && letter <= 'Z') {
        return true;
    }
    return false;
}

// print any letters following pointed-to letter using
// recursion and then print pointed-to letter
void revWord(const char *str) {
    char *ptr = str;
    if (!isLetter(*ptr)) {
        return;
    }
    else {
        char *savPlace = ptr;
        revWord(++ptr);
        sprintf(&retS[strlen(retS)], "%c%c", *savPlace, '\0');
        return;
    }        
}

// return index of next word
char *nextWord(const char *pword) {
    char *x = pword;
    while (isLetter(*x)) {
        x++;
    }
    return x;
}

char *reverseWords(char *text) {  
    strcpy(retS, ""); 
    char *pletter = text;
    while (*pletter != '\0') {
        if (isLetter(*pletter)) {
            revWord(pletter);
            pletter = nextWord(pletter);
        } else {
            sprintf(&retS[strlen(retS)], "%c%c", *pletter, '\0');
            pletter++;
        }
    }
    return retS;
}


int main() {
    // printf("\n");
    // strcpy(retS, "this is a test");
    // printf("%s\n", retS);
    // printf("%s\n", &retS[2]);
    printf("%s\n", reverseWords("Ab"));
    printf("%s\n", reverseWords("This is an example"));
    printf("%s\n", reverseWords("double  spaces"));
    return 0;
}