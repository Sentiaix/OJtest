'''PYTHON2025 2학기 컴공 
#소스코드 한글지원 안됩니다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------
#문제: 
간단한 은행 계좌 관리 시스템을 구현하시오. 아래 3단계의 지시사항을 따라 코드를 작성하시오. 

1단계: 부모 클래스 BankAccount 구현
다음 명세에 따라 기본 은행 계좌 클래스를 정의하시오.
	- 속성 (Attributes):
		-name: 예금주 이름 (문자열)
		-balance: 계좌 잔액 (정수)
	-메소드 (Methods):
		-__init__(name, balance): 예금주 이름과 초기 잔액을 받아 속성을 초기화한다.
		-deposit(amount): amount만큼 잔액을 증가시키고, "Deposited [amount] won"을 출력한다.
		-withdraw(amount): 출금을 시도한다.
			-잔액이 충분하면: 잔액을 차감하고 "Withdrew [amount] won"을 출력한다.
			-잔액이 부족하면: "Insufficient funds"를 출력하고 출금하지 않는다.
		-print_info(): 예금주와 잔액 정보를 "Owner: [name], Balance: [balance]" 형식으로 출력한다.

2단계: 자식 클래스 SavingsAccount 구현
BankAccount를 상속받아 이자를 지급하는 저축 계좌 클래스를 정의하시오.
	-새로운 속성:
		-interest_rate: 이자율 (실수형, 예: 0.1은 10%)
	-메소드:
		-__init__(name, balance, interest_rate):
			-이자율(interest_rate) 속성을 추가로 설정한다.
		- add_interest(): 현재 잔액에 이자율을 곱해 이자를 계산하고, 이를 잔액에 더한다. 
		    "Interest added: [amount] won"을 출력한다.

3단계: 실행 코드 작성
위에서 만든 클래스들을 테스트하기 위해 다음 순서대로 실행 코드를 작성하시오.
	a. Alice의 일반 계좌(BankAccount)를 생성한다 (초기 잔액 1,000원).
		- print_info()로 초기 상태를 출력한다.
		- 2,000원 출금을 시도하여 "Insufficient funds" 메시지가 뜨는지 확인한다.
	b. Bob의 저축 계좌(SavingsAccount)를 생성한다 (초기 잔액 5,000원, 이자율 0.1).
		-print_info()로 초기 상태를 출력한다.
		-add_interest()를 호출하여 이자를 지급한다.
		-다시 print_info()를 호출하여 잔액이 5,500원이 되었는지 확인한다.
#----------------------------------------------------------------------------------------------------------------------------------------------------------

# 예제 
print("--- Testing Alice's Account ---")
alice_acc = BankAccount("Alice", 1000)
alice_acc.print_info()
alice_acc.withdraw(2000)  

print("\n--- Testing Bob's Savings Account ---")
bob_savings = SavingsAccount("Bob", 5000, 0.1)
bob_savings.print_info()
bob_savings.add_interest() 
bob_savings.print_info()  

#실행 결과:
--- Testing Alice's Account ---
Owner: Alice, Balance: 1000
Insufficient funds

--- Testing Bob's Savings Account ---
Owner: Bob, Balance: 5000
Interest added: 500 won
Owner: Bob, Balance: 5500
'''

class BankAccount:
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance
    
    def deposit(self, amount):
        self.balance += amount
        print(f"Deposited {amount} won")
    
    def withdraw(self, amount):
        if self.balance < amount :
            print("Insufficient funds")
        else :
            self.balance -= amount
            print(f"Withdrew {amount} won")
        
    def print_info(self):
        print(f"Owner: {self.name}, Balance: {self.balance}")


class SavingsAccount(BankAccount):
    def __init__(self, name, balance, interest_rate):
        super().__init__(name, balance)
        self.interest_rate = interest_rate
    
    def add_interest(self):
        amount = self.balance * self.interest_rate
        amount = int(amount)
        self.balance += amount
        print(f"Interest added: {amount} won")

print("--- Testing Alice's Account ---")
alice_acc = BankAccount("Alice", 1000)
alice_acc.print_info()
alice_acc.withdraw(2000)  

print("\n--- Testing Bob's Savings Account ---")
bob_savings = SavingsAccount("Bob", 5000, 0.1)
bob_savings.print_info()
bob_savings.add_interest() 
bob_savings.print_info()