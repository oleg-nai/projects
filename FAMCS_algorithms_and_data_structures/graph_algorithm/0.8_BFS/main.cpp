#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

bool mat[101][101]; // Adjacency matrix
int n = 0;          // number of vertex

queue<int> q, q_save;
bool used[101] = {false};
int s = 1; // start vertex

void chech(int s)
{
    for (int i = 1; i <= n; i++)
    {
        if (mat[s][i] == true)
        {
            if (used[s] == true)
                continue;
            q.push(i);
            q_save.push(s);
            used[i] = true;
        }
    }
}

int main()
{

    ifstream fin("input.txt");
    fin >> n;

    // read data
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> mat[i][j];

    // check for first element
    bool a = false;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            if (mat[i][j] == 1){
                a = true;
                s = i;
            }
        }
        if(a == true)
            break;
    }

    q.push(s);
    used[s] = true;
    q_save.push(s);

    while (!q.empty())
    {
        s = q.front();
        for (int i = 1; i <= n; i++)
        {
            if (mat[s][i] == true)
            {
                if (used[i] == true)
                    continue;
                q.push(i);
                used[i] = true;
                q_save.push(i);
            }
        }
        q.pop();
    }

    for(int i = 1; i <= n; i++)
        if(used[i] == false)
            q_save.push(i);
    // output
    ofstream fout("output.txt");
    while (!q_save.empty())
    {
        fout << q_save.front() << " ";
        q_save.pop();
    }

    return 0;
}