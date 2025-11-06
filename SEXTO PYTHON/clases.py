class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def mostrar_info(self):
        print(f"nombre: {self.nombre}")
        print(f"edad: {self.edad}")

    def cumplir_anios(self):
        self.edad += 1
        print(f"{self.nombre} ahora tiene {self.edad} años.")

persona1 = Persona("mile", 17)
persona1.mostrar_info()
persona1.cumplir_anios()