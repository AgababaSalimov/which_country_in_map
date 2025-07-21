#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

class Account {
    int accountNumber;
    char name[50];
    char type;
    double balance;

public:
    void createAccount();
    void showAccount() const;
    void modify();
    void deposit(double);
    void withdraw(double);
    void report() const;
    int getAccountNumber() const;
    double getBalance() const;
    char getType() const;
};

void Account::createAccount() {
    cout << "Enter the account number: ";
    cin >> accountNumber;
    cout << "Enter the name of the account holder: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter the type of account (C/S): ";
    cin >> type;
    type = toupper(type);
    cout << "Enter the initial balance: ";
    cin >> balance;
    cout << "Account created successfully!" << endl;
}

void Account::showAccount() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Account Type: " << type << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
}

void Account::modify() {
    cout << "Modify account details for account number: " << accountNumber << endl;
    cout << "Enter new name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter new type of account (C/S): ";
    cin >> type;
    type = toupper(type);
    cout << "Enter new balance: ";
    cin >> balance;
    cout << "Account details modified successfully!" << endl;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
    }
    else {
        cout << "Deposit amount must be positive!" << endl;
    }
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Withdrawal amount must be positive!" << endl;
    }
    else if (amount > balance) {
        cout << "Insufficient balance!" << endl;
    }
    else {
        balance -= amount;
        cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
    }
}

void Account::report() const {
    cout << left << setw(10) << accountNumber
        << setw(20) << name
        << setw(10) << type
        << setw(10) << fixed << setprecision(2) << balance << endl;
}

int Account::getAccountNumber() const { return accountNumber; }
double Account::getBalance() const { return balance; }
char Account::getType() const { return type; }

// Fonksiyon Prototipleri
void writeAccount();
void displayAccount(int);
void modifyAccount(int);
void deleteAccount(int);
void displayAll(int);
void depositWithdraw(int, int);

// Ana Fonksiyon
int main() {
    int choice;
    int accNo;

    do {
        cout << "\n\n===== Bank Management System =====\n";
        cout << "1. New Account\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Balance Enquiry\n";
        cout << "5. All Account Holder List\n";
        cout << "6. Close an Account\n";
        cout << "7. Modify an Account\n";
        cout << "8. Exit\n";
        cout << "Select Your Option (1-8): ";
        cin >> choice;

        switch (choice) {
        case 1:
            writeAccount();
            break;
        case 2:
            cout << "Enter account number: ";
            cin >> accNo;
            depositWithdraw(accNo, 1);
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> accNo;
            depositWithdraw(accNo, 2);
            break;
        case 4:
            cout << "Enter account number: ";
            cin >> accNo;
            displayAccount(accNo);
            break;
        case 5:
            displayAll(0); // Tüm hesapları listele
            break;
        case 6:
            cout << "Enter account number to close: ";
            cin >> accNo;
            deleteAccount(accNo);
            break;
        case 7:
            cout << "Enter account number to modify: ";
            cin >> accNo;
            modifyAccount(accNo);
            break;
        case 8:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Please select a valid option." << endl;
        }

    } while (choice != 8);

    return 0;
}

// Yeni hesap oluşturur
void writeAccount() {
    Account acc;
    acc.createAccount();
    ofstream outFile("accounts.dat", ios::binary | ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
    outFile.close();
}

// Hesap görüntüleme
void displayAccount(int n) {
    Account acc;
    ifstream inFile("accounts.dat", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccountNumber() == n) {
            acc.showAccount();
            found = true;
            break;
        }
    }
    inFile.close();

    if (!found) {
        cout << "Account number " << n << " not found." << endl;
    }
}

// Hesap bilgisi düzenleme
void modifyAccount(int n) {
    Account acc;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccountNumber() == n) {
            acc.modify();
            file.seekp(-static_cast<int>(sizeof(Account)), ios::cur);
            file.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Account number " << n << " not found." << endl;
    }
}

// Hesap silme
void deleteAccount(int n) {
    Account acc;
    ifstream inFile("accounts.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccountNumber() != n) {
            outFile.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
        }
        else {
            found = true;
        }
    }
    inFile.close();
    outFile.close();

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found) {
        cout << "Account number " << n << " closed successfully." << endl;
    }
    else {
        cout << "Account number " << n << " not found." << endl;
    }
}

// Tüm hesapları listeleme
void displayAll(int n) {
    Account acc;
    ifstream inFile("accounts.dat", ios::binary);
    bool found = false;

    cout << "\n\n\tACCOUNT HOLDER LIST\n\n";
    cout << left << setw(10) << "Acc No" << setw(20) << "Name" << setw(10)
        << "Type" << setw(10) << "Balance" << endl;
    cout << "--------------------------------------------------------\n";

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (n == 0 || acc.getAccountNumber() == n) {
            acc.report();
            found = true;
        }
    }
    inFile.close();

    if (!found && n != 0) {
        cout << "No accounts found." << endl;
    }
}

// Para yatırma veya çekme
void depositWithdraw(int n, int option) {
    Account acc;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.getAccountNumber() == n) {
            found = true;
            double amount;
            if (option == 1) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc.deposit(amount);
            }
            else if (option == 2) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc.withdraw(amount);
            }
            file.seekp(-static_cast<int>(sizeof(Account)), ios::cur);
            file.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Account number " << n << " not found." << endl;
    }
}
