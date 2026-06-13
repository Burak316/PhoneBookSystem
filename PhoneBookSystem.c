#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
char name[100];
char phoneNumber[20];
struct person *next;
};

void addPerson(struct person **head,char *name,char *phoneNumber);


int main(){
struct person *head=NULL;
}


void addPerson(struct person **head,char *name,char *phoneNumber){

struct person *newPerson=malloc(sizeof(struct person));
if(newPerson==NULL) return;
printf("Enter name: ");
if(scanf("%99s", newPerson->name) != 1){
    fprintf(stderr, "Invalid name\n");
    free(newPerson);
    return;
}

printf("Enter phone number: ");
if(scanf("%19s", newPerson->phoneNumber) != 1){
    fprintf(stderr, "Invalid number\n");
    free(newPerson);
    return;
}
newPerson->next=NULL;

struct person *previousPtr=NULL;
struct person *currentPtr=*head;

if(currentPtr==NULL){
    *head=newPerson;
}

}