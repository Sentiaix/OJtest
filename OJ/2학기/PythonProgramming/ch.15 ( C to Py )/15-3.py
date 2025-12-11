'''
입력 받은 문자열의 영어 단어를 나누어서 2차원 배열에 넣는 parsing 함수를 작성하라. 
parsing 함수는 영어 단어 수를 반환한다. 
영어 단어는 소문자 대문자로만 만들어 진다고 가정한다. (don’t이나 pal’s 같은 단어는 없다고 가정한다.) 
main함수는 변경 금지이다.
int main(){
	char str[256];
	char str2d[64][64];
	int size;
	scanf("%[^\n]s", str);
	size = parsing(str2d, str);
	for( int i = size-1 ; i >= 0; i--){
		printf("%s ", str2d[i] );
	}
	printf("\n");
}

입출력 예시 1:
Print it backward please.
please backward it Print

입출력 예시 2:
No numbers like 256 and 32. No punctuations like ? and !
and like punctuations No and like numbers No

입출력 예시 3:
Foot Foot still likes to roam around.
around roam to likes still Foot Foot
** C 문제를 Python으로 변환한 문제입니다. **
** main함수를 구현 할 필요 없고, 결과만 일치하면 됩니다. **
'''

def parsing(s, words):
    current = ""
    
    for ch in s:
        if ch.isalpha(): # 알파벳이면 단어 계속 추가
            current += ch
        else:            # 알파벳이 아니면 단어 종료
            if current != "":
                words.append(current)
                current = ""
    
    # 마지막 단어 처리
    if current != "":
        words.append(current)
    
    return len(words)


s = input()
words = []
count = parsing(s, words)

for i in range(count - 1, -1, -1):
    print(words[i], end=' ')
print()
