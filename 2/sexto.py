n = int(input())
final = []

for i in range(0,n):
    num_casillas = int(input())
    lista_saltos = input().split(" ")
    recorridos = []
    contador = 0
    num_saltos = 0

    while True:
        contador += int(lista_saltos[contador])
        print(recorridos)
        print(contador)  
        terminar = False
        for k in recorridos:
            if k == contador:
                final.append(num_saltos)
                terminar = True
                break
        if terminar == True:
            num_saltos += -1
            break
                
        if (contador >= num_casillas):
            final.append(num_saltos)
            break
        
        
        
        recorridos.append(contador)
        num_saltos += 1

print("final: ")
for n in final:
    print(n + 1)







    
