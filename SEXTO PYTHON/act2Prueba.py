"""Escribí un programa en Python que permita practicar el uso de estructuras de datos (listas y tuplas) 
y ciclos (for y while).
*Creá una lista con al menos tres nombres de frutas.
*Creá una tupla con los precios correspondientes a esas frutas.
*Mostrá por pantalla ambos conjuntos de datos.
*Recorcé la lista de frutas con un ciclo for y mostrá cada elemento.
*Agregá una nueva fruta a la lista y luego eliminá una existente. Mostrá la lista actualizada.
*Usá un ciclo for con range() y len() para mostrar las frutas junto con su posición en la lista.
*Usá un ciclo while para recorrer la lista y mostrar un mensaje por cada fruta.
*Mostrá los valores de la tupla uno por uno."""

frutas = ["manzana", "banana", "naranja"]
precios = (80, 100, 120)

print("lista de frutas:")
print(frutas)

print("\ntupla de precios:")
print(precios)

for fruta in frutas:
    print(f"quiero comprar {fruta}")

print("\n--- Agrega y eliminar elementos de la lista ---")
frutas.append("pera")
print("Después de agregar:", frutas)

frutas.remove("banana")  # Elimina un elemento
print("Después de eliminar:", frutas)

print("\n--- Recorriendo con índice ---")
for i in range(len(frutas)):
    print(f"Fruta {i+1}: {frutas[i]}")

print("\n--- Ciclo while ---")
contador = 0
while contador < len(frutas):
    print(f"Comiendo {frutas[contador]}...")
    contador += 1

print("\n--- Accediendo a datos de la tupla ---")
for i in range(len(precios)):
    print(f"Precio {i+1}: ${precios[i]}")

print("\n--- Emparejando listas y tuplas ---")
for fruta, precio in zip(frutas, precios):
    print(f"La {fruta} cuesta ${precio}")
