#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Recurrence_relation\\20_Palindrome\\input.txt");
    
    string str;
    getline(fin, str);    
    int n = str.size();

    int ** boot = new int*[n]; // init mat
    // f[i][i] = 1, i = 1_n
    for(int i = 0; i < n; i++) { 
        boot[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                boot[i][j] = 1;
            else
                boot[i][j] = 0;
        }
    }

    // f[i][i+1] = 2 if str[i] == str[i+1], else 1; i = 1_n-1
    for(int i = 0; i < n - 1; i++){
        if(str[i] == str[i+1])
            boot[i][i+1] = 2;
        else
            boot[i][i+1] = 1;
    }

    // f[i][j] = f[i+1][j-1] + 2 if str[i] == str[j], else max{f[i+1][j], f[i][j-1]}; i = 1_n-2, j > i
    for(int j = 2; j < n; j++) {
        for(int i = j - 2; i >= 0; i--){
                if(str[i] == str[j]){
                    boot[i][j] = boot[i+1][j-1] + 2;
                }
                else {
                    boot[i][j] = max(boot[i+1][j], boot[i][j-1]);
    
            }
        }
    }

    // test mat
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << boot[i][j] << " ";
        }
        cout << "\n";
    }


    // f[i][i] = 1, i = 1_n
    // f[i][i+1] = 2 if str[i] == str[i+1], else 1; i = 1_n-1
    // f[i][j] = f[i+1][j-1] + 2 if str[i] == str[j], else max{f[i+1][j], f[i][j-1]}; i = 1_n-2, j > i


    string ans;

    int i = 0, j = n-1;
    int a = (int) floor(j/2);
    // ans = str[j];
    while(j >= a){
        if(boot[i][j] > boot[i][j-1] && boot[i][j] > boot[i+1][j]) {
            ans += str[j];
            i++;
            j--;
            continue;
        }
        else {
            if(boot[i][j-1] > boot[i+1][j]) { // left is bigger
                j--;
                // ans += str[j];
                // lst.push_front(str[j]);

            }
            else { // right is bigger
                i++;
                // ans +=str[j];
                // lst.push_front(str[j]);
            }   
        }
    }

    string temp = ans; // temp = asf
    reverse(ans.begin(), ans.end()); // ans = fsa
    if(boot[0][n-1] % 2 != 0) {

        ans.erase(ans.begin(), ans.begin()+1);
    }

    ans = temp + ans;
    // // test
    // cout << boot[0][n-1] << "\n";
    // cout << ans;




    FILE *fout;
    fout = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Recurrence_relation\\20_Palindrome\\output.txt", "w");
    fprintf(fout, "%d\n%s", boot[0][n-1], ans.c_str());

    return 0;
}