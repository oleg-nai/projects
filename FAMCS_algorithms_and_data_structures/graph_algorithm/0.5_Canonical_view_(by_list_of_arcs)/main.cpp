#include <iostream>
#include <fstream>

using namespace std;

int main(){

    int n = 0;
    int u = 0, v = 0;
    int label[100001];

    ifstream fin("input.txt");
    fin >> n;
    for(int i = 0; i < n-1; i++){
        fin >> u >> v;
        label[v] = u;
    }
    
    ofstream fout("output.txt");
    for(int i = 1; i < n+1; i++){
        fout << label[i] << " ";
    }
    return 0;
}