#include <stdio.h>

// function to perform binary search on a sorted array
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        // if the element is present at the middle
        if (arr[mid] == x) return mid;
        // if element is smaller than mid, search left subarray
        if (arr[mid] > x) return binarySearch(arr, left, mid - 1, x);
        // else search right subarray
        return binarySearch(arr, mid + 1, right, x);
    }
    // if element is not present in the array
    return -1;
}

// driver code
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        printf("Element not present in array");
    } else {
        printf("Element found at index %d", result);
    }
    return 0;
}
