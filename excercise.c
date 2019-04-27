#include<stdio.h>
#include<math.h>
int min(int step, int size)
{
    return (step<size) ? step : size;
}

int JumpSearch(int arr[],int key, int size)
{
    int step = sqrt(size);
    int prev = 0;

    while(arr[min(step,size)-1] < key){
        prev = step;
        step += sqrt(size);

        if(prev >= size)
            return -1;
    }

    while(arr[prev] < key){
        prev++;

        if(prev == min(step,size))
            return -1;
    }

    if(arr[prev] == key)
        return prev;

    return -1;
}

void main()
{
    int arr[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};

    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 55;

    int index = JumpSearch(arr,key,size);

    if(index == -1)
        printf("Not Found!!\n");
    else
        printf("%d is found at %d position\n",key,index);
}
