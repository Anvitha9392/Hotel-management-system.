#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct customerdetails //STRUCTURE DECLARATION
{
int roomnumber;
char name [20] ;
char address[25];
int period;
}so;
void book() //FUNCTIONS
{
so *s;
FILE *fp;
char ch;
int n;
//printf(" Enter how many rooms the customer want\n");
//scanf("%d",&n);
s=(so *)calloc(n,sizeof(so));
/*if (fp=fopen("add.txt","a+"))
{
printf("hi");
}*/
/*/if(fp==0)
{ */ fp=fopen("add.txt","w+");
/*printf("Please hold on while we set our data in your computer");
printf("\n Process completed press any key to continue!! ");
}*/
int i;
char c;
int type_of_rooms;
if(1)
{
fp=fopen("add.txt","w+");
printf("What type of room do you want to book?\n ");
printf(" 1.Basic room Rs1000\n 2.Medium roon Rs2000\n 3.Delux room Rs 3000\n 4. I do not want to choose any thing\n");
scanf("%d",&type_of_rooms);
fflush(stdin);
if(type_of_rooms==1)
{
printf("\n you choose basic room .Enjoy your stay");
printf("your room no is 1");
printf("Room type =BASIC");
printf("billprice=1000");
}
}
if(type_of_rooms==2)
{
printf("\n you choose medium room .Enjoy your stay");
printf("your room no is 2");
printf("room type=medium");
printf("billprice=2000");
}
if(type_of_rooms==3)
{
printf("\n you choose delux room .Enjoy your stay");
printf("your room no is 3");
printf("room type=delux");
printf("billprice=3000");
}
if(type_of_rooms==4)
{
printf("you have entered wrong choice");
}
s=(so *)calloc(1,sizeof(so));
for(i=0;i<1;i++)
{
printf("\n Enter Customer Details:");
printf("\n");
printf("\n Enter the room number: ");
scanf("%d",&s[i].roomnumber);
fflush(stdin);
printf("Enter Name:\n");
scanf("%s",s[i].name);
fflush(stdin);
printf("Enter Address:\n");
scanf("%s",s[i].address);
fflush(stdin);
printf("Enter Period(\'x\'days):\n");
scanf("%d",&s[i].period);
printf("\n\n1 Room is successfully booked!!");
fwrite(&s,sizeof(so),1,fp);
break;
}
fclose(fp);
}
void delete1()
{
FILE *fp,*tp;
int i=0;
so s;
int roomnumber;
if((tp=fopen("temp.txt","w"))==NULL)
exit(0);
if((fp=fopen("add.txt","r"))==NULL)
exit(0);
printf("Enter the Room Number of the hotel to be delete from the data \n");
scanf("%d",&roomnumber);
while(fread(&s,sizeof(so),1,fp))
{
if(roomnumber==s.roomnumber)
{
i=1;
}
else
fwrite(&s,sizeof(so),1,tp);
}
if(i==1)
{
printf("\n\n roomnumber %d is now available",roomnumber);
fclose(fp);
}
remove("add.txt");
rename("temp.txt","add.txt");
printf("\n\nThe Customer is successfully removed....");
fclose(fp);
fclose(tp);
}
void edit()
{
FILE *fp,*tp;
int i=0;
so s;
int roomnumber;
if((tp=fopen("temp.txt","w"))==NULL)
exit(0);
if((fp=fopen("add.txt","r"))==NULL)
exit(0);
printf("Enter the Room Number of the hotel to edit the customer details \n");
scanf("%d",&roomnumber);
while(fread(&s,sizeof(so),1,fp))
{
if(roomnumber==s.roomnumber)
{
printf("\n Edit Customer Details:");
printf("\n**");
printf("\n Enter Room number:\n");
scanf("%d",&s.roomnumber);
printf("Enter Address:\n");
scanf("%s",s.address);
printf("Enter Period('x'days):\n");
scanf("%d",&s.period);
fflush(stdin);
fwrite(&s,sizeof(so),1,tp);
}
else
fwrite(&s,sizeof(so),1,tp);
}
if(i==1)
{
printf("\n\n Records of Customer in this Room number is not found!!");
fclose(fp);
fclose(tp);
}
remove("add.txt");
rename("add.txt","temp.txt");
printf("\n\nThe details of Customer is successfully edited ....");
fclose(fp);
fclose(tp);
}
void login()
{
int a=0,i=0,choice;
char username[11];
char password[13]="group16srmap",c[13];
char user[11]="cseproject";
printf("\t\t\t\t\t ***WELCOME TO HOTEL***\n");
printf("\t\t\t\t\t\t*LOGIN FORM*\n");
do
{
printf("\n\tENTER USERNAME:-");
scanf(" %[^\n]s",username);
printf("\n\tENTER PASSWORD:-");
scanf(" %[^\n]s",c);
if(strcmp(user,username)==0 && strcmp(password,c)==0)
{
printf("\n\n\n\t\t\t\tWELCOME ! ! ! LOGIN IS SUCCESSFUL");
}
else
{
printf("\t\t\tSORRY ! ! ! LOGIN IS UNSUCCESSFUL\t\n");
printf("\t\t\tSORRY!PLEASE TRY AGAIN\n");
a++;
}
if(a==2)
exit(0);
}
while(a==2);
}
void display()
{
FILE *fp;
int i=0;
so s;
if((fp=fopen("add.txt","r"))==NULL)
exit(0);
printf("Display the customer details \n");
while(fread(&s,sizeof(so),1,fp))
{
printf("%d\t\t%s %s\t\t%s %d\t\t%s",s.roomnumber,s.name,s.address,s.period );
}
fclose(fp);
}
int main() //MAIN FUNCTION
{
int i=0,choice;
time_t t;
char customername;
login();
while(1) //INFINITE LOOP
{
printf("-");
printf("\n");
printf("\t\t\t\t\t** MAIN MENU **\n");
printf("\t\t\tPlease enter your choice for menu:\n\n");
printf("\n Enter 1 -> Book a room ");
printf("\n------------------------");
printf("\n Enter 2 -> Delete customer record");
printf("\n----------------------------------");
printf("\n Enter 3 -> Edit customer record");
printf("\n--------------------------------");
printf("\n Enter 4 -> display room");
printf("\n-----------------");
printf("\n Enter 5 -> Exit");
printf("\n-----------------");
printf("\n");
printf("Enter the choice: ");
scanf("%d",&choice);
switch(choice) //SWITCH STATEMENT
{
case 1:
book();break;
case 2:
delete1();break;
case 3:
edit();break;
case 4:
display();break;
case 5:
exit(0);
default:
printf("Incorrect input");
printf("\n press any key to countinue") ;
}
}
}