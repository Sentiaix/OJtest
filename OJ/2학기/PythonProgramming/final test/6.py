'''편의점에 다음과 같은 물건 가격이 있다.
products = { 'beef':25000, 'pork':15000, 'ramen':5000, 'spam':4000, 'rice':50000, 'kiwi':10000, 'eggs':8000}
set에 1/2 할인 물건을 등록하고, products에 없는 물건을 등록하면 1/2 할인 물건 등록을 종료하고, 
할인 set의 요소를 정렬해서 출력하라. (hint: empty set은 set()으로 만든다.)
구매하는 목록을 예시처럼 입력하면 총 구매 금액을 int로 출력하라 

입출력 예시 1:
enter half price item: spam
enter half price item: spam
enter half price item: ramen
enter half price item: quit
half price sale set: ramen spam 
enter things to buy: spam eggs ramen spam
price total is 14500

입출력 예시 2:
enter half price item: spam
enter half price item: rice
enter half price item: pork
enter half price item: kiwi
enter half price item: beef
enter half price item: spam
enter half price item: quit
half price sale set: beef kiwi pork rice spam 
enter things to buy: rice eggs eggs
price total is 41000
'''

products = { 'beef':25000, 'pork':15000, 'ramen':5000, 'spam':4000, 'rice':50000, 'kiwi':10000, 'eggs':8000}

half_price = set()

while True:
    p = input("enter half price item: ")
    if p == 'quit':
        break

    half_price.add(p)

temp = []
print("half price sale set: ", end='')
for i in half_price:
    temp.append(i)
temp.sort()
for i in temp:
    print(i, end=' ')
print()

buy = input("enter things to buy: ").split()
bill = 0 # 최종 금액

for i in range(len(buy)):
    if buy[i] in half_price:
        bill += products[buy[i]] // 2
    else :
        bill += products[buy[i]]

print(f"price total is {bill}")