public class BankMain {

    public static void main(String[] args) {
        // Test Base Account
        System.out.println("+++++++++ Base Account Test +++++++++");
        Account account = new Account("6667 1001 338", 1000.00);
        account.displayAccountInfo();
        account.deposit(200);
        account.withdraw(400);
        account.withdraw(3000);
        account.displayAccountInfo();

        // Test Savings Account
        System.out.println("\n\n+++++++ Savings Account Test +++++++");
        Account savingsAccount = new SavingsAccount("5623 9887 642",
                600, 0.03);
        savingsAccount.displayAccountInfo();
        savingsAccount.deposit(1000);
        savingsAccount.withdraw(500);
        savingsAccount.displayAccountInfo();

        // Test Checking Account
        System.out.println("\n\n++++++ Checking Account Test ++++++");
        Account checkingAccount = new CheckingAccount("1124 3897 557",
                5000, 0.01, 1000);
        checkingAccount.displayAccountInfo();
        checkingAccount.deposit(1000);
        checkingAccount.withdraw(2000);
        checkingAccount.withdraw(4500);
        checkingAccount.withdraw(1000);

        //
    }
}
