#include <stdio.h>
#include <stdlib.h>
#define n 8

int main(void)
{
    int *arr = malloc(n * sizeof(int));
    if(arr == NULL)
    {
        perror("memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for(int i =0 ;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    for(int i =0 ;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("final");

    return 0;
}