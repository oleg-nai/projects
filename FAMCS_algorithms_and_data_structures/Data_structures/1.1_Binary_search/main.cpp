#include <fstream>
#include <cmath>

int n = 0;
int k = 0;

int binary_search(int* arr, int x) {
    int l = 0;
    int r = n;
    int k = 0;
    while(l < r) {
        k = ceil((l+r) / 2);
        if ( x == arr[k])
            return 1;
        else if (x < arr[k])
            r = k;
        else
            l = k + 1;
    }
    return 0;
}

int UpperBount(int* arr, int x) {
    int l = 0;
    int r = n;
    int k = 0;
    while(l < r) { 
        k = ceil((l+r) / 2);
        if(x < arr[k]) 
            r = k;
        else
            l = k + 1;
    }
    return l;
}

int LowerBound(int* arr, int x) {
    int l = 0;
    int r = n;
    int k = 0;
    while(l < r) {
        k = ceil((l+r) / 2);
        if(x <= arr[k])
            r = k;
        else
            l = k + 1;
    }
    return l;
}

int main() {
  
    int* arr;
    int temp = 0;
    
    scanf("%d", &n); 
    arr = new int[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &temp);
        if (i + 1 == k)
            printf("%d %d %d", binary_search(arr, temp), LowerBound(arr, temp), UpperBount(arr, temp));
        else
            printf("%d %d %d\n", binary_search(arr, temp), LowerBound(arr, temp), UpperBount(arr, temp));
    }

    return 0;
}