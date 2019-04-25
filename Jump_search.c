#include<stdio.h>
#include<math.h>

int min(int x, int y){
    return (x>y) ? x : y;
}

int jumpSearch(int arr[],int x, int n)
{
    //Finding block size to be jumped//
    int step = sqrt(n);

    //Finding the block where element is present(if present)//
    int prev = 0;
    while(arr[min(step,n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if(prev >= n)
            return -1;
    }
    //Doing a linear search for x in block beginning with prev//
    while(arr[prev] < x){
        prev++;
        //if we reached next block or end of array, element is not present//
        if(prev == min(step,n))
            return -1;
    }

    //if element is found//
    if(arr[prev] == x)
        return prev;

    return -1;
}

void main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89, 144, 233, 377, 610 };
    int x = 1;
    int n = sizeof(arr) / sizeof(arr[0]);

    //Find the index of 'x' using Jump search//
    int index  = jumpSearch(arr,x,n);
    //print the index where 'x' is located//
    if(index == -1)
        printf("Not found\n");
    else
        printf("Number %d is at index %d\n",x,index);
}
