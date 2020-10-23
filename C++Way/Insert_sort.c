#include<stdio.h>

void insertion_sort(int arr[], int len){
    int i, j, temp;
    for(i=1; i<len; i++){
        temp = arr[i];
        for(j=i; j>0 && arr[j-1]>temp; j--)
            arr[j] = arr[j-1];
        
        arr[j] = temp;
    }
}

int main(){
    int arr[] = {2312, 34, 451, 54, 1344, 767, 232, 767, 7213, 532};
    int len = (int)sizeof(arr)/sizeof(*arr);
    insertion_sort(arr, len);
    for(int i=1; i<len; i++){
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}