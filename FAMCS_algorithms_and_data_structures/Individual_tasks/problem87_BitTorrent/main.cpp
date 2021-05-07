#include <iostream>
#include <algorithm>
using namespace std;

int comp(const int *i, const int *j)
{
    return *i - *j;
}

int main() {
    FILE *fin;
    fin = fopen("kr/bittorrent.in", "r");
    FILE *fout;
    fout = fopen("kr/bittorrent.out", "w");
    int N, P, L;
    fscanf(fin, "%d", &N);
    fscanf(fin, "%d", &P);
    fscanf(fin, "%d", &L);

    if(P > L) {
        int i = 0;
        fprintf(fout, "%d", &i);
        return 0;
    }

    int** boot = new int*[N];
    

    for(int i = 0 ; i< N; i++) {
        fscanf(fin, "%d", &boot[i]);
    }




    return 0;
}