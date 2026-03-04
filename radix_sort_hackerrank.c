#include <stdio.h>
#include <stdlib.h>

void countsort(int a[], int n, int place)
{
    int count[10] = {0};
    int temp[n];

    // Count frequency of digits
    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--)
        temp[--count[(a[i] / place) % 10]] = a[i];

    // Copy back
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}

void radixsort(int a[], int n)
{
    int max = a[0];

    // Find maximum element
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    // Apply counting sort for each digit place
    for (int place = 1; max / place > 0; place *= 10)
        countsort(a, n, place);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixsort(a, n);

    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(",");
    }
    printf("]");

    return 0;
}