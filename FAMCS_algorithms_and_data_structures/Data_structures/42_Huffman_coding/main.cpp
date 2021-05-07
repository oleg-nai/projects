#include <iostream>
#include <fstream>
#include <list>

using namespace std;

struct data{
    long int a;
    int ans;
};

int main() {
    FILE *fin;
    fin = fopen("huffman.in", "r");

    int n; // number of units
    fscanf(fin,"%d", &n);

    list<long int> huff; // container for data
    list<int>::iterator it;
    
    long int tmp; // read data
    for(int i = 0; i < n; i++){
        fscanf(fin, "%d", &tmp);
        huff.push_back(tmp);
    }    



    return 0;
}