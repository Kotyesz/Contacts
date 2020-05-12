#include <stdio.h>
#include <string.h>

typedef struct{
  char name[128],
  tel[128],
  age[128];
} contacts;

static int numofC = 0;
static contacts contact[128];

void mainMenu();

void addMenu(){
  printf("Name: ");
  scanf("%s", contact[numofC].name);
  printf("Tel: ");
  scanf("%s", contact[numofC].tel);
  printf("Age: ");
  scanf("%s", contact[numofC].age);
  numofC++;
  mainMenu();
}

void printContacts(){
  printf("\n\n\n\n\n\n\n");
  for(int i = 0; i < numofC; i++)
    printf("ID: %d \tName: %s\tTel: %s\tAge: %s\n",
      i,
      contact[i].name,
      contact[i].tel,
      contact[i].age
    );
    mainMenu();
}

void printSpecific(){
    printf("\n\n\n\n\n\n\n");
    char shearchWord[128];
    scanf("%s", shearchWord);
    char output[] = "";
    for(int i = 0; i < numofC; i++){
      if(strstr(contact[i].name,shearchWord) != NULL ||
         strstr(contact[i].tel,shearchWord) != NULL ||
         strstr(contact[i].age,shearchWord) != NULL){
           char temp[3];
           sprintf(output,"%d",i);
           strcat(output, "\nID: ");
           strcat(output, temp);
           strcat(output, "\tName: ");
           strcat(output, contact[i].name);
           strcat(output, "\tTel: ");
           strcat(output, contact[i].tel);
           strcat(output, "\tAge: ");
           strcat(output, contact[i].age);
         }
    }

    printf("%s\n\n", output);
    mainMenu();

}

void mainMenu(){
  int option;
  printf("\n\n\n\n\n\n\n1) add\n2) print specific\n3) print all\n4) exit\n\nChoice: ");
  scanf("%d", &option);

  option == 1 ? addMenu() :
  option == 2 ? printSpecific() :
  option == 3 ? printContacts() :
  NULL;

}

int main(){
  mainMenu();
  return 0;
}
