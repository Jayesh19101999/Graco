#include <stdio.h>
#include <string.h>

// Define a typedef for the union
typedef union {
    int id;
    char name[20];
    float sensor;
} Data;

int main(void) {
    // Declare a variable of the typedef-ed union
    Data data1;

    // Assign values to the union members
    data1.id = 1;
    printf("ID: %d\n", data1.id);

    strcpy(data1.name, "pressure_switch");
    printf("Name: %s\n", data1.name);

    data1.sensor = 24.4;
    printf("Sensor: %.2f\n", data1.sensor);

    return 0;
}
