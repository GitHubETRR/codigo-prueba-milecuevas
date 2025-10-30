agenda = []

def mostrarMenu():
    print("MENU")
    print("1. agregar contacto")
    print("2. ver contactos")
    print("3. buscar contacto")
    print("4. modificar contacto")
    print("5. eliminar contacto")
    print("6. salir")

def agregarContacto():
    nombre = input("\nnombre: ")
    apellido = input("apellido: ")
    edad = input("edad: ")
    telefono = input("teléfono: ")
    contacto = {"nombre": nombre, "apellido": apellido, "edad": edad, "telefono": telefono}
    agenda.append(contacto)
    print("contacto agregado\n")

def verContactos():
    if len(agenda) == 0:
        print("no hay contactos guardados\n")
    else:
        print("\nCONTACTOS:")
        i = 1
        for contacto in agenda:
            print(str(i) + ". " + contacto["nombre"] + " " + contacto["apellido"])
            print("edad: " + contacto["edad"])
            print("teléfono: " + contacto["telefono"])
            print()
            i = i + 1

def buscarContacto():
    nombreBuscado = input("ingrese el nombre a buscar: ")
    encontrado = False
    for contacto in agenda:
        if contacto["nombre"] == nombreBuscado:
            print("\nencontrado:")
            print(contacto["nombre"] + " " + contacto["apellido"])
            print("edad: " + contacto["edad"])
            print("teléfono: " + contacto["telefono"])
            print()
            encontrado = True
    if not encontrado:
        print("no se encontró ningún contacto con ese nombre.\n")

def modificarContacto():
    verContactos()
    if len(agenda) == 0:
        return
    num = int(input("ingrese el número del contacto a modificar: "))
    if 1 <= num <= len(agenda):
        contacto = agenda[num-1]
        print("\nelija qué quiere modificar:")
        print("1. nombre")
        print("2. apellido")
        print("3. edad")
        print("4. teléfono")
        opcion = input("opción: ")

        if opcion == "1":
            contacto["nombre"] = input("nuevo nombre: ")
        elif opcion == "2":
            contacto["apellido"] = input("nuevo apellido: ")
        elif opcion == "3":
            contacto["edad"] = input("nueva edad: ")
        elif opcion == "4":
            contacto["telefono"] = input("nuevo teléfono: ")
        else:
            print("opción inválida")
            return

        print("contacto modificado\n")
    else:
        print("número inválido\n")

def eliminarContacto():
    verContactos()
    if len(agenda) == 0:
        return
    num = int(input("ingrese el número del contacto a eliminar: "))
    if 1 <= num <= len(agenda):
        del agenda[num-1]
        print("contacto eliminado\n")
    else:
        print("número inválido\n")

while True:
    mostrarMenu()
    opcion = input("elige una opcion: ")

    if opcion == "1":
        agregarContacto()
    elif opcion == "2":
        verContactos()
    elif opcion == "3":
        buscarContacto()
    elif opcion == "4":
        modificarContacto()
    elif opcion == "5":
        eliminarContacto()
    elif opcion == "6":
        print("chauu")
        break
    else:
        print("opcion invalida\n")