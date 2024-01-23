// C program for shallow and deep copy

#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int age;
};

// Function for shallow copy
void shallowCopy(struct Student *dest, const struct Student *src)
{
    *dest = *src;
}

// Function for deep copy
void deepCopy(struct Student *dest, const struct Student *src)
{
    strcpy(dest->name, src->name);
    dest->age = src->age;
}

int main()
{
    struct Student student1;

    // Accept user input for the original data
    printf("\nEnter details for Student 1:\n");
    printf("Name: ");
    scanf("%s", student1.name); // Assuming the name doesn't contain spaces
    printf("Age: ");
    scanf("%d", &student1.age);

    struct Student student2, student3;

    shallowCopy(&student2, &student1); // Shallow copy
    deepCopy(&student3, &student1); // Deep copy

    printf("\nOriginal Data:\n");
    printf(" %s, %d years old\n", student1.name, student1.age);

    printf("\nShallow Copy:\n");
    printf(" %s, %d years old\n", student2.name, student2.age);

    printf("\nDeep Copy:\n");
    printf(" %s, %d years old\n", student3.name, student3.age);

    return 0;
}
