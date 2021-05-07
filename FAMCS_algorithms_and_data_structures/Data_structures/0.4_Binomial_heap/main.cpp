#include <iostream> 
#include <fstream> 

using namespace std;

int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");

	long long int n, key = 0;
	input >> n;

	while (n){
		if (n % 2 == 1)
		{
			output << key << "\n";
		}
		n = n / 2;
		key = key + 1;
	}	
    return 0;
}