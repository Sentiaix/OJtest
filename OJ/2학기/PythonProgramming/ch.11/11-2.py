'''5개의 물건 가격을 입력 받아 dictionary를 만들고 구매할 물건을 입력하면 가격 합을 출력하라. 
가격은 float이다. String의 split함수를 사용해서 string을 단어 list로 만들 수 있다. 
입출력 예시를 잘 확인해서 구현하라.'''

menu = {}
for i in range(5):
    s = input('Enter product and price: ').split()
    product = s[0]
    price = float(s[1])
    menu[product] = price

req = input('Enter things to buy: ').split()
total_price = 0.0
for i in range(len(req)):
    total_price += menu[req[i]]
print('Price total is', total_price)