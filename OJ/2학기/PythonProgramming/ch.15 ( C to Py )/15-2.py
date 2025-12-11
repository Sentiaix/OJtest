'''
문자열(최대 100글자)을 입력받아, 
문자열 바꾸기(replace)/문자 지우기(remove)/문자열 반전(inverse)/문자 검색(search)를 구현하라.
단, switch문을 사용하여 repace/remove/inverse/search를 실행하시오.
(4개 모두 구현해야하며, 부분점수 없음/switch 사용하지 않을시 0점 처리)

[예시 1]
Input >> Hello
===MENU===
1: replace
2: remove
3: inverse
4: search
==========
Select >> 1
Old letter >> l
New letter >> k
Result letter is Hekko.

[예시 2]
Input >> Hello
===MENU===
1: replace
2: remove
3: inverse
4: search
==========
Select >> 2
letter >> l
Result letter is Heo.

[예시 3]
Input >> Hello
===MENU===
1: replace
2: remove
3: inverse
4: search
==========
Select >> 3
Result letter is olleH.

[예시 4]
Input >> Hello
===MENU===
1: replace
2: remove
3: inverse
4: search
==========
Select >> 4
letter >> l
Index number is 2.

[예시 5]
Input >> Hello
===MENU===
1: replace
2: remove
3: inverse
4: search
==========
Select >> 5
Error!
'''

def replace(s, old, new):
    length = len(s)
    for i in range(length):
        if s[i] == old:
            s[i] = new

    return s

def remove(s, char):
    legnth = len(s)
    result = []
    for i in range(legnth):
        if s[i] != char:
            result.append(s[i])

    return result

def inverse(s):
    return s[::-1]

def search(s, char):
    length = len(s)
    for i in range(length):
        if s[i] == char:
            return i
    return -1

s = list(input("Input >> "))

print("===MENU===")
print("1: replace")
print("2: remove")
print("3: inverse")
print("4: search")
print("==========")

select = int(input("Select >> "))
if select == 1:
    old = input("Old letter >> ")
    new = input("New letter >> ")
    result = replace(s, old, new)
    print(f"Result letter is {''.join(result)}.")
elif select == 2:
    char = input("letter >> ")
    result = remove(s, char)
    print(f"Result letter is {''.join(result)}.")
elif select == 3:
    result = inverse(s)
    print(f"Result letter is {''.join(result)}.")
elif select == 4:
    char = input("letter >> ")
    index = search(s, char)
    if index != -1:
        print(f"Index number is {index}.")
    else:
        pass
else:
    print("Error!")