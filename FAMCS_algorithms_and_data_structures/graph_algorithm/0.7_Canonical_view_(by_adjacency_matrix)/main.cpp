#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n = 0, boot = 0;
    int arr[101];
    for(int i = 0; i < 101; i++)
        arr[i] = 0;
    ifstream fin("input.txt");
    fin >> n;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
        fin >> boot;
        if(boot == 1)
            arr[j] = i; 
        }
    }
    ofstream fout("output.txt");
    for(int i = 1; i < n+1; i++)
        fout << arr[i] << " ";
    return 0;
}