// standard merge sort implementation in c 
#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}
//moified merge sort with divided the given array in three part 


#include <stdio.h>

void mergeThree(int arr[], int l, int m1, int m2, int r)
{
    int temp[r - l + 1];
    int i = l;
    int j = m1 + 1;
    int k = m2 + 1;
    int t = 0;

    while (i <= m1 && j <= m2 && k <= r)
    {
        if (arr[i] <= arr[j] && arr[i] <= arr[k])
            temp[t++] = arr[i++];
        else if (arr[j] <= arr[i] && arr[j] <= arr[k])
            temp[t++] = arr[j++];
        else
            temp[t++] = arr[k++];
    }

    while (i <= m1 && j <= m2)
        temp[t++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    while (j <= m2 && k <= r)
        temp[t++] = (arr[j] < arr[k]) ? arr[j++] : arr[k++];

    while (i <= m1 && k <= r)
        temp[t++] = (arr[i] < arr[k]) ? arr[i++] : arr[k++];

    while (i <= m1)
        temp[t++] = arr[i++];

    while (j <= m2)
        temp[t++] = arr[j++];

    while (k <= r)
        temp[t++] = arr[k++];

    for (int x = 0; x < t; x++)
        arr[l + x] = temp[x];
}

void modifiedMergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int third = (r - l) / 3;

    int m1 = l + third;
    int m2 = l + 2 * third + 1;

    if (m2 > r)
        m2 = r;

    modifiedMergeSort(arr, l, m1);
    modifiedMergeSort(arr, m1 + 1, m2);
    modifiedMergeSort(arr, m2 + 1, r);

    mergeThree(arr, l, m1, m2, r);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    modifiedMergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}