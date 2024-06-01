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
    string name;
    double price;
    int stock;
};
// Define a class to represent a store
class Store {
public:
    void addItem(const Product& product) {
        items.push_back(product);
    }
    //Function to display all products in the stores
    void displayItems() const {
        cout << left << setw(20 ) << "Item" << setw(15) << "Price" << "Stock" << endl;
        cout << "********************************************************" << endl;

        for ( const auto & product : items ) {
            cout << left << (20) << product.getName()
                 << setw (15) << product.getPrice()
                 << product.getStock() << endl;

        }
    }
   
    //here now 
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
    vector <Product> items;
}; 

int main(){
    Store store;
    store.addItem(Product("Camera", 201.1, 30));
    store.addItem(Product("Battries", 13.25, 13));
    store.addItem(Product("Smart TV", 100, 87));
    store.addItem(Product("DVD Player", 50.50, 32));
    store.addItem(Product("Shaving Machine", 20.00, 37));
    store.addItem(Product("Back Pack", 12.10, 50));

    //Writes store name.
    cout << "ABC Corner Store\n";

 
    while (true){
        cout << "\n Display Menu:" << endl;
        cout << "1. Show Product:" << endl;
        cout << "2. Buy Product:" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Your Choice:";
        
        int choice;
        
        cin >> choice;
        ;
    // bottom 
        if (choice == 1) {
            store.displayItems();
        } else if (choice == 2) {
            cout << "Enter product name: ";
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