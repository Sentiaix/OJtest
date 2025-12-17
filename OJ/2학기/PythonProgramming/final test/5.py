'''물건 수 입력, 물건과 가격 입력 후, 구매하는 개수와 물건을 영문으로 입력하면,
구매 개수와 물건 그리고 총 구매 값을 출력하라.
입력 개수는 영문으로 입력 zero, one, two, three, four, five, six, seven, eight, nine까지 가능하게 하고,
출력은 0, 1, 2, …9으로 출력하라.
Dictionary를 사용해서 문제를 구현하라.

입출력 예시 1: ‘:’ 다음에 나오는 것이 입력입니다.
enter number of products: 3
enter product price: ramen 500
enter product price: coke 1500
enter product price: beer 3000
enter products to buy: five ramen one coke six beer
5 ramen 1 coke 6 beer for 22000

입출력 예시 2: ‘:’ 다음에 나오는 것이 입력입니다.
enter number of products: 5
enter product price: cheese 4
enter product price: onion 2
enter product price: beef 9
enter product price: pork 6
enter product price: cake 5
enter products to buy: five cake two beef one onion
5 cake 2 beef 1 onion for 45'''

numbers = {'zero':0, 'one':1, 'two':2, 'three':3, 'four':4,
           'five':5, 'six':6, 'seven':7, 'eight':8, 'nine':9}

n = int(input("enter number of products: "))

menu = {}

for i in range(n):
    thing, price = input("enter product price: ").split()
    price = int(price)
    menu[thing] = price

order = input("enter products to buy: ").split()
result = 0
amount = 0

price_is_key = {}
for k in menu.keys():
    price_is_key[menu[k]] = k
#print(price_is_key)

for i in range(len(order)):
    if i%2 == 0:
        amount = 0
        amount = numbers[order[i]]
        print(amount, end=' ')
    else :
        print(price_is_key[menu[order[i]]], end=' ')
        result += amount * menu[order[i]]

print(f"for {result}")
