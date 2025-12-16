menu = { "a": 0, "b": 1}
ab = list(menu.keys())
print(ab[0])
print(menu['a'])
print(menu.keys())
menu["c"] = 2
print(menu)
print(menu.values())

for k in menu.keys():
    print(f"{k}:{menu[k]}")