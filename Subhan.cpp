#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Accessory {
    int id;
    string name;
    double price;
    int quantity;

    Accessory(int id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

class MobileAccessoriesStore {
private:
    vector<Accessory> inventory; 

public:
    
    void addAccessory() {
        int id, quantity;
        string name;
        double price;

        cout << "Enter Accessory ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter Accessory Name: ";
        getline(cin, name);
        cout << "Enter Accessory Price: ";
        cin >> price;
        cout << "Enter Accessory Quantity: ";
        cin >> quantity;

        Accessory newAccessory(id, name, price, quantity);
        inventory.push_back(newAccessory);
        cout << "Accessory added successfully!\n";
    }

   
    void displayInventory() {
        if (inventory.empty()) {
            cout << "No accessories available in the inventory.\n";
            return;
        }

        cout << "\nInventory List:\n";
        cout << "ID\tName\t\tPrice\tQuantity\n";
        for (const auto& accessory : inventory) {
            cout << accessory.id << "\t" << accessory.name << "\t" << accessory.price << "\t" << accessory.quantity << endl;
        }
    }

  
    void sellAccessory() {
        int id, quantity;
        cout << "Enter Accessory ID to sell: ";
        cin >> id;
        cout << "Enter Quantity to sell: ";
        cin >> quantity;

        for (auto& accessory : inventory) {
            if (accessory.id == id) {
                if (accessory.quantity >= quantity) {
                    accessory.quantity -= quantity;
                    double totalCost = accessory.price * quantity;
                    cout << "Sale successful! Total cost: " << totalCost << endl;
                    return;
                } else {
                    cout << "Not enough stock available.\n";
                    return;
                }
            }
        }
        cout << "Accessory not found!\n";
    }


    void exitSystem() {
        cout << "Thank you for using the Mobile Accessories Store Management System!\n";
    }
};

int main() {
    MobileAccessoriesStore store;
    int choice;

    while (true) {
        cout << "\nMobile Accessories Store Management System\n";
        cout << "1. Add New Accessory\n";
        cout << "2. Display Inventory\n";
        cout << "3. Sell Accessory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.addAccessory();
                break;
            case 2:
                store.displayInventory();
                break;
            case 3:
                store.sellAccessory();
                break;
            case 4:
                store.exitSystem();
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
