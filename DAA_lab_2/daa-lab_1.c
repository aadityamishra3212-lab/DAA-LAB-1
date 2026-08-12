#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int arr[MAX];
int size = 0;

// Insert
void insert(int key)
{
    arr[size++] = key;
}

// Search
int search(int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

// Delete
void deleteKey(int key)
{
    int index = search(key);

    if(index==-1)
        return;

    arr[index]=arr[size-1];
    size--;
}

// Maximum
int maximum()
{
    int max=arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }

    return max;
}

// Minimum
int minimum()
{
    int min=arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }

    return min;
}

// Predecessor
int predecessor(int key)
{
    int pred=-1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]<key)
        {
            if(pred==-1 || arr[i]>pred)
                pred=arr[i];
        }
    }

    return pred;
}

// Successor
int successor(int key)
{
    int succ=-1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>key)
        {
            if(succ==-1 || arr[i]<succ)
                succ=arr[i];
        }
    }

    return succ;
}

int main()
{
    clock_t start,end;
    double time_taken;

    // Insert random values
    for(int i=0;i<50000;i++)
        insert(rand());

    start=clock();
    search(arr[40000]);
    end=clock();
    printf("Search Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    insert(500);
    end=clock();
    printf("Insert Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    deleteKey(arr[20000]);
    end=clock();
    printf("Delete Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    maximum();
    end=clock();
    printf("Maximum Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    minimum();
    end=clock();
    printf("Minimum Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    predecessor(arr[10000]);
    end=clock();
    printf("Predecessor Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    start=clock();
    successor(arr[10000]);
    end=clock();
    printf("Successor Time = %lf seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}