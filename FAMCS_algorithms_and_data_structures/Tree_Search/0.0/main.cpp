#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>  

using namespace std;

string SumStr(string str1, string str2)
{
    if(str1.size() < str2.size()) // in correct order
        swap(str1, str2);

    int tmp = str1.size() - 1;

    for(int i = str2.size() - 1; i >= 0; i--, tmp--) {
        str1[tmp] += (str2[i] - '0');
    }

    for(int i=str1.size() - 1; i > 0; i--) {
        if(str1[i] > '9')
        {
            int digit = str1[i] - '0';
            str1[i-1] = ((str1[i - 1] - '0') + digit / 10) + '0';
            str1[i] = (digit % 10) + '0';
        }
    }


    if(str1[0] > '9') {
        string tmpStr;
        tmpStr = str1[0];
        str1[0] = ((str1[0] - '0') % 10) + '0';
        tmpStr[0] = ((tmpStr[0] - '0') / 10) + '0';
        str1 = tmpStr + str1;
    }
    return str1;
}


string getStr(long int arr[]){
  string ans = "";
  for(int i = 0; i < sizeof(arr); i++){
    if(arr[i] == 0)
      continue;
    ans += arr[i];
  }
  return ans;
}

const int sizeOfNum(int n) {
  int count = 0;
  while(n){
    n /= 10;
    count++;
  }
  return count;
}

int * intToArray(long int num) {
  int sizeNum = sizeOfNum(num);
  int * array = new int[sizeNum];
  for (int i = sizeNum; i >= 0; i--) {
    array[i] = num % 10;
    num /= 10;
  }
}

int * subDig(long int arr[], long int num){

}

int * sumDig(long int arr[], long int num){
  
  if(num < 0)
    return subDig(arr, num);
    
    
  int sizeNum = sizeOfNum(num);
  for(int i = sizeof(arr), j = sizeNum; i >=0; i++, j--) {

  }
}

int main(){

  long int arr[2500] = {};

  ifstream file;
  file.open("C:\\Users\\programming\\cpp-examples\\fpmi-algos\\0.0\\input.txt");

  long n = 0;
  long int k=0;
  long int stor[500] = {};
  bool boo = false;

  while (file >> n) {
    boo = false;

    for(int i = 0; i < k; i++) // chech for unique
      if(arr[i] == n)
         boo = true;
    if (boo == true){
      continue;
    }

      arr[k] = n;
      k++;
      sumDig(stor, n);
    }

  string str = getStr(stor);
  ofstream fout;
  fout.open("C:\\Users\\programming\\cpp-examples\\fpmi-algos\\0.0\\output.txt");
  fout << stor;
  return 0;

}
