#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4};
    int len = (int)sizeof(arr)/sizeof(*arr);

    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            for(int k=0; k<len; k++){
                if(arr[i]!=arr[j]&&arr[j]!=arr[k]&&arr[i]!=arr[k])
                    printf("%d%d%d\n", arr[i], arr[j], arr[k]);
            }
        }
    }
}


