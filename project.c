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
void staffLogin();

void viewProduct();
void searchProduct();
void buyProduct();

void addProduct();
void deleteProduct();
void modifyProduct();
void generateSalesReport();
void checkLowStock();
void backupData();
void manageStaff();
void addStaff();
void modifyStaff();
void removeStaff();
void staffMenu();
void viewReviews();
void giveReview();

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
struct Staff {
    int id;
    char name[100];
    char username[50];
    char password[50];
};struct Review
{
    char name[100];
    char phoneNumber[15];
    float rating;
    char comments[500]; // Assuming approximately 500 characters
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
    printf("\t");
    for (i = 0; i < 70; i++)
    {
        printf(BOLD_YELLOW"*"RESET);
        Sleep(10);
    }
    printf("\n\t");
    printf(GREEN "*******        Welcome to Super Shop Management System!        *******\n" RESET);
    printf("\t");
    for (i = 0; i < 70; i++)
    {
        printf(BOLD_YELLOW"*"RESET);
        Sleep(10);
    }
    printf("\n\n");
    printf(BOLD_CYAN"\t\tCurrent Date and Time: %s" RESET, ctime(&t));
    printf("\t\t");
    for (i = 0; i < 47; i++)
    {
        printf(BOLD_MAGENTA "." RESET);
        Sleep(20);
    }
    printf("\n\n");
    printf(BOLD_YELLOW"\n\tPress any key to continue....\n" RESET);
    getch();
    system("cls");

    do
    {
        system("cls");
        printf("\n");
        printf(BOLD_WHITE "                   Continue as...     \n" RESET);
        printf(BOLD_MAGENTA "             <----------------------> \n\n");
        printf(CYAN "   ******************************************\n\n" RESET);
        printf(BOLD_GREEN "         1 =>   Customer.                      \n" RESET);
        Sleep(400);
        printf(BOLD_YELLOW "         2 =>   Shop Administrators.           \n" RESET);
        Sleep(400);
        printf(BOLD_RED "         3 =>   Exit the system.               \n\n" RESET);
        Sleep(400);
        printf(CYAN "   ******************************************\n" RESET);
        printf("\n\n");

        printf(BLUE"Please Enter Your Selection (1-3): " RESET);
        scanf("%d", &n);
        getchar();
        fflush(stdin);
        switch (n)
        {
        case 1:
            customer(); // Calling customer
            break;
        case 2:
            system("cls");
            int c2;
            printf(BOLD_CYAN"\t\tWelcome :)\n"RESET);
            printf(BOLD_YELLOW"\t<------------------------->\n\n"RESET);
            printf(BOLD_MAGENTA"\t1 =>"RESET);
            printf(BOLD_GREEN"\tLogin as Staff.\n"RESET);
            printf(BOLD_MAGENTA"\t2 => "RESET);
            printf(BOLD_GREEN"\tLogin as Admin.\n\n"RESET);
            printf(BOLD_YELLOW"\t<------------------------->\n\n"RESET);
            printf(BOLD_BLUE"   Enter your choice ==> "RESET);
            scanf("%d", &c2);
            getchar();
            fflush(stdin); // used for standerd input NOTE: it may not work in all compiler
            if (c2 == 1)
            {
                staffLogin();
            }
            else if (c2 == 2)
            {
                adminLogin();
            }
            else
            {
                printf(RED"\tInvalid choice. Please select a valid option.\n\n"RESET);
                printf(GREEN"\tReturning to Main Menu........"RESET);
                printf(BOLD_WHITE"3"RESET);
                Sleep(1000);
                printf(BOLD_WHITE"2"RESET);
                Sleep(1000);
                printf(BOLD_WHITE"1"RESET);
                Sleep(1000);
            }
            break;
        case 3:
            system("cls");
            printf(BOLD_CYAN "\t\t<====Thank you for visiting our shop.====>\n     \t\t<====Stay Safe. :)====> \n\n\n\n" RESET);
            break;
        default:
            printf(RED "Please select a valid option.\n" RESET);
            printf(GREEN"Please Try Again.\n"RESET);
            Sleep(2000);
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
        printf(BOLD_RED "-------------------------------------- \n\n" RESET);
        printf(BOLD_RED "\t1. " RESET);
        printf(BOLD_GREEN "View Product \n" RESET);
        Sleep(20);
        printf(BOLD_RED "\t2. " RESET);
        printf(BOLD_GREEN "Search Product. \n");
        Sleep(20);
        printf(BOLD_RED "\t3. " RESET);
        printf(BOLD_GREEN "Buy Product. \n");
        Sleep(20);
        printf(BOLD_RED "\t4. " RESET);
        printf(BOLD_GREEN "Rate Our Shop. \n");
        Sleep(20);
        printf(BOLD_RED "\t5. " RESET);
        printf(BOLD_GREEN "Return to Main Menu. \n\n"); // Added option to return to the main menu
        Sleep(20);
        printf(BOLD_RED "-------------------------------------- \n\n" RESET);
        Sleep(20);
        printf(GREEN "Enter your choice: " RESET);
        scanf("%d", &choice);
        getchar(); // consumes new line
        fflush(stdin);

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
            giveReview();
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
                printf(CYAN"Would you like to try again? (Y/N): "RESET);
                scanf(" %c", &choice);
                getchar();
                if (choice == 'N' || choice == 'n')
                {
                    return; // Exit to the main menu
                }
            }
            else
            {
                printf(BOLD_RED"No attempts left. Returning to main menu.\n"RESET);
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
void admin() {
    int choice, opt, d;
    char stay, choice2, stay1;
    do {
        system("cls");
        printf(BOLD_GREEN "\nHey Admin! What would you like to do?\n\n" RESET);
        printf(BOLD_RED "----------------------------------- \n\n" RESET);
        printf(BOLD_WHITE "\t1. Manage Store.\n" RESET);
        printf(BOLD_WHITE "\t2. Generate Sales Report\n" RESET);
        printf(BOLD_WHITE "\t3. Check Low Stock.\n" RESET);
        printf(BOLD_WHITE "\t4. Backup Data.\n" RESET);
        printf(BOLD_WHITE "\t5. Manage Staff.\n" RESET);
        printf(BOLD_WHITE "\t6. View Customer Review.\n" RESET);
        printf(BOLD_WHITE "\t0. Logout.\n\n" RESET); // Option to return to the main menu
        printf(BOLD_RED "------------------------------------ \n\n" RESET);
        printf(BOLD_YELLOW "\tEnter your choice: " RESET);
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        fflush(stdin);
        switch (choice) {
            case 0:
                return; // This will exit the function and return to the main menu
            case 1:
                do {
                    system("cls");
                    printf("1. View Product.\n");
                    printf("2. Search Product.\n");
                    printf("3. Add Product.\n");
                    printf("4. Delete Product.\n");
                    printf("5. Modify Product.\n");
                    printf("0. Return To Admin Menu.\n");
                    scanf("%d", &d);
                    getchar();
                    fflush(stdin);
                    switch (d) {
                        case 0:
                            return;
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
                        default:
                            printf(BOLD_RED"Please Select Valid Option!\n\n" RESET);
                            Sleep(1000);
                            break;
                    }
                    printf(BOLD_YELLOW"Do you want to stay in the Manage Store menu? (Y/N): " RESET);
                    scanf(" %c", &stay1);
                    getchar();
                    fflush(stdin);
                } while (stay1 == 'Y' || stay1 == 'y');
                break; // Add this break statement
            case 2:
                generateSalesReport();
                break;
            case 3:
                checkLowStock();
                break;
            case 4:
                do {
                    system("cls");
                    printf(BOLD_GREEN"Which Section Data you want to Backup: \n"RESET);
                    printf(BOLD_CYAN"1. Product. \n"RESET);
                    printf(BOLD_YELLOW"2. Sales. \n"RESET);
                    printf(BOLD_MAGENTA"3. Staff. \n"RESET);
                    printf(BOLD_BLUE"4. Review. \n\n"RESET);
                    printf(BOLD_YELLOW"Enter your choice:  "RESET);
                    scanf("%d", &opt);
                    getchar();
                    fflush(stdin);
                    switch (opt) {
                        case 1:
                            backupData("products.txt", "products_backup.txt");
                            break;
                        case 2:
                            backupData("sales.txt", "sales_backup.txt");
                            break;
                        case 3:
                            backupData("staff.txt", "staff_backup.txt");
                            break;
                        case 4:
                            backupData("reviews.txt", "review_backup.txt");
                            break;
                        default:
                            printf("Enter a Valid Option.\n");
                            break;
                    }
                    printf(BOLD_YELLOW"Do you want to back up another file? [Y/N] => "RESET);
                    scanf(" %c", &choice2);
                    getchar();
                    fflush(stdin);
                } while (choice2 == 'Y' || choice2 == 'y');
                break;
            case 5:
                manageStaff();
                break;
            case 6:
                viewReviews();
                break;
            default:
                printf(BOLD_RED "\nInvalid choice. Please enter a valid option.\n" RESET);
                Sleep(2000);
                break;
        }
        printf(BOLD_GREEN "\nDo you want to stay in the Admin Menu? (Y/N): " RESET);
        scanf(" %c", &stay); // The space before %c to consume any leftover newline character
        getchar();
        fflush(stdin);
    } while (stay == 'Y' || stay == 'y');
    system("cls"); // Clear the screen
}


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Managing Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void manageStaff()
{
    int choice;
    do
    {
        system("cls");
        printf(BOLD_CYAN"\nStaff Management:\n"RESET);
        printf(BOLD_CYAN"1. Add Staff\n"RESET);
        printf(BOLD_CYAN"2. Remove Staff\n"RESET);
        printf(BOLD_CYAN"3. Modify Staff\n"RESET);
        printf(BOLD_CYAN"4. Return to Main Menu\n"RESET);
        printf(BOLD_CYAN"Enter your choice: "RESET);
        scanf("%d", &choice);
        getchar();
        fflush(stdin);

        switch (choice)
        {
        case 1:
            addStaff();
            break;
        case 2:
            removeStaff();
            break;
        case 3:
            modifyStaff();
            break;
        case 4:
            return;
        default:
            printf(BOLD_RED"Invalid choice. Please enter a valid option.\n"RESET);
            break;
        }
    } while (choice != 4);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Add Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void addStaff()
{
    struct Staff s;
    FILE *file = fopen("staff.txt", "a+");
    if (file == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }
    system("cls");
    printf(BOLD_YELLOW"Enter new staff ID: "RESET);
    scanf("%d", &s.id);
    printf(BOLD_YELLOW"Enter new staff name: "RESET);
    scanf(" %[^\n]s", s.name); // Read the full name including spaces
    getchar();
    printf(BOLD_YELLOW"Enter new staff username: "RESET);
    scanf("%s", s.username);
    getchar();
    printf(BOLD_YELLOW"Enter new staff password: "RESET);
    scanf("%s", s.password);
    getchar();

    fprintf(file, "%d\t%s\t%s\t%s\n", s.id, s.name, s.username, s.password);
    fclose(file);
    printf(BOLD_GREEN"New staff added successfully.\n"RESET);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Remove Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void removeStaff()
{
    struct Staff s;
    int idToRemove;
    FILE *file = fopen("staff.txt", "r");
    FILE *tempFile = fopen("temp_staff.txt", "w");
    if (file == NULL || tempFile == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }

    printf(BOLD_YELLOW"Enter the ID of the staff to remove: "RESET);
    scanf("%d", &idToRemove);

    int found = 0;
    while (fscanf(file, "%d\t%[^\t]\t%s\t%s\n", &s.id, s.name, s.username, s.password) != EOF)
    {
        if (s.id != idToRemove)
        {
            fprintf(tempFile, "%d\t%s\t%s\t%s\n", s.id, s.name, s.username, s.password);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("staff.txt");
        rename("temp_staff.txt", "staff.txt");
        printf(BOLD_GREEN"Staff removed successfully.\n"RESET);
    }
    else
    {
        remove("temp_staff.txt");
        printf(BOLD_RED"Staff not found.\n"RESET);
    }
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Modify Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void modifyStaff() {
    struct Staff s;
    int idToEdit, found;
    char modifyAnother, line[300];
    do {
        found = 0; // Reset the found flag for each iteration
        system("cls");
        FILE *file = fopen("staff.txt", "r");
        FILE *tempFile = fopen("temp_staff.txt", "w");
        if (file == NULL || tempFile == NULL) {
            printf(BOLD_GREEN"Error opening file!\n"RESET);
            return;
        }

        printf(BOLD_GREEN"Enter the ID of the staff to edit: "RESET);
        scanf("%d", &idToEdit);
        getchar(); // Consume the newline character

        while (fgets(line, sizeof(line), file) != NULL) {
            // Parse the line into fields (ID, name, username, password)
            sscanf(line, "%d\t%[^\t]\t%s\t%s", &s.id, s.name, s.username, s.password);

            if (s.id == idToEdit) {
                found = 1; // Staff member found
                printf("-------------------------------------------------------------\n");
                printf(BOLD_YELLOW"Current Staff Name: %s\n"RESET, s.name);
                printf(BOLD_YELLOW"Current Username: %s\n"RESET, s.username);
                printf(BOLD_YELLOW"Current Password: %s\n\n"RESET, s.password);
                printf(BOLD_YELLOW"Enter new username: "RESET);
                scanf("%s", s.username);
                getchar();
                printf(BOLD_YELLOW"Enter new password: "RESET);
                scanf("%s", s.password);
                getchar(); // Consume the newline character
            }
            // Write the staff information to the temp file (updated if necessary)
            fprintf(tempFile, "%d\t%s\t%s\t%s\n", s.id, s.name, s.username, s.password);
        }

        fclose(file);
        fclose(tempFile);

        if (found) {
            remove("staff.txt");
            rename("temp_staff.txt", "staff.txt");
            printf(BOLD_YELLOW"Staff credentials updated successfully.\n"RESET);
        } else {
            remove("temp_staff.txt");
            printf(BOLD_YELLOW"Staff not found.\n"RESET);
        }

        printf(BOLD_YELLOW"Do you want to modify another staff member? (Y/N): "RESET);
        scanf(" %c", &modifyAnother);
        getchar(); // Consume the newline character
    } while (modifyAnother == 'Y' || modifyAnother == 'y');

    printf(BOLD_RED"Returning to main menu...\n"RESET);
    Sleep(1000);
}

// // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Staff Login Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void staffLogin()
{
    struct Staff s;
    char inputUsername[50], inputPassword[50];
    file = fopen("staff.txt", "r");
    if (file == NULL)
    {
        printf(BOLD_RED "Error opening file!\n" RESET);
        printf(BOLD_RED"Returning to Main Menu!\n"RESET);
        Sleep(3000);

        return;
    }

    printf(BOLD_GREEN"Staff Login\n"RESET);
    printf(BOLD_GREEN"Enter Username: "RESET);
    scanf("%s", inputUsername);
    printf(BOLD_GREEN"Enter Password: "RESET);
    scanf("%s", inputPassword);

    int loginSuccess = 0;
    while (fscanf(file, "%d\t%[^\t]\t%s\t%s\n", &s.id, s.name, s.username, s.password) != EOF)
    {
        if (strcmp(s.username, inputUsername) == 0 && strcmp(s.password, inputPassword) == 0)
        {
            loginSuccess = 1;
            break;
        }
    }

    fclose(file);

    if (loginSuccess)
    {
        printf(BOLD_YELLOW"Login successful. Welcome, %s!\n"RESET, s.name);
        staffMenu(s.name); // Call staff menu
    }
    else
    {
        printf(BOLD_YELLOW"Invalid Username or Password. Access denied.\n"RESET);
        printf(BOLD_YELLOW"Returning to main Menu.\n"RESET);
        Sleep(3000);
    }
}
// // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Staff Menu >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void staffMenu(const char *staffName)
{
    int choice;
    char stay;
    do
    {
        system("cls");
        printf(BOLD_CYAN"\nWelcome, %s!\n"RESET, staffName);
        printf(BOLD_CYAN"1. View Products\n"RESET);
        printf(BOLD_CYAN"2. Search Products\nRESET");
        printf(BOLD_CYAN"3. Add New Product\n"RESET);
        printf(BOLD_CYAN"4. Modify Product\n"RESET);
        printf(BOLD_CYAN"5. Delete Product\n"RESET);
        printf(BOLD_CYAN"6. Check Low Stock\n"RESET);
        printf(BOLD_CYAN"7. Logout\n"RESET);
        printf(BOLD_CYAN"Enter your choice: "RESET);
        scanf("%d", &choice);
        getchar(); // Consume newline character
        fflush(stdin);

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
            modifyProduct();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            checkLowStock();
            break;
        case 7:
            return;
        default:
            printf(BOLD_RED"Invalid choice. Please enter a valid option.\n"RESET);
            Sleep(2000);
            break;
        }

        printf(BOLD_RED"\nDo you want to perform another action? (Y/N): "RESET);
        scanf(" %c", &stay);
        getchar(); // Consume newline character
        fflush(stdin);
    } while (stay == 'Y' || stay == 'y');
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Adding Product  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void addProduct()
{
    struct Product p1;
    char choice;
    FILE *file = fopen("products.txt", "a+");
    if (file == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }

    do
    {
        system("cls");
        printf(BOLD_CYAN"Enter Product ID: "RESET);
        scanf("%d", &p1.ID);
        getchar(); // Consume the newline character

        printf(BOLD_CYAN"Enter Product Category: "RESET);
        fgets(p1.category, sizeof(p1.category), stdin);
        p1.category[strcspn(p1.category, "\n")] = 0; // Remove newline character

        printf(BOLD_CYAN"Enter Product Name: "RESET);
        fgets(p1.name, sizeof(p1.name), stdin);
        p1.name[strcspn(p1.name, "\n")] = 0; // Remove newline character

        printf(BOLD_CYAN"Enter Product Price: "RESET);
        scanf("%f", &p1.price);
        getchar(); // Consume the newline character

        printf(BOLD_CYAN"Enter Quantity [pics/KG]: "RESET);
        scanf("%f", &p1.quantity);
        getchar(); // Consume the newline character

        fprintf(file, "%d\t%s\t%s\t%.2f\t%.2f\n", p1.ID, p1.category, p1.name, p1.price, p1.quantity);
        printf(BOLD_CYAN "\nItem Successfully Added. Do you want to add more? (Y/N): " RESET);
        scanf(" %c", &choice);
        getchar();
        fflush(stdin);
    } while (choice == 'Y' || choice == 'y');

    fclose(file);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Delete Product Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void deleteProduct() {
    struct Product p;
    int idToDelete, found;
    char more;

    do {
        found = 0;
        FILE *file = fopen("products.txt", "r");
        FILE *tempFile = fopen("temp.txt", "w");
        if (file == NULL || tempFile == NULL) {
            printf(BOLD_GREEN"Error opening file!\n"RESET);
            return;
        }

        system("cls");
        printf(BOLD_GREEN"Enter Product ID to delete: "RESET);
        scanf("%d", &idToDelete);
        getchar();

        while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF) {
            if (p.ID == idToDelete) {
                found = 1;
            } else {
                fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
            }
        }

        fclose(file);
        fclose(tempFile);

        if (found) {
            remove("products.txt");
            rename("temp.txt", "products.txt");
            printf(BOLD_MAGENTA"Product deleted successfully.\n"RESET);
        } else {
            remove("temp.txt");
            printf("Product not found.\n");
        }

        printf(BOLD_RED"Do you want to delete another item? (Y/N): "RESET);
        scanf(" %c", &more);
        getchar();  // Consume the newline character
        fflush(stdin);

    } while (more == 'Y' || more == 'y');
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   View Product Function     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void viewProduct()
{
    struct Product products[100]; // Assuming a maximum of 100 products for simplicity
    int count = 0;
    file = fopen("products.txt", "r");
    if (file == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }

    // Reading products from the file into the products array
    while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &products[count].ID, products[count].category, products[count].name, &products[count].price, &products[count].quantity) != EOF)
    {
        count++;
    }
    fclose(file);
    system("cls");

    // Check if the file was empty
    if (count == 0)
    {
        printf(BOLD_RED"\tNo Products Available Right Now. :( \n"RESET);
        return;
    }

    // Display products grouped by category
    printf(BOLD_YELLOW"\n\t<== Products by Category ==>\n"RESET);
    printf(BOLD_YELLOW"\t___________________________\n"RESET);

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
            printf(BOLD_CYAN "\nCategory: " RESET);  //Color added
            printf(WHITE "%s\n" RESET, products[i].category);
            // printf(BOLD_MAGENTA "ID     Name                 Price     Quantity\n" RESET);
            printf(BOLD_RED "ID" RESET);
            printf(BOLD_GREEN "     Name" RESET);
            printf(BOLD_WHITE "                 Price" RESET);
            printf(BOLD_MAGENTA "     Quantity\n" RESET);
            printf(BOLD_CYAN "---------------------------------------------\n" RESET);
            for (int j = 0; j < count; j++)
            {
                if (strcmp(products[i].category, products[j].category) == 0)
                {
                    // printf("%-6d %-20s %-8.2f %.2f\n", products[j].ID, products[j].name, products[j].price, products[j].quantity);
                    printf(BOLD_RED "%-6d " RESET, products[j].ID);
                    printf(BOLD_GREEN "%-20s " RESET, products[j].name);
                    printf(BOLD_WHITE "%-8.2f " RESET, products[j].price);
                    printf(BOLD_MAGENTA "%.2f\n" RESET, products[j].quantity);
                }
            }
            printf(BOLD_CYAN "---------------------------------------------\n" RESET);
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

            printf(BOLD_YELLOW "\n\t<== Products in Category: %s ==>\n\n" RESET, searchTerm);
            printf("ID     Name                 Price     Quantity\n");
            printf("---------------------------------------------\n");

            while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF)
            {
                if (strcasecmp(p1.category, searchTerm) == 0)
                {
                    printf("%-6d %-20s %-7.2f  %.2f\n", p1.ID, p1.name, p1.price, p1.quantity);
                    found = 1;
                }
            }
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf(BOLD_BLUE "\n\nEnter name to search: " RESET);
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

            printf(BOLD_YELLOW "\n\t<== Products with Name: %s ==>\n\n" RESET, searchTerm);
            printf("ID     Category            Price     Quantity\n");
            printf("---------------------------------------------\n");

            while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF)
            {
                if (strcasecmp(p1.name, searchTerm) == 0)
                {
                    printf("%-6d %-20s %-7.2f  %.2f\n", p1.ID, p1.category, p1.price, p1.quantity);
                    found = 1;
                }
            }
        }
        else
        {
            printf(BOLD_RED "Invalid choice.\n" RESET);
            Sleep(2000);
        }

        if (found == 0)
        {
            printf(BOLD_RED "\n\t\tNo products found. :( \n" RESET);
        }

        fclose(file);

        printf(BOLD_RED"\nDo you want to search again? (Y/N): " RESET);
        scanf(" %c", &repeat);
        getchar();
        fflush(stdin);
    } while (repeat == 'Y' || repeat == 'y');
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Modify Product Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void modifyProduct() {
    struct Product p;
    int idToModify, found;
    char modifyAnother;

    do {
        found = 0; // Reset the found flag for each iteration
        system("cls");
        FILE *file = fopen("products.txt", "r");
        FILE *tempFile = fopen("temp.txt", "w");
        if (file == NULL || tempFile == NULL) {
            printf(BOLD_RED"Error opening file!\n"RESET);
            return;
        }

        printf(BOLD_GREEN"Enter Product ID to modify: "RESET);
        scanf("%d", &idToModify);
        getchar(); // Consume the newline character

        while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF) {
            if (p.ID == idToModify) {
                found = 1;
                printf(BOLD_YELLOW"-------------------------------------------------------------\n"RESET);
                printf(BOLD_CYAN"Enter new Product Price: "RESET);
                scanf("%f", &p.price);
                getchar(); // Consume the newline character
                printf(BOLD_CYAN"Enter new Product Quantity: "RESET);
                scanf("%f", &p.quantity);
                getchar(); // Consume the newline character
            }
            fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
        }

        fclose(file);
        fclose(tempFile);

        if (found) {
            remove("products.txt");
            rename("temp.txt", "products.txt");
            printf(BOLD_GREEN"Product modified successfully.\n"RESET);
        } else {
            remove("temp.txt");
            printf(BOLD_RED"Product not found.\n"RESET);
        }

        printf(BOLD_RED"Do you want to modify another product? (Y/N): "RESET);
        scanf(" %c", &modifyAnother);
        getchar(); // Consume the newline character
        fflush(stdin);
    } while (modifyAnother == 'Y' || modifyAnother == 'y');

    // Ensure function returns control properly
    printf(BOLD_RED"Returning to main menu...\n"RESET);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Buy Product Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void buyProduct() {
    struct Purchase {
        char customerName[100];
        char phoneNumber[15];
        int productID;
        int quantity;
        float totalPrice;
    };
    struct CartItem {
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
    FILE *salesFile;

    system("cls");
    printf(BOLD_YELLOW "Enter your name: " RESET);
    fgets(purchase.customerName, sizeof(purchase.customerName), stdin);
    purchase.customerName[strcspn(purchase.customerName, "\n")] = 0; // Remove newline character
    printf(BOLD_YELLOW"Enter your phone number: " RESET);
    fgets(purchase.phoneNumber, sizeof(purchase.phoneNumber), stdin);
    purchase.phoneNumber[strcspn(purchase.phoneNumber, "\n")] = 0; // Remove newline character

    do {
        file = fopen("products.txt", "r");
        tempFile = fopen("temp.txt", "w");
        salesFile = fopen("sales.txt", "a+");
        if (file == NULL || tempFile == NULL || salesFile == NULL) {
            printf(BOLD_RED"Error opening file!\n"RESET);
            return;
        }
        found = 0;
        printf(BOLD_YELLOW "-------------------------------------------------------------\n" RESET);
        printf(BOLD_GREEN "\nEnter Product ID to buy: " RESET);
        scanf("%d", &idToBuy);
        printf(BOLD_GREEN "Enter Quantity: " RESET);
        scanf("%d", &quantity);
        while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF) {
            if (p.ID == idToBuy) {
                if (p.quantity >= quantity) {
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
                    printf(BOLD_CYAN"\nProduct Purchased: %s\n" RESET, p.name);
                    printf(BOLD_CYAN "Total Price for this item: %.2f\n" RESET, itemTotalPrice);
                    printf(BOLD_CYAN "-------------------------------------------------------------\n" RESET);
                } else {
                    printf(BOLD_RED " Sorry :( \nNot enough quantity available.\n" RESET);
                    found = 1;
                    fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
                }
            } else {
                fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
            }
        }
        if (!found) {
            printf(BOLD_RED "Sorry :( Product not found. \nPlease try again with valid ProductID.>>\n" RESET);
        }
        fclose(file);
        fclose(tempFile);
        fclose(salesFile);
        remove("products.txt");
        rename("temp.txt", "products.txt");

        printf(BOLD_RED"\nDo you want to add another item? (Y/N): "RESET);
        scanf(" %c", &addMore);
    } while (addMore == 'Y' || addMore == 'y');

    printf(BOLD_CYAN "\nFinal Bill:\n" RESET);
    printf(BOLD_YELLOW "ID     Name                 Category            Quantity  Price\n" RESET);
    printf(BOLD_CYAN "-----------------------------------------------------------------------\n" RESET);
    for (int i = 0; i < cartCount; i++) {
        printf("%-6d %-20s %-20s %-9d %.2f\n", cart[i].product.ID, cart[i].product.name, cart[i].product.category, cart[i].quantity, cart[i].totalPrice);
    }
    printf(BOLD_CYAN "-----------------------------------------------------------------------\n" RESET);
    printf(BOLD_YELLOW"Total Price: %.2f\n"RESET, totalPrice);

    // suparshop may have a vat so added VAT percentage input
    float vatPercentage, amountGiven, change, vatAmount;
    printf(BOLD_RED"Enter VAT percentage: "RESET);
    scanf("%f", &vatPercentage);

    // Calculate VAT and final total price
    vatAmount = (totalPrice * vatPercentage) / 100;
    totalPrice += vatAmount;

    printf(BOLD_YELLOW"Total Price including VAT: %.2f\n"RESET, totalPrice);

    // Keep asking for sufficient amount until the purchase is successful
    do {
        printf(BOLD_RED"Enter amount given by the customer: "RESET);
        scanf("%f", &amountGiven);

        if (amountGiven >= totalPrice) {
            change = amountGiven - totalPrice;
            printf(BOLD_RED"Change to be returned: %.2f\n"RESET, change);
            break; // Exit loop if the amount given is sufficient
        } else {
            float amountNeeded = totalPrice - amountGiven;
            printf(BOLD_YELLOW"Insufficient amount. You need to give %.2f more.\n"RESET, amountNeeded);
        }
    } while (1); // Loop until sufficient amount is given
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Generate Bill Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

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
        printf(BOLD_RED"Error opening sales file!\n"RESET);
        return;
    }
    system("cls");
    printf(BOLD_YELLOW"\nSales Report:\n\n"RESET);
    printf(BOLD_YELLOW"Customer Name           Phone Number    Product ID   Product Name       Quantity    Total Price\n"RESET);
    printf(BOLD_MAGENTA "------------------------------------------------------------------------------------------------\n" RESET);

    while (fscanf(salesFile, "%99[^\t]\t%14[^\t]\t%d\t%99[^\t]\t%d\t%f\n", purchase.customerName, purchase.phoneNumber, &purchase.productID, purchase.productName, &purchase.quantity, &purchase.totalPrice) != EOF)
    {
        printf("%-23s %-15s %-12d %-20s %-10d %.2f\n", purchase.customerName, purchase.phoneNumber, purchase.productID, purchase.productName, purchase.quantity, purchase.totalPrice);
    }
    printf(BOLD_MAGENTA "------------------------------------------------------------------------------------------------\n" RESET);
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
    system("cls"); // clearing Screen
    printf(BOLD_RED"\nLow Stock Alert:\n"RESET);
    printf(BOLD_YELLOW"Product ID    Name                 Category            Available Quantity\n"RESET);
    printf(BOLD_GREEN"-----------------------------------------------------------------------\n"RESET);

    while (fscanf(file, "%d\t%s\t%s\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
    {
        if (p.quantity < 10)
        { // asuming the low stock in less then 10
            printf(BOLD_RED"%-12d %-20s %-20s %.2f\n"RESET, p.ID, p.name, p.category, p.quantity);
        }
    }

    fclose(file);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Backup Data Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void backupData(const char *sourceFile, const char *backupFile)
{
    FILE *source = fopen(sourceFile, "r");
    FILE *backup = fopen(backupFile, "w");

    if (source == NULL || backup == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, backup);
    }

    fclose(source);
    fclose(backup);
    printf(BOLD_GREEN"Backup of %s created successfully as %s\n"RESET, sourceFile, backupFile);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Taking Review from Customer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void giveReview()
{
    struct Review r;
    FILE *file = fopen("reviews.txt", "a+");
    if (file == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        return;
    }
    system("cls");
    printf(BOLD_YELLOW"Enter your name: "RESET);
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name, "\n")] = 0; // Remove newline character

    printf(BOLD_YELLOW"Enter your phone number: "RESET);
    fgets(r.phoneNumber, sizeof(r.phoneNumber), stdin);
    r.phoneNumber[strcspn(r.phoneNumber, "\n")] = 0; // Remove newline character

    do
    {
        printf(BOLD_MAGENTA"Rate our super shop (1-5): "RESET);
        scanf("%f", &r.rating); 
        getchar(); // Consume the newline character
        fflush(stdin);
        if (r.rating < 1 || r.rating > 5)
        {
            printf(BOLD_RED"Invald Rating please Enter valid Number!\n\n"RESET);
        }
        
    } while (r.rating < 1 || r.rating > 5);

    printf(BOLD_WHITE"Enter your comments (200 words max): "RESET);
    fgets(r.comments, sizeof(r.comments), stdin);
    r.comments[strcspn(r.comments, "\n")] = 0; // Remove newline character

    fprintf(file, BOLD_YELLOW"%s\t%s\t%f\t%s\n"RESET, r.name, r.phoneNumber, r.rating, r.comments);
    fclose(file);

    printf(BOLD_MAGENTA"Thank you for your feedback!\n"RESET);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Viewing customer reviews >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void viewReviews()
{
    struct Review r;
    FILE *file = fopen("reviews.txt", "r");
    if (file == NULL)
    {
        printf(BOLD_RED"Error opening file!\n"RESET);
        Sleep(2000);
        return;
        
    }
    system("cls");
    printf(BOLD_GREEN"\nCustomer Reviews:\n"RESET);
    printf(BOLD_GREEN"Name                     Phone Number    Rating  Comments\n"RESET);
    printf(BOLD_YELLOW"----------------------------------------------------------------------------\n\n"RESET);

    while (fscanf(file, "%99[^\t]\t%14[^\t]\t%f\t%499[^\n]\n", r.name, r.phoneNumber, &r.rating, r.comments) != EOF)
    {
        printf(BOLD_CYAN"%-24s %-15s %-7.2f %s\n\n"RESET, r.name, r.phoneNumber, r.rating, r.comments);
        printf(BOLD_GREEN"----------------------------------------------------------------------------\n\n"RESET);
    }

    fclose(file);
}
// end of the project Super shop Management
