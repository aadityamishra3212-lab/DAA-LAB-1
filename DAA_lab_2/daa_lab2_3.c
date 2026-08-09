// merge array one by one
#include <stdio.h>

#define MAX 100

// Merge two sorted arrays
void merge(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];
}

int main()
{
    int k, n;

    printf("Enter number of arrays: ");
    scanf("%d", &k);

    printf("Enter elements in each array: ");
    scanf("%d", &n);

    int arr[k][MAX];

    for (int i = 0; i < k; i++)
    {
        printf("\nEnter %d sorted elements of Array %d:\n", n, i + 1);

        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    int result[MAX];

    // Copy first array
    for (int i = 0; i < n; i++)
        result[i] = arr[0][i];

    int currentSize = n;

    for (int i = 1; i < k; i++)
    {
        int temp[MAX];

        merge(result, currentSize, arr[i], n, temp);

        currentSize += n;

        for (int j = 0; j < currentSize; j++)
            result[j] = temp[j];
    }

    printf("\nMerged Array:\n");

    for (int i = 0; i < currentSize; i++)
        printf("%d ", result[i]);

    return 0;
}

// pairing merging (using divide and conquer)


#include <stdio.h>

#define MAX 100

void merge(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];
}

int main()
{
    int k, n;

    printf("Enter number of arrays: ");
    scanf("%d", &k);

    printf("Enter elements in each array: ");
    scanf("%d", &n);

    int arrays[20][MAX];
    int size[20];

    for (int i = 0; i < k; i++)
    {
        printf("\nEnter %d sorted elements of Array %d:\n", n, i + 1);

        size[i] = n;

        for (int j = 0; j < n; j++)
            scanf("%d", &arrays[i][j]);
    }

    while (k > 1)
    {
        int newK = 0;

        for (int i = 0; i < k; i += 2)
        {
            if (i + 1 == k)
            {
                // Odd array left
                for (int j = 0; j < size[i]; j++)
                    arrays[newK][j] = arrays[i][j];

                size[newK] = size[i];
                newK++;
            }
            else
            {
                int temp[MAX];

                merge(arrays[i], size[i],
                      arrays[i + 1], size[i + 1],
                      temp);

                int total = size[i] + size[i + 1];

                for (int j = 0; j < total; j++)
                    arrays[newK][j] = temp[j];

                size[newK] = total;
                newK++;
            }
        }

        k = newK;
    }

    printf("\nMerged Array:\n");

    for (int i = 0; i < size[0]; i++)
        printf("%d ", arrays[0][i]);

    return 0;
}