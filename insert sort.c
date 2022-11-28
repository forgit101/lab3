#include <stdio.h>

int main() {
    int size, key, i;
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    for (int j = 1; j < size; j++){
        key = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > key){
            array[i+1] = array[i];
            i -= 1;
        }
        array[i+1] = key;
    }

    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}