#include <iostream>
#include <string>
#include <iomanip>

// claim the constant size of account array and the function
const int Maxsize = 10;
void cleanInput();

class Bank;// claim the friend class Bank behind the class Account

class Account{
private:
    std::string ownerName;
    double balance;
    int accountNumber;

public:
    // constructure the class Account
    // don't give the parameter for the array of the Account
    Account(){
        ownerName = "";
        balance = 0;
        accountNumber = 0;
    }
    // give the parameter to private member and static value
    Account(std::string name, double Balance, int number){
        ownerName = name;
        balance = Balance;
        accountNumber = number;
        totalAccount++;
    }

    static int totalAccount;
    static int getTotalAccount(){
        return totalAccount;
    };

    friend class Bank;
};

// initialize the static integer of total Account
int Account::totalAccount = 0;

class Bank{
public:
    static void displayAccountDetail(const Account& account){
        // display the detail of the private member in class Account
        std::cout << "\n=============== Account Detail ===============\n";
        std::cout << "Account Number: " << account.accountNumber << "\n";
        std::cout << "Owner Name: " << account.ownerName << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account.balance << "\n";
        std::cout << "--------------------------------------------\n";
    }

    static Account createAccount(){
        int Number = Account::getTotalAccount() + 1;

        std::string name;
        double balance;
        int ID;

        std::cout << "Enter the user name: ";
        getline(std::cin, name);
        std::cout << "Enter the balance: ";
        // check the invalid input of double of balance in class account
        while(!(std::cin >> balance) || balance < 0){
            std::cout << "Input Invalid ! Enter an integer again: ";
            cleanInput();
        }
        cleanInput();
        std::cout << "Enter the account number: ";
        // check the invalid input of integer of ID in class account
        while(!(std::cin >> ID) || ID <= 0){
            std::cout << "Input Invalid ! Enter an ID again: ";
            cleanInput();
        }
        cleanInput();
        std::cout << ">>>> creating the account ...\n";
        return Account(name, balance, ID);
    }
};

int main(){
    Account bankAccount[Maxsize];
    int count = 0;

    int choice;
    do{
        // use loop to choose which service of the bank 
        std::cout << "\n================ Bank Account  ================\n";
        std::cout << "1.Create a new account.\n";
        std::cout << "2.Display detail of all accounts.\n";
        std::cout << "3.Display the total number of accounts.\n";
        std::cout << "0.Exit.\n";
        std::cout << "Please choose your opreate:";
        while(!(std::cin >> choice) || choice > 3 || choice < 0){
            std::cout << "Invalid Option! Please enter your option agin: ";
            cleanInput();
        }
        cleanInput();

        switch (choice)
        {
        case 1:{
            // use function in Bank to create new account
            if (count < Maxsize){
                bankAccount[count] = Bank::createAccount();
                count++;
                std::cout << "Create Account Success.\n";
            }else{
                std::cout << "Account is full.\n";
            }
            break;
        }

        case 2:{
            // use function to display each bank account
            if(count == 0){
                std::cout << "No account yet.\n";
            }else{
                for(int i = 0; i < count; i++){
                    Bank::displayAccountDetail(bankAccount[i]);
                }
            }
            break;
        }

        case 3:{
            std::cout << "The total number of current system account: " << Account::getTotalAccount() << "\n";
            break;
        }
            
        case 0:{
            std::cout << "Thanks for your using. Bye.\n";
            break;
        }

        default:{
            std::cout << "Invalid option!";
            break;
        }
        }
    }while(choice != 0);

    std::cin.ignore();
    std::cin.get();
    return 0;
}

void cleanInput(){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}