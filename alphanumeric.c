#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool alphanumeric(const char* strin) {

    if (strlen(strin) == 0) {
        return false;
    }
    for (char *p = strin; *p != '\0'; p++) {
        if ((*p >= 'a' && *p <= 'z') ||
            (*p >= 'A' && *p <= 'Z') ||
            (*p >= '0' && *p <= '9')) {
                continue;
            } else {
                return false;
            }
    }
    return true;
}

void main() {
    char *testing = "hello_world";
    printf("%s, %s\n", testing, alphanumeric(testing)? "true" : "false");
    testing = "PassW0rd";
    printf("%s, %s\n", testing, alphanumeric(testing)? "true" : "false");
    testing = ("     ");
    printf("%s, %s\n", testing, alphanumeric(testing)? "true" : "false");
    testing = ("a");
    printf("%s, %s\n", testing, alphanumeric(testing)? "true" : "false");
}