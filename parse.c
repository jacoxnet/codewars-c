#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *parse (const char *program)
{
	// return a heap-allocated int array
	// its length shall be at least equal to
	// the count of 'o' commands in the program
    int *return_array;
    int return_array_len = 0;
    return_array = (int *) calloc(strlen(program), sizeof(int));
    int cur_val = 0;
    for (char *p = (char *) program; *p != '\0'; p++) {
        switch (*p) {
            case 'i': 
                cur_val++;
                break;
            case 'd':
                cur_val--;
                break;
            case 's':
                cur_val = cur_val * cur_val;
                break;
            case 'o':
                return_array[return_array_len++] = cur_val;
                break;
            default: ;
        }
    }
    return return_array;
}

int main() {
    char *testing = "iisdosodooisdosidod";
    int len = strlen(testing);
    int *ret; ret = parse(testing);
    for (int i = 0; i < len; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}