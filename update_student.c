#include <stdio.h>
#include <stdlib.h>
#define Lenght 64

int main(int argc, char const *argv[]) 
{

    char first_name[Lenght];
    char last_name[Lenght];
    int age;

    printf("First Name: ");
    scanf("%s", first_name);

    printf("Last Name: ");
    scanf("%s", last_name);

    printf("Age: ");
    scanf("%d", &age);

    FILE* fd=fopen("student.dat","r+");

    fseek(fd,sizeof(int)+(atoi(argv[1])-1)*(sizeof(first_name)+sizeof(last_name)+sizeof(age)+sizeof(int))+sizeof(int),SEEK_SET);

    fwrite(first_name,sizeof(first_name),1,fd);
    fwrite(last_name,sizeof(last_name),1,fd);
    fwrite(&age,sizeof(age),1,fd);
    fclose(fd);
    return 0;
}
