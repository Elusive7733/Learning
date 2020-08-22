#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
  char name[50];
  int ID;
}student;

void main()
{
  int N, i;
  student *students;
  printf("Enter Number of students:\n");
  scanf(" %d", &N);
  students = (student*) calloc(N, sizeof(student));
  for(i = 0; i < N; i++)
  {
    fflush(stdin);
    printf("Enter Name of student # %d\n", i+1);
    gets((students + i)->name);
    printf("Enter ID of student # %d\n", i+1);
    scanf(" %d", &(students+i)->ID);
  }

  for(i = 0; i < N; i++)
  {
    if((students+i)->name[0] == 'A' || (students+i)->name[0] == 'a')
    {
      printf("Name = %s\n", (students+i)->name);
      printf("ID = %d\n", (students+i)->ID);
    }
  }
}
