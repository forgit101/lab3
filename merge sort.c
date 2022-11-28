#include <stdio.h>
 void merge(int *array, int left, int mid, int right){

    int it1 = 0;
    int it2 = 0;
    int result_array[right - left];

    while (left + it1 < mid && mid + it2 < right){
        if (array[left + it1] < array[mid + it2]){
            result_array[it1 + it2] = array[left + it1];
            it1 += 1;
        }
        else{
            result_array[it1 + it2] = array[mid + it2];
            it2 += 1;
        }
    }

    while (left + it1 < mid){
        result_array[it1 +it2] = array[left + it1];
        it1 += 1;
    }
    while (mid + it2 < right){
        result_array[it1 + it2] = array[mid + it2];
        it2 += 1;
    }
    for (int i = 0; i < it1 + it2; i++){
        array[left + i] = result_array[i];
    }
}

 void mergeSortRecursive (int *array, int left, int right){

     
    if (left + 1 < right){
     // int *array_address1 = &array;
     // int *array_address2 = &array;
        int mid = (left + right) / 2;
        mergeSortRecursive(array, left, mid);
        mergeSortRecursive(array, mid, right);
        merge(array, left, mid, right);
    }
    //return merge(array, left, mid, right);


}

int main() {
    int n;
    scanf("%d", &n);
    int array [n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    mergeSortRecursive(array, 0, n);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    //printf("%p", *array_after_merge);
    return 0;
}
