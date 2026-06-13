#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct person{
char name[100];
char phoneNumber[20];
struct person *next;
};

void addPerson(struct person **head);
bool getPersonInput(char *name , char *phoneNumber);
int printMenu(void);
void clearBuffer(void);



int main(void){
int choice=0;
    struct person *head=NULL;



do{
       choice=printMenu();
        switch(choice){
            case 1: addPerson(&head);
            break;

            case 2: listNumbers();
            break;

            case 3: deleteNumber();
            break;

            case 4: searchNumber();
            break;

            case 5: printf("Exiting...\n");
            break;

            default: printf("Invalid selection. Please try again\n");
        }
    }while(choice!=5);


}
int printMenu(void){
    int choice=0;
        printf("To add a new number, click 1\n");
        printf("To list the numbers, click 2\n");
        printf("To delete the number, click 3\n");
        printf("To search the number, click 4\n");
        printf("To exit, click 5\n");

        if(scanf("%d",&choice)!=1){
            printf("Please enter a valid number\n");
            clearBuffer();
        return 0;
        }
        return choice;
}
bool getPersonInput(char *name , char *phoneNumber){

printf("Enter name: ");
if(scanf("%99s", name) != 1){
    fprintf(stderr, "Invalid name\n");
    clearBuffer();
    return false;
}

printf("Enter phone number: ");
if(scanf("%19s", phoneNumber) != 1){
    fprintf(stderr, "Invalid number\n");
    clearBuffer();
    return false;
}
return true;
}

void addPerson(struct person **head){
struct person *newPerson=malloc(sizeof(struct person));
if(newPerson==NULL) return;
newPerson->next=NULL;
bool isSuccess = getPersonInput(newPerson->name, newPerson->phoneNumber);

    if(!isSuccess){
    free(newPerson);
    return;
}
    struct person *previousPtr=NULL;
    struct person *currentPtr=*head;

    while(currentPtr != NULL && strcmp(newPerson->name , currentPtr->name)>0){

        previousPtr=currentPtr;
        currentPtr=currentPtr->next;
    }

    if(previousPtr==NULL){
        newPerson->next=*head;
        *head=newPerson;
    }

    else{
        previousPtr->next=newPerson;
        newPerson->next=currentPtr;
    }

}
void clearBuffer(void){
int c;
while((c=getchar())!='\n' && c!=EOF);
}