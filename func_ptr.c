#if 0
#include <stdio.h>
#include <stdlib.h>


int test(int a,int b)
{
    return a + b;
}
int main()
{
    int (*func_ptr)(int,int);
    func_ptr =test;

    int result = func_ptr(10,5);

    printf("test result %d",result);
}

#endif

#include <stdio.h>
#include <stdlib.h>

int dynamic(int a ,int b)
{
    
}

int main()
{
    int (*ptr)(int,int);

    ptr = dynamic;

    int result = ptr(10,10)

}