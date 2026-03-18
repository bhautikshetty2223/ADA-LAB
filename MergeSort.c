#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int temp[high+1];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high){
        if (a[i] <= a[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid){
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high){
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergesort(int a[], int low, int high)
{
    int mid;

    if (low < high){
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    clock_t start_t, end_t;
    double total_t;

    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    start_t = clock();
    mergesort(a, 0, n - 1);
    end_t = clock();

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);


    total_t = (end_t - start_t)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f", total_t);

    return 0;
}
