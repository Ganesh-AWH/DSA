#include<stdio.h>
int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key) return i;
    }
    return -1;
}
int main(){
    int arr[] = {3,45,6,8,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 100;
    int index = linearSearch(arr, n, key);
    if(index == -1){
        printf("The element is not found in array");
    }else{
        printf("The element index = %d", index);
    }
}
