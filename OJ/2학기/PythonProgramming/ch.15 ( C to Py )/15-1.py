'''입력 받은 문자열의 영어 단어 수를 반환하는 count_words 함수를 작성하라. 
영어 단어는 소문자 대문자로만 만들어 진다고 가정한다. (don’t이나 pal’s 같은 단어는 없다고 가정한다.) 
main함수는 변경 금지이다.
int main(){
	char str[512];
	scanf("%[^\n]s", str);
	printf("%d number of words.\n", count_words(str));
}

입출력 예시 1:
9 lives for cat, 1 for human.
5 number of words.

입출력 예시 2:
Nine lives for cat, one for human.
7 number of words.

입출력 예시 3:
A cat named Foot Foot. He likes to roam.
9 number of words.
'''

n = input().split()

length = len(n)

for i in n:
    if i.isnumeric():
        n.remove(i)

print(f"{len(n)} number of words.")