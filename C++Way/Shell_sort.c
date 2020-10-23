#include<stdio.h>
#include<stdlib.h>

void shell_sort(int arr[], int len)
{
    int gap, i, j;
    int temp;
    for(gap = len >> 1; gap > 0; gap = gap >> 1)
        for(i = gap; i < len; i++){
            temp = arr[i];
            for(j = i - gap; j>= 0&& arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}

int main(){
    int arr[] = {2312, 34, 451, 54, 1344, 767, 232, 767, 7213, 532};
    int len = (int)sizeof(arr)/sizeof(*arr);
    shell_sort(arr, len);
    for(int i=0; i<len; i++){
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}