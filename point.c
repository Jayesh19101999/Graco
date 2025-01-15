#include <stdio.h>

void pointermodify(int **doubleptr)
{   
    
    **doubleptr = 200; 
}

int main()
{
    int *ptr;     
    int a = 65;   
    ptr = &a;     

    printf("Before modification: %d\n", a);  

    pointermodify(&ptr); 

    printf("After modification: %d\n", a);  
    return 0;
}
