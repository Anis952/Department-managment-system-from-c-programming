#include<stdio.h>
#include <conio.h>

#define TV_PRICE 110.00
#define RICE_PRICE 80.00
#define chocolate_PRICE 100.00
#define oil_PRICE 75.00
#define REMOTE_PRICE 9.20
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RESET   "\033[0m" 

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

struct department //
{
 int itemno;
 char name[30];
 float price;
}stud;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void create()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the item no   :");
 scanf("%d", &stud.itemno);
 printf("Enter the Name      :");
 scanf("%s", &stud.name);
 printf("Enter the price      :");
 scanf("%f", &stud.price);
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}
//    Fnction to display record
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nitem Number\tName\tprice\n\n");
 while (fread(&stud, sizeof(stud), 1, fp1))
 printf("  %d\t\t%s\t%.2f\n", stud.itemno, stud.name, stud.price);
 fclose(fp1);
}
//    Fnction to search given record
void search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Item no you want to search  :");
 scanf("%d", &r);
 avl = avlitemno(r);
 if (avl == 0)
  printf("Item No %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&stud, sizeof(stud), 1, fp2))
  {
   s = stud.itemno;
   if (s == r)
   {
    printf("\nitem no = %d", stud.itemno);
    printf("\nName    = %s", stud.name);
    printf("\nMark    = %.2f\n", stud.price);
   }
  }
  fclose(fp2);
 }
}
//    Function to delete the record


void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Item no you want to delete ");
 scanf("%d", &r);
 if (avlitemno(r) == 0)
  printf("item no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("tempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.itemno;
   if (s != r) 
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter Item number to update:");
 scanf("%d", &r);
 avl = avlitemno(r);
 if (avl == 0)
 {
  printf("Item number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.itemno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of Item Number %d", r);
    printf("\n\t2. Update price of Item Number %d", r);
    printf("\n\t3. Update both Name and price of item Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s", &stud.name);
     break;
    case 2:
     printf("Enter price : ");
     scanf("%f", &stud.price);
     break;
    case 3:
     printf("Enter Name: ");
     scanf("%s", &stud.name);
     printf("Enter price: ");
     scanf("%f", &stud.price);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&stud, sizeof(stud), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
  {
   fwrite(&stud, sizeof(stud), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}

//    Function to check item is available or not //
int avlitemno(int ino)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&stud, sizeof(stud), 1, fp);

  if (ino == stud.itemno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//Function to check file is empty or not
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&stud, sizeof(stud), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}

//
 void price()
{

	const double LCD_PRICE = 500.00;
	const double TAPE_PRICE = 48.00;
	const double taxRate = 8.25; 

	int tvQTY;
	int riceQTY;
	int oilQTY;
	int chocolateQTY;
	int remoteQTY;
	int lcdQTY;
	int tapeQTY;


	float total_tv;
	float total_rice;
	float total_remote;
	float total_lcd;
	float total_tape;
	float total_oil;
	float total_chocolate;
	float subTotal;
	float tax;
	float bill_Amount;
	char name[250];
	char cname[250];




	printf("Customer's Name: \n");
	scanf("%s",cname);
	
	printf("\n\t***Enter 0 for none****");

	printf("\nHow many TVs were sold? \n");
	scanf("%d", &tvQTY);

	printf("How many RICEs were sold? \n");
	scanf("%d", &riceQTY);

	printf("How many Remote Controllers were sold? \n");
	scanf("%d", &remoteQTY);

	printf("How many LCDs were sold? \n");
	scanf("%d", &lcdQTY);

	printf("How many Tape Recorders were sold? \n");
	scanf("%d", &tapeQTY);
	printf("How many oil were sold? \n");
	      scanf("%d", &oilQTY);
	    printf("How many chocolate were sold? \n");
	      scanf("%d", &chocolateQTY);
	
	printf("\n Press Any Key To Generate Bill");
	getch();

printf("\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t");
int a;
   	for( a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		printf("...");
	}
      printf("\n\n\t\t\t\t\tBill Generated. \n\n");
      
      system("PAUSE");
      system("CLS");

//	Calculation Statements

	total_tv = tvQTY * TV_PRICE;
	total_rice = riceQTY * RICE_PRICE;
	total_oil = oilQTY * oil_PRICE;
	total_chocolate = chocolateQTY * chocolate_PRICE;
	total_remote = remoteQTY * REMOTE_PRICE;
	total_lcd = lcdQTY * LCD_PRICE;
	total_tape = tapeQTY * TAPE_PRICE;
	subTotal = total_tv + total_rice + total_remote + total_lcd + total_tape;
	tax = (subTotal * taxRate)/100;
	bill_Amount = subTotal + tax;



//	Printing Bills
    printf("\n");
    printf("\t\t\t====================================================\n");
	printf("\t\t\t\t      Department Store Bill\n");
	printf("\t\t\t====================================================\n");
	printf("\t\t\tQTY \t Description \t Unit Price(rs)\t Total Price(rs)\n");
	printf("\t\t\t--- \t ----------- \t ---------- \t -----------\n\n");
	printf("\t\t\t%02d \t TV                  %.2f       %10.2f \n", tvQTY, TV_PRICE, total_tv);
	printf("\t\t\t%02d  \t RICE                 %.2f       %10.2f  \n", riceQTY, RICE_PRICE, total_rice);
	printf("\t\t\t%02d  \t oil                 %.2f       %10.2f  \n", oilQTY, oil_PRICE, total_oil);
	printf("\t\t\t%02d  \t chocolate                 %.2f       %10.2f  \n", chocolateQTY, chocolate_PRICE, total_chocolate);
	printf("\t\t\t%02d   \t Remote CTRLR          %.2f       %10.2f   \n", remoteQTY, REMOTE_PRICE, total_remote);
	printf("\t\t\t%02d    \t LCD                 %.2f       %10.2f    \n", lcdQTY, LCD_PRICE, total_lcd);
	printf("\t\t\t%02d     \t Tape Recorder        %.2f       %10.2f     \n\n", tapeQTY, TAPE_PRICE, total_tape);
	printf("\t\t\t                                           ---------\n\n");
	printf("\t\t\t                           SUBTOTAL       %10.2f   \n", subTotal);
	printf("\t\t\t                           TAX            %10.2f    \n", tax);
	printf("\t\t\t                           Total$         %10.2f     \n", bill_Amount);
	printf("\t\t\t                           Customer         %s     \n", cname);
	printf("\t\t\t                           Cashier          %s     \n", name);
	printf("\t\t\t====================================================\n\n");
	printf("\t\t\t\t\t\tEnd of bill\n\n");

	system("PAUSE");
	system("CLS");
	
} 




void admin(){
		char name[250];
	char cname[250];
		printf("\t\tWelcome To Department Store Billing System\n");
	printf("\n Please Enter the following details. \n\n");
	char password[12];
	int count= 0;
	
	printf("Cashier's Name: \n");
	scanf("%s",&name);
	mylabel2:
    	system("CLS");
    	printf("Enter your password:\n");
    	        	while(1)
{
	char ch=getch();
	if(ch==ENTER)
	{
		password[count]='\0';
		break;
	}
	else if(ch==BKSP)
	{
		if(count>0)
		{
			count--;
			printf("\b \b");
		}
	}
	else if(ch==TAB||ch==SPACE)
	{
		continue;
	}
	else
	{
		password[count]=ch;
		putch('*');
		count++;
	}
}
if(strcmp(password,"1234")==0){
printf("\nWelcome Login Success as %s!\n",name);
        	
        }else{
        	count++;
    		printf(BOLDRED"\nwrong password\n"RESET);
    		sleep(1);
    		if(count>2){
    			system("CLS");
    			return;
			}
		goto mylabel2;
			}
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. Create\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   create();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   emp = empty();
   if (emp == 0)
    printf("\n The file is EMPTY\n");
  case 7:
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}


void customer(){
	price();
	
}


//main program

void main(){
	int n,c;
	while(1){
				
	printf("\n\n\n\n\n \t\t\t|============ WELCOME TO Department STORE ============|");
	printf("\n\n\n\n\n\t\t\t\t   CHOOSE YOUR OPTION");
	printf("\n\t\t\t=============================================================");
	printf("\n\n\t\t\t\t\t   1. Admin \n\n\t\t  \t\t\t   2. Customer");
	printf("\n\n\t\t\t============================================================\n");
	scanf("%d",&c);
      switch (c){
  	
  	
  	
		case 1:
			admin();
			break;
		case 2:
		    customer();
		    break;
		case 3:
		    return;
			break;

}
}
}
