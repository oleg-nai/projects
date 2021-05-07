from math import floor

def check_for_valid(heap, n):
    for k in range (n//2):
        if heap[k] > heap[k* 2 + 1]:
            return False
        if 2 * k + 2 < n and heap[k] > heap[k* 2 + 2]:
            return False
    return True

fin = open("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Data_structures\\0.3.Binary_heap\\input.txt", "r")

heap = []
n = int(fin.readline())
strtmp = fin.readline()
for tmp in strtmp.split(" "):
    heap.append(int(tmp))

fin.close()

fout = open("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\Data_structures\\0.3.Binary_heap\\output.txt", "w")
if(check_for_valid(heap, n) == True):
    fout.write("yes")
else:
    fout.write("no")
fout.close()
