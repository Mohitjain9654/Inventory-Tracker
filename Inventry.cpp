#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Base Item class
class Item {
protected:
    string name;
    int stock;
    double price;

public:
    Item(string name = "", int stock = 0, double price = 0.0) : name(name), stock(stock), price(price) {}

    virtual ~Item() {}

    virtual void display() const {
        cout << "Name: " << name << ", Stock: " << stock << ", Price: $" << price << endl;
    }

    string getName() const { return name; }
    int getStock() const { return stock; }
    void setStock(int stock) { this->stock = stock; }
    double getPrice() const { return price; }

    virtual void save(ofstream& outFile) const {
        outFile << "Item " << name << " " << stock << " " << price << endl;
    }
};

// Derived class for specialized items (if needed)
class PerishableItem : public Item {
    int expirationDate;

public:
    PerishableItem(string name = "", int stock = 0, double price = 0.0, int expirationDate = 0)
        : Item(name, stock, price), expirationDate(expirationDate) {}

    void display() const {
        Item::display();
        cout << "Expiration Date: " << expirationDate << endl;
    }

    void save(ofstream& outFile) const {
        outFile << "PerishableItem " << name << " " << stock << " " << price << " " << expirationDate << endl;
    }
};

// Inventory class
class Inventory {
    vector<Item*> items;

public:
    ~Inventory() {
        for (size_t i = 0; i < items.size(); ++i) {
            delete items[i];
        }
    }

    void addItem(Item* item) {
        items.push_back(item);
        cout << "Item added to inventory.\n";
    }

    void updateItem(const string& name, int newStock) {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i]->getName() == name) {
                items[i]->setStock(newStock);
                cout << "Stock for " << name << " updated to " << newStock << ".\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void removeItem(const string& name) {
        for (auto it = items.begin(); it != items.end(); ++it) { //auto is a type specifier that tells the compiler to deduce the type of a variable automatically
            if ((*it)->getName() == name) {
                delete *it;
                items.erase(it);
                cout << "Item " << name << " removed from inventory.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void displayAllItems() const {
        cout << "Inventory:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            items[i]->display();
            if (items[i]->getStock() < 5) {
                cout << "Warning: Low stock on " << items[i]->getName() << "!\n";
            }
        }
    }

    void saveInventory(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file for saving.\n";
            return;
        }
        for (size_t i = 0; i < items.size(); ++i) {
            items[i]->save(outFile);
        }
        outFile.close();
        cout << "Inventory saved to " << filename << ".\n";
    }

    void loadInventory(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for loading.\n";
            return;
        }
        items.clear();
        
        string type, name;
        int stock;
        double price;
        while (inFile >> type >> name >> stock >> price) {
            if (type == "Item") {
                items.push_back(new Item(name, stock, price));
            } else if (type == "PerishableItem") {
                int expirationDate;
                inFile >> expirationDate;
                items.push_back(new PerishableItem(name, stock, price, expirationDate));
            }
        }
        inFile.close();
        cout << "Inventory loaded from " << filename << ".\n";
    }
};

// Function to get user input for adding a new item
void addItemToInventory(Inventory& inventory) {
    string type, name;
    int stock, expirationDate;
    double price;

    cout << "Enter item type (Item or PerishableItem): ";
    cin >> type;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter stock quantity: ";
    cin >> stock;
    cout << "Enter price: ";
    cin >> price;

    if (type == "PerishableItem") {
        cout << "Enter expiration date (YYYYMMDD): ";
        cin >> expirationDate;
        inventory.addItem(new PerishableItem(name, stock, price, expirationDate));
    } else {
        inventory.addItem(new Item(name, stock, price));
    }
}

int main() {
    Inventory inventory;
    int choice;
    string name;
    int stock;
    
    while (true) {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item Stock\n";
        cout << "3. Remove Item\n";
        cout << "4. Display All Items\n";
        cout << "5. Save Inventory\n";
        cout << "6. Load Inventory\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItemToInventory(inventory);
                break;
            case 2:
                cout << "Enter item name to update: ";
                cin >> name;
                cout << "Enter new stock quantity: ";
                cin >> stock;
                inventory.updateItem(name, stock);
                break;
            case 3:
                cout << "Enter item name to remove: ";
                cin >> name;
                inventory.removeItem(name);
                break;
            case 4:
                inventory.displayAllItems();
                break;
            case 5:
                inventory.saveInventory("inventory.txt");
                break;
            case 6:
                inventory.loadInventory("inventory.txt");
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}