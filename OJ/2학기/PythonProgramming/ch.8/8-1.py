'''PYTHON2025 2학기 컴공 8장 문제 1
#소스코드 한글지원 안됩니다.

공백으로 구분 된 토큰에서 먼저 등장한 것만 유지하고 출력하라.

* 힌트 :  입력 데이터를 리스트로 형식으로 저장하고, 반복문을 통해 요소 중 2번 이상 입력된 요소를 구분한다.

#--------------------------------------------------------------
입력 예시 1:
a b a c b d
출력 예시 1:
a b c d
#--------------------------------------------------------------
입력 예시 2:
c c d q r s s t
출력 예시 2:
c d q r s t'''

chars = input("").split()
printed_list = []

for i in range(len(chars)):
    if chars[i] not in printed_list :
        print(chars[i], end=" ")
        printed_list.append(chars[i])
    