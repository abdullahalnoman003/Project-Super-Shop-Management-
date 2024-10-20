/*
  Super Shop Management System
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define RESET       "\033[0m"        // Reset all attributes
// Text color codes

#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define WHITE       "\033[0;37m"

// Bold text colors
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE   "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN   "\033[1;36m"
#define BOLD_WHITE  "\033[1;37m"

#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "password"

void menu();
void customer();
void admin();
void adminLogin();

void viewProduct();
void searchProduct();
void checkout();
void addtoCart();
void deleteFromCart();

void addProduct();
void deleteProduct();
void editProduct();
void generateBill();

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Starting of Functions  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Customer Function   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void customer() {
    int i, choice;
    char stay;

    system("cls");  // Clear the screen
    printf(BOLD_MAGENTA"Hello! Welcome To our Shop :)\n"RESET);

    // Simulate a loading animation
    for (i = 0; i < 31; i++) {
        printf(".");
        Sleep(50);  // Pause to create a loading effect
    }
    printf("\n");
do{
    system("cls");
    printf("\n");
    printf(BOLD_CYAN"What would you like to do? \n"RESET);
    printf(BOLD_RED"-------------------------- \n\n"RESET);
    printf("1.  View Product. \n");
    Sleep(20);
    printf("2.  Search Product. \n");
    Sleep(20);
    printf("3.  Add to cart. \n");
    Sleep(20);
    printf("4.  Delete from cart? \n");
    Sleep(20);
    printf("5.  Return to Main Menu. \n\n");  // Added option to return to the main menu
    Sleep(20);
    printf(BOLD_RED"-------------------------- \n\n"RESET);
    Sleep(20);
    printf(GREEN"Enter your choice: "RESET);
    scanf("%d", &choice);
    getchar(); //consumes new line

    switch (choice) {
        case 1:
            viewProduct(); //calling vieew product
            
            break;
        case 2:
            searchProduct();   //calling search product
            
            break;
        case 3:
            //addtoCart(); //calling add cart
            printf("Adding items to cart...\n");
            break;
        case 4:
            //deleteFromCart(); //calling view product
            printf("Deleting items from cart...\n");
            break;
        case 5:
            // Return to the main menu
            return;  // This will exit function and return to the main menu
        default:
            printf("Invalid choice. Please Enter valid option.\n");
            break;
    }
// asking user if he wants to stay or not
        printf(BOLD_GREEN"\nDo you want to stay in the Customer Menu? (Y/N): "RESET);
        scanf(" %c", &stay);  // the space before %c to consume any leftover newline character

    } while (stay == 'Y' || stay == 'y');
    system("cls");  // Clearing screen
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Admin Login Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void adminLogin() {
    char username[50];
    char password[50];
    int attempts = 3;  // Number of login attempts
    char choice;
    system("cls"); //clearing Screen
    while (attempts > 0) {
        system("cls");
        printf(BOLD_YELLOW"\t\tWelcome :)\n"RESET);
        printf(CYAN"Please Login to continue......\n\n"RESET);
        printf(MAGENTA"Enter Username: "RESET);
        scanf("%s", username); //username canbe one word
        getchar();// consuming newline
        printf(BOLD_MAGENTA"Enter Password: "RESET);
        scanf("%s", password);
        getchar(); //consuming new line

        if (strcmp(username, ADMIN_USERNAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
            printf(BOLD_BLUE"\n\nLogin successful. Welcome, Admin!\n"RESET);
            for(int i=0; i<47; i++){
            printf(BOLD_MAGENTA"."RESET);
            Sleep(20);}
            admin();
            return;  // Exit the login function on successful login
        } else {
            attempts--;
            printf("Invalid Username or Password. You have %d attempt(s) left.\n", attempts);
            if (attempts > 0) {
                printf("Would you like to try again? (Y/N): ");
                scanf(" %c", &choice);
                getchar();
                if (choice == 'N' || choice == 'n') {
                    return;  // Exit to the main menu
                }
            } else {
                printf("No attempts left. Returning to main menu.\n");
                printf("3\n");
                Sleep(1000);
                printf("2\n");
                Sleep(1000);
                printf("1\n");
                Sleep(1000);
                return;  // Exit to the main menu after all attempts are used
            }
        }
    }
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Admin  Function  After login >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void admin() {
    int choice;
    char stay;
    system("cls");  // Clear the screen

    printf(BOLD_WHITE"\tWelcome back, Admin!\n"RESET);
    for (int i = 0; i < 31; i++) {
        printf(".");
        Sleep(20);  // Pause to create a loading effect
    }
    printf("\n");

    do {
        system("cls");
        printf(BOLD_GREEN"\nWhat would you like to do?\n"RESET);
        printf("1. View Product\n");
        printf("2. Search Product\n");
        printf("3. Add Product\n");
        printf("4. Delete Product\n");
        printf("5. Edit Product\n");
        printf("6. Generate Bill\n");
        printf("7. Return to Main Menu\n");  // Option to return to the main menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
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
                //deleteproduct();
                break;
            case 5:
                //editproduct();
                break;
            case 6:
                //salesReport();
                break;
            case 7:
                return;  // This will exit the function and return to the main menu
            default:
                printf(BOLD_RED"Invalid choice. Please enter a valid option.\n"RESET);
                break;
        }
        // Asking admin if they want to stay in the admin menu
        printf(GREEN"\nDo you want to stay in the Admin Menu? (Y/N): "RESET);
        scanf(" %c", &stay);  // The space before %c to consume any leftover newline character
    } while (stay == 'Y' || stay == 'y');
    system("cls");  // Clear the screen
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Adding Product  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void addProduct(){
    struct addProduct{
        int ID;
        char name[100];
        char category[100];
        float price;
        float Quantity;
    }p1;
    char choice;
    FILE *file;
    file = fopen("products.txt", "a+");
    if (file == NULL){
        printf("Error");
        return;
    }
   do{
    system("cls"); 
    printf("Enter Product ID: ");
    scanf("%d", &p1.ID);
    getchar();
    printf("Enter Product Category: ");
    fgets(p1.category, sizeof(p1.category), stdin);
    p1.category[strcspn(p1.category, "\n")] = 0;  // Remove newline character
    printf("Enter Product Name: ");
    fgets(p1.name, sizeof(p1.name), stdin);
    p1.name[strcspn(p1.name, "\n")] = 0;  // Remove newline character
    printf("Enter Product Price: ");
    scanf("%f", &p1.price);
    getchar();
    printf("Enter Quantity [pics/KG]: ");
    scanf("%f", &p1.Quantity);
    getchar();
    fprintf(file,"%d\t %s\t %s\t %.2f\t %.2f \n",p1.ID, p1.category, p1.name, p1.price, p1.Quantity);
    printf(BOLD_CYAN"\nItem Successfully Added. Do you want to add more? (Y/N):"RESET);
    scanf(" %c", &choice);
    }while (choice =='Y'|| choice =='y');
    fclose(file);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Searching Product Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void searchProduct() {
    struct Product {
        int ID;
        char name[100];
        char category[100];
        float price;
        float quantity;
    } p1;

    char choice;
    char searchTerm[100];
    FILE *file;
    int found = 0;

    file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    system("cls");
    printf(GREEN"Search by [C]ategory or [N]ame? -> "RESET);
    scanf(" %c", &choice);
    getchar();  // Consume the newline character

    if (choice == 'C' || choice == 'c') {
        printf(BOLD_BLUE"Enter category to search: "RESET);
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = 0;  // Remove newline character

        while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF) {
            if (strcasecmp(p1.category, searchTerm) == 0) {
                printf("ID: %d\t\n", p1.ID);
                printf("Category: %s\t\n", p1.category);
                printf("Name: %s\t\n", p1.name);
                printf("Price: %.2f\t\n", p1.price);
                printf("Quantity: %.2f\n\n", p1.quantity);

                found = 1;
            }
        }
    } else if (choice == 'N' || choice == 'n') {
        printf(BOLD_BLUE"Enter name to search: "RESET);
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = 0;  // Remove newline character

        while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF) {
            if (strcasecmp(p1.name, searchTerm) == 0) {
                printf("ID: %d\t\n", p1.ID);
                printf("Category: %s\t\n", p1.category);
                printf("Name: %s\t\n", p1.name);
                printf("Price: %.2f\t\n", p1.price);
                printf("Quantity: %.2f\n", p1.quantity);
                found = 1;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    if (found==0) {
        printf(BOLD_RED"No products found. :( \n"RESET);
    }

    fclose(file);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   View Product Function     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void viewProduct() {
    struct Product {
    int ID;
    char name[100];
    char category[100];
    float price;
    float quantity;
};
    struct Product products[100];  // Assuming a maximum of 100 products for simplicity
    int count = 0;
    FILE *file;

    file = fopen("products.txt", "r");
    if (file == NULL) {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }

    // Read products from the file into the products array
    while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &products[count].ID, products[count].category, products[count].name, &products[count].price, &products[count].quantity) != EOF) {
        count++;
    }
    fclose(file);
    system("cls");
    // Check if the file was empty
    if (count == 0) {
        printf(BOLD_RED"\tNo Products Available Right Now. :( \n"RESET);
        return;
    }
    // Display products grouped by category
    printf(BOLD_YELLOW"\n\tProducts by Category:\n"RESET);
    printf(BOLD_YELLOW"\n\t_____________________\n"RESET);

    for (int i = 0; i < count; i++) {
        printf(BOLD_GREEN"\nCategory: %s\n"RESET, products[i].category);
        printf("ID: %d\n", products[i].ID);
        printf(BOLD_MAGENTA"Name: %s\n"RESET, products[i].name);
        printf("Price: %.2f\n", products[i].price);
        printf("Quantity: %.2f\n", products[i].quantity);

        // Display all products of this category
        for (int j = i + 1; j < count; j++) {
            if (strcmp(products[i].category, products[j].category) == 0) {
                printf("ID: %d\n", products[j].ID);
                printf(BOLD_MAGENTA"Name: %s\n"RESET, products[j].name);
                printf("Price: %.2f\n", products[j].price);
                printf("Quantity: %.2f\n", products[j].quantity);

            }
        }
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Menu Function    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void menu(){
  // code starts here with Welcome message.
  
  system("cls");
  int i,n;
  time_t t;
  time(&t); 
  for ( i = 0; i < 70; i++){
    printf("*");
    Sleep(10);}
    printf("\n");
  printf(GREEN"*******        Welcome to Super Shop Management System!        *******\n"RESET);
    for ( i = 0; i < 70; i++){
    printf("*");
    Sleep(10);}
    printf("\n\n");
  printf(BOLD_GREEN"\tCurrent Date and Time: %s"RESET,ctime(&t));
  printf("\t");
  for(i=0; i<47; i++){
        printf(BOLD_MAGENTA"."RESET);
        Sleep(20);
    }
  printf("\n\n");
	printf(BLUE"\nPress any key to continue....\n"RESET);
  getch();
  system("cls");

do {
    system("cls");
    printf("\n");
    printf(BOLD_WHITE"                   Continue as...     \n"RESET);
    printf(BOLD_MAGENTA"             ---------------------- \n\n");
    printf(CYAN"   ******************************************\n\n"RESET);
    printf(BOLD_MAGENTA"         1.   Customer.                      \n"RESET);
    Sleep(400);
    printf(BOLD_YELLOW"         2.   Shop Administrators.           \n"RESET);
    Sleep(400);
    printf(BOLD_RED"         3.   Exit the system.               \n\n"RESET);
    Sleep(400);
    printf(CYAN"   ******************************************\n"RESET);
    printf("\n\n");

    // Take input from user
    printf(BOLD_GREEN"Please Enter Your Selection (1-3): "RESET);
    scanf("%d", &n);
    getchar();

    // Process user input
    switch (n) {
        case 1:
            customer();  //Calling customer
            break;
        case 2:
            adminLogin();  // calling admin for login.
            break;  
        case 3:
        system("cls");
            printf(BOLD_CYAN"Thank you for visiting our shop.\n     Stay Safe. :) \n"RESET); // Exiting 
            break;  
        default:
        
            printf(RED"Please select a valid option.\n"RESET);
            Sleep(2500);  // Pause to allow the user to see the message
            system("cls");  // Clear screen 
            break;
    }
} while (n != 3);  // Loop until the user selects option 3 to exit
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Main Function starting   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void main(void)
{
  menu();
}
