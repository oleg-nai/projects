class DSU:

    def __init__(self, n):
        self.size = [1 for i in range(n+1)]
        self.parent = [1 for i in range(n+1)]
    
    # for finding master
    def FindSet(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.FindSet(self.parent[x])
        return self.parent[x]
    
    # for connecting bought units
    def Union(self, u, v):
        u = self.FindSet(u)
        v = self.FindSet(v)
        if u != v:
            if self.size[u] < self.size[v]:
                u, v = v, u
                self.parent[v] = u
                self.size[u] += self.size[v]
                return False
        return True
        

fin = open("input.txt", "r")

n, q = fin.readline().split()
n = int(n)
q = int(q)

count = n

temp = DSU(n)

fout = open("output.txt", "w")

for i in range(n):
    u, v = fin.readline().split()
    u = int(u)
    v = int(v)
    if count == 1:
        fout.write(str(count) + "\n")
        continue
    if temp.Union(u, v):
        count-=1
    fout.write(str(count) + "\n")