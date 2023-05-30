#include <iostream> 
#include <Windows.h> 
using namespace std;


double getDouble() {

	double a;
	while (!(cin >> a)) {

		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Ошибка ввода" << endl;
		return a;
	}
}

class BankAccount {
	friend bool transfer(BankAccount&, BankAccount&, double);
private:
	int accountNumber;
	double interestRate;
	double balance;
public:
	BankAccount(int accountNumber, double balance) {
		this->accountNumber = accountNumber;
		this->balance = balance;
		this->interestRate = 0;
	}
	void deposit(double value) {
		this->balance += value;
	}
	bool withdraw(double value) {

		if (this->balance >= value) {
			this->balance -= value;
			return true;
		}
		else
			return false;
	}
	double getBalance() {
		return this->balance;
	}
	double getInterest() {
		return this->balance * this->interestRate * 1 / 12;
	}
	void setInterestRate(double value) {
		value = value / 100;
		this->interestRate = value;
	}
};

bool transfer(BankAccount& acc1, BankAccount& acc2, double value) {
	if (acc1.balance >= value)
	{
		acc1.withdraw(value);
		acc2.deposit(value);
		return true;
	}
	else 
	{
		return false;
	}
}

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int accountNumber1, accountNumber2;
	double balance1, balance2;
	cout << "Введите номер и баланс первого банковского счета" << endl;
	accountNumber1 = div(getDouble(), 1).quot;
	balance1 = getDouble();
	cout << endl << "Введите номер и баланс второго банковского счета" << endl;
	accountNumber2 = div(getDouble(), 1).quot;
	balance2 = getDouble();

	BankAccount bankAcc1(accountNumber1, balance1);
	BankAccount bankAcc2(accountNumber2, balance2);

	cout << "Введите процентную ставку первого и второго счета" << endl;
	bankAcc1.setInterestRate(getDouble());
	bankAcc2.setInterestRate(getDouble());

	cout << "Введите сумму перевода" << endl; double valuev = getDouble();
	cout << "Баланс первого счета до перевода: " << bankAcc1.getBalance() << endl;
	cout << "Баланс второго счета до перевода: " << bankAcc2.getBalance() << endl;
	if (transfer(bankAcc1, bankAcc2, valuev)) {
		cout << "Баланс первого счета после перевода: " << bankAcc1.getBalance() << endl;
		cout << "Баланс второго счета после перевода: " << bankAcc2.getBalance() << endl;
	}
	else {
		cout << "Ошибка перевода!! Недостаточно средств!!";
	}
	cout << "Проценты первого счета за месяц: " << bankAcc1.getInterest() << endl;
	cout << "Проценты второго счета за месяц: " << bankAcc2.getInterest() << endl;
}