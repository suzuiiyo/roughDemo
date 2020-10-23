#include<stdio.h>

void swap(int *a, int *b)  //交换两个变数
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int len)
{
    int i, j;

    for(i=0; i<len; i++){
        int min = i;
        for(j=i+1; j<len; j++)          //走访未排序的元素
            if(arr[j] < arr[min])           //找到目前最小值
                min = j;                   //记录最小值
            swap(&arr[min], &arr[i]);      //做交换
    }
}

int main(){
    int arr[] = {2312, 34, 451, 54, 1344, 767, 232, 767, 7213, 532};
    int len = (int)(sizeof(arr)/sizeof(*arr));
    selection_sort(arr, len);
    for(int i=0; i<len; i++){
        printf("arr[%d}: %d\n", i, arr[i]);
    }
}