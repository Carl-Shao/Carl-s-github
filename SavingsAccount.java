/**
 * Account to save money
 * subclass from base class Account
 * increase monthly interest
 */
public class SavingsAccount extends Account {

    protected double interestRate;

    // Construct Function
    SavingsAccount(String accountNumber, double balance, double interestRate) {
        super(accountNumber, balance);
        this.interestRate = interestRate;
    }

    // no monthly fee -- return 0
    @Override
    public double calculateMonthlyFee() {
        return 0.0;
    }

    // calculate monthly interest
    public double calculateMonthlyInterest() {
        return balance * interestRate / 12;
    }

    // override display information
    @Override
    public void displayAccountInfo() {
        System.out.println("============== Account Information ==============");
        System.out.println("Account Number: " + accountNumber);
        System.out.printf("Balance: $%.2f%n", balance);
        System.out.printf("Interest Rate: %.2f%%%n", interestRate * 100);
        System.out.printf("Monthly Interest: $%.2f%n", calculateMonthlyInterest());
        System.out.printf("Monthly Fee: $%.2f%n", calculateMonthlyFee());
    }

    // Getter function
    public double getInterestRate() {
        return interestRate;
    }
}
