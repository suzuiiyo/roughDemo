#include<stdio.h>

void bubble_sort(int arr[], int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {2312, 34, 451, 54, 1344, 767, 232, 767, 7213, 532};
    int len = (int) sizeof(arr)/sizeof(*arr);
    bubble_sort(arr, len);
    for(int i=0; i<len; i++){
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    return 0;
}