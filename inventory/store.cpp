
#include <iostream> //includes the input-output stream library
#include <vector> // include the vector library
#include <string> // include the string library
#include <iomanip> // include the iomanip library for stream manipulators

using namespace std; // use the standard namespace

//Defines a class to represent a item in the store
class Product {
public: 
    //Constructor to initiate product with name, price snd quantity.
    Product(string name, double price, int stock)
        : name(name), price(price), stock(stock) {}
    //Getter function for the product's name to be displayed when user makes a choice
    string getName() const { return name; }
    //Getter function for price
    double getPrice() const { return price; }
    //Getter function for items
    int getStock() const { return stock; }


    // function to reduce stock by given number
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
// Define a class to represent a store
class Store {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }
    //Function to display all products in the stores
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
    //Writes store name.
    cout << "ABC Corner Store\n";

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