#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// Create Node class
class Node 
{
public:
    int account_number;
    string account_holder;
    double balance;
    Node * next;
    Node * prev;

    Node(int account_number, string account_holder, float balance) {
        this->account_number = account_number;
        this->account_holder = account_holder;
        this->balance = balance;
        next = nullptr;
        prev = nullptr;
    }
};

// Create Double Linked List class
class DoublyLinkedList 
{
private:
    Node * head;
    Node * tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while(current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Task 1: Add Account at the end
    void add_account(int number, string holder, float balance) {
        Node* newNode = new Node(number, holder, balance);
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Account has added.\n";
    }

    Node* search_node(int acc_no) {
        Node* current = head;
        while (current != nullptr) {
            if (current->account_number == acc_no)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    // Task 2: Search Account
    void search_account(int number) {
        Node* found = search_node(number);
        if (found != nullptr) {
            cout << "\n--- Account Found ---\n";
            cout << "Account Number: " << found->account_number << "\n";
            cout << "Account Holder: " << found->account_holder << "\n";
            cout << "Balance: $" << fixed << setprecision(2) << found->balance << "\n";
        } else {
            cout << "Account number " << number << " was not found.\n";
        }
    }

    // Task 3: Remove Account
    void remove_account(int number) {
        Node* target = search_node(number);
        // jedge if it is empty
        if(target == nullptr) {
            cout << "Account number " << number << " was not found.\n";
            return;
        }

        if (target == head && target == tail) {
            head = tail = nullptr;
        } else if (target == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (target == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }

        delete target;
        cout << "Account has removed.\n";
    }

    // Task 4: Sort
    void sort_accounts() {
        if (head == nullptr || head->next == nullptr) {
            cout << "It is empty.\n";
            return;
        }

        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->account_number > current->next->account_number) {
                    swap(current->account_number, current->next->account_number);
                    swap(current->account_holder, current->next->account_holder);
                    swap(current->balance, current->next->balance);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

        cout << "Accounts has been sorted.\n";
    }

    // Task 5: Display Accounts
    void display_accounts() {
        // judge if the list is empty
        if(head == nullptr) {
            cout << "It is empty.\n";
            return;
        }

        Node* current = head;
        cout << "--------------------------------------\n";
        while (current != nullptr) {
            cout << "Account Number: " << current->account_number << "\n"
                 << "Holder: " << current->account_holder << "\n"
                 << "Balance: $" << fixed << setprecision(2)
                 << current->balance << "\n\n";
            current = current->next;
        }
        cout << "--------------------------------------\n";
    }

    // Task 6: Deposit
    void deposit(int number, double money) {
        if(money <= 0) {
            cout << "You can not add no money.";
            return;
        }
        Node* target = search_node(number);
        if(target == nullptr) {
            cout << "Account number " << number << " was not found.\n";
            return;
        }
        target->balance += money;
        cout << "Account: " << target->account_number << ". New balance: $" 
             << fixed << setprecision(2) << target->balance << "\n";
    }

    // Task 7: Withdraw
    void withdraw(int number, double money) {
        if(money <= 0) {
            cout << "You can not withdraw no money.";
            return;
        }
        Node* target = search_node(number);
        if(target == nullptr) {
            cout << "Account number " << number << " was not found.\n";
            return;
        }
        if(target->balance < money) {
            cout << "The balance is not enough.";
            return;
        }
        target->balance -= money;
        cout << "Account: " << target->account_number << ". New balance: $" 
             << fixed << setprecision(2) << target->balance << "\n";
    }
};

int
main()
{
    DoublyLinkedList bank;
    int choice;

    do {
        cout << "\n========== Bank Management System ==========\n";
        cout << "1. Add Account\n";
        cout << "2. Search Account\n";
        cout << "3. Remove Account\n";
        cout << "4. Sort Accounts\n";
        cout << "5. Display Accounts\n";
        cout << "6. Deposit\n";
        cout << "7. Withdraw\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int acc_no;
            string holder;
            float bal;
            cout << "Enter account number: ";
            cin >> acc_no;
            cin.ignore();
            cout << "Enter account holder name: ";
            getline(cin, holder);
            cout << "Enter initial balance: ";
            cin >> bal;
            bank.add_account(acc_no, holder, bal);
            break;
        }
        case 2: {
            int acc_no;
            cout << "Enter account number to search: ";
            cin >> acc_no;
            bank.search_account(acc_no);
            break;
        }
        case 3: {
            int acc_no;
            cout << "Enter account number to remove: ";
            cin >> acc_no;
            bank.remove_account(acc_no);
            break;
        }
        case 4:
            bank.sort_accounts();
            break;
        case 5:
            bank.display_accounts();
            break;
        case 6: {
            int acc_no;
            float amount;
            cout << "Enter account number: ";
            cin >> acc_no;
            cout << "Enter deposit amount: ";
            cin >> amount;
            bank.deposit(acc_no, amount);
            break;
        }
        case 7: {
            int acc_no;
            float amount;
            cout << "Enter account number: ";
            cin >> acc_no;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            bank.withdraw(acc_no, amount);
            break;
        }
        case 8:
            cout << "Exiting system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    cin.get();
    cin.ignore();
    return 0;
}