#include <iostream>


int max(const int a, const int b) {
    if(a > b) return a;
    else return b;
}

int main() {
    
    FILE *fin;
    fin= fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Рекуррентные_соотношения\\69_Кувшинки\\input.txt", "r");
    
    FILE *fout;
    fout = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Рекуррентные_соотношения\\69_Кувшинки\\output.txt", "w");

    int n = 0;
    fscanf(fin, "%d", &n);

    if(n == 1){
        int temp = 0;
        fscanf(fin, "%d", &temp);
        fprintf(fout, "%d", temp);
        return 0; 
    }

    if(n <= 2) {
        fprintf(fout, "%d", -1);
        return 0;
    }

    int * arr = new int[n];
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }

    int * boot = new int[n];
    boot[0] = arr[0];
    boot[1] = INT_MIN;
    boot[2] = arr[0] + arr[2];
    for(int i = 3; i < n; i++) {
        boot[i] = max(boot[i-3], boot[i-2]) + arr[i];
    }
    
    fprintf(fout, "%d", boot[n-1]);

    return 0;
}