#include <stdio.h>

// Swap function
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int start = low;
    int end = high;

    while (start < end)
    {
        while (a[start] <= pivot && start < high)
            start++;

        while (a[end] > pivot)
            end--;

        if (start < end)
            swap(&a[start], &a[end]);
    }

    swap(&a[low], &a[end]);
    return end;
}

// Quick Sort function
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int location = partition(a, low, high);

        quicksort(a, low, location - 1);
        quicksort(a, location + 1, high);
    }
}

// Main function
int main()
{
    int n;

    printf("\nEnter array size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}