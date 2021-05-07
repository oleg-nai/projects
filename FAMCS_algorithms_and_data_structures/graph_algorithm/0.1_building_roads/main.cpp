#include <iostream>
#include <fstream>

using namespace std;

class DSU{
    public:
    long *parent;
    long *size;

    DSU(long n){
        parent = new long[n+1];
        size = new long[n+1];
        for(int i = 1; i < n+1; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindSet(long x) {
        if(x == parent[x])
            return x;
        parent[x] = this->FindSet(parent[x]);
        return parent[x];
    }

    bool Union(long u, long v){
        u = FindSet(u);
        v = FindSet(v);
        if (u != v){
            parent[v] = u;
            size[u] += size[v];
            return true;
        }
        return false;
    }
};

int main()
{
    long n, q; // n - number of vertices, q - number of requests 

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n >> q;
    DSU temp(n);
    long u = 0, v = 0, count = n;
    for(int i = 0; i < q; i++){
        fin >> u >> v;
        if (temp.Union(u, v) && count > 1)
            count--;
        if(i == q - 1)
            fout << count;
        else
            fout << count << "\n";
    }
    return 0;
}