#include <iostream>

int min_my(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

using namespace std;

int main() {
    FILE *fin;
    fin = fopen("kr/input.txt", "r");
    FILE *fout;
    fout = fopen("kr/output.txt", "w");


    int n = 0, m = 0;
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);


    // read data
    int** data = new int*[n];
    int** boot = new int*[n];
    for(int i = 0; i < n; i++){
        data[i] = new int[m];
        boot[i] = new int[m+2];
        for(int j = 0; j < m; j++)
        {
            fscanf(fin, "%d", &data[i][j]);  
            if(i == 0){
                boot[i][j+1] = data[i][j];
            }
            if(j == 0) 
                boot[i][j] = INT_MAX;
            if(j == m-1)
                boot[i][j+2] = INT_MAX;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m+1; j++){
            boot[i][j] = min_my(boot[i-1][j-1], boot[i-1][j], boot[i-1][j+1]) + data[i][j-1];
        }
    }

    int min = INT_MAX;
    for(int i = 1; i < m+1; i++){
        if(min > boot[n-1][i]){
            min = boot[n-1][i];
        }
    }
    
    fprintf(fout, "%d", min);

    return 0;
}