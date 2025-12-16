class Vehicle :
    def __init__(self, brand = ''):
        self.brand = brand
    def describe(self):
        return f"Brand: {self.brand}"

class Car(Vehicle) :
    def __init__(self, brand = '', model = ''):
        super().__init__(brand)
        self.model = model
    def __str__(self):
        return f"Brand: {self.brand}, Model: {self.model}"
    
my_car = Car("Hyundai", "Avante")
print(my_car)