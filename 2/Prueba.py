n = int(input())  
final = []

for _ in range(n):
    num_casillas = int(input())  
    lista_saltos = input().split()  
    recorridos = []
    contador = 0
    num_saltos = 0

    while True:
        if contador in recorridos:
            final.append(num_saltos)
            break
        
        recorridos.append(contador)

        contador += int(lista_saltos[contador])
        num_saltos += 1

        if contador < 0 or contador >= num_casillas:
            final.append(num_saltos)
            break

for n in final:
    print(n)
