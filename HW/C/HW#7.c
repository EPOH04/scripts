#include <stdio.h>

int binary_search(int list[], int left, int right, int key) {
    if (left > right) {
        return -1;  // Element not found
    }

    int mid = left + (right - left) / 2;

    if (list[mid] == key) {
        return mid;  // Element found, return its index
    }
    else if (list[mid] > key) {
        return binary_search(list, left, mid - 1, key);  // Search in the left half
    }
    else {
        return binary_search(list, mid + 1, right, key);  // Search in the right half
    }
}

int main() {
    int nums[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int NUMEL = sizeof(nums) / sizeof(nums[0]);
    int item = 7;

    int location = binary_search(nums, 0, NUMEL - 1, item);

    if (location != -1) {
        printf("Element found at index: %d\n", location);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
