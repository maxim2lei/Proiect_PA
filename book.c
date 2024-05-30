#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_BOOKS 100
#define MAX_PAGES 1000

int pages[MAX_BOOKS];
int sum[MAX_BOOKS];

int random_number(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
void generate_random_input(int *n)
{
    *n = random_number(1, MAX_BOOKS);
    for (int i = 0; i < *n; i++)
    {
        pages[i] = random_number(1, MAX_PAGES);
        sum[i] = (i == 0) ? pages[i] : sum[i - 1] + pages[i];
    }
}
// Funcție pentru a obține un număr natural de la utilizator
int get_natural_number()
{
    int num;
    char term;
    while (printf("Enter a natural number: "),
            scanf("%d%c", &num, &term) != 2 || term != '\n' || num < 1)
    {
        printf("Invalid input! Please enter a natural number.\n");
        while (getchar() != '\n'); // Curăță buffer-ul
    }
    return num;
}
// Calculează suma paginilor de la indexul start la indexul end
int range_sum(int start, int end)
{
    if (start == 0) return sum[end];
    return sum[end] - sum[start - 1];
}

// Afișează paginile pentru fiecare angajat
void print_pages(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        printf("%d ", pages[i]);
    }
    printf("\n");
}

// Soluție pentru împărțirea cărților care minimizează diferența maximă
void solve(int books)
{
    int total_sum = sum[books - 1];
    int min_diff = INT_MAX;
    int best_end1 = 0, best_end2 = 0;

    for (int end1 = 1; end1 < books - 1; end1++)
    {
        for (int end2 = end1 + 1; end2 < books; end2++)
        {
            int sum1 = range_sum(0, end1 - 1);
            int sum2 = range_sum(end1, end2 - 1);
            int sum3 = range_sum(end2, books - 1);
            int local_max = sum1 > sum2 ? (sum1 > sum3 ? sum1 : sum3) : (sum2 > sum3 ? sum2 : sum3);
            int local_min = sum1 < sum2 ? (sum1 < sum3 ? sum1 : sum3) : (sum2 < sum3 ? sum2 : sum3);
            int diff = local_max - local_min;
            if (diff < min_diff)
            {
                min_diff = diff;
                best_end1 = end1;
                best_end2 = end2;
            }
        }
    }

    printf("Employee 1: %d pages ", range_sum(0, best_end1 - 1));
    print_pages(0, best_end1 - 1);
    printf("Employee 2: %d pages ", range_sum(best_end1, best_end2 - 1));
    print_pages(best_end1, best_end2 - 1);
    printf("Employee 3: %d pages ", range_sum(best_end2, books - 1));
    print_pages(best_end2, books - 1);
}
