/**
 * subclass of SavingsAccount
 * get monthly fee
 * support protection of overdraft
 */
public class CheckingAccount extends SavingsAccount{
    private double overdraftLimit;
    private static final double MONTHLY_FEE = 10.0;

    // Construct Function
    public CheckingAccount(String accountNumber, double balance, double interestRate, double overdraftLimit) {
        super(accountNumber, balance, interestRate);
        this.overdraftLimit = overdraftLimit;
    }

    // permit overdraft when balance is not enough
    @Override
    public void withdraw(double money) {
        if (money >= 0) {
            if (balance + overdraftLimit >= money) {
                balance -= money;
                System.out.printf("Withdraw $%.2f, Now Balance: $%.2f%n", money, balance);
                if (balance < 0) {
                    System.out.printf("Warning: Account Overdraft $%.2f%n", -balance);
                }
            } else {
                System.out.printf("Out the limit. Withdraw failed（Max: $%.2f）%n", balance + overdraftLimit);
            }
        } else {
            System.out.println("Money should be positive.");
        }
    }

    @Override
    public double calculateMonthlyFee() {
        return MONTHLY_FEE;
    }

    @Override
    public void displayAccountInfo() {
        System.out.println("============== Account Information ==============");
        System.out.println("Account Number: " + accountNumber);
        System.out.printf("Balance: $%.2f%n", balance);
        System.out.printf("Interest Rate: %.2f%%%n", interestRate * 100);
        System.out.printf("Monthly Interest: $%.2f%n", calculateMonthlyInterest());
        System.out.printf("Monthly Fee: $%.2f%n", calculateMonthlyFee());
        System.out.printf("Overdraft Limit: $%.2f%n", overdraftLimit);
    }

    // Getter Function
    public double getOverdraftLimit() {
        return overdraftLimit;
    }

}
