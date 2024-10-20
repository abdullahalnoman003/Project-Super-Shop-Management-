/*
  Super Shop Management System

  Name: Abdullah Al Noman
  ID: 232-35-003

  Name: Adnan Iqbal
  ID: 232-35-024

  Name: Rashedul Islam
  ID: 232-35-066
  
  Section: A2
  */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
// Text color codes
#define RESET       "\033[0m"        // Reset all attributes

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

void menu();
void customer();
void admin();

void viewProduct();
void searchProduct();
void checkout();
void addtoCart();
void deleteFromCart();

void addProduct();
void deleteProduct();
void editProduct();

void customer() {
    int i, choice;
    char stay;

    system("cls");  // Clear the screen
    printf("Hello! Welcome To our Shop :)\n");

    // Simulate a loading animation
    for (i = 0; i < 31; i++) {
        printf(".");
        Sleep(20);  // Pause to create a loading effect
    }
    printf("\n");
do{
    printf("\n");
    printf("What would you like to do? \n");
    printf("1.  View Product. \n");
    printf("2.  Search Product. \n");
    printf("3.  Add to cart. \n");
    printf("4.  Delete from cart? \n");
    printf("5.  Return to Main Menu. \n");  // Added option to return to the main menu
    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            //viewProduct(); //calling vieew product
            printf("Viewing products...\n");
            break;
        case 2:
            //searchProduct(); //calling search product
            printf("Searching products...\n");
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
        printf("\nDo you want to stay in the Customer Menu? (Y/N): ");
        scanf(" %c", &stay);  // the space before %c to consume any leftover newline character

    } while (stay == 'Y' || stay == 'y');
    system("cls");  // Clearing screen
}

void admin(){

}
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
  printf(CYAN"\tCurrent Date and Time: %s"RESET,ctime(&t));
  printf("\t");
  for(i=0; i<47; i++){
        printf(BOLD_MAGENTA"."RESET);
        Sleep(20);
    }
  printf("\n\n");
	printf("\nPress any key to continue....\n");
  getch();
  system("cls");

do {
    printf("\n");
    printf(BOLD_WHITE"                   Continue as...     \n"RESET);
    printf(BOLD_MAGENTA"             ---------------------- \n\n");
    printf(CYAN"   ******************************************\n"RESET);
    printf(BOLD_MAGENTA"         1.   Customer.                      \n"RESET);
    Sleep(500);
    printf(BOLD_YELLOW"         2.   Shop Administrators.           \n"RESET);
    Sleep(500);
    printf(BOLD_RED"         3.   Exit the system.               \n"RESET);
    Sleep(500);
    printf(CYAN"   ******************************************\n"RESET);
    printf("\n");

    // Take input from user
    printf("Please Enter Your Selection: ");
    scanf("%d", &n);

    // Process user input
    switch (n) {
        case 1:
            customer();  //Calling customer
            break;
        case 2:
            admin();  // calling admin
            break;  
        case 3:
            printf("Thank you for visiting our shop.\n     Stay Safe. :) \n"); // Exiting 
            break;  
        default:
        
            printf(RED"Please select a valid option.\n"RESET);
            Sleep(3000);  // Pause to allow the user to see the message
            system("cls");  // Clear screen 
            break;
    }
} while (n != 3);  // Loop until the user selects option 3 to exit
}

// main Function starting

void main(void)
{
  menu();
}
