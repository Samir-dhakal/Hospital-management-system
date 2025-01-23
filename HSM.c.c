
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void addPatients();
void viewPatients();
void addDoctors();
void viewDoctors();
void searchPatient();
char *current_time();
int isFileEmpty(FILE *file);

int main()
{
    int index;
    printf("\nHospital Management System\n");
    printf("1: To store the data of new patients.\n");
    printf("2: To see the patients' records.\n");
    printf("3: To enter the doctors' records.\n");
    printf("4: To see the records of the doctors.\n");
    printf("5: To find a specific patient in the hospital.\n");
    printf("0: Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &index);

    switch (index)
    {
    case 1:
        addPatients();
        break;
    case 2:
        viewPatients();
        break;
    case 3:
        addDoctors();
        break;
    case 4:
        viewDoctors();
        break;
    case 5:
        searchPatient();
        break;
    case 0:
        printf("Exiting the program.\n");
        exit(0);
    default:
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}
void addPatients()
{
    int nop;
    printf("Enter the number of patients: ");
    scanf("%d", &nop);

    struct patients
    {
        int id;
        char name[100];
        long phone_no;
        char gender[10];
        int age;
        char time[40];
    };

    struct patients people[nop];

    for (int i = 0; i < nop; i++)
    {
        printf("Enter the ID of patient %d: ", i + 1);
        scanf("%d", &people[i].id);
        printf("Enter the phone number of patient %d: ", i + 1);
        scanf("%ld", &people[i].phone_no);
        getchar();
        printf("Enter the name of patient %d: ", i + 1);
        scanf("%[^\n]", people[i].name);
        printf("Enter the age of patient %d: ", i + 1);
        scanf("%d", &people[i].age);

        printf("Enter the gender of patient %d (m for male, f for female): ", i + 1);
        char genderInput;
        scanf(" %c", &genderInput);
        if (genderInput == 'm')
        {
            strcpy(people[i].gender, "male");
        }
        else
        {
            strcpy(people[i].gender, "female");
        }

        strcpy(people[i].time, current_time());
    }

    FILE *file = fopen("patan.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    if (isFileEmpty(file))
    {
        fprintf(file, "%-5s%-20s%-12s%-5s%-5s%-20s\n", "ID", "NAME", "CONTACT NO", "AGE", "GENDER", "TIME OF ADMISSION");
    }

    for (int i = 0; i < nop; i++)
    {
        fprintf(file, "%-5d%-20s%-12ld%-5d%-20s%-6s\n",
                people[i].id, people[i].name, people[i].phone_no,
                people[i].age, people[i].gender, people[i].time);
    }

    fclose(file);
    printf("Data saved successfully to 'patan.txt'.\n");
}
void viewPatients()
{
    FILE *file = fopen("patan.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file or file does not exist.\n");
        return;
    }

    char line;
    while ((line = fgetc(file)) != EOF)
    {
        putchar(line);
    }

    fclose(file);
}

void addDoctors()
{
    int nod;
    printf("Enter the number of doctors to store records: ");
    scanf("%d", &nod);

    struct doctors
    {
        int id;
        char name[100];
        long phone_no;
        char specialization[100];
    };

    struct doctors doctors[nod];

    for (int i = 0; i < nod; i++)
    {
        printf("Enter the ID of doctor %d: ", i + 1);
        scanf("%d", &doctors[i].id);
        printf("Enter the phone number of doctor %d: ", i + 1);
        scanf("%ld", &doctors[i].phone_no);
        getchar();
        printf("Enter the name of doctor %d: ", i + 1);
        scanf("%[^\n]", doctors[i].name);
        getchar();
        printf("Enter the specialization of doctor %d: ", i + 1);
        scanf("%[^\n]", doctors[i].specialization);
    }

    FILE *file = fopen("doctor.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < nod; i++)
    {
        fprintf(file, "%-5d%-20s%-12ld%-20s\n",
                doctors[i].id, doctors[i].name, doctors[i].phone_no, doctors[i].specialization);
    }

    fclose(file);
    printf("Data saved successfully to 'doctor.txt'.\n");
}
void viewDoctors()
{
    FILE *file = fopen("doctor.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file or file does not exist.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
}
void searchPatient()
{
    char name[100], line[256];
    printf("Enter the name of the patient you want to search: ");
    getchar();
    scanf("%[^\n]", name);

    FILE *file = fopen("patan.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file or file does not exist.\n");
        return;
    }

    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, name) != NULL)
        {
            found = 1;
            printf("Patient found:\n");
            printf("%-5s%-20s%-12s%-5s%-5s%-20s\n", "ID", "NAME", "CONTACT NO", "AGE", "GENDER", "TIME OF ADMISSION");
            printf("%s", line);
            break;
        }
    }

    if (!found)
    {
        printf("Patient not found.\n");
    }

    fclose(file);
}
int isFileEmpty(FILE *file)
{
    long currentPos = ftell(file);
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, currentPos, SEEK_SET);
    return fileSize == 0;
}
char *current_time()
{
    time_t now = time(NULL);
    return ctime(&now);
}
