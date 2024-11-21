n = int(input())

palabra = input().split(", ")
final = []


for i in range(0,(n+1)//2):
    final.append(palabra[i])
    if i != n-i-1:
        final.append(palabra[n-i-1])
print("".join(final))


