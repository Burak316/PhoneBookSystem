#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NAME_LENGTH 100
#define phoneNumber_LENGTH 20
struct person{
char name[NAME_LENGTH];
char phoneNumber[phoneNumber_LENGTH];
struct person *next;
};

void addPerson(struct person **head);
bool getPersonInput(struct person *head, char *name , char *phoneNumber);
void listNumbers(struct person *head);
void deleteNumber(struct person **head);
void searchNumber(struct person *head);
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

            case 2: listNumbers(head);
            break;

            case 3: deleteNumber(&head);
            break;

            case 4: searchNumber(head);
            break;

            case 5: printf("Exiting...\n");
            break;

            default: printf("Invalid selection. Please try again\n");
        }
    }while(choice!=5);

 return 0;
}
int printMenu(void){
    int choice=0;
        printf("\t\t\t=================================================\n");
        printf("\t\t\t*               PHONE BOOK SYSTEM \t\t*\n");
        printf("\t\t\t*           1-To add a new number \t\t*\n");
        printf("\t\t\t*           2-To list the numbers \t\t*\n");
        printf("\t\t\t*           3-To delete the number\t\t*\n");
        printf("\t\t\t*           4-To search the number\t\t*\n");
        printf("\t\t\t*           5-To exit             \t\t*\n");
        printf("\t\t\t=================================================\n");
        
        if(scanf("%d",&choice)!=1){
            printf("Please enter a valid number\n");
            clearBuffer();
        return 0;
        }
        return choice;
}
bool getPersonInput(struct person *head,char *name , char *phoneNumber){

printf("Enter name: ");
char tempName[NAME_LENGTH];
clearBuffer();
fgets(tempName,sizeof(tempName),stdin);
tempName[strcspn(tempName, "\n")]='\0';
if(tempName[0]=='\0'){
    fprintf(stderr,"Name can not be empty");
    return false;
}

struct person *tempPtr=head;
while(tempPtr!=NULL){
    if(strcmp(tempPtr->name, tempName)==0){
         fprintf(stderr, "Warning: %s already exists. Rejected!\n", tempName);
         return false;
    }
    tempPtr=tempPtr->next;
}
printf("Enter phone number: ");
char tempPhoneNumber[phoneNumber_LENGTH];

fgets(tempPhoneNumber,sizeof(tempPhoneNumber),stdin);
tempPhoneNumber[strcspn(tempPhoneNumber, "\n")]='\0';
if(tempPhoneNumber[0]=='\0'){
    fprintf(stderr,"Phone number can not be empty");
    return false;
}
tempPtr=head;
while(tempPtr!=NULL){
    if(strcmp(tempPtr->phoneNumber, tempPhoneNumber)==0){
         fprintf(stderr, "Warning: %s already exists. Rejected!\n", tempPhoneNumber);
         return false;
    }
    tempPtr=tempPtr->next;
}
strcpy(name, tempName);
strcpy(phoneNumber, tempPhoneNumber);
return true;
}

void addPerson(struct person **head){
struct person *newPerson=malloc(sizeof(struct person));
if(newPerson==NULL) return;
newPerson->next=NULL;
bool isSuccess = getPersonInput(*head,newPerson->name, newPerson->phoneNumber);

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



void listNumbers(struct person *head){
    printf("\t\t\tName\t\t\tPhone Number\n");
    printf("\t\t\t----\t\t\t------------\n");
    struct person *tempPtr=head;
    while(tempPtr!=NULL){
        printf("\t\t\t%s\t\t\t%s\n",tempPtr->name,tempPtr->phoneNumber);
        tempPtr=tempPtr->next;
    }


}