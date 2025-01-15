#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input = malloc(20);
    char *output = malloc(20);

    if (input == NULL || output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strncpy(output, "normal output", 20);
    output[19] = '\0'; // Ensure null termination

    if (argc > 1) {
        strncpy(input, argv[1], 19); // Copy at most 19 characters
        input[19] = '\0'; // Ensure null termination
    } else {
        fprintf(stderr, "No input provided\n");
        return 1;
    }

    printf("input at %p: %s\n", (void *)input, input);
    printf("output at %p: %s\n", (void *)output, output);
    printf("\n\n%s\n", output);

    // Free allocated memory before exiting
    free(input);
    free(output);

    return 0;
}

#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc,char *argv[])
{   
    size_t buffer_size[20];
    char *input = malloc(20);
    char *output = malloc(20);

    if(input == NULL || output == NULL)
    {
        perror("error: ");
        exit(EXIT_FAILURE);
    }
    strncpy(output,"dataop",buffer_size-1);
    printf("test %s",output);
    if(argc != 3)
    {   
        perror("error :");
        free(input);
        free(output);
        exit(EXIT_FAILURE);
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("the two args passed : %d & %d\n",num1,num2);

    return 0;
}



