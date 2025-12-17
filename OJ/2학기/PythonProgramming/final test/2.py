'''PYTHON2025 2학기 컴공 
#소스코드 한글지원 안됩니다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------
#문제:
거꾸로 단어(palindrome)는 앞에서부터 읽으나 뒤에서부터 읽어도 동일한 문자열을 의미한다. 
예를 들어 “nurses run”, “never odd or even” 과 같은 문장들은 공백을 제거하면 palindrome이 된다.
사용자로부터 문자열을 반복해서 입력받아, 입력된 문자열이 palindrome인지 판별하는 프로그램을 작성하시오.
사용자가 “-1”을 입력하면 프로그램은 종료된다.

요구사항
1.	사용자가 입력한 문자열의 모든 공백을 제거할 것.
2.	대소문자는 구분하지 않는다. (예: “Race Car” → palindrome)
3.	공백 이외의 문자는 그대로 사용한다.
4.	palindrome 여부를 확인하여 다음과 같이 출력할 것:
	- palindrome이면: “Palindrome”
	- palindrome이 아니면: “Not Palindrome”

#----------------------------------------------------------------------------------------------------------------------------------------------------------

#실행 결과 예시:
Enter text: race car
Palindrome
Enter text: nurses
Not Palindrome
Enter text: nurSes run
Palindrome
Enter text: -1
'''

char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
char_a = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
def allLower(s):
    n = len(char)
    for i in range(n):
        if s == char_a[i]:
            return char[i]
    return s
    
def isPalindrome(s):
    new_s = s.split()
    n = len(new_s)
    result = []
    for i in range(n):
        ln = len(new_s[i])
        for j in range(ln):
            result.append(new_s[i][j])
            #print(result)
            
    r_n = len(result)

    for i in range(r_n):
        result[i] = allLower(result[i])
    #print(result)

    rev_result = result[::-1]

    
    for i in range(r_n):
        if result[i] == rev_result[i]:
            pass
        else:
            return f"Not Palindrome"
        
    return f"Palindrome"

while(True):
    s = input("Enter text: ").strip()
    if s == '-1':
        break
    result = isPalindrome(s)
    print(result)
