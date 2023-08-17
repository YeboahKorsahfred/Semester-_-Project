#include <iostream>
#include <vector>
#include <string>

class Stock {
public:
    std::string symbol;
    double price;

    Stock(const std::string& s, double p) : symbol(s), price(p) {}
};

class Transaction {
public:
    std::string action; // Buy or Sell
    std::string symbol;
    int quantity;
    double price;

    Transaction(const std::string& a, const std::string& s, int q, double p) : action(a), symbol(s), quantity(q), price(p) {}
};

class TradingApp {
private:
    std::vector<Stock> stocks;
    std::vector<Transaction> transactions;
    double accountBalance;

public:
    TradingApp(double initialBalance) : accountBalance(initialBalance) {
        // Initialize stocks
        stocks.push_back(Stock("AAPL", 150.0));
        stocks.push_back(Stock("GOOG", 2800.0));
        stocks.push_back(Stock("AMZN", 3500.0));
    }

    void displayStocks() {
        for (const Stock& stock : stocks) {
            std::cout << stock.symbol << " - $" << stock.price << std::endl;
        }
    }

    void getAccountInfo() {
        std::cout << "Account Balance: $" << accountBalance << std::endl;
    }

    void depositMoney(double amount) {
        accountBalance += amount;
        std::cout << "Deposited $" << amount << " into the account." << std::endl;
    }

    void buyStock(const std::string& symbol, int quantity) {
        // Implement buying logic
        // Update accountBalance and transactions
    }

    void sellStock(const std::string& symbol, int quantity) {
        // Implement selling logic
        // Update accountBalance and transactions
    }

    void checkTransactions() {
        std::cout << "Transaction History:" << std::endl;
        for (const Transaction& transaction : transactions) {
            std::cout << transaction.action << " " << transaction.quantity << " shares of " << transaction.symbol
                      << " at $" << transaction.price << std::endl;
        }
    }

    // Other methods for UI, error handling, etc.
};

int main() {
    TradingApp app(1000.0);  // Initial account balance

    std::cout << "Available stocks:" << std::endl;
    app.displayStocks();

    app.depositMoney(500.0);  // Deposit $500
    app.getAccountInfo();

    app.buyStock("AAPL", 10);  // Buy 10 shares of AAPL
    app.sellStock("GOOG", 5);  // Sell 5 shares of GOOG

    app.checkTransactions();  // Check transaction history

    return 0;
}