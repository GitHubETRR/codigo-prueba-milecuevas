pilotos = []

def mostrarMenu():
    print("\nBASE DE DATOS F1")
    print("1. agregar piloto")
    print("2. ver pilotos")
    print("3. buscar piloto")
    print("4. modificar piloto")
    print("5. eliminar piloto")
    print("6. salir")

def agregarPiloto():
    nombre = input("\nnombre: ")
    apellido = input("apellido: ")
    escuderia = input("escudería: ")
    numero = input("número de auto: ")
    puntos = input("puntos en el campeonato: ")

    piloto = {
        "nombre": nombre,
        "apellido": apellido,
        "escuderia": escuderia,
        "numero": numero,
        "puntos": puntos
    }

    pilotos.append(piloto)
    print("piloto agregado\n")

def mostrarPilotos():
    if len(pilotos) == 0:
        print("no hay pilotos cargados\n")
    else:
        print("\nPILOTOS:")
        i = 1
        for piloto in pilotos:
            print("\nPILOTO" + " " + str(i))
            print(piloto["nombre"] + " " + piloto["apellido"])
            print("escudería: " + piloto["escuderia"])
            print("número: " + piloto["numero"])
            print("puntos: " + piloto["puntos"])
            i += 1

def buscarPiloto():
    nombreBuscado = input("ingrese el nombre a buscar: ")
    encontrado = False
    i = 1
    for piloto in pilotos:
        if piloto["nombre"] == nombreBuscado:
            print("\nPILOTO ENCONTRADO:")
            print("PILOTO " + str(i))
            print(piloto["nombre"] + " " + piloto["apellido"])
            print("escudería: " + piloto["escuderia"])
            print("número: " + piloto["numero"])
            print("puntos: " + piloto["puntos"])
            encontrado = True
        i += 1

    if not encontrado:
        print("no se encontró ningún piloto\n")

def modificarPiloto():
    mostrarPilotos()
    if len(pilotos) == 0:
        return

    num = int(input("\ningrese el número del piloto a modificar: "))
    if 1 <= num <= len(pilotos):
        piloto = pilotos[num-1]
        print("\nelija qué quiere modificar:")
        print("1. nombre")
        print("2. apellido")
        print("3. escudería")
        print("4. número del auto")
        print("5. puntos del campeonato")
        opcion = input("opción: ")

        if opcion == "1":
            piloto["nombre"] = input("nuevo nombre: ")
        elif opcion == "2":
            piloto["apellido"] = input("nuevo apellido: ")
        elif opcion == "3":
            piloto["escuderia"] = input("nueva escudería: ")
        elif opcion == "4":
            piloto["numero"] = input("nuevo número de auto: ")
        elif opcion == "5":
            piloto["puntos"] = input("nuevos puntos: ")
        else:
            print("opción inválida")
            return
        print("piloto modificado\n")
    else:
        print("número inválido\n")

def eliminarPiloto():
    mostrarPilotos()
    if len(pilotos) == 0:
        return

    num = int(input("ingrese el número del piloto a eliminar: "))
    if 1 <= num <= len(pilotos):
        del pilotos[num-1]
        print("piloto eliminado\n")
    else:
        print("número inválido\n")

while True:
    mostrarMenu()
    opcion = input("elija una opción: ")
    if opcion == "1":
        agregarPiloto()
    elif opcion == "2":
        mostrarPilotos()
    elif opcion == "3":
        buscarPiloto()
    elif opcion == "4":
        modificarPiloto()
    elif opcion == "5":
        eliminarPiloto()
    elif opcion == "6":
        print("chauu")
        break
    else:
        print("opción inválida\n")