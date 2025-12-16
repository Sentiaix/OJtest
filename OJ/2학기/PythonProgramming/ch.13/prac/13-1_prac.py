class Counter :
    def __init__(self, number = 0):
        if number <= -1 or number >= 100:
            self.__number = 0
        else:
            self.__number = number
    def reset(self):
        self.__number = 0
    def inc(self):
        if self.__number >= 100:
            self.__number = 0
        else :
            self.__number += 1
    def dec(self):
        if self.__number <= -1:
            self.__number = 0
        else :
            self.__number -= 1
    def __str__(self):
        return f"C({self.__number})"

c1 = Counter(10)
c1.inc()
print('c1 =', c1)

c2 = Counter()
c2.inc()
c2.inc()
c2.dec()
print('c2 =', c2)
c2.reset()
print('c2 =', c2)