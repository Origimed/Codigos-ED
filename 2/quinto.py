casos = int(input())

final = []

for i in range(0,casos):
    juego = input().split(" ")
    monedas = input().split(" ")
    cantidades = []
    lista = []
    juego[0] = int(juego[0])
    juego[1] = int(juego[1])

    for j in range(juego[0]): ## cada jugador
        suma_jug_actual = 0
        for k in range(0,juego[1]): ##### reocorre todas las monedas
            if (k % juego[0]==j):
                suma_jug_actual += int(monedas[k])
        lista.append(suma_jug_actual)
    final.append(max(lista)-min(lista))

for n in final:
    print(n)

    
            
        
            
            
