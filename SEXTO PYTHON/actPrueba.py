agenda = []
def mostrarMenu():
    print("MENU")
    print("1. agregar contacto")
    print("2. ver contactos")
    print("3. salir")

while True:
    mostrarMenu()
    opcion = input("elige una opcion: ")

    if opcion == "1":
        nombre = input("Nombre: ")
        telefono = input("Teléfono: ")
        contacto = {"nombre": nombre, "telefono": telefono}
        agenda.append(contacto)
        print("contacto agregado")
        
    elif opcion == "2":

    elif opcion == "3":
        print("chauu")
        break