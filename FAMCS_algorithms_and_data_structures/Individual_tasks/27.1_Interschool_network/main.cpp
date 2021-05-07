#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


bool sTransMap[100][100] = {false};
bool sMap[100][100] = {false};


// алгоритм ”оршелла дл€ перевода транзитивного бинарного отношени€ sTransMap в sMap
void Warshall(int n) {
    
    for(int i = 0; i < n; i++) // copy matrix
        for(int j = 0; j<n;j++)
            sMap[i][j] = sTransMap[i][j];

    for(int k = 0; k < n; k++) { // algorithm Warshall
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (sMap[i][j] || (sMap[i][k] && sMap[k][j]))
                    sMap[i][j] = true;
                else
                    sMap[i][j] = false;
            }
        }
    }
}


// нахождение множества вершин ориентированного графа, €вл€ющихс€ его базой
int search(int n, bool mat[100][100]) {
    // a - множество вершин графа
    bool p[100];
    for(int i = 0; i < n; i++)
        p[i] = true;
    vector<int> a;

    for(int i = 0; i < n; i++){
        if (p[i]){
            for(int j = 0; j < n; j++) {
                if(count(a.begin(), a.end(), j) && mat[i][j])
                   a.erase(find(a.begin(), a.end(), j));  // исключаем из а все вершины j, смежные с i
            }
            for(int j = 0; j < n; j++) {
                if(mat[i][j])
                    p[j] = false;   // все вершины, смежные с i исключаем из дальнейшего рассмотрени€
            }
            a.push_back(i);         // включаем вершину i в базу
        }
    }

    return a.size();
}


int main(){
    ifstream fin;
    fin.open("input.txt");

    int n = 0; // number of vertex
    int temp = 0;
    fin >> n;
    for(int i = 0; i < n; i++) {
        while (fin >> temp) {
            if (temp == 0)
                break;
            sTransMap[i][temp-1] = true;
        }
    }

    Warshall(n);

    int size_s = search(n, sMap);

    bool tmp_mat[100][100];

    for (int i = 0; i < n; i++) // copy mat
        for(int j = 0; j < n; j++)
            tmp_mat[i][j] = sMap[i][j];

    bool tempa = false; // transpose
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            tempa = tmp_mat[i][j];
            tmp_mat[i][j] = tmp_mat[j][i];
            tmp_mat[j][i] = tempa;
        }
    }

    int size_s_t = search(n, tmp_mat); 
    // cout << size_s << endl << size_s_t;
    
    ofstream fout("output.txt");
    fout << size_s << endl << size_s_t;
    return 0;
}