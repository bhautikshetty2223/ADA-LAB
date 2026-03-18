#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int lb, int ub)
{
    int pivot, i, j, temp;

    pivot = a[lb];
    i = lb;
    j = ub;

    while (i < j)
    {
        while (a[i] <= pivot && i <= ub)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[lb] = a[j];
    a[j] = pivot;

    return j;
}

void quicksort(int a[], int lb, int ub)
{
    int k;

    if (lb < ub)
    {
        k = partition(a, lb, ub);
        quicksort(a, lb, k - 1);
        quicksort(a, k + 1, ub);
    }
}

int main()
{
    int n, i;
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    start = clock();

    quicksort(a, 0, n - 1);

    end = clock();

    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTime taken = %lf seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
