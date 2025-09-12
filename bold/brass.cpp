#include<iostream>
#include "brass.h"
using namespace std;
typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string &s, long an, double bal) {
    fullName = s;
    accountNumber = an;
    balance = bal;
}
void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}
void Brass::Withdraw(double amt) {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) {
        cout << "Withdrawal amount must be positive; "
             << "withdrawal cancelled.\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal cancelled.\n";
    }
    restore(initialFormat, prec);
}
double Brass::Balance() const {
    return balance;
}
void Brass::ViewAcct() const {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialFormat, prec);
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r)
    : Brass(s, an, bal) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
    : Brass(ba) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}
void BrassPlus::Withdraw(double amt) {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt <= bal) {
        // Enough balance to withdraw
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        // Withdraw from loan
        double advance = amt - bal;
        owesBank += advance*(1 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialFormat, prec);
}
void BrassPlus::ViewAcct() const {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();
    cout << "Maximum Loan: $" << maxLoan << endl;
    cout <<"Owes the Bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialFormat, prec);
}
format setFormat() {
    return cout.setf(ios_base::fixed, ios_base::floatfield);
}
void restore(format f, precis p) {
    cout.setf(f, ios_base::floatfield);
    cout.precision(p);
}