#include <stdio.h>

int main() {
    int n, i, key;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &key);

    // Binary Search to find last index where element <= key
    int low = 0, high = n - 1, mid;
    int result = -1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] <= key) {
            result = mid;       // store index
            low = mid + 1;      // move right to find last occurrence
        } else {
            high = mid - 1;
        }
    }

    // Count = index + 1
    printf("%d", result + 1);

    return 0;
}
