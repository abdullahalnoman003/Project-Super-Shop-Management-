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
        printf(BOLD_MAGENTA "-" RESET);
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
        printf(BOLD_MAGENTA "             <----------------------> \n\n");
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
            break;
        case 2:
            system("cls");
            int c2;
            printf(BOLD_CYAN "\t\tWelcome :)\n" RESET);
            printf(BOLD_MAGENTA "\t<------------------------>\n\n" RESET);
            printf(BOLD_GREEN "\t1 => Login as Staff.\n" RESET);
            printf(BOLD_YELLOW "\t2 => Login as Admin.\n\n");
            printf(BOLD_MAGENTA "\t<------------------------->\n\n" RESET);
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
            printf(BOLD_CYAN "\t\t<====Thank you for visiting our shop.====>\n     \t\t<====Stay Safe. :)====> \n\n\n\n" RESET);
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