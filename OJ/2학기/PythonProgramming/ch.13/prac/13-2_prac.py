class BankAccount :
    def __init__(self, name, account_num, balance = 0):
        self.__name = name
        self.__account_num = account_num
        self.__balance = balance
    def __str__(self):
        f_balacne = f"{self.__balance:,}" # f-string을 사용하여 천 단위 구분 쉼표
        # str.format(self.__balance, ',')
        return f"{self.__name}'s account {self.__account_num}'s balance is {f_balacne} won."
    def get_name(self):
        return self.__name
    def get_account_num(self):
        return self.__account_num
    def get_balance(self):
        return self.__balance
    def deposit(self, amount):
        self.__balance += amount
        print(f"{amount} won was deposited. The balance is {self.__balance} won.")
    def withdraw(self, amount):
        if self.__balance < amount :
            print(
                f"Your account balance is {self.__balance} won,"
                f" which is less than the withdrawal request amount {amount} won."
            )
        else :
            self.__balance -= amount

account1 = BankAccount("Jhon", "1234-0001")
print(account1)
account1.deposit(2000)
print(account1)
account1.withdraw(500)
print(account1)
account1.withdraw(5000)