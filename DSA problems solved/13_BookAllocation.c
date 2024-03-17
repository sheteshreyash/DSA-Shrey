// You are given an array ‘pages’ of integer numbers.
// In this array, the ‘pages[i]’ represents the number of pages in the ‘i - th’ book.
// There are ‘m’ number of students,
// and the task is to allocate all the books to the students.

// Allocate books in a way such that :

// Each student gets at least one book.Each book should be allocated to a student.
// Book allocation should be in a contiguous manner.
// You have to allocate the books to ‘m’ students such that the maximum
// number of pages assigned to a student is minimum.

// input : -Number of books = 4 and Number of students = 2
// pages[] = {10, 20, 30, 40}
// output : -60

#include <stdio.h>

// Function to check if it is possible to allocate books with a maximum of max_pages to each student
int isPossible(int pages[], int n, int m, int max_pages)
{
    int students = 1;
    int pages_allocated = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages[i] > max_pages)
        {
            return 0; // Not possible to allocate each student at least one book
        }

        pages_allocated += pages[i];
        if (pages_allocated > max_pages)
        {
            students++;
            pages_allocated = pages[i];
        }
    }
    return students <= m;
}

// Function to find the minimum pages using a brute-force approach
int findMinimumPages(int pages[], int n, int m)
{
    if (m > n)
    {
        return -1; // Impossible to allocate each student at least one book
    }

    int minPages = 1;
    int maxPages = 0;

    for (int i = 0; i < n; i++)
    {
        maxPages += pages[i];
    }

    int result = -1;
    for (int x = minPages; x <= maxPages; x++)
    {
        if (isPossible(pages, n, m, x))
        {
            result = x;
            break;
        }
    }
    return result;
}

int main()
{
    int n, m;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the number of students: ");
    scanf("%d", &m);

    printf("Enter the number of pages for each book:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Book %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    int result = findMinimumPages(pages, n, m);
    if (result != -1)
    {
        printf("Minimum number of pages assigned to a student: %d\n", result);
    }
    else
    {
        printf("Impossible to allocate books as required.\n");
    }
    return 0;
}
