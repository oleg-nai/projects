with open("input.txt") as file:
    n = int(file.readline())
n = str(bin(13))[2:]

isPoss = False
with open("output.txt", "w") as file:    
    for key in range(len(n) - 1, -1, -1):
        if (n[key] == "1"):
            isPoss = True
            file.write(str(len(n) - key - 1) + '\n')
    if isPoss == False:
        file.write(str(-1))
