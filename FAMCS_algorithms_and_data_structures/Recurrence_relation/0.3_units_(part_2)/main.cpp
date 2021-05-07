#include <iostream>
#define ll long long
#define const 1000000007
ll fact(int num) {
    ll ans = 1;
    for(int i = 2 ; i <= num; i++){
        ans = (ans * i) % const;
    }
    return ans;
}
ll func(ll temp, int num){
    ll ans = 1;
    while(num) {
        if(num & 1){
            ans = temp * ans % const;
        }
        temp = (temp * temp) % const;
        num = num >> 1;
    }
    return ans;
}
int main() {
    int N, K;
    std::cin >> N >> K;
    ll a, b, c;
    a = (fact(N) * func(fact(K), const - 2)) % const;
    b = (func(fact(N - K ), const - 2)) % const;
    c = (a * b) % const;
    std::cout << c;
    return 0;
}