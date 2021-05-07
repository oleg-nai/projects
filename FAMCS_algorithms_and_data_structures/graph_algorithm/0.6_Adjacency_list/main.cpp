#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0, v = 0, u = 0;
    ifstream fin("input.txt");
    fin >> n >> m;
    vector <vector <int>> vec(n+1);

    for(int i = 0; i < m; i++) {
        fin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    ofstream fout("output.txt");
    for(int i = 1; i < n+1; i++){
        fout << vec[i].size() << " ";
        for(auto j: vec[i])
            fout << j << " ";
        fout << "\n";
    }
    return 0;
}