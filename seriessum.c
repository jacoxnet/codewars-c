#include <stdio.h>

int get_sum(int a , int b) {
    int low = (a < b)? a : b;
    int high = (a > b)? a : b;
    int sum = 0;
    for (int i = low; i <= high; i++) {
        sum += i;
    }
    return sum;
}

main() {
    printf("%d, %d: %d\n", 1, 0, get_sum(1, 0));
    printf("%d, %d: %d\n", 1, 2, get_sum(1, 2));
    printf("%d, %d: %d\n", 0, 1, get_sum(0, 1));
    printf("%d, %d: %d\n", 1, 1, get_sum(1, 1));
    printf("%d, %d: %d\n", -1, 0, get_sum(-1, 0));
    printf("%d, %d: %d\n", -1, 2, get_sum(-1, 2));

}