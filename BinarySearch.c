#include<stdio.h>
int binarySearch(int arr[], int s, int e, int key){
    if(s>e){
        return -1;
    }

    int mid = (s+e)/2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key){
        return binarySearch(arr, s, mid-1, key);
    }
    else{
        return binarySearch(arr, mid+1, e, key);
    }
}
int main(){
    //the array should be sorted
    int arr[] = {2,6,7,9,21,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 7;
    int index = binarySearch(arr, 0, n-1, key);
    if(index == -1){
        printf("Element not found in the array");
    }else{
        printf("The element index = %d", index);
    }
}
