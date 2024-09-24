int insertionSort(int *arr, int lo, int hi) {
    // [2,3,4,5,6,7,8,..., 1]
    // [n,1,2,3,4,5,6,...]
    int i, j, key;
    for (i = lo + 1; i <= hi; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= lo && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return 0;
}