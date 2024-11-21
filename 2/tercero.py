

n = int(input())

resultados = []

for i in range (0,n):
    palabra = (input().split(" "))
    mitad = len(palabra) // 2
    for j in range(0,mitad):
        actual = palabra[j]
        palabra[j] = palabra[-j - 1]
        palabra[-j - 1] = actual


    for k in range(0,len(palabra),2):
        if (k == len(palabra)-1):
            break 
        actual = palabra[k]
        palabra[k] = palabra[k+1]
        palabra[k + 1] = actual
    palabra = "".join(palabra)
    resultados.append(palabra)

for n in resultados:

    print(n)
    
        


        
    


    



    