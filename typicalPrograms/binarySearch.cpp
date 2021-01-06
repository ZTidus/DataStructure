/*
binarySearch(key, array[], min, max)
// key: the number we are searching
if (max < min):
    return -1
else:
    midpoint = findMidPoint(min, max)
    if(array[midpoint] < key):
        binarySearch(key, array, midpoint + 1, max)
    else if(array[midpoint] > key):
        binarySearch(key, array, min, midpoint - 1)
    else:
        return midpoint  // return current midpoint index
*/

#include <iostream>
using namespace std;

int findMidpoint(int min, int max) {
    return (min + max) / 2;
}

// Return index of key
int binarySearch(int key, int arr[], int min, int max) {
    if(max < min)
        return -1;
    else {
        int midpoint = findMidpoint(min, max);
        if(arr[midpoint] < key)
            binarySearch(key, arr, midpoint + 1, max);
        else if(arr[midpoint] > key)
            binarySearch(key, arr, min, midpoint - 1);
        else
            return midpoint;
    }
}

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int length = sizeof(primes)/sizeof(primes[0]); // get primes's length
    printf("%d\n", length);
    int key = 67, min = 0, max = length-1;
    int ans = binarySearch(key, primes, min, max);
    printf("%d's index is: %d\n", key, ans);
    return 0;
}

