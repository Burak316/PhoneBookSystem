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

int main(){
struct person *head=NULL;
}

bool getPersonInput(char *name , char *phoneNumber){

printf("Enter name: ");
if(scanf("%99s", name) != 1){
    fprintf(stderr, "Invalid name\n");
    return 0;
}

printf("Enter phone number: ");
if(scanf("%19s", phoneNumber) != 1){
    fprintf(stderr, "Invalid number\n");
    return 0;
}
return 1;
}

void addPerson(struct person **head){
struct person *newPerson=malloc(sizeof(struct person));
if(newPerson==NULL) return;
newPerson->next=NULL;
int control = getPersonInput(newPerson->name, newPerson->phoneNumber);

    if(!control){
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