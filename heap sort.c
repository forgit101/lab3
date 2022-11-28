import java.util.Scanner;
public class Main {

    static void siftDown(int [] array, int size, int i) {
        int swap;
        int large = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int temporary_size_of_pyramid = size;

        if ( right < temporary_size_of_pyramid && array[right] > array[large]){
            large = right;
        }

        if ( left < temporary_size_of_pyramid && array[left] > array[large]){
            large = left;
        }

        if ( i != large ){
            swap = array[large];
            array[large] = array[i];
            array[i] = swap;

            siftDown(array, size, large);
        }
    }

    static void maxHeapify (int [] array, int i){
        int swap;
        int large = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if ( right < array.length && array[right] > array[large]){
            large = right;
        }

        if ( left < array.length && array[left] > array[large]){
            large = left;
        }

        if ( i != large){
            swap = array[large];
            array[large] = array[i];
            array[i] = swap;

            maxHeapify(array, large);
        }


    }

    static void buildHeap(int [] array){
        int last_parent = array.length;
        for (int i = last_parent; i > -1; i--) {
            maxHeapify(array, i);
        }
    }

    static void heapSort (int [] array, int n){
        buildHeap(array);
        int size = array.length;
        int swap;
        for (int i = 0; i < n; i++){
            swap = array[0];
            array[0] = array[n - 1 - i];
            array[n - 1 - i] = swap;
            size--;
            siftDown(array, size, 0);
        }
    }
    

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int [] array = new int [n];

        for (int i = 0; i < n; i++) {
            array[i] = in.nextInt();
        }

        heapSort(array, n);

        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", array[i]);
        }

    }
}
