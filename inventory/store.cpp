
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Product {
public:
    Product(string name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void reduceStock(int amount) {
        if (amount <= stock) {
            stock -= amount;
        }
    }

private:
    string name;
    double price;
    int stock;
};

class Store {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayProducts() const {
        cout << left << setw(15) << "Product" << setw(10) << "Price" << "Stock" << endl;
        cout << "-----------------------------------" << endl;
        for (const auto& product : products) {
            cout << left << setw(15) << product.getName()
                 << setw(10) << product.getPrice()
                 << product.getStock() << endl;
        }
    }

    void purchaseProduct(const string& productName, int quantity) {
        for (auto& product : products) {
            if (product.getName() == productName) {
                if (product.getStock() >= quantity) {
                    product.reduceStock(quantity);
                    cout << "Purchased " << quantity << " of " << productName << endl;
                } else {
                    cout << "Insufficient stock for " << productName << endl;
                }
                return;
            }
        }
        cout << "Product " << productName << " not found." << endl;
    }

private:
    vector<Product> products;
};

int main() {
    Store store;
    store.addProduct(Product("Apple", 0.5, 100));
    store.addProduct(Product("Banana", 0.3, 150));
    store.addProduct(Product("Orange", 0.8, 120));

    while (true) {
        cout << "\nStore Menu:" << endl;
        cout << "1. Display Products" << endl;
        cout << "2. Purchase Product" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            store.displayProducts();
        } else if (choice == 2) {
            cout << "Enter product name: ";
            string productName;
            cin >> productName;
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;
            store.purchaseProduct(productName, quantity);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}