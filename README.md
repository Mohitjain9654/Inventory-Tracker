# 🗃️ Inventory Tracker – C++ Console Application

A command-line based inventory management system built using C++. This project helps manage product details such as name, quantity, price, and category with options to add, search, update, or delete records.

---

## 📌 Features

- ➕ Add new inventory items
- 🔍 Search and view item details
- ✏️ Update existing item data
- ❌ Delete inventory items
- 💾 Store inventory using file handling (binary or text files)
- 📜 Display all available inventory records

---

## 🔧 Technologies Used

- **Language:** C++
- **Concepts:**  
  - Object-Oriented Programming (OOP)  
  - File Handling (fstream)  
  - Classes & Structs  
  - Conditional Logic & Loops

---

## 🗂️ Project Structure

```bash
Inventory-Tracker/
├── inventory.cpp # Main source file
├── inventory.txt # Inventory data file (generated at runtime)
└── README.md # Project documentation
```
## 🚀 How to Run

### 📦 Compile the Code

```bash
g++ inventory.cpp -o inventory
```
Run the Program
```bash
./inventory
```
🖥️ This is a terminal-based application. All actions are interactive via command-line menus.

---
### Sample Output
Inventory Management System
1. Add Item
2. Update Item Stock
3. Remove Item
4. Display All Items
5. Save Inventory
6. Load Inventory
7. Exit
Enter your choice: 1

Enter item type (Item or PerishableItem): Item
Enter item name: keyboard
Enter stock quantity: 10
Enter price: 799.99
Item added to inventory.

Inventory Management System
Enter your choice: 1

Enter item type (Item or PerishableItem): PerishableItem
Enter item name: milk
Enter stock quantity: 3
Enter price: 45.5
Enter expiration date (YYYYMMDD): 20250721
Item added to inventory.

Inventory Management System
Enter your choice: 4

Inventory:
Name: keyboard, Stock: 10, Price: $799.99
Name: milk, Stock: 3, Price: $45.5
Expiration Date: 20250721
Warning: Low stock on milk!

Inventory Management System
Enter your choice: 2

Enter item name to update: milk
Enter new stock quantity: 7
Stock for milk updated to 7.

Inventory Management System
Enter your choice: 5

Inventory saved to inventory.txt.

Inventory Management System
Enter your choice: 7

---

🙋‍♂️ Author
Mohit Jain

Feel free to connect or collaborate!

- 🔗 [LinkedIn](https://www.linkedin.com/in/mohit-jain-dev/)  
- 💻 [GitHub](https://github.com/Mohitjain9654)  
- 🌐 [Portfolio Website](https://mohitjain-portfolio.vercel.app/)  
- 📧 Email: mohitjain965405@gmail.com

---
📧 mohitjain965405@gmail.com
