#include <iostream>
#include <fstream>
// build graph matrix
using namespace std;

int main(){

    int n, m;
    int u, v; 
    bool mat[100][100];

    ifstream fin("input.txt");
    fin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = false;
    
    for(int i = 0; i < m; i++) {
        fin >> u >> v;
        mat[u-1][v-1] = true;
        mat[v-1][u-1] = true;
    }

    ofstream fout("output.txt");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            fout << mat[i][j] << " ";
        fout << "\n";
    }
            
    return 0;
}