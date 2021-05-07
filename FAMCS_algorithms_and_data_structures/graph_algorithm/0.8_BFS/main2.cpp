#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;

    int matrix[100][100];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			in >> matrix[i][j];

	queue<int> q;
	vector<int> temp(n, 0);
	bool used[100] = { 0 };
    
    for(int k = 0; k < n; k++)
    {
        if(used[k] == 0) {
            q.push(k);
            temp[k] = 1;
        }
    }
    
    return 0;
}