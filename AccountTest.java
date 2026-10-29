import javax.swing.*;

public class AccountTest {
    public static void main(String[] args) {

        // b) create an object of class Account
        Account acc1 = new Account("Mike Jones", 500.0);

        // print balance
        showInfo(acc1);

        // j) increase the balance to test deposit function
        double money = Double.parseDouble(JOptionPane.showInputDialog(
                "Enter deposit amount for " + acc1.getName() + ":"));
        JOptionPane.showMessageDialog(null, acc1.deposit(money));

        // k) test withdraw
        double wd = Double.parseDouble(JOptionPane.showInputDialog(
                "Enter withdrawal amount for " + acc1.getName() + ":"));
        JOptionPane.showMessageDialog(null, acc1.withdraw(wd));

        showInfo(acc1);
    }

    private static void showInfo(Account acc) {
        JOptionPane.showMessageDialog(null,
                "Account Holder: " + acc.getName() +
                        "\nBalance: " + acc.getBalance());
    }
}