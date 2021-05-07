#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct Data{
    long key;
    int addNumStr;  // to what line need to tie
    char link;
    long long int key_left;  // min value
    long long int key_right; // max value
};

int main() {

    int n = 0; // number of roots
    Data* data;
    FILE *fp;
    fp = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\0.3\\bst.in", "r");
    fscanf(fp,"%d", &n);

    if (n == 1) {
        ofstream fout;
        fout.open("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\0.3\\bst.out");
        fout << "YES";
        return 0;
    }
    
    data = new Data[n];
    
    fscanf(fp, "%d", &data[0].key);
    data[0].link = 'L';
    data[0].addNumStr = 0;
    data[0].key_left = LLONG_MIN;
    data[0].key_right = LLONG_MAX;

    for(int i = 1; i < n; i++) {
        fscanf(fp, "%d %d %c", &data[i].key, &data[i].addNumStr, &data[i].link);
        if(data[i].link == 'L') {
            data[i].key_left = data[data[i].addNumStr - 1].key_left;
            data[i].key_right = data[data[i].addNumStr - 1].key;
        }
        else if(data[i].link == 'R') {
            data[i].key_left = data[data[i].addNumStr - 1].key;
            data[i].key_right = data[data[i].addNumStr - 1].key_right;
        }
        
        if (data[i].key >= data[i].key_right || data[i].key < data[i].key_left) {
            ofstream fout;
            fout.open("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\0.3\\bst.out");
            fout << "NO";
            return 0;
        }
    }

    ofstream fout;
    fout.open("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\0.3\\bst.out");

    fout << "YES";
    fclose(fp);
    return 0;
}