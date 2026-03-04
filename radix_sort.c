#include <stdio.h>

// Counting sort used inside Radix Sort (for each digit place)
void countSort(int a[], int n, int place)
{
    int temp[n];
    int count[10] = {0};

    // Store frequency of digits
    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (a[i] / place) % 10;
        temp[--count[digit]] = a[i];
    }

    // Copy back
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}

// Radix Sort function
void radixSort(int a[], int n)
{
    int max = a[0];

    // Find maximum element
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    // Apply counting sort for each digit place
    for (int place = 1; max / place > 0; place *= 10)
        countSort(a, n, place);
}

int main()
{
    int n;

    printf("\nEnter array size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}