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

#define ADMIN_USERNAME "ADMIN"    // Username is fixed for security
#define ADMIN_PASSWORD "PASSWORD" // Password is fixed for security

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
void viewStaffList();
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
struct Staff
{
    int id;
    char name[100];
    char username[50];
    char password[50];
};
struct Review
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
        printf(BOLD_YELLOW "*" RESET);
        Sleep(10);
    }
    printf("\n");
    printf(GREEN "\t*******              Welcome to The Daily Market!              *******\n" RESET);
    printf(BOLD_WHITE "\t*******         <------------------------------------>         *******\n" RESET);
    printf(GREEN "\t*******          {_Your One-Stop Shop for Everything_}         *******\n" RESET);
    printf("\t");
    for (i = 0; i < 70; i++)
    {
        printf(BOLD_YELLOW "*" RESET);
        Sleep(10);
    }
    printf("\n\n");
    printf(BOLD_CYAN "\t\tCurrent Date and Time: %s" RESET, ctime(&t));
    printf("\t\t");
    for (i = 0; i < 47; i++)
    {
        printf(BOLD_MAGENTA "=" RESET);
        Sleep(20);
    }
    printf("\n\n");
    printf(BOLD_YELLOW "\n\tPress any key to continue....\n" RESET);
    getch();
    system("cls");

    do
    {
        system("cls");
        printf("\n");
        printf(BOLD_WHITE "                   Continue as...     \n" RESET);
        printf(BOLD_MAGENTA "             <======================> \n\n");
        printf(CYAN "   ******************************************\n\n" RESET);
        printf(BOLD_GREEN "         1 =>   Customer.                      \n" RESET);
        Sleep(400);
        printf(BOLD_YELLOW "         2 =>   Shop Administrators.           \n" RESET);
        Sleep(400);
        printf(BOLD_RED "         3 =>   Exit the system.               \n\n" RESET);
        Sleep(400);
        printf(BOLD_CYAN "   ******************************************\n" RESET);
        printf("\n\n");

        printf(BOLD_BLUE "Please Enter Your Selection (1-3): " RESET);
        scanf("%d", &n);
        getchar();
        fflush(stdin);
        switch (n)
        {
        case 1:
            customer(); // Calling customer
            fflush(stdin);
            break;
        case 2:
            system("cls");
            int c2;
            printf(BOLD_CYAN "\t\tWelcome :)\n" RESET);
            printf(BOLD_MAGENTA "<==================================>\n\n" RESET);
            printf(BOLD_GREEN "\t1 => Login as Staff.\n" RESET);
            printf(BOLD_YELLOW "\t2 => Login as Admin.\n\n");
            printf(BOLD_MAGENTA "<==================================>\n\n" RESET);
            printf(BOLD_BLUE "   Enter your choice ==> " RESET);
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
                printf(BOLD_BLUE "Invalid choice. Please select a valid option.\n" RESET);
                printf(BOLD_GREEN "Returning to Main Menu........\n" RESET);
                printf("3 ");
                Sleep(1000);
                printf("2 ");
                Sleep(1000);
                printf("1 ");
                Sleep(1000);
            }
            break;
        case 3:
            system("cls");
            printf(BOLD_MAGENTA "\n\n\t===============================================================================\n" RESET);
            printf(BOLD_GREEN "\t||                                                                           ||\n" RESET);
            printf(BOLD_GREEN "\t||\t\t<====  Thank you for visiting our shop. ====>\t\t     ||\n" RESET);
            printf(BOLD_GREEN "\t||\t\t\t<====  Stay Safe. :)  ====>\t\t\t     ||\n" RESET);
            printf(BOLD_GREEN "\t||                                                                           ||\n" RESET);
            printf(BOLD_MAGENTA "\t===============================================================================\n\n\n\n\n\n\n\n" RESET);
            Sleep(3000);

            break;
        default:
            printf(BOLD_RED "Please select a valid option.\n" RESET);
            printf(BOLD_GREEN "Please Try Again.\n" RESET);
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
    printf(BOLD_MAGENTA "\n\t\tHello! Welcome To our Shop :)\n\t" RESET);

    // Simulate a loading animation
    for (i = 0; i < 40; i++)
    {
        printf(".");
        Sleep(30); // Pause to create a loading effect
    }
    printf("\n");
    do
    {
        system("cls");
        printf("\n");
        printf(BOLD_CYAN "\tWhat would you like to do? \n" RESET);
        printf(BOLD_WHITE "<============================================> \n\n" RESET);
        printf(BOLD_MAGENTA "\t1 => " RESET);
        printf(BOLD_GREEN "View Product. \n" RESET);
        Sleep(20);
        printf(BOLD_MAGENTA "\t2 => " RESET);
        printf(BOLD_GREEN "Search Product. \n" RESET);
        Sleep(20);
        printf(BOLD_MAGENTA "\t3 => " RESET);
        printf(BOLD_GREEN "Buy Product. \n" RESET);
        Sleep(20);
        printf(BOLD_MAGENTA "\t4 => " RESET);
        printf(BOLD_GREEN "Rate Our Shop. \n" RESET);
        Sleep(20);
        printf(BOLD_MAGENTA "\t5 => " RESET);
        printf(BOLD_GREEN "Return to Main Menu. \n\n" RESET); // Added option to return to the main menu
        Sleep(20);
        printf(BOLD_WHITE "<============================================> \n\n" RESET);
        Sleep(20);
        printf(GREEN "Enter your choice: " RESET);
        scanf("%d", &choice);
        getchar(); // consumes new line
        fflush(stdin);

        switch (choice)
        {
        case 1:
            viewProduct(); // calling view product
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
            printf(BOLD_RED "Invalid choice. Please Enter valid option.\n" RESET);
            break;
        }
        // asking user if he wants to stay or not
        printf(BOLD_GREEN "\nDo you want to stay in the Customer Menu? (Y/N): " RESET);
        scanf(" %c", &stay); // the space before %c to consume any leftover newline character
        getchar();
        fflush(stdin);

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
        printf(BOLD_YELLOW "<============================================>\n\n" RESET);
        printf(CYAN "\tPlease Login to continue......\n\n" RESET);
        printf(BOLD_MAGENTA "\tEnter Username: " RESET);
        scanf("%s", username); // username canbe one word
        getchar();             // consuming newline
        printf(BOLD_MAGENTA "\tEnter Password: " RESET);
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
            printf(BOLD_RED "Invalid Username or Password. You have %d attempt(s) left.\n" RESET, attempts);
            if (attempts > 0)
            {
                printf(BOLD_RED "Would you like to try again? (Y/N): " RESET);
                scanf(" %c", &choice);
                getchar();
                if (choice == 'N' || choice == 'n')
                {
                    return; // Exit to the main menu
                }
            }
            else
            {
                printf(BOLD_RED "No attempts left. Returning to main menu.\n" RESET);
                printf(BOLD_CYAN "3\n" RESET);
                Sleep(1000);
                printf(BOLD_CYAN "2\n" RESET);
                Sleep(1000);
                printf(BOLD_CYAN "1\n" RESET);
                Sleep(1000);
                return; // Exit to the main menu after all attempts are used
            }
        }
    }
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Admin  Function  After login >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void admin()
{
    int choice, opt, d;
    char stay, choice2, stay1;
    do
    {
        system("cls");
        printf(BOLD_GREEN "\nHey Admin! What would you like to do?\n\n" RESET);
        printf(BOLD_CYAN "<=====================================> \n\n" RESET);
        printf(BOLD_WHITE "\t1. Manage Store.\n" RESET);
        printf(BOLD_YELLOW "\t2. Generate Sales Report.\n" RESET);
        printf(BOLD_RED "\t3. Check Low Stock.\n" RESET);
        printf(BOLD_WHITE "\t4. Backup Data.\n" RESET);
        printf(BOLD_MAGENTA "\t5. Manage Staff.\n" RESET);
        printf(BOLD_GREEN "\t6. View Customer Review.\n" RESET);
        printf(BOLD_RED "\t0. Logout. \n\n" RESET); // Option to return to the main menu
        printf(BOLD_CYAN "<=====================================> \n\n" RESET);
        printf(BOLD_YELLOW "\tEnter your choice: " RESET);
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        fflush(stdin);
        switch (choice)
        {
        case 0:
            return; // This will exit the function and return to the main menu
        case 1:
            do
            {
                system("cls");
                printf(BOLD_CYAN "\tWhat would you like to do? \n" RESET);
                printf(BOLD_YELLOW "<======================================> \n\n" RESET);
                printf(BOLD_WHITE "\t1. View Product.\n" RESET);
                printf(BOLD_BLUE "\t2. Search Product.\n" RESET);
                printf(BOLD_MAGENTA "\t3. Add Product.\n" RESET);
                printf(BOLD_WHITE "\t4. Delete Product.\n" RESET);
                printf(BOLD_YELLOW "\t5. Modify Product.\n" RESET);
                printf(BOLD_RED "\t0. Return To Admin Menu.\n" RESET);
                printf(BOLD_YELLOW "\n\n<======================================> \n\n" RESET);
                printf(BOLD_GREEN "\n\nEnter you choice: " RESET);
                scanf("%d", &d);
                getchar();
                fflush(stdin);
                switch (d)
                {
                case 0:
                    continue;
                    ;
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
                    printf(BOLD_RED "Please Select Valid Option!\n\n" RESET);
                    Sleep(1000);
                    break;
                }
                printf(BOLD_GREEN "Do you want to stay in the Manage Store menu? (Y/N): " RESET);
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
            do
            {
                system("cls");
                printf(BOLD_GREEN "Which Section Data you want to Backup: \n" RESET);
                printf(BOLD_YELLOW "<============================================>\n\n" RESET);
                printf(BOLD_CYAN "\t1. Product. \n" RESET);
                printf(BOLD_WHITE "\t2. Sales. \n" RESET);
                printf(BOLD_YELLOW "\t3. Staff. \n" RESET);
                printf(BOLD_MAGENTA "\t4. Review. \n" RESET);
                printf(BOLD_YELLOW "\n<============================================>\n\n" RESET);
                printf(BOLD_CYAN "Enter your choice:  " RESET);
                scanf("%d", &opt);
                getchar();
                fflush(stdin);
                switch (opt)
                {
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
                    printf(BOLD_RED "Enter a Valid Option.\n" RESET);
                    break;
                }
                printf(BOLD_WHITE "Do you want to back up another file? [Y/N] => " RESET);
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
            printf(BOLD_RED "Invalid choice. Please enter a valid option.\n" RESET);
            Sleep(2000);
            break;
        }
        printf(BOLD_GREEN "\nDo you want to stay in the Admin Menu Or Logout? (Y/N): " RESET);
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
        printf(BOLD_GREEN "\n\t  Staff Management:\n" RESET);
        printf(BOLD_YELLOW "<=====================================> \n\n" RESET);
        printf(BOLD_GREEN "\t1. View Staff\n" RESET);
        printf(BOLD_GREEN "\t2. Add Staff\n" RESET);
        printf(BOLD_RED "\t3. Remove Staff\n" RESET);
        printf(BOLD_WHITE "\t4. Modify Staff\n" RESET);
        printf(BOLD_RED "\t5. Return to Main Menu\n" RESET);
        printf(BOLD_YELLOW "\n\n<=====================================> \n\n" RESET);
        printf(BOLD_CYAN "\nEnter your choice: " RESET);
        scanf("%d", &choice);
        getchar();
        fflush(stdin);

        switch (choice)
        {
        case 1:
            viewStaffList();
            break;
        case 2:
            addStaff();
            break;
        case 3:
            removeStaff();
            break;
        case 4:
            modifyStaff();
            break;
        case 5:
            return;
        default:
            printf(BOLD_RED "Invalid choice. Please enter a valid option.\n" RESET);
            Sleep(2000);
            break;
        }
    } while (choice != 5);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< View Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void viewStaffList()
{
    struct Staff s;
    FILE *file = fopen("staff.txt", "r");
    if (file == NULL)
    {
        printf(BOLD_RED "Error opening file!\n" RESET);
        Sleep(2000);
        return;
    }
    system("cls");
    printf(BOLD_GREEN "Staff List:\n\n" RESET);
    printf(BOLD_CYAN "ID\t\tName\t\t\tUsername\n" RESET);
    printf(BOLD_CYAN "========================================================\n\n" RESET);
    while (fscanf(file, "%d\t%[^\t]\t%s\t%s\n", &s.id, s.name, s.username, s.password) != EOF)
    {
        printf(BOLD_WHITE "%-8d\t%-20s\t%s\n" RESET, s.id, s.name, s.username);
    }
    printf(BOLD_CYAN "\n========================================================\n\n" RESET);
    fclose(file);
    printf(BOLD_GREEN "\nPress any key to return to the menu..." RESET);
    getchar();
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Add Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void addStaff()
{
    struct Staff s;
    FILE *file = fopen("staff.txt", "a+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        Sleep(2000);
        return;
    }
    system("cls");
    printf(BOLD_YELLOW "\n<============================================>\n\n" RESET);
    printf(BOLD_WHITE "\tEnter new staff ID      : " RESET);
    scanf("%d", &s.id);
    printf(BOLD_YELLOW "\tEnter new staff name    : " RESET);
    scanf(" %[^\n]s", s.name); // Read the full name including spaces
    getchar();
    printf(BOLD_CYAN "\tEnter new staff username: " RESET);
    scanf("%s", s.username);
    getchar();
    printf(BOLD_MAGENTA "\tEnter new staff password: " RESET);
    scanf("%s", s.password);
    getchar();

    fprintf(file, "%d\t%s\t%s\t%s\n", s.id, s.name, s.username, s.password);
    fclose(file);
    printf(BOLD_YELLOW "\n<============================================>\n\n" RESET);
    printf(BOLD_GREEN "New staff added successfully.\n" RESET);
    printf(BOLD_GREEN "\nPress any key to return to the menu..." RESET);
    getchar();
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
        printf(BOLD_RED "Error opening file!\n" RESET);
        return;
    }
    system("cls");
    printf(BOLD_CYAN "<================================================>\n" RESET);
    printf(BOLD_RED "\tEnter the ID of the staff to remove: " RESET);
    scanf("%d", &idToRemove);
    getchar();
    fflush(stdin);

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
        printf(BOLD_GREEN "\n\nStaff removed successfully.\n\n" RESET);
        printf(BOLD_GREEN "\nPress any key to return to the menu..." RESET);
        ;
        getchar();
    }
    else
    {
        remove("temp_staff.txt");
        printf(BOLD_RED "Staff not found.\n" RESET);
        printf(BOLD_GREEN "\nPress any key to return to the menu..." RESET);
        getchar();
    }
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Modify Staff Members  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void modifyStaff()
{
    struct Staff s;
    int idToEdit, found, choice;
    char modifyAnother;

    do
    {
        found = 0; // Reset the found flag for each iteration
        system("cls");
        FILE *file = fopen("staff.txt", "r");
        FILE *tempFile = fopen("temp_staff.txt", "w");
        if (file == NULL || tempFile == NULL)
        {
            printf(BOLD_RED "Error opening file!\n" RESET);
            return;
        }
        printf(BOLD_CYAN "========================================================\n" RESET);
        printf(BOLD_CYAN "\nEnter the ID of the staff to edit: " RESET);
        scanf("%d", &idToEdit);
        getchar(); // Consume the newline character

        while (fscanf(file, "%d\t%[^\t]\t%s\t%s\n", &s.id, s.name, s.username, s.password) != EOF)
        {
            if (s.id == idToEdit)
            {
                found = 1; // Staff member found
                printf(BOLD_WHITE "=============================================================\n" RESET);
                printf(BOLD_MAGENTA "\tCurrent Staff Name: %s\n" RESET, s.name);
                printf(BOLD_MAGENTA "\tCurrent Username:   %s\n" RESET, s.username);
                printf(BOLD_MAGENTA "\tCurrent Password:   %s\n" RESET, s.password);
                printf(BOLD_WHITE "=============================================================\n" RESET);
                printf(BOLD_YELLOW "\nWhat do you want to modify?\n" RESET);
                printf(BOLD_YELLOW "1. Name\n" RESET);
                printf(BOLD_YELLOW "2. Username\n" RESET);
                printf(BOLD_YELLOW "3. Password\n" RESET);
                printf(BOLD_YELLOW "4. All\n\n" RESET);
                printf(BOLD_CYAN "Enter your choice: " RESET);
                scanf("%d", &choice);
                getchar(); // Consume the newline character

                switch (choice)
                {
                case 1:
                    printf(BOLD_GREEN "\nEnter new staff name: " RESET);
                    scanf("%[^\n]", s.name);
                    getchar(); // Consume the newline character
                    break;
                case 2:
                    printf(BOLD_GREEN "Enter new username: " RESET);
                    scanf("%s", s.username);
                    getchar(); // Consume the newline character
                    break;
                case 3:
                    printf(BOLD_GREEN "Enter new password: " RESET);
                    scanf("%s", s.password);
                    getchar(); // Consume the newline character
                    break;
                case 4:
                    printf(BOLD_GREEN "Enter new staff name: " RESET);
                    scanf("%[^\n]", s.name);
                    getchar(); // Consume the newline character
                    printf(BOLD_GREEN "Enter new username: " RESET);
                    scanf("%s", s.username);
                    getchar(); // Consume the newline character
                    printf(BOLD_GREEN "Enter new password: " RESET);
                    scanf("%s", s.password);
                    getchar(); // Consume the newline character
                    break;
                default:
                    printf(BOLD_RED "Invalid choice. Please select a valid option.\n" RESET);
                    Sleep(1500);   // Pause to allow the user to see the message
                    system("cls"); // Clear screen
                    continue;
                }
                printf(BOLD_YELLOW "=============================================================\n" RESET);
            }
            // Write the staff information to the temp file (updated if necessary)
            fprintf(tempFile, "%d\t%s\t%s\t%s\n", s.id, s.name, s.username, s.password);
        }

        fclose(file);
        fclose(tempFile);

        if (found)
        {
            remove("staff.txt");
            rename("temp_staff.txt", "staff.txt");
            printf(BOLD_CYAN "\n\nStaff credentials updated successfully.\n" RESET);
        }
        else
        {
            remove("temp_staff.txt");
            printf(BOLD_RED "Staff not found.\n" RESET);
        }

        printf(BOLD_GREEN "Do you want to modify another staff member? (Y/N): " RESET);
        scanf(" %c", &modifyAnother);
        getchar(); // Consume the newline character
    } while (modifyAnother == 'Y' || modifyAnother == 'y');

    printf(BOLD_RED "Returning to main menu...\n" RESET);
    Sleep(2000);
}

// // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Staff Login Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void staffLogin()
{
    struct Staff s;
    char inputUsername[50], inputPassword[50];
    file = fopen("staff.txt", "r");
    if (file == NULL)
    {
        printf(BOLD_RED "Error Getting Staff Information. Contact to Admin 1st!\n" RESET);
        printf("Returning to Main Menu!\n");
        Sleep(3000);

        return;
    }
    system("cls");
    printf(BOLD_CYAN "<==  Enter Username and Password to Login  ==>\n" RESET);
    printf(BOLD_CYAN "<================================================>\n\n" RESET);

    printf(BOLD_YELLOW "\tEnter Username: " RESET);
    scanf("%s", inputUsername);
    getchar();
    printf(BOLD_YELLOW "\tEnter Password: " RESET);
    scanf("%s", inputPassword);
    getchar();
    printf(BOLD_CYAN "\n<================================================>\n\n" RESET);

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
        printf(BOLD_GREEN "Login successful. Welcome, %s!\n" RESET, s.name);
        Sleep(2000);
        staffMenu(s.name); // Call staff menu
    }
    else
    {
        printf(BOLD_RED "Invalid Username or Password. Access denied.\n" RESET);
        printf(BOLD_GREEN "Returning to main Menu.\n" RESET);
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
        printf(BOLD_GREEN "\n\tWelcome, %s!\n" RESET, staffName);
        printf(BOLD_YELLOW "\n<================================================>\n\n" RESET);
        printf(BOLD_MAGENTA "\t1 => " RESET);
        printf(BOLD_CYAN "View Products\n" RESET);
        printf(BOLD_MAGENTA "\t2 => " RESET);
        printf(BOLD_CYAN "Search Products\n" RESET);
        printf(BOLD_MAGENTA "\t3 => " RESET);
        printf(BOLD_GREEN "Add New Product\n" RESET);
        printf(BOLD_MAGENTA "\t4 => " RESET);
        printf(BOLD_GREEN "Modify Product\n" RESET);
        printf(BOLD_MAGENTA "\t5 => " RESET);
        printf(BOLD_RED "Delete Product\n" RESET);
        printf(BOLD_MAGENTA "\t6 => " RESET);
        printf(BOLD_RED "Check Low Stock\n" RESET);
        printf(BOLD_MAGENTA "\t7 => " RESET);
        printf(BOLD_RED "Logout\n\n" RESET);
        printf(BOLD_YELLOW "<================================================>\n\n" RESET);
        printf(BOLD_GREEN "Enter your choice: " RESET);
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
            printf(BOLD_RED "Invalid choice. Please enter a valid option.\n" RESET);
            Sleep(2000);
            break;
        }

        printf(BOLD_RED "\nDo you want to perform another action? (Y/N): " RESET);
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
        printf(BOLD_RED "Error Opening Prodduct file!\n" RESET);
        Sleep(2000);
        return;
    }

    do
    {
        system("cls");

        printf(BOLD_GREEN "\tEnter Product Information below\n" RESET);
        printf(BOLD_YELLOW "<================================================>\n\n" RESET);
        printf(BOLD_GREEN "\tEnter Product ID: " RESET);
        scanf("%d", &p1.ID);
        getchar(); // Consume the newline character

        printf(BOLD_YELLOW "\tEnter Product Category: " RESET);
        fgets(p1.category, sizeof(p1.category), stdin);
        p1.category[strcspn(p1.category, "\n")] = 0; // Remove newline character

        printf(BOLD_MAGENTA "\tEnter Product Name: " RESET);
        fgets(p1.name, sizeof(p1.name), stdin);
        p1.name[strcspn(p1.name, "\n")] = 0; // Remove newline character

        printf(BOLD_BLUE "\tEnter Product Price: " RESET);
        scanf("%f", &p1.price);
        getchar(); // Consume the newline character

        printf(BOLD_WHITE "\tEnter Quantity [pics/KG]: " RESET);
        scanf("%f", &p1.quantity);
        getchar(); // Consume the newline character

        fprintf(file, "%d\t%s\t%s\t%.2f\t%.2f\n", p1.ID, p1.category, p1.name, p1.price, p1.quantity);
        printf(BOLD_YELLOW "<================================================>\n\n" RESET);
        printf(BOLD_CYAN "\nItem Successfully Added. Do you want to add more? (Y/N): " RESET);
        scanf(" %c", &choice);
        fflush(stdin);
    } while (choice == 'Y' || choice == 'y');

    fclose(file);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Delete Product Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void deleteProduct()
{
    struct Product p;
    int idToDelete, found;
    char more;

    do
    {
        found = 0;
        FILE *file = fopen("products.txt", "r");
        FILE *tempFile = fopen("temp.txt", "w");
        if (file == NULL || tempFile == NULL)
        {
            printf(BOLD_RED "Error opening Product file!\n" RESET);
            Sleep(2000);
            return;
        }

        system("cls");
        printf(BOLD_CYAN "========================================================\n\n" RESET);
        printf(BOLD_RED "\tEnter Product ID to delete: " RESET);
        scanf("%d", &idToDelete);
        getchar();

        while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
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
            printf(BOLD_GREEN "\tProduct deleted successfully.\n\n" RESET);
        }
        else
        {
            remove("temp.txt");
            printf(BOLD_RED "\nProduct not found.\n" RESET);
        }

        printf(BOLD_WHITE "Do you want to delete another item? (Y/N): " RESET);
        scanf(" %c", &more);
        getchar(); // Consume the newline character
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
        printf(BOLD_RED "Error opening file. Try adding or Contact to Admin!\n" RESET);
        Sleep(2000);
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
        printf(BOLD_RED "\n\tNo Products Available Right Now. :( \n" RESET);
        return;
    }

    // Display products grouped by category
    printf("\n\t<== Products by Category ==>\n");
    printf("\t___________________________\n");

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
            printf(BOLD_CYAN "\nCategory: " RESET); // Color added
            printf(WHITE "%s\n" RESET, products[i].category);
            // printf(BOLD_MAGENTA "ID     Name                 Price     Quantity\n" RESET);
            printf(BOLD_RED "ID" RESET);
            printf(BOLD_GREEN "     Name" RESET);
            printf(BOLD_WHITE "                 Price" RESET);
            printf(BOLD_MAGENTA "     Quantity\n" RESET);
            printf(BOLD_CYAN "================================================\n" RESET);
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
            printf(BOLD_CYAN "================================================\n" RESET);
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
            printf(BOLD_RED "Error opening Product file!\n" RESET);
            Sleep(2000);
            return;
        }

        printf(GREEN "\nDo you want to Search by [C]ategory or [N]ame? -> " RESET);
        scanf(" %c", &choice);
        getchar(); // Consume the newline character
        fflush(stdin);

        if (choice == 'C' || choice == 'c')
        {
            printf("\n<=---------------------------------------------=>\n");
            printf(BOLD_BLUE "\nEnter category to search: " RESET);
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

            printf(BOLD_YELLOW "\n\t<== Products in Category: %s ==>\n\n" RESET, searchTerm);
            // printf("ID     Name                 Price     Quantity\n");
            printf(BOLD_RED "ID" RESET);
            printf(BOLD_GREEN "     Name" RESET);
            printf(BOLD_WHITE "                 Price" RESET);
            printf(BOLD_MAGENTA "     Quantity\n" RESET);
            printf("================================================\n");

            while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF)
            {
                if (strcasecmp(p1.category, searchTerm) == 0)
                {
                    // printf("%-6d %-20s %-7.2f  %.2f\n", p1.ID, p1.name, p1.price, p1.quantity);
                    printf(BOLD_RED "%-6d " RESET, p1.ID);
                    printf(BOLD_GREEN "%-20s " RESET, p1.name);
                    printf(BOLD_WHITE "%-8.2f " RESET, p1.price);
                    printf(BOLD_MAGENTA "%.2f\n" RESET, p1.quantity);
                    found = 1;
                }
            }
            printf("================================================\n");
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf("\n<=---------------------------------------------=>\n");
            printf(BOLD_BLUE "\n\nEnter name to search: " RESET);
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

            printf(BOLD_YELLOW "\n\t<== Products with Name: %s ==>\n\n" RESET, searchTerm);
            // printf("ID     Category            Price     Quantity\n");
            printf(BOLD_RED "ID" RESET);
            printf(BOLD_GREEN "     Name" RESET);
            printf(BOLD_WHITE "                 Price" RESET);
            printf(BOLD_MAGENTA "     Quantity\n" RESET);
            printf(BOLD_CYAN "=============================================\n" RESET);

            while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p1.ID, p1.category, p1.name, &p1.price, &p1.quantity) != EOF)
            {
                if (strcasecmp(p1.name, searchTerm) == 0)
                {
                    // printf("%-6d %-20s %-7.2f  %.2f\n", p1.ID, p1.category, p1.price, p1.quantity);
                    printf(BOLD_RED "%-6d " RESET, p1.ID);
                    printf(BOLD_GREEN "%-20s " RESET, p1.name);
                    printf(BOLD_WHITE "%-8.2f " RESET, p1.price);
                    printf(BOLD_MAGENTA "%.2f\n" RESET, p1.quantity);

                    found = 1;
                }
            }
            printf("=============================================\n");
        }
        else
        {
            printf(BOLD_RED "Invalid choice.\n" RESET);
        }

        if (found == 0)
        {
            printf(BOLD_RED "\n\t\tNo products found. :( \n" RESET);
            printf(BOLD_CYAN "\n=============================================\n\n" RESET);
        }

        fclose(file);

        printf(BOLD_GREEN "\nDo you want to search again? (Y/N): " RESET);
        scanf(" %c", &repeat);
        getchar();
        fflush(stdin);
    } while (repeat == 'Y' || repeat == 'y');
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Modify Product Function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void modifyProduct()
{
    int ch;
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
            printf(BOLD_RED "Error opening Staff file. Check if the File is available or not!\n" RESET);
            Sleep(2000);
            return;
        }
        printf(BOLD_YELLOW "<============================================>\n\n" RESET);
        printf(BOLD_GREEN "\tEnter Product ID to modify: " RESET);
        scanf("%d", &idToModify);
        getchar(); // Consume the newline character

        while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
        {
            if (p.ID == idToModify)
            {
                found = 1;
                printf(BOLD_YELLOW "\n<============================================>\n\n" RESET);
                printf(BOLD_YELLOW "\tWhat do you want to modify: \n" RESET);
                printf(BOLD_YELLOW "\t1. Price. \n" RESET);
                printf(BOLD_YELLOW "\t2. Quantity. \n" RESET);
                printf(BOLD_YELLOW "\t3. Both. \n" RESET);
                printf(BOLD_YELLOW "<============================================>\n\n" RESET);
                printf(BOLD_CYAN "Enter your choice: " RESET);
                scanf("%d", &ch);
                getchar(); // Consume the newline character
                fflush(stdin);

                switch (ch)
                {
                case 1:
                    printf(BOLD_GREEN "Enter new Product Price: " RESET);
                    scanf("%f", &p.price);
                    getchar();
                    break;
                case 2:
                    printf(BOLD_GREEN "Enter new Product Quantity: " RESET);
                    scanf("%f", &p.quantity);
                    getchar();
                    break;
                case 3:
                    printf(BOLD_GREEN "Enter new Product Price: " RESET);
                    scanf("%f", &p.price);
                    getchar();
                    printf(BOLD_GREEN "Enter new Product Quantity: " RESET);
                    scanf("%f", &p.quantity);
                    getchar();
                    break;
                default:
                    printf(RED "Invalid choice. Please select a valid option.\n" RESET);
                    Sleep(1500);   // Pause to allow the user to see the message
                    system("cls"); // Clear screen
                    continue;
                }
                printf(BOLD_RED "=============================================================\n" RESET);
            }
            fprintf(tempFile, "%d\t%s\t%s\t%.2f\t%.2f\n", p.ID, p.category, p.name, p.price, p.quantity);
        }

        fclose(file);
        fclose(tempFile);

        if (found)
        {
            remove("products.txt");
            rename("temp.txt", "products.txt");
            printf(BOLD_GREEN "\tProduct modified successfully.\n\n" RESET);
        }
        else
        {
            remove("temp.txt");
            printf(RED "Product not found.\n" RESET);
        }

        printf(BOLD_CYAN "Do you want to modify another product? (Y/N): " RESET);
        scanf(" %c", &modifyAnother);
        getchar(); // Consume the newline character
    } while (modifyAnother == 'Y' || modifyAnother == 'y');

    // Ensure function returns control properly
    printf(BOLD_RED "Returning to main menu...\n" RESET);
    Sleep(2000);
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
    char addMore, choice;
    FILE *salesFile;

    system("cls");
    printf(BOLD_YELLOW "<=====================================================================>\n\n" RESET);
    printf(BOLD_RED "\t\tPlease Choose Product Id and Quantity carefully.\n" RESET);
    printf(BOLD_GREEN "\tOnce you select a Product and Quantity it can't be changed!\n\n" RESET);
    printf(BOLD_YELLOW "<=====================================================================>\n\n" RESET);
    printf(BOLD_GREEN "Do you Want to Continue? [Y/N]=> " RESET);
    scanf(" %c", &choice);
    getchar();
    fflush(stdin);
    system("cls");
    if (choice == 'y' || choice == 'Y')
    {

        printf(BOLD_CYAN "\tPlease Fillup the information\n" RESET);
        printf(BOLD_YELLOW "<==============================================>\n\n" RESET);
        printf(BOLD_YELLOW "\tEnter your name: " RESET);
        fgets(purchase.customerName, sizeof(purchase.customerName), stdin);
        purchase.customerName[strcspn(purchase.customerName, "\n")] = 0; // Remove newline character
        printf(BOLD_CYAN "\tEnter your phone number: " RESET);
        fgets(purchase.phoneNumber, sizeof(purchase.phoneNumber), stdin);
        purchase.phoneNumber[strcspn(purchase.phoneNumber, "\n")] = 0; // Remove newline character

        do
        {
            file = fopen("products.txt", "r");
            tempFile = fopen("temp.txt", "w");
            salesFile = fopen("sales.txt", "a+");
            if (file == NULL || tempFile == NULL || salesFile == NULL)
            {
                printf("Error opening Products file!\n");
                Sleep(2000);
                return;
            }
            found = 0;
            printf(BOLD_WHITE "\n\tEnter Product ID to buy: " RESET);
            scanf("%d", &idToBuy);
            printf(BOLD_WHITE "\tEnter Quantity: " RESET);
            scanf("%d", &quantity);
            while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
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
                        printf(BOLD_CYAN "\nProduct Purchased: %s\n" RESET, p.name);
                        printf(BOLD_MAGENTA "Total Price for this item: %.2f\n" RESET, itemTotalPrice);
                        printf(BOLD_GREEN "<===========================================================>\n" RESET);
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
                printf(BOLD_RED "Sorry :( Product not found. \nPlease try again with valid ProductID.>>\n\n" RESET);
                Sleep(2000);
            }
            fclose(file);
            fclose(tempFile);
            fclose(salesFile);
            remove("products.txt");
            rename("temp.txt", "products.txt");

            printf(BOLD_GREEN "\nDo you want to add another item? (Y/N): " RESET);
            scanf(" %c", &addMore);
            getchar();
            fflush(stdin);
        } while (addMore == 'Y' || addMore == 'y');

        printf(BOLD_BLUE "\n<========================== Final Bill ==========================>\n\n" RESET);
        printf(BOLD_RED "ID" RESET);
        printf(BOLD_GREEN "     Name" RESET);
        printf(BOLD_WHITE "                 Category" RESET);
        printf(BOLD_MAGENTA "            Quantity" RESET);
        printf(BOLD_YELLOW "  Price\n" RESET);
        printf(BOLD_CYAN "=======================================================================\n" RESET);
        for (int i = 0; i < cartCount; i++)
        {
            printf(BOLD_RED "%-6d " RESET, cart[i].product.ID);
            printf(BOLD_GREEN "%-20s " RESET, cart[i].product.name);
            printf(BOLD_WHITE "%-20s " RESET, cart[i].product.category);
            printf(BOLD_MAGENTA "%-9d" RESET, cart[i].quantity);
            printf(BOLD_YELLOW "%-5.2f\n", cart[i].product.price);
        }
        printf(BOLD_CYAN "=======================================================================\n" RESET);
        printf(BOLD_YELLOW "\n\nTotal Price: %.2f\n" RESET, totalPrice);

        // suparshop may have a vat so added VAT percentage input
        float vatPercentage, amountGiven, change, vatAmount;
        printf(BOLD_CYAN "\n\tEnter VAT percentage(if avilable): " RESET);
        scanf("%f", &vatPercentage);

        // Calculate VAT and final total price
        vatAmount = (totalPrice * vatPercentage) / 100;
        totalPrice += vatAmount;

        printf(BOLD_WHITE "\tTotal Price including VAT: %.2f\n" RESET, totalPrice);

        // Keep asking for sufficient amount until the purchase is successful
        do
        {
            printf(BOLD_GREEN "\tEnter your amount: " RESET);
            scanf("%f", &amountGiven);
            getchar();
            fflush(stdin);

            if (amountGiven >= totalPrice)
            {
                change = amountGiven - totalPrice;
                printf(BOLD_RED "\tChange you will get: %.2f\n" RESET, change);
                printf(BOLD_MAGENTA "\n\nThank you for purchasing :)\n" RESET);
                break; // Exit loop if the amount given is sufficient
            }
            else
            {
                float amountNeeded = totalPrice - amountGiven;
                printf(BOLD_RED "Insufficient amount. You need to give %.2f more.\n" RESET, amountNeeded);
            }
        } while (1); // Loop until sufficient amount is given
    }
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
        printf(BOLD_RED "\t\tError opening sales file!\n\n" RESET);
        Sleep(2000);
        return;
    }
    system("cls");
    printf(BOLD_BLUE "\nSales Report:\n\n" RESET);
    printf(BOLD_YELLOW "Customer Name" RESET);
    printf(BOLD_WHITE "          Phone Number" RESET);
    printf(BOLD_RED "    Product ID" RESET);
    printf(BOLD_YELLOW "   Product Name" RESET);
    printf(BOLD_CYAN "       Quantity" RESET);
    printf(BOLD_MAGENTA "    Total Price\n" RESET);
    printf(BOLD_MAGENTA "=================================================================================================\n" RESET);

    while (fscanf(salesFile, "%99[^\t]\t%14[^\t]\t%d\t%99[^\t]\t%d\t%f\n", purchase.customerName, purchase.phoneNumber, &purchase.productID, purchase.productName, &purchase.quantity, &purchase.totalPrice) != EOF)
    {
        printf(BOLD_YELLOW "%-23s" RESET, purchase.customerName);
        printf(BOLD_WHITE " %-15s" RESET, purchase.phoneNumber);
        printf(BOLD_RED " %-12d" RESET, purchase.productID);
        printf(BOLD_YELLOW " %-20s" RESET, purchase.productName);
        printf(BOLD_CYAN " %-10d" RESET, purchase.quantity);
        printf(BOLD_MAGENTA " %.2f\n" RESET, purchase.totalPrice);
    }
    printf(BOLD_MAGENTA "=================================================================================================\n" RESET);
    fclose(salesFile);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Low Stock Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void checkLowStock()
{
    struct Product p;
    int cnt = 0;
    FILE *file = fopen("products.txt", "r");
    if (file == NULL)
    {
        printf("Error opening Products file! Check if the file is Available...\n");
        return;
    }
    system("cls"); // clearing Screen
    printf(BOLD_RED "\nLow Stock Alert:\n\n" RESET);
    // printf("Product ID   Name                 Category            Available Quantity\n");
    printf(BOLD_RED "Product ID" RESET);
    printf(BOLD_YELLOW "    Name" RESET);
    printf(BOLD_WHITE "                 Category" RESET);
    printf(BOLD_CYAN "            Available Quantity\n" RESET);
    printf(BOLD_MAGENTA "=======================================================================\n\n" RESET);

    while (fscanf(file, "%d\t%[^\t]\t%[^\t]\t%f\t%f\n", &p.ID, p.category, p.name, &p.price, &p.quantity) != EOF)
    {
        if (p.quantity < 10)
        { // asuming the low stock in less then 10
            cnt = 1;
            printf(BOLD_RED "%-12d" RESET, p.ID);
            printf(BOLD_YELLOW " %-20s" RESET, p.name);
            printf(BOLD_WHITE " %-20s" RESET, p.category);
            printf(BOLD_CYAN " %.2f\n" RESET, p.quantity);
        }
    }
    if (cnt == 0)
    {
        printf(BOLD_GREEN "\n\tAll Products are available in good amount... :) \n" RESET);
    }
    printf(BOLD_MAGENTA "\n=======================================================================\n" RESET);
    fclose(file);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Backup Data Function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void backupData(const char *sourceFile, const char *backupFile)
{
    FILE *source = fopen(sourceFile, "r");
    FILE *backup = fopen(backupFile, "w");

    if (source == NULL || backup == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, backup);
    }

    fclose(source);
    fclose(backup);
    printf(BOLD_GREEN "Backup of %s created successfully as %s\n\n" RESET, sourceFile, backupFile);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Taking Review from Customer >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void giveReview()
{
    struct Review r;
    FILE *file = fopen("reviews.txt", "a+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    system("cls");
    printf(BOLD_YELLOW "<=================================================>\n\n" RESET);
    printf(YELLOW "\tEnter your name: " RESET);
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name, "\n")] = 0; // Remove newline character

    printf(CYAN "\n\tEnter your phone number: " RESET);
    fgets(r.phoneNumber, sizeof(r.phoneNumber), stdin);
    r.phoneNumber[strcspn(r.phoneNumber, "\n")] = 0; // Remove newline character

    do
    {
        printf(RED "\n\tRate our super shop (1-5): " RESET);
        scanf("%f", &r.rating);
        getchar(); // Consume the newline character
    } while (r.rating < 1 || r.rating > 5);

    printf(WHITE "\n\tEnter your comments (200 words max): " RESET);
    fgets(r.comments, sizeof(r.comments), stdin);
    r.comments[strcspn(r.comments, "\n")] = 0; // Remove newline character

    fprintf(file, "%s\t%s\t%f\t%s\n", r.name, r.phoneNumber, r.rating, r.comments);
    fclose(file);
    printf(BOLD_YELLOW "\n<===================================================>\n\n" RESET);
    printf(MAGENTA "\n\n\nThank you for your feedback!  :)\n" RESET);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Viewing customer reviews >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void viewReviews()
{
    struct Review r;
    FILE *file = fopen("reviews.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        Sleep(2000);
        return;
    }
    system("cls");
    printf(BOLD_CYAN "\n\tCustomer Reviews:\n\n" RESET);
    // printf("Name                     Phone Number    Rating  Comments\n");
    printf(BOLD_YELLOW "Name" RESET);
    printf(BOLD_MAGENTA "                     Phone Number" RESET);
    printf(BOLD_RED "    Rating" RESET);
    printf(BOLD_WHITE "  Comments\n" RESET);
    printf(BOLD_RED "======================================================================================\n\n" RESET);

    while (fscanf(file, "%99[^\t]\t%14[^\t]\t%f\t%499[^\n]\n", r.name, r.phoneNumber, &r.rating, r.comments) != EOF)
    {
        // printf("%-24s %-15s %-7.2f %s\n\n", r.name, r.phoneNumber, r.rating, r.comments);
        printf(BOLD_YELLOW "%-24s" RESET, r.name);
        printf(BOLD_MAGENTA " %-15s" RESET, r.phoneNumber);
        printf(BOLD_RED " %-7.2f" RESET, r.rating);
        printf(BOLD_WHITE " %s\n\n" RESET, r.comments);
        printf(BOLD_RED "======================================================================================\n\n" RESET);
    }

    fclose(file);
}
// end of the project Super shop Management.
