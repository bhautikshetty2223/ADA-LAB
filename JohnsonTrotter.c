#include <stdio.h>
#include <time.h>


int n;
int p[10], dir[10];

// Print current permutation
void printPerm()
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

// Find largest mobile element
int largestMobile()
{
    int mobile = 0;

    for (int i = 0; i < n; i++)
    {
        // Moving left
        if (dir[i] == -1 && i != 0 && p[i] > p[i - 1])
        {
            if (p[i] > mobile)
                mobile = p[i];
        }

        // Moving right
        if (dir[i] == 1 && i != n - 1 && p[i] > p[i + 1])
        {
            if (p[i] > mobile)
                mobile = p[i];
        }
    }

    return mobile;
}

int main()
{
    clock_t start_t, end_t;
    double total_t;

    printf("Enter n: ");
    scanf("%d", &n);

    start_t = clock();
    // Initialize permutation and directions
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        dir[i] = -1; // all move left initially
    }

    printPerm();

    while (1)
    {
        int mobile = largestMobile();

        if (mobile == 0)
            break;

        int pos;

        // Find position of mobile element
        for (int i = 0; i < n; i++)
        {
            if (p[i] == mobile)
            {
                pos = i;
                break;
            }
        }

        // Swap mobile element
        int newPos = pos + dir[pos];

        int temp = p[pos];
        p[pos] = p[newPos];
        p[newPos] = temp;

        // Swap directions too
        temp = dir[pos];
        dir[pos] = dir[newPos];
        dir[newPos] = temp;

        // Reverse direction of larger elements
        for (int i = 0; i < n; i++)
        {
            if (p[i] > mobile)
                dir[i] = -dir[i];
        }
        end_t = clock();

        //  printPerm();
    }
    end_t = clock();
    total_t = (end_t - start_t)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f", total_t);

    return 0;
}
