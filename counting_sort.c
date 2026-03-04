#include <stdio.h>

void countingSort(int a[], int n)
{
    int i;

    // Find maximum element
    int max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    int count[max + 1];
    int temp[n];

    // Initialize count array
    for (i = 0; i <= max; i++)
        count[i] = 0;

    // Store frequency
    for (i = 0; i < n; i++)
        count[a[i]]++;

    // Cumulative count
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array (stable sorting)
    for (i = n - 1; i >= 0; i--)
        temp[--count[a[i]]] = a[i];

    // Copy back to original array
    for (i = 0; i < n; i++)
        a[i] = temp[i];
}

int main()
{
    int n, i;
    int a[100];

    printf("\nEnter array size: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    countingSort(a, n);

    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}