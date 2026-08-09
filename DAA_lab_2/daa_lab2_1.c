#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;

// Insert
void insert(int key)
{
    if (n == MAX)
    {
        printf("Dictionary is Full!\n");
        return;
    }
    arr[n++] = key;
    printf("Inserted %d\n", key);
}

// Search
int search(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Delete
void deleteKey(int key)
{
    int pos = search(key);

    if (pos == -1)
    {
        printf("Key not found!\n");
        return;
    }

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
    printf("Deleted %d\n", key);
}

// Maximum
void maximum()
{
    if (n == 0)
    {
        printf("Dictionary Empty\n");
        return;
    }

    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    printf("Maximum = %d\n", max);
}

// Minimum
void minimum()
{
    if (n == 0)
    {
        printf("Dictionary Empty\n");
        return;
    }

    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Minimum = %d\n", min);
}

// Predecessor
void predecessor(int key)
{
    int pred;
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < key)
        {
            if (!found || arr[i] > pred)
            {
                pred = arr[i];
                found = 1;
            }
        }
    }

    if (found)
        printf("Predecessor = %d\n", pred);
    else
        printf("No predecessor exists.\n");
}

// Successor
void successor(int key)
{
    int succ;
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > key)
        {
            if (!found || arr[i] < succ)
            {
                succ = arr[i];
                found = 1;
            }
        }
    }

    if (found)
        printf("Successor = %d\n", succ);
    else
        printf("No successor exists.\n");
}

// Display
void display()
{
    if (n == 0)
    {
        printf("Dictionary Empty\n");
        return;
    }

    printf("Dictionary: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int choice, key;

    while (1)
    {
        printf("\n------ Dictionary Operations ------\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Maximum\n");
        printf("5. Minimum\n");
        printf("6. Predecessor\n");
        printf("7. Successor\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter key: ");
            scanf("%d", &key);

            if (search(key) != -1)
                printf("Key Found\n");
            else
                printf("Key Not Found\n");
            break;

        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            deleteKey(key);
            break;

        case 4:
            maximum();
            break;

        case 5:
            minimum();
            break;

        case 6:
            printf("Enter key: ");
            scanf("%d", &key);
            predecessor(key);
            break;

        case 7:
            printf("Enter key: ");
            scanf("%d", &key);
            successor(key);
            break;

        case 8:
            display();
            break;

        case 9:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}