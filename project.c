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

#include <stdio.h>
int main()
{
  // code starts here with Welcome message.
  printf("**********************************************************************\n");
  printf("**********************************************************************\n");
  printf("***                                                                ***\n");
  printf("*****                                                            *****\n");
  printf("*******        Welcome to Super Shop Management System!        *******\n");
  printf("*****                                                            *****\n");
  printf("***                                                                ***\n");
  printf("**********************************************************************\n");
  printf("**********************************************************************\n");
  printf("\n");
  printf("                          Continue as...     \n");
  printf("                     ---------------------- \n\n");
  printf("\t   ******************************************\n");
  printf("\t   |     1.   Customer.                     |\n");
  printf("\t   |     2.   Shop Administrators.          |\n");
  printf("\t   |     3.   Shop Employee.                |\n");
  printf("\t   |     4.   Exit the system.              |\n");
  printf("\t   ******************************************\n");

  // here taking input from user.
  int n;
  scanf("%d", &n);

  switch (n)
  {
  case 1:
    // customer();
    break;
  case 2:
    // shopAdministrations();
  case 3:
    printf("Thank you for visiting our shop.\n");
    break;
  default:
    printf("Please select a valid option.\n");
    break;
  }

  return 0;
}
