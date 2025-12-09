'''int을 입력 받아 0에서 9가 입력되면, zero, one, two, three, four, five, six, seven,
eight, nine중 하나가 출력되고 0~9수가 아니면 ‘?’를 출력하라.

입출력 예시 1: 0가 입력
0
zero

입출력 예시 2: 6이 입력
6
six

입출력 예시 3: 75가 입력
75
?
'''

# dict에는 key값과 value값이 있다. 이를 한 쌍(key: value)으로 취급한다.
# dict의 key값을 list처럼 호출하면, value가 출력된다.
nums = { 0: 'zero', 1: 'one', 2: 'two', 3: 'three', 4: 'four',
         5: 'five', 6: 'six', 7: 'seven', 8: 'eight', 9: 'nine'}

n = int(input())

clearly_printed = 1 # 값이 dict에 있다면 0으로 바뀜.

for i in nums.keys():
    if n == i:
        print(nums[i])
        clearly_printed = 0
        break

if clearly_printed:
    print("?")