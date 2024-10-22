/*
  Super Shop Management System
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define RESET "\033[0m" // Reset all attributes
// Text color codes

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Bold text colors
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"

#define ADMIN_USERNAME "1" // Username is fixed for security
#define ADMIN_PASSWORD "1" // Password is fixed for security

void menu();
void customer();
void admin();
void adminLogin();

void viewProduct();
void searchProduct();
void buyProduct();

void addProduct();
void deleteProduct();
void modifyProduct();
void generateSalesReport();
void checkLowStock();

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Starting of Functions  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Globally declaring Structure
struct Product
{
    int ID;
    char name[100];
    char category[100];
    float price;
    float quantity;
};
// Globally Declaring File pointers
FILE *file;
FILE *tempFile;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Main Function starting   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void main(void)
{
    menu();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Menu Function    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void menu()
{
    // code starts here with Welcome message.

    system("cls");
    int i, n;
    time_t t;
    time(&t);
    for (i = 0; i < 70; i++)
    {
        printf("*");
        Sleep(10);
    }
    printf("\n");
    printf(GREEN "*******        Welcome to Super Shop Management System!        *******\n" RESET);
    for (i = 0; i < 70; i++)
    {
        printf("*");
        Sleep(10);
    }
    printf("\n\n");
    printf(BOLD_GREEN "\tCurrent Date and Time: %s" RESET, ctime(&t));
    printf("\t");
    for (i = 0; i < 47; i++)
    {
        printf(BOLD_MAGENTA "." RESET);
        Sleep(20);
    }
    printf("\n\n");
    printf(BLUE "\nPress any key to continue....\n" RESET);
    getch();
    system("cls");

    do
    {
        system("cls");
        printf("\n");
        printf(BOLD_WHITE "                   Continue as...     \n" RESET);
        printf(BOLD_MAGENTA "             ---------------------- \n\n");
        printf(CYAN "   ******************************************\n\n" RESET);
        printf(BOLD_MAGENTA "         1.   Customer.                      \n" RESET);
        Sleep(400);
        printf(BOLD_YELLOW "         2.   Shop Administrators.           \n" RESET);
        Sleep(400);
        printf(BOLD_RED "         3.   Exit the system.               \n\n" RESET);
        Sleep(400);
        printf(CYAN "   ******************************************\n" RESET);
        printf("\n\n");

        // Take input from user
        printf(BOLD_GREEN "Please Enter Your Selection (1-3): " RESET);
        scanf("%d", &n);
        getchar();

        // Process user input
        switch (n)
        {
        case 1:
            customer(); // Calling customer
            break;
        case 2:
            adminLogin(); // calling admin for login.
            break;
        case 3:
            system("cls");
            printf(BOLD_CYAN "Thank you for visiting our shop.\n     Stay Safe. :) \n" RESET); // Exiting
            break;
        default:

            printf(RED "Please select a valid option.\n" RESET);
            Sleep(2500);   // Pause to allow the user to see the message
            system("cls"); // Clear screen
            break;
        }
    } while (n != 3); // Loop until the user selects option 3 to exit
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Customer Function   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void customer()
{
    int i, choice;
    char stay;

    system("cls"); // Clear the screen
    printf(BOLD_MAGENTA "Hello! Welcome To our Shop :)\n" RESET);

    // Simulate a loading animation
    for (i = 0; i < 31; i++)
    {
        printf(".");
        Sleep(50); // Pause to create a loading effect
    }
    printf("\n");
    do
    {
        system("cls");
        printf("\n");
        printf(BOLD_CYAN "What would you like to do? \n" RESET);
        printf(BOLD_RED "-------------------------- \n\n" RESET);
        printf(BOLD_WHITE "1.  View Product. \n" RESET);
        Sleep(20);
        printf(BOLD_WHITE "2.  Search Product. \n" RESET);
        Sleep(20);
        printf(BOLD_WHITE "3.  Buy Product. \n" RESET);
        Sleep(20);
        printf(BOLD_WHITE "4.  Rate Our Shop. \n" RESET);
        Sleep(20);
        printf(BOLD_WHITE "5.  Return to Main Menu. \n\n" RESET); // Added option to return to the main menu
        Sleep(20);
        printf(BOLD_RED "-------------------------- \n\n" RESET);
        Sleep(20);
        printf(GREEN "Enter your choice: " RESET);
        scanf("%d", &choice);
        getchar(); // consumes new line

        switch (choice)
        {
        case 1:
            viewProduct(); // calling vieew product

            break;
        case 2:
            searchProduct(); // calling search product

            break;
        case 3:
            buyProduct(); // calling Buy Product

            break;
        case 4:
            // deleteFromCart(); //calling view product
            printf("Deleting items from cart...\n");
            break;
        case 5:

            return; // This will exit function and return to the main menu
        default:
            printf("Invalid choice. Please Enter valid option.\n");
            break;
        }
        // asking user if he wants to stay or not
        printf(BOLD_GREEN "\nDo you want to stay in the Customer Menu? (Y/N): " RESET);
        scanf(" %c", &stay); // the space before %c to consume any leftover newline character

    } while (stay == 'Y' || stay == 'y');
    system("cls"); // Clearing screen
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Admin Login Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void adminLogin()
{
    char username[50];
    char password[50];
    int attempts = 3; // Number of login attempts
    char choice;
    system("cls"); // clearing Screen
    while (attempts > 0)
    {
        system("cls");
        printf(BOLD_YELLOW "\t\tWelcome :)\n" RESET);
        printf(CYAN "Please Login to continue......\n\n" RESET);
        printf(MAGENTA "Enter Username: " RESET);
        scanf("%s", username); // username canbe one word
        getchar();             // consuming newline
        printf(BOLD_MAGENTA "Enter Password: " RESET);
        scanf("%s", password);
        getchar(); // consuming new line

        if (strcmp(username, ADMIN_USERNAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0)
        {
            printf(BOLD_BLUE "\n\nLogin successful. Welcome, Admin!\n" RESET);
            for (int i = 0; i < 47; i++)
            {
                printf(BOLD_MAGENTA "." RESET);
                Sleep(20);
            }
            admin();
            return; // Exit the login function on successful login
        }
        else
        {
            attempts--;
            printf("Invalid Username or Password. You have %d attempt(s) left.\n", attempts);
            if (attempts > 0)
            {
                printf("Would you like to try again? (Y/N): ");
                scanf(" %c", &choice);
                getchar();
                if (choice == 'N' || choice == 'n')
                {
                    return; // Exit to the main menu
                }
            }
            else
            {
                printf("No attempts left. Returning to main menu.\n");
                printf("3\n");
                Sleep(1000);
                printf("2\n");
                Sleep(1000);
                printf("1\n");
                Sleep(1000);
                return; // Exit to the main menu after all attempts are used
            }
        }
    }
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Admin  Function  After login >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void admin()
{
    int choice;
    char stay;
    system("cls"); // Clear the screen

    do
    {
        system("cls");
        printf(BOLD_GREEN "\nHey Admin! What would you like to do?\n\n" RESET);
        printf(BOLD_RED "-------------------------- \n\n" RESET);
        printf(BOLD_WHITE "\t1. View Product\n" RESET);
        printf(BOLD_WHITE "\t2. Search Product\n" RESET);
        printf(BOLD_WHITE "\t3. Add Product\n" RESET);
        printf(BOLD_WHITE "\t4. Delete Product\n" RESET);
        printf(BOLD_WHITE "\t5. Edit Product\n" RESET);
        printf(BOLD_WHITE "\t6. Generate Sales Report\n" RESET);
        printf(BOLD_WHITE "\t7. Check Low Stock.\n" RESET);
        printf(RESET "\t8. Return to Main Menu\n\n"); // Option to return to the main menu
        printf(BOLD_RED "-------------------------- \n\n" RESET);
        printf(BOLD_YELLOW "\tEnter your choice: " RESET);
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice)
        {
        case 1:
            viewProduct();
            break;
        case 2:
            searchProduct();
            break;
        case 3:
            addProduct();
            break;
        case 4:
            deleteProduct();
            break;
        case 5:
            modifyProduct();
            break;
        case 6:
            generateSalesReport();
            break;
        case 7:
            checkLowStock();
            break;
        case 8:
            return; // This will exit the function and return to the main menu
        default:
            printf(BOLD_RED "Invalid choice. Please enter a valid option.\n" RESET);
            break;
        }
        // Asking admin if they want to stay in the admin menu
        printf(GREEN "\nDo you want to stay in the Admin Menu? (Y/N): " RESET);
        scanf(" %c", &stay); // The space before %c to consume any leftover newline character
    } while (stay == 'Y' || stay == 'y');
    system("cls"); // Clear the screen
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Adding Product  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void addProduct()
{
    struct Product p1;
    char choice;
    FILE *file = fopen("products.txt", "a+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    do
    {
        system("cls");
        printf("Enter Product ID: ");
        scanf("%d", &p1.ID);
        getchar(); // Consume the newline character

        printf("Enter Product Category: ");
        fgets(p1.category, sizeof(p1.category), stdin);
        p1.category[strcspn(p1.category, "\n")] = 0; // Remove newline character

        printf("Enter Product Name: ");
        fgets(p1.name, sizeof(p1.name), stdin);
        p1.name[strcspn(p1.name, "\n")] = 0; // Remove newline character

        printf("Enter Product Price: ");
        scanf("%f", &p1.price);
        getchar(); // Consume the newline character

        printf("Enter Quantity [pics/KG]: ");
        scanf("%f", &p1.quantity);
        getchar(); // Consume the newline character

        fprintf(file, "%d\t%s\t%s\t%.2f\t%.2f\n", p1.ID, p1.category, p1.name, p1.price, p1.quantity);
        printf(BOLD_CYAN "\nItem Successfully Added. Do you want to add more? (Y/N): " RESET);
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    fclose(file);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Delete Product Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void deleteProduct()
{
    struct Product p;
    int idToDelete, found = 0;

    file = fopen("products.txt", "r");
    tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf(MAGENTA "Enter Product ID to delete: " RESET);
    scanf("%d", &idToDelete);

    while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
    {
        if (p.ID == idToDelete)
        {
            found = 1;
        }
        else
        {
            fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        printf(BOLD_GREEN "Product deleted successfully.\n" RESET);
    }
    else
    {
        remove("temp.txt");
        printf(BOLD_RED "Product not found.\n" RESET);
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   View Product Function     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void viewProduct()
{
    struct Product products[100]; // Assuming a maximum of 100 products for simplicity
    int count = 0;
    int uniqueIDs[100]; // Array to track unique IDs
    int uniqueCount = 0;

    file = fopen("products.txt", "r");
    if (file == NULL)
    {
        printf(BOLD_RED "Error opening file!\n" RESET);
        return;
    }

    // Read products from the file into the products array
    while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &products[count].ID, products[count].category, products[count].name, &products[count].price, &products[count].quantity) != EOF)
    {
        // Check for duplicate IDs
        int isUnique = 1;
        for (int i = 0; i < uniqueCount; i++)
        {
            if (products[count].ID == uniqueIDs[i])
            {
                isUnique = 0;
                break;
            }
        }
        if (isUnique)
        {
            uniqueIDs[uniqueCount++] = products[count].ID; // Add unique ID to the list
            count++;
        }
    }
    fclose(file);

    system("cls");

    // Check if the file was empty
    if (count == 0)
    {
        printf(BOLD_RED "\tNo Products Available Right Now. :( \n" RESET);
        return;
    }

    // Display products grouped by category
    printf(BOLD_YELLOW "\n\t<== Products by Category ==>\n" RESET);
    printf(BOLD_YELLOW "\t___________________________\n" RESET);

    // Loop through each product
    for (int i = 0; i < count; i++)
    {
        int alreadyPrinted = 0;
        // Check if this category has already been printed
        for (int k = 0; k < i; k++)
        {
            if (strcmp(products[i].category, products[k].category) == 0)
            {
                alreadyPrinted = 1;
                break;
            }
        }
        // If not printed, print all products in this category
        if (!alreadyPrinted)
        {
            printf(BOLD_GREEN "\nCategory: %s\n" RESET, products[i].category);
            printf("ID     Name                 Price     Quantity\n");
            printf("---------------------------------------------\n");
            for (int j = 0; j < count; j++)
            {
                if (strcmp(products[i].category, products[j].category) == 0)
                {
                    printf("%-6d %-20s %-8.2f %.2f\n", products[j].ID, products[j].name, products[j].price, products[j].quantity);
                }
            }
            printf("---------------------------------------------\n");
        }
    }
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Searching Product Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void searchProduct()
{
    struct Product p1;
    char choice, repeat;
    char searchTerm[100];
    int found = 0;

    do
    {
        system("cls");
        FILE *file = fopen("products.txt", "r");
        if (file == NULL)
        {
            printf(BOLD_RED "Error opening file!\n" RESET);
            return;
        }

        printf(GREEN "Search by [C]ategory or [N]ame? -> " RESET);
        scanf(" %c", &choice);
        getchar(); // Consume the newline character

        if (choice == 'C' || choice == 'c')
        {
            printf(BOLD_BLUE "\n\nEnter category to search: " RESET);
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

            printf(BOLD_YELLOW "\n\t<== Products in Category: %s ==>\n" RESET, searchTerm);
            printf("ID     Name                 Price     Quantity\n");
            printf("---------------------------------------------\n");

            while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF)
            {
                if (strcasecmp(p1.category, searchTerm) == 0)
                {
                    printf("%-6d %-20s %-8.2f %.2f\n", p1.ID, p1.name, p1.price, p1.quantity);
                    found = 1;
                }
            }
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf(BOLD_BLUE "\n\nEnter name to search: " RESET);
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

            printf(BOLD_YELLOW "\n\t<== Products with Name: %s ==>\n" RESET, searchTerm);
            printf("ID     Category            Price     Quantity\n");
            printf("---------------------------------------------\n");

            while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF)
            {
                if (strcasecmp(p1.name, searchTerm) == 0)
                {
                    printf("%-6d %-20s %-8.2f %.2f\n", p1.ID, p1.category, p1.price, p1.quantity);
                    found = 1;
                }
            }
        }
        else
        {
            printf(BOLD_RED "Invalid choice.\n" RESET);
        }

        if (found == 0)
        {
            printf(BOLD_RED "\n\t\tNo products found. :( \n" RESET);
        }

        fclose(file);

        printf(BOLD_GREEN "\nDo you want to search again? (Y/N): " RESET);
        scanf(" %c", &repeat);
    } while (repeat == 'Y' || repeat == 'y');
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Modify Product Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void modifyProduct()
{
    struct Product p;
    int idToModify, found;
    char modifyAnother;

    do
    {
        found = 0; // Reset the found flag for each iteration
        system("cls");
        FILE *file = fopen("products.txt", "r");
        FILE *tempFile = fopen("temp.txt", "w");
        if (file == NULL || tempFile == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        printf(BOLD_YELLOW "Enter Product ID to modify: " RESET);
        scanf("%d", &idToModify);
        getchar(); // Consume the newline character

        while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
        {
            if (p.ID == idToModify)
            {
                found = 1;
                printf(BOLD_CYAN "-------------------------------------------------------------\n" RESET);
                printf("Enter new Product Price: ");
                scanf("%f", &p.price);
                getchar(); // Consume the newline character
                printf("Enter new Product Quantity: ");
                scanf("%f", &p.quantity);
                getchar(); // Consume the newline character
            }
            fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
        }

        fclose(file);
        fclose(tempFile);

        if (found)
        {
            remove("products.txt");
            rename("temp.txt", "products.txt");
            printf(BOLD_GREEN "Product modified successfully.\n" RESET);
        }
        else
        {
            remove("temp.txt");
            printf(BOLD_RED "Product not found.\n" RESET);
        }

        printf(BOLD_GREEN "\nDo you want to modify another product? (Y/N): " RESET);
        scanf(" %c", &modifyAnother);
        getchar(); // Consume the newline character
    } while (modifyAnother == 'Y' || modifyAnother == 'y');
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Buy Product Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void buyProduct()
{

    struct Purchase
    {
        char customerName[100];
        char phoneNumber[15];
        int productID;
        int quantity;
        float totalPrice;
    };

    struct CartItem
    {
        struct Product product;
        int quantity;
        float totalPrice;
    };

    struct Product p;
    struct Purchase purchase;
    struct CartItem cart[100]; // Assuming a maximum of 100 items in the cart
    int cartCount = 0;
    int idToBuy, quantity, found;
    float totalPrice = 0.0;
    char addMore;

    FILE *file;
    FILE *tempFile;
    FILE *salesFile;

    system("cls");
    printf(BOLD_YELLOW "Enter your name: " RESET);
    fgets(purchase.customerName, sizeof(purchase.customerName), stdin);
    purchase.customerName[strcspn(purchase.customerName, "\n")] = 0; // Remove newline character

    printf(BOLD_CYAN "Enter your phone number: " RESET);
    fgets(purchase.phoneNumber, sizeof(purchase.phoneNumber), stdin);
    purchase.phoneNumber[strcspn(purchase.phoneNumber, "\n")] = 0; // Remove newline character

    do
    {
        file = fopen("products.txt", "r");
        tempFile = fopen("temp.txt", "w");
        salesFile = fopen("sales.txt", "a+");
        if (file == NULL || tempFile == NULL || salesFile == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        found = 0;
        printf(BOLD_GREEN "-------------------------------------------------------------\n" RESET);
        printf(BOLD_WHITE "\nEnter Product ID to buy: " RESET);
        scanf("%d", &idToBuy);
        printf(BOLD_WHITE "Enter Quantity: " RESET);
        scanf("%d", &quantity);

        while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
        {
            if (p.ID == idToBuy)
            {
                if (p.quantity >= quantity)
                {
                    found = 1;
                    p.quantity -= quantity;
                    float itemTotalPrice = quantity * p.price;
                    totalPrice += itemTotalPrice;

                    cart[cartCount].product = p;
                    cart[cartCount].quantity = quantity;
                    cart[cartCount].totalPrice = itemTotalPrice;
                    cartCount++;

                    fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
                    fprintf(salesFile, "%s\t%s\t%d\t%s\t%d\t%.2f\n", purchase.customerName, purchase.phoneNumber, p.ID, p.name, quantity, itemTotalPrice);

                    printf(CYAN "\nProduct Purchased: %s\n" RESET, p.name);
                    printf(MAGENTA "Total Price for this item: %.2f\n" RESET, itemTotalPrice);
                    printf(BOLD_GREEN "-------------------------------------------------------------\n" RESET);
                }
                else
                {
                    printf(BOLD_RED " Sorry :( \nNot enough quantity available.\n" RESET);
                    found = 1;
                    fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
                }
            }
            else
            {
                fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
            }
        }

        if (!found)
        {
            printf(BOLD_RED "Sorry :( Product not found. \nPlease try again with valid ProductID.>>\n" RESET);
        }

        fclose(file);
        fclose(tempFile);
        fclose(salesFile);

        remove("products.txt");
        rename("temp.txt", "products.txt");
        printf(BOLD_GREEN "-------------------------------------------------------------\n" RESET);
        printf("\nDo you want to add another item? (Y/N): ");
        scanf(" %c", &addMore);
    } while (addMore == 'Y' || addMore == 'y');

    printf(BOLD_BLUE "\nFinal Bill:\n" RESET);
    printf(BOLD_YELLOW "ID     Name                 Category            Quantity  Price\n" RESET);
    printf(BOLD_CYAN "-----------------------------------------------------------------------\n" RESET);
    for (int i = 0; i < cartCount; i++)
    {
        printf("%-6d %-20s %-20s %-9d %.2f\n", cart[i].product.ID, cart[i].product.name, cart[i].product.category, cart[i].quantity, cart[i].totalPrice);
    }
    printf(BOLD_CYAN "-----------------------------------------------------------------------\n" RESET);
    printf("Total Price: %.2f\n", totalPrice);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Generate Bill Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void generateSalesReport()
{

    struct Purchase
    {
        char customerName[100];
        char phoneNumber[15];
        int productID;
        char productName[100];
        int quantity;
        float totalPrice;
    };

    struct Purchase purchase;
    FILE *salesFile = fopen("sales.txt", "r");
    if (salesFile == NULL)
    {
        printf("Error opening sales file!\n");
        return;
    }
    system("cls");
    printf("\nSales Report:\n");
    printf("Customer Name       Phone Number    Product ID   Product Name         Quantity    Total Price\n");
    printf(BOLD_MAGENTA "------------------------------------------------------------------------------------------------\n" RESET);

    while (fscanf(salesFile, "%99[^\t]\t%14[^\t]\t%d\t%99[^\t]\t%d\t%f\n", purchase.customerName, purchase.phoneNumber, &purchase.productID, purchase.productName, &purchase.quantity, &purchase.totalPrice) != EOF)
    {
        printf("%-23s %-15s %-12d %-20s %-10d %.2f\n", purchase.customerName, purchase.phoneNumber, purchase.productID, purchase.productName, purchase.quantity, purchase.totalPrice);
    }

    fclose(salesFile);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Low Stock Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void checkLowStock()
{
    struct Product p;
    FILE *file = fopen("products.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nLow Stock Alert:\n");
    printf("Product ID    Name                 Category            Available Quantity\n");
    printf("-----------------------------------------------------------------------\n");

    while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
    {
        if (p.quantity < 10)
        { // Assuming low stock threshold is 10
            printf("%-12d %-20s %-20s %.2f\n", p.ID, p.name, p.category, p.quantity);
        }
    }

    fclose(file);
}

// end 