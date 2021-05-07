#include <iostream>

#define ll long long
#define r 1000000007

ll fact(int n) {
    ll mul = 1;
    for(int i =2 ; i <= n; i++) 
        mul = (mul * i) % r;
    return mul;
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << fact(n) / (fact(k) * fact(n-k)) % r;
    return 0;
}

