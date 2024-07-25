
# Warehouse Management System

A simple warehouse management system in C that allows users to add items, remove specific quantities of items, and check the stock of items. The system stores item information in a text file.
# TODO
- Implement user authentication.
- Add functionality to update item prices.
- Create a user-friendly interface.
- More functionality for management.
- Add item categorization.
- Generate reports for stock levels, added items, and removed quantities.


This project is a starting point for a more comprehensive warehouse management system. Contributions and suggestions are welcome!


## Main Functions

### `additem()`
Prompts the user to enter the item name, quantity, and price, and then stores this information in a text file.

### `removeitem()`
Prompts the user to enter the item name and the quantity to remove. It updates the item quantity in the text file accordingly.

### `checkstock()`
Prompts the user to enter the item name and displays the quantity and price of the item from the text file.

## How to Use

1. **Clone the Repository:**
    ```sh
    git clone https://github.com/yourusername/warehouse-management-system.git
    cd warehouse-management-system
    ```

2. **Compile the Code:**
    ```sh
    gcc -o warehouse warehouse.c
    ```

3. **Run the Program:**
    ```sh
    ./warehouse
    ```

