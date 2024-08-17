char findMissingLetter(char array[], int arrayLength) {
    int arr_len = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < arr_len - 1; i++) {
        if (array[i + 1] - array[i] > 1) {
            return (char) (array[i] + 1);
        }
    }
}

