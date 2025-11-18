'''5개의 물건 가격을 입력 받아 dictionary를 만들고, 
물건과 가격을 물건 이름 순으로 정렬해서 출력하고, 
물건과 가격을 제일 작은 가격부터 정렬해서 출력하라. 
가격은 int이다. 

String의 split함수를 사용해서 string을 단어 list로 만들 수 있다. 
같은 물건과 가격은 없다고 가정하고, 입출력 예시를 잘 확인해서 구현하라. 
(hint: dictionary를 2개 만들면 문제가 쉬어질 수 있고, Keys를 list로 변경해서 sort()할 수 있다.)
'''

menu = {}
for i in range(5):
    s = input('Enter product and price: ').split()
    product = s[0]
    price = int(s[1])
    menu[product] = price

# print(menu) # debug print

key_list = list(menu.keys())
key_list.sort()
for k in key_list:
    print(f"{k}:{menu[k]}", end=' ')

price_is_key = {} # price가 key가 된 새로운 dict
for k in key_list:
    price_is_key[menu[k]] = k

print()

price_list = list(menu.values())
price_list.sort()
for p in price_list:
    print(f"{price_is_key[p]}:{p}", end=' ')