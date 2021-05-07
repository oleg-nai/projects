from math import factorial as fact

def solution(n,k):
    return fact(n) // (fact(k) * fact(n - k))


n, k = map(int, input().split())
print(solution(n,k))
