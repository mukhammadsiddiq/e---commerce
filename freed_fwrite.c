#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[256];
    int age;
    double average;
} student;

// Function prototypes
bool write_value(char *filename, student *data, int total);
student *read_value(char *filename, int *total);

int main(int argc, char **argv)
{
    student *school;

    // Allocate memory for an array of 3 students
    school = malloc(sizeof(student) * 3);

    // Initialize student data
    strcpy(school[0].name, "John Smith"); // you cannot directly assign a string to a character array. Instead, you could use strcpy, strncpy, or snprintf to copy the string literal into the character array.
    school[0].age = 21;
    school[0].average = 87.1;

    strcpy(school[1].name, "David Hitmann");
    school[1].age = 26;
    school[1].average = 97.1;

    strcpy(school[2].name, "Alexa Marrie");
    school[2].age = 29;
    school[2].average = 77.1;

    // Write student data to a binary file
    if (write_value("school.bin", school, 3))
        printf("Writed succesfully.\n"); // Success message
    else 
        printf("Failed"); // Failure message

    // Free allocated memory
    free(school);

    int total = 3; // Total number of students
    student *school_data = read_value("school.bin", &total); // Read student data from file
    if (school_data == NULL)
    {
        printf("Couldn't read"); // Error message if reading failed
        return 1;
    }
    printf("data read succesfully.\n"); // Success message
    // Print student data
    for (int i = 0; i < total; i++)
    {
        printf("\nstudent %d \n\n", i + 1); // Print student number
        printf("student_name: %s", school_data[i].name); // Print student name
        printf("student_average: %f\n", school_data[i].average); // Print student average
        printf("student_age: %d\n", school_data[i].age); // Print student age
    }
    // Free allocated memory
    free(school_data);
}

// Function to write student data to a binary file
bool write_value(char *filename, student *data, int total)
{
    FILE *file = fopen(filename, "wb"); // Open file for writing in binary mode

    if (file == NULL) return 1; // Return false if file opening failed

    // Write total number of students to file
    if (fwrite(&total, sizeof(int), 1, file) != 1)
        return false;

    // Write student data to file
    if (fwrite(data, sizeof(student), total, file) != total)
        return false;

    fclose(file); // Close file
    return true; // Return true indicating success
}

// Function to read student data from a binary file
student *read_value(char *filename, int *total)
{
    FILE *file = fopen(filename, "rb"); // Open file for reading in binary mode

    if (file == NULL) return NULL; // Return NULL if file opening failed

    // Read total number of students from file
    if (fread(total, sizeof(int), 1, file) != 1)
        return NULL;
    
    // Allocate memory for storing student data
    student *data = malloc(sizeof(student) * (*total));

    // Read student data from file
    if (fread(data, sizeof(student), *total, file) != *total)
    {
        free(data); // Free memory if reading failed
        return NULL;
    }

    fclose(file); // Close file
    return data; // Return pointer to student data
}
