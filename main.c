#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "book.h"

#define MAX_BOOKS 100

int pages[MAX_BOOKS];
int sum[MAX_BOOKS];

int menu()
{
    int choice;
    printf("Choose the input method:\n");
    printf("1. Enter data manually\n");
    printf("2. Generate data randomly\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    int n, choice;
    srand(time(NULL));  // Initialize random number generator seed

    choice = menu(); // Display menu and get user choice

    if (choice == 1)
    {
        printf("Enter the number of books: ");
        n = get_natural_number();
        printf("Enter the number of pages for each book:\n");
        for (int i = 0; i < n; i++)
        {
            printf("Book %d: ", i + 1);
            pages[i] = get_natural_number();
            sum[i] = (i == 0) ? pages[i] : sum[i - 1] + pages[i];
        }
    }
    else if (choice == 2)
    {
        generate_random_input(&n);
        printf("Generated %d books with the following pages:\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("Book %d: %d pages\n", i + 1, pages[i]);
        }
    }
    else
    {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    solve(n);
    return 0;
}
