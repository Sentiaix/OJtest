'''5개의 요소가 들어가는 set를 만들 때까지 입력을 요구하는 코드를 작성하라. 
Set가 만들어지면, Set의 요소를 정렬해서 출력하라. 
Set의 요소는 모두 string이라고 가정한다. '''

words_set = {'',}
words_set.clear()

while len(words_set) < 5 :
    s = input('Enter set element: ').strip()
    words_set.add(s)

words_list = list(words_set)
words_list.sort()
for i in range(len(words_list)):
    print(words_list[i], end=' ')