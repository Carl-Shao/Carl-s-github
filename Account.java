public class Account {

    private String name;
    private double balance;

    // Construct only name
    public Account(String name) {
        this.name = name;
    }

    //construct name and balance
    public Account(String name, double balance) {
        this.name = name;
        setBalance(balance);
    }

    // Getter and Setter function
    public String getName() {
        return name;
    }

    public double getBalance() {
        return balance;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setBalance(double balance) {
        // balance must be positive
        if(balance >= 0.0) {
            this.balance = balance;
        } else {
            this.balance = 0.0;
        }
    }

    public String deposit(double money) {
        if(money >= 0) {
            balance += money;
            return "Deposit successful. New balance: " + balance;
        } else {
            return "money should be positive.";
        }
    }

    public String withdraw(double money) {
        if(money <= balance) {
            balance -= money;
            return "Withdrawal successful. New balance: " + balance;
        } else {
            return "withdrawal amount exceeded account balance.";
        }
    }
}
