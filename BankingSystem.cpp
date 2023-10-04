
// A simple banking system in C++ that uses a pin number for authentication
#include <iostream>
using namespace std;

// A class to represent a bank account
class BankAccount
{
private:
  // The balance of the account
  double balance;
  // The pin number of the account
  int pin;

public:
  // A constructor to initialize the account with a given balance and pin
  BankAccount(double b, int p)
  {
    balance = b;
    pin = p;
  }
  // A method to check if the pin is correct
  bool checkPin(int p)
  {
    return p == pin;
  }
  // A method to deposit money into the account
  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposit successful. New balance: " << balance << endl;
  }
  // A method to withdraw money from the account
  void withdraw(double amount)
  {
    if (balance >= amount)
    {
      balance -= amount;
      cout << "Withdrawal successful. New balance: " << balance << endl;
    }
    else
    {
      cout << "Insufficient funds." << endl;
    }
  }
  // A method to display the balance of the account
  void display()
  {
    cout << "The balance of the account is: " << balance << endl;
  }
};

// A main function to test the banking system
int main()
{
  // Create a bank account object with an initial balance of 1000 and a pin of 1234
  BankAccount ba(10000, 1234);
  // Declare a variable to store the user's choice of operation
  int choice;
  // Declare a variable to store the user's input of pin
  int pin;
  // Declare a variable to store the user's input of amount
  double amount;
  // Display a welcome message
  cout << "+--------------------------------+" << endl;
  cout << "| Welcome to the banking system. |" << endl;
  cout << "+--------------------------------+" << endl;
  cout << endl;
  // Prompt the user to enter the pin
  cout << "Please enter your pin: ";
  cin >> pin;
  cout << endl;
  // Check if the pin is correct
  while (1)
  {
    if (ba.checkPin(pin))
    {
      // Display a menu of operations
      cout << "Please choose an operation:" << endl;
      cout << "1. Deposit" << endl;
      cout << "2. Withdraw" << endl;
      cout << "3. Display balance" << endl;
      cout << "4. Exit" << endl;
      // Get the user's choice of operation
      cout << "Enter your choices: ";
      cin >> choice;
      // Perform the operation based on the choice
      switch (choice)
      {
      case 1:
        // Deposit operation
        cout << "Please enter the amount to deposit: ";
        cin >> amount;
        ba.deposit(amount);
        cout << endl;
        break;
      case 2:
        // Withdraw operation
        cout << "Please enter the amount to withdraw: ";
        cin >> amount;
        ba.withdraw(amount);
        cout << endl;
        break;
      case 3:
        // Display balance operation
        ba.display();
        cout << endl;
        break;
      case 4:
        // Exit operation
        exit(1);
        cout << "Thank you for using the banking system. Goodbye." << endl;
        break;
      default:
        // Invalid choice
        cout << "Invalid choice. Please try again." << endl;
        break;
      }
    }
    else
    {
      // Incorrect pin
      cout << "Incorrect pin. Access denied." << endl;
    }
  }
}