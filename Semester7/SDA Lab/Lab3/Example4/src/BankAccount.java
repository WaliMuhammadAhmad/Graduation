public class BankAccount {
    private String accountNumber;
    private double balance;

    BankAccount(String accountNumber, double balance){
        this.accountNumber =accountNumber;
        this.balance=balance;
    }

    public  void deposit(double amount){
        if(amount>0){
            balance+=amount;
        }
    }

    public void widthdraw(double amount){
        if(amount>0&&amount<=balance){
            balance-=amount;
        }
    }
}
