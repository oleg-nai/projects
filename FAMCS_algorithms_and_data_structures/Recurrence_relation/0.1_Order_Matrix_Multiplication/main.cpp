#include <iostream>
#include <algorithm>

int matmulti(int* arr, int n) {

    int **mat = new int*[n];
	for (int i = 0; i < n; i++){
		mat[i] = new int[n];
        mat[i][i] = 0;
    }

    for (int l = 1; l < n; ++l)
    {
        for (int i = 0; i < n - l; ++i)
        {
            int j = i + l;
            mat[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                mat[i][j] = std::min(mat[i][j],
                mat[i][k] + mat[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1]);
            }
        }
    }
    return mat[0][n - 1];
}

int main()
{

    FILE *fin;
    fin = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Recurrence_relation\\0.1_Order_Matrix_Multiplication\\input.txt", "r");
    FILE *fout;
    fout = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Recurrence_relation\\0.1_Order_Matrix_Multiplication\\output.txt", "w");

    int n = 0;
    fscanf(fin, "%d", &n);
    n++;
    
    int *arr = new int[n];
    int temp;
    
    fscanf(fin, "%d %d", &arr[0], &arr[1]);
    for (int i = 2; i < n; i++)
    {
        fscanf(fin, "%d %d", &temp, &arr[i]);
    }
    fprintf(fout, "%d", matmulti(arr, n-1));
    return 0;
}