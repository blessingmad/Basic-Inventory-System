
//includes the input-output stream library
#include <iostream>
// include the vector library
#include <vector> 
// include the string library
#include <string>
// include the iomanip library for stream manipulators
#include <iomanip>

// use the standard namespace
using namespace std; 


 

//Defines a class to represent a item in the store
class Product {
public: 
    //Constructor to initiate product with name, price snd quantity.
    Product(string name, double price, int stock)
        : name(name), price(price), stock(stock) {}
    //Getter function for the product's name to be displayed when user makes a choice
    string getName() const {return name;}
    //Getter function for price
    double getPrice() const {return price;}
    
    //Getter function for items
    int getStock() const {return stock;}
    
    // function to reduce stock by given number
    void reduceStock(int amount){
        if (amount <= stock) {
            stock -= amount;
        }
    }

private:
    //naming the item
    string name;
    // pricing the item
    double price;
    int stock; // Number of items in store
};
// Define a class to represent a store
class Store {
public:
    void addItem(const Product& product) {
        items.push_back(product);
    }
    //Function to display all products in the stores
   void displayItems() const {
        // Spacing the product, price and stock columns
        cout << left << setw(30 ) << "Product" << setw(20) <<  "Price:$" << "Stock\n" << endl;
        cout << "********************************************************" << endl;

        for ( const auto& product : items ) {
            cout << left << setw(30) << product.getName()
                 << setw (20) << product.getPrice()
                 << product.getStock() << endl;

        }
    }
    //function to manage purchasing of items from the store
    void purchaseItem (const string& itemName, int quantity){
        for (auto& product : items) {
            if (product.getName() == itemName) { 
                if (product.getStock() >= quantity) { 
                    product.reduceStock(quantity);
                   cout << "Purchase" << quantity << " Of " << itemName << endl;
                 
                } else {
                    cout << "Insuficient stock for " << itemName << endl;
                }
                
                return;
                
            }
        }
        cout << "Item" << itemName << "item not found in the store.";
    
    };

private:
    vector <Product> items; // vector to store the shop items
}; 

int main(){
    Store store;
    store.addItem(Product("\n Camera",   199.90, 100));
    store.addItem(Product("Battries",    102.30, 150));
    store.addItem(Product("Smart TV",    210.80, 120));
    store.addItem(Product("Games",   40.10, 100));
    store.addItem(Product("Books",    12.20, 150));
    store.addItem(Product("Accessories\n",   10.00, 120));

    //Writes store name.
    cout << "\n ABC Corner Store\n";

 
    while (true){
        cout << "\n Display Menu:\n" << endl;
        cout << "1. Show Product:" << endl;
        cout << "2. Buy Product:" << endl;
        cout << "3. Exit\n" << endl;
        cout << "\n Enter Your Choice:\n";
        
        int choice;
        
        cin >> choice;
        ;
    //Manage the user's menu choice 
        if (choice == 1) {
            store.displayItems();
        } else if (choice == 2) {
            cout << "\n Enter product name: ";
            string itemName;
            cin >> itemName;
            cout << "Enter Quantity: ";
            int total;
            cin >> total;
            store.purchaseItem(itemName, total);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. please try again" << endl;
            
        }
    }

    return 0;
}



