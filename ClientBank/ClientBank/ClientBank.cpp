#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

#define MAX_ACCOUNTS 10
#define BUFFER_SIZE 50

typedef struct {
    char accountNumber[20];
    char IBAN[20];
    double balance;
} BankAccount;

class ClientBank {
private:
    string firstName;
    string lastName;
    int clientNumber;
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount;

public:
    ClientBank() : accountCount(0) {}

    ClientBank(string fName, string lName, int cNumber)
        : firstName(fName), lastName(lName), clientNumber(cNumber), accountCount(0) {
    }

    ClientBank& operator=(const ClientBank& other) {
        if (this != &other) {
            firstName = other.firstName;
            lastName = other.lastName;
            clientNumber = other.clientNumber;
            accountCount = other.accountCount;
            for (int i = 0; i < accountCount; i++) {
                strncpy(accounts[i].accountNumber, other.accounts[i].accountNumber, 19);
                accounts[i].accountNumber[19] = '\0';
                strncpy(accounts[i].IBAN, other.accounts[i].IBAN, 19);
                accounts[i].IBAN[19] = '\0';
                accounts[i].balance = other.accounts[i].balance;
            }
        }
        return *this;
    }

    void addAccount(const char* accNum, const char* iban, double bal) {
        if (accountCount < MAX_ACCOUNTS) {
            strncpy(accounts[accountCount].accountNumber, accNum, 19);
            accounts[accountCount].accountNumber[19] = '\0';
            strncpy(accounts[accountCount].IBAN, iban, 19);
            accounts[accountCount].IBAN[19] = '\0';
            accounts[accountCount].balance = bal;
            accountCount++;
            printf("✓ Акаунт добавен успешно!\n");
        }
        else {
            printf("✗ Не мога да добавя повече акаунти!\n");
        }
    }

    void removeAccount(const char* iban) {
        for (int i = 0; i < accountCount; i++) {
            if (strcmp(accounts[i].IBAN, iban) == 0) {
                for (int j = i; j < accountCount - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                accountCount--;
                printf("✓ Акаунт изтрит успешно!\n");
                return;
            }
        }
        printf("✗ Акаунт не намерен!\n");
    }

    BankAccount* findAccount(const char* iban) {
        for (int i = 0; i < accountCount; i++) {
            if (strcmp(accounts[i].IBAN, iban) == 0) {
                return &accounts[i];
            }
        }
        return NULL;
    }

    void deposit(const char* iban, double amount) {
        BankAccount* account = findAccount(iban);
        if (account) {
            account->balance += amount;
            printf("✓ Депозит от %.2f успешен!\n", amount);
        }
        else {
            printf("✗ Акаунт не намерен!\n");
        }
    }

    void withdraw(const char* iban, double amount) {
        BankAccount* account = findAccount(iban);
        if (account) {
            if (account->balance >= amount) {
                account->balance -= amount;
                printf("✓ Теглене от %.2f успешно!\n", amount);
            }
            else {
                printf("✗ Недостатъчни средства!\n");
            }
        }
        else {
            printf("✗ Акаунт не намерен!\n");
        }
    }

    double totalBalance() {
        double sum = 0;
        for (int i = 0; i < accountCount; i++) {
            sum += accounts[i].balance;
        }
        return sum;
    }

    void printClientInfo() {
        printf("\n========================================\n");
        printf("Клиент: %s %s\n", firstName.c_str(), lastName.c_str());
        printf("Номер на клиент: %d\n", clientNumber);
        printf("Брой акаунти: %d\n", accountCount);
        printf("----------------------------------------\n");
        if (accountCount > 0) {
            printf("Акаунти:\n");
            for (int i = 0; i < accountCount; i++) {
                printf("  %d. IBAN: %s | Номер: %s | Салдо: %.2f BGN\n",
                    i + 1, accounts[i].IBAN, accounts[i].accountNumber, accounts[i].balance);
            }
            printf("----------------------------------------\n");
            printf("Общо салдо: %.2f BGN\n", totalBalance());
        }
        else {
            printf("Няма акаунти.\n");
        }
        printf("========================================\n");
    }

    int getClientNumber() const {
        return clientNumber;
    }

    int getAccountCount() const {
        return accountCount;
    }

    string getFullName() const {
        return firstName + " " + lastName;
    }
};

class Bank {
private:
    int TableEnd;
    int Size;
    ClientBank* Table;

public:
    Bank(int size) : Size(size), TableEnd(0) {
        Table = new ClientBank[Size];
    }

    ~Bank() {
        delete[] Table;
    }

    void Append(const ClientBank& client) {
        if (TableEnd < Size) {
            Table[TableEnd] = client;
            TableEnd++;
            printf("✓ Клиент добавен успешно!\n");
        }
        else {
            printf("✗ Не мога да добавя нови клиенти! Банката е пълна.\n");
        }
    }

    void RemoveClient(int clientNumber) {
        for (int i = 0; i < TableEnd; i++) {
            if (Table[i].getClientNumber() == clientNumber) {
                for (int j = i; j < TableEnd - 1; j++) {
                    Table[j] = Table[j + 1];
                }
                TableEnd--;
                printf("✓ Клиент изтрит успешно!\n");
                return;
            }
        }
        printf("✗ Клиент не намерен!\n");
    }

    void printAllClients() {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║        ИНФОРМАЦИЯ ЗА ВСИЧКИ КЛИЕНТИ      ║\n");
        printf("╚════════════════════════════════════════╝\n");

        if (TableEnd == 0) {
            printf("Няма регистрирани клиенти.\n");
            return;
        }

        printf("Общо клиенти: %d\n\n", TableEnd);

        for (int i = 0; i < TableEnd; i++) {
            printf("%d. ", i + 1);
            Table[i].printClientInfo();
        }
    }

    double getTotalBankBalance() {
        double total = 0;
        for (int i = 0; i < TableEnd; i++) {
            total += Table[i].totalBalance();
        }
        return total;
    }

    ClientBank* findClient(int clientNumber) {
        for (int i = 0; i < TableEnd; i++) {
            if (Table[i].getClientNumber() == clientNumber) {
                return &Table[i];
            }
        }
        return NULL;
    }

    void printBankSummary() {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║          ОБОБЩЕНИЕ НА БАНКАТА          ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("Брой клиенти: %d\n", TableEnd);
        printf("Вместимост: %d\n", Size);
        printf("Свободни места: %d\n", Size - TableEnd);
        printf("Общо салдо на банката: %.2f BGN\n", getTotalBankBalance());
        printf("════════════════════════════════════════\n\n");
    }
};

int main() {
    printf("╔════════════════════════════════════════╗\n");
    printf("║      СИСТЕМА ЗА УПРАВЛЕНИЕ НА БАНКА   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");

    Bank bank(10);

    // Създаване на клиенти и техните акаунти
    printf("--- Добавяне на клиенти ---\n");

    ClientBank client1("Иван", "Петров", 1001);
    client1.addAccount("ACC123", "BG123456789", 500.0);
    client1.addAccount("ACC124", "BG123457890", 1200.0);
    bank.Append(client1);

    ClientBank client2("Мария", "Иванова", 1002);
    client2.addAccount("ACC125", "BG123458901", 750.0);
    bank.Append(client2);

    ClientBank client3("Петър", "Стойчев", 1003);
    client3.addAccount("ACC126", "BG123459012", 2500.0);
    client3.addAccount("ACC127", "BG123460123", 3000.0);
    client3.addAccount("ACC128", "BG123461234", 1500.0);
    bank.Append(client3);

    // Показване на цялата информация
    bank.printBankSummary();
    bank.printAllClients();

    // Демонстрация на операции
    printf("\n--- Демонстрация на операции ---\n\n");

    printf("1. Депозит на 500 BGN на Иван Петров:\n");
    ClientBank* client = bank.findClient(1001);
    if (client) {
        client->deposit("BG123456789", 500.0);
    }

    printf("\n2. Теглене на 200 BGN на Мария Иванова:\n");
    client = bank.findClient(1002);
    if (client) {
        client->withdraw("BG123458901", 200.0);
    }

    printf("\n3. Неудачен опит за теглене на 1000 BGN (недостатъчни средства):\n");
    client = bank.findClient(1002);
    if (client) {
        client->withdraw("BG123458901", 1000.0);
    }

    // Показване на актуализирана информация
    bank.printBankSummary();
    bank.printAllClients();

    printf("\n✓ Програмата завърши успешно!\n");
    return 0;
}
