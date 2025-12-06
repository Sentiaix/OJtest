'''PYTHON2025 2학기 컴공 12장 문제 2
#소스코드 한글지원 안됩니다.

#------------------------------------------------------------------------------------------------------------------------------------------------
다음과 같은 기능을 가지는 은행계좌 클래스 BankAccount 클래스를 구현하여라. 
그리고 이 클래스를 이용하여 인스턴스를 생성하여라. 이 클래스는 다음과 같은 속성과 동작을 가진다.

•속성
인스턴스 변수        -->  하는 일
---------------------------------------
__name                  --> 계좌 주인의 이름이 문자열 형으로 저장
__account_num      --> 계좌 번호 "1234-5678"과 같은 문자열 형식으로 저장
__balance                --> 계좌의 잔액을 int 형으로 저장

•동작(메소드)
메소드                     -->  하는 일
-------------------------------------------
__init__()                 -->  계좌 주인의 이름, 계좌번호, 최초 잔액으로 BankAccount를 초기화함
__str__()                  --> 계좌 주인의 이름, 계좌번호, 잔액을 문자열로 반환함
get_name()              --> 이름을 반환하는 메소드
get_account_num()  --> 계좌번호를 반환하는 메소드
get_balance()           --> 계좌 잔액을 반환하는 메소드
deposit(money)        --> money만큼의 돈을 balance에 추가함
withdraw(money)     --> money만큼의 돈이 balance에서 빠져나감. 
                                     만일 balance가 money보다 작으면 계좌 잔액과 인출 요구금액을 출력하고 출금이 되지 않음

BankAccount라는 클래스를 만든 후 다음과 같이 account1이라는 계좌를 생성하고 2,000원을 입금하여라. 
이 계좌 정보를 출력한 후 500원을 출금한 후 다음과 같이 계좌 정보를 출력하여라. 마지막으로 5,000원을 출금하여라.

#--------------------------------------------------------------------------------------------------------------------------------------------------
# 예제    
account1 = BankAccount("Jhon", "1234-0001")
print(account1)
account1.deposit(2000)
print(account1)
account1.withdraw(500)
print(account1)
account1.withdraw(5000)


실행 결과:
Jhon's account 1234-0001's balance is 0 won.
2000 won was deposited. The balance is 2000 won.
Jhon's account 1234-0001's balance is 2,000 won.
Jhon's account 1234-0001's balance is 1,500 won.
Your account balance is 1500 won, which is less than the withdrawal request amount 5000 won.'''

class BankAccount:
    def __init__(self, name = '', account_num = '', balance = 0):
        self.__name = name
        self.__account_num = account_num
        self.__balance = balance
    def __str__(self):
        formatted_balance = f"{self.__balance:,}" # f-string을 사용하여 천 단위 구분 쉼표 추가
        #str.format(self.__balance, ',')
        #locale 모듈을 사용할 수도 있지만, 여기서는 간단한 f-string 방식을 사용
        return f"{self.__name}'s account {self.__account_num}'s balance is {formatted_balance} won."
    def get_name(self):
        return self.__name
    def get_account_num(self):
        return self.__account_num
    def get_balance(self):
        return self.__balance
    def deposit(self, money):
        self.__balance += money
        print(f"{money} won was deposited. The balance is {self.__balance} won.")
    def withdraw(self, money):
        if self.__balance < money:
            print(f"Your account balance is {self.__balance} won, which is less than the withdrawal request amount {money} won.")
        else:
            self.__balance -= money

# 예제
account1 = BankAccount("Jhon", "1234-0001")
print(account1)
account1.deposit(2000)
print(account1)
account1.withdraw(500)
print(account1)
account1.withdraw(5000)