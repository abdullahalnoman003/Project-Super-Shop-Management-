# 🛒 **The Daily Market Management System**  

The **Daily Market Management System** is a powerful, console-based retail management solution built in **C programming language**. Designed for small to medium-sized businesses, this project handles inventory, sales, and staff operations seamlessly, ensuring efficient workflows for store owners and an intuitive shopping experience for customers.  

---

## ✨ **Key Features**  

### **🔹 Customer Module**  
- **View Products**: Easily view all products from shop.  
- **Search Products**: Easily search products from shop by name or category.  
- **Buy Products**: Easily purchase items by selecting a product ID and quantity.  
- **Bill Generation**: Displays itemized bills with accurate total prices and VAT calculations.  
- **Feedback**: Easily give feedback about store.    

### **🔹 Staff Module**  
- **🔑 Staff Login**: Secure authentication using username and password.  
- **Inventory Management**:  
  - Add, update, or delete products from inventory.  
  - Search products by name or category.  
  - Group and display products by categories.  
- **Low Stock Alerts**: View products running low on stock.  

### **🔹 Admin Module**  
- **Manage Store**: Easily Manage the store.  
- **Manage Staffs**: Easily manage staff members, modify them as needed.  
- **Generate Report**: Generate Customer review, Sales report.  
- **Backup Data**: Backup every data including staff, product, sales and more.

---

## 📂 **File Structure**  

| **File**          | **Purpose**                                        |  
|--------------------|----------------------------------------------------|  
| `main.c`           | Core program logic.                               |  
| `products.txt`     | Stores product details (ID, category, name, price, stock). |  
| `sales.txt`        | Logs transaction history.                         |  
| `staff.txt`        | Stores staff login credentials.                   |  

---

## ⚙️ **How It Works**  

### **1. Menu Navigation**  
- A user-friendly menu guides customers and staff to their respective modules.  
- Staff and Admin must log in to access administrative and inventory management features.  

### **2. Real-Time Product Management**  
- Add new products or update existing inventory dynamically.  
- View low-stock items and maintain optimal inventory levels.  

### **3. Persistent Data Storage**  
- Product, sales, and staff information is stored in text files for data consistency across sessions.  

### **4. Timestamp Integration**  
- Leverages the `time.h` library to record precise timestamps for all transactions.  

---

## 🛠️ **Technologies Used**  

- **C Programming Language**: For core functionality and logic.  
- **File Handling**: To store and update product, sales, and staff data persistently.  
- **Libraries**:  
  - `stdio.h` for standard input/output operations.  
  - `string.h` for string manipulations.  
  - `time.h` for handling date and time.  
  - `windows.h` for UI enhancements (e.g., `Sleep` and `system("cls")`).  

---

## 🚀 **Getting Started**  

### **Step 1: Clone the Repository**  
```bash  
git clone https://github.com/yourusername/daily-market.git  
cd daily-market  
```  

### **Step 2: Compile the Code**  
Using GCC:  
```bash  
gcc main.c -o market -lm  
```  

### **Step 3: Run the Program**  
```bash  
./market  
```  

---

## 📈 **Future Enhancements**  

- **Online Store**: Implement functionality to run Online.  
- **Database Integration**: Use SQL databases to replace text files for better performance and scalability.  
- **Graphical Interface**: Upgrade from the console interface to a modern GUI.  
- **Barcode Scanner Integration**: Support for scanning product barcodes.  

---

## 📝 **Sample Data**  

### Example `products.txt` File:  
```  
101   Electronics   Smartphone   250.00   50  
102   Groceries     Rice         20.00    100  
103   Clothing      T-Shirt      15.00    200  
```  

### Example `staff.txt` File:  
```  
1   Abdullah Al Noman   Noman    pass123  
2   Rashedul Islam      Rashed   pass456  
3   Adnan Iqbal         Adnan    pass890  
```  

---

## 💡 **What You’ll Learn**  

By exploring this project, you’ll gain practical experience with:  
- Advanced file handling techniques in C.  
- Struct-based programming for real-world applications.  
- Implementing secure login systems and menu-driven interfaces.  
- Leveraging C libraries like `time.h` for date and time management.  

---

## 🤝 **Contributions**  

Contributions are welcome! Feel free to fork this repository, submit pull requests, or report issues.  

---

## 🏆 **Credits**  

Developed by **Us** as a practical demonstration of C programming skills applied to real-world business scenarios.  

---  
# <p align="center">Thank You 😊<br>Happy Coding!</p>
