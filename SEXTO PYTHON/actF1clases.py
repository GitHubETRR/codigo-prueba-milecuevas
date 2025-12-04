class Piloto:
    def __init__(self, nombre, apellido, escuderia, numero, puntos):
        self.nombre = nombre
        self.apellido = apellido
        self.escuderia = escuderia
        self.numero = numero
        self.puntos = puntos

    def mostrar(self):
        print("Nombre:", self.nombre)
        print("Apellido:", self.apellido)
        print("Escudería:", self.escuderia)
        print("Número de auto:", self.numero)
        print("Puntos:", self.puntos ,"\n")

    def modificar(self):
        print("\nQué querés editar?")
        print("1- Nombre")
        print("2- Apellido")
        print("3- Escudería")
        print("4- Número de auto")
        print("5- Puntos")
        opcion = input("Opción: ")

        if opcion == "1":
            self.nombre = input("Nuevo nombre: ")
        elif opcion == "2":
            self.apellido = input("Nuevo apellido: ")
        elif opcion == "3":
            self.escuderia = input("Nueva escudería: ")
        elif opcion == "4":
            self.numero = int(input("Nuevo número: "))
        elif opcion == "5":
            self.puntos = int(input("Nuevos puntos: "))
        else:
            print("Opción inválida")

class BaseF1:
    def __init__(self):
        self.pilotos = []

    def agregarPiloto(self):
        nombre = input("Nombre: ")
        apellido = input("Apellido: ")
        escuderia = input("Escudería: ")
        numero = int(input("Número de auto: "))
        puntos = int(input("Puntos: "))
        nuevo = Piloto(nombre, apellido, escuderia, numero, puntos)
        self.pilotos.append(nuevo)
        print("Piloto agregado correctamente\n")

    def mostrarPilotos(self):
        if len(self.pilotos) == 0:
            print("No hay pilotos cargados\n")
            return

        print("\nLista de Pilotos")

        i = 1
        for p in self.pilotos:
            print(f"\nPILOTO {i}")
            p.mostrar()
            i+=1  

    def editarPiloto(self):
        if len(self.pilotos) == 0:
            print("No hay pilotos para editar\n")
            return

        numero = int(input("Número de auto del piloto a editar: "))
        for p in self.pilotos:
            if p.numero == numero:
                print("\nDatos actuales:")
                p.mostrar()
                p.modificar()
                print("Piloto modificado\n")
                return
        print("No existe un piloto con ese número.\n")

    def eliminarPiloto(self):
        if len(self.pilotos) == 0:
            print("No hay pilotos para eliminar.\n")
            return

        numero = int(input("Número de auto del piloto a eliminar: "))
        for p in self.pilotos:
            if p.numero == numero:
                self.pilotos.remove(p)
                print("Piloto eliminado\n")
                return
        print("No existe un piloto con ese número.\n")

base = BaseF1()
while True:
    print("BASE DE DATOS F1")
    print("1- Agregar piloto")
    print("2- Ver pilotos")
    print("3- Editar piloto")
    print("4- Eliminar piloto")
    print("5- Salir")

    op = input("Opción: ")

    if op == "1":
        base.agregarPiloto()
    elif op == "2":
        base.mostrarPilotos()
    elif op == "3":
        base.editarPiloto()
    elif op == "4":
        base.eliminarPiloto()
    elif op == "5":
        print("Chauu :)")
        break
    else:
        print("Opción inválida\n")