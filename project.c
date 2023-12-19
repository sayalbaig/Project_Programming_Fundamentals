#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<dos.h>
#include<time.h>
int count=0;
void admin();
void cust();
void add();
void del();
void delay(int);
void displayMenuItems();
void convertFileToStructObj();
struct menu
{
	char nm[30];
	int price;
};

struct bill
{
	char nam[30];
	int quan;
	int pric;
};
struct menu a[30]; struct bill b[30];
int main()
{
	int i;
	for(i=1;i<=30;i++)
	{
		strcpy(a[i].nm,"");
		a[i].price=0;
	}
	convertFileToStructObj();
	char ab;
	do
	{
		system("@cls||clear");
		printf(
		   "\n\t\t\t\t\t\t||||||||||||||||||||"
	       "\n\t\t\t\t\t\t|                  |"
		   "\n\t\t\t\t\t\t|    1)Admin       |"
		   "\n\t\t\t\t\t\t|    2)Customer    |"
		   "\n\t\t\t\t\t\t|    0)Exit        |"
		   "\n\t\t\t\t\t\t|                  |"
		   "\n\t\t\t\t\t\t||||||||||||||||||||"
		   "\n\t\t\t\t\t\tSelect From The Menu Please ");
		   ab=getche();
		   if(ab=='1')
	       {
		      system("@cls||clear");
		      admin();
	       }
	       else if(ab=='2')
	       {
	       	  system("@cls||clear");
		      cust();
		   }
	}while(ab!='0');
	
}
void admin()
{
	    char adm[5];
	    printf("Enter Password: ");
	    if(adm[0]=getch())
	    {
	    	printf("#");
		}
		if(adm[1]=getch())
	    {
	    	printf("#");
		}
		if(adm[2]=getch())
	    {
	    	printf("#");
		}
		if(adm[3]=getch())
	    {
	    	printf("#");
		}
		adm[4]='\0';
		if(strcmp(adm,"7890"))
		{
			system("COLOR 74");
			printf("\nAccess Denied ");
			printf("\nReturning in \n3... ");
			delay(1);
			printf("\n2... ");
			delay(1);
			printf("\n1... ");
			delay(1);
			printf("\n0... ");
			system("COLOR 07");
			return;
		}
	char ab;
	do
	{
		system("@cls||clear");
		printf(
		   "\n\t\t\t\t\t\t|||||||||||||||||||||||||"
	       "\n\t\t\t\t\t\t|                       |"
	       "\n\t\t\t\t\t\t|  1) ADD DISH          |"
		   "\n\t\t Admin Panel    \t\t|  2) Delete            |"
		   "\n\t\t\t\t\t\t|  0) EXIT TO MAIN MENU |"
		   "\n\t\t\t\t\t\t|                       |"
		   "\n\t\t\t\t\t\t|||||||||||||||||||||||||"
		   "\n\t\t\t\t\t\tSelect The Key please ");
		ab=getche();
		   if(ab=='1')
		   {
				system("@cls||clear");
				add();
		   }
		   if(ab=='2')
		   {
		   	   	system("@cls||clear");
		   	   	del();
		   }
	}while(ab!='0');
}
void convertFileToStructObj()
{
	int count = 0;
	FILE* menu = fopen("menu.txt","r+");
    char s[30] ;
    while(fgets(s,30,menu))
    {   
        int itemNo, price;
        char tem[30];
        sscanf(s,"%d) %s %d",&itemNo,tem,&price);
        strcpy(a[itemNo].nm,tem);
        a[itemNo].price = price;
		count++;
    }
    fclose(menu);
	for (int i = count+1; i <= 30; i++)
	{
		strcpy(a[i].nm,"");
		a[i].price = 0;
	}
	
}
void cust()
{
	int i,j,g,q; char c;
    count=0;
	j=1;
	convertFileToStructObj();
	do
	{
		p:
		system("@cls||clear");
		printf("Select A dish\n");
	    displayMenuItems();
    	scanf("%d",&g);
    	if(a[g].price!=0 && a[g].nm!=""){
    		printf("Enter Quantity ");
    		scanf("%d",&q);
		}
		else {
			system("@cls||clear");
			system("COLOR 74");
			printf("INVALID DISH\n");
			delay(1);
			system("COLOR 07");
			goto p;
		}
		strcpy(b[j].nam,a[g].nm);
		b[j].quan = q;
		b[j].pric = a[g].price *q;
		j++;
        printf("\nDo you want to select another dish? y/n: ");
        c = getch();
	} while(c!='n');
	int total=0,cash;
	char custname[15];
	for(i=1;i<j;i++)
	{
		total+=b[i].pric;
	}
	if(total==0)
	{
		system("@cls||clear");
		return;
	}
	printf("\n\nEnter Your First Name: ");
	scanf("%s",custname);
	system("@cls||clear");
	time_t t;   // not a primitive datatype
    time(&t);
	printf("\tYour Order is.....\n\n#) Name\t\tQuantity\tPrice\n--------------------------------------\n");
	for(i=1;i<j;i++)
	{
		printf("%d) %s\t%d\t\t%d\n",i,b[i].nam, b[i].quan ,b[i].pric);
	}
	printf("--------------------------------------\nTotal:\t\t\t\t%d\n--------------------------------------\n",total);
	printf("\nDate-Time:    %s\n", ctime(&t));
	printf("Cashier-Name:        Ibrahim, Sayal, Saad \n");
	printf("\nCustomer-Name:       \t\t %s ",custname);
	printf("\n\nEnter Your Cash Amount: \t  ");
	sc:
	scanf("%d",&cash);
	if(cash<total)
	{
		system("COLOR 74");
		printf("\nCash cannot be less than total Amount, Input Again :");
		delay(1);
		system("COLOR 07");
		goto sc;
	}
	system("COLOR 0A");
	printf("\n--------------------------------------\nChange-Given:       \t\t %d\n--------------------------------------",cash-total);
	printf("\n\tHAVE A GREAT DAY!!\n\n\n--------------------------------------\nBy IbrahimSayalSaad Labs");
	FILE *bill = fopen("bill.html","w+");
	fprintf(bill,"<!DOCTYPE html><html lang='en'><head><link rel='stylesheet' href='style.css' ><!--  This file has been downloaded from bootdey.com @bootdey on twitter --><!--  All snippets are MIT license http://bootdey.com/license --><title>invoice order receipt</title><script src='https://code.jquery.com/jquery-1.10.2.min.js'></script><link href='https://netdna.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css' rel='stylesheet'><script src='https://netdna.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js'></script></head><body><div class='container'><div class='row'><!-- BEGIN INVOICE --><div class='col-xs-12'><div class='grid invoice'><div class='grid-body'><div class='invoice-title'><div class='row'><div class='col-xs-12'><p></p></div></div><br><div class='row'><div class='col-xs-12'><h2>invoice<br><span class='small'>order #1082</span></h2></div></div></div><hr><div class='row'><div class='col-xs-6'><address><strong>Billed To:</strong><br>%s<br></address></div><div class='col-xs-6 text-right'><address><strong>Order Date:</strong><br>%s</address></div></div><div class='row'><div class='col-md-12'><h3>ORDER SUMMARY</h3><table class='table table-striped'><thead><tr class='line'><td><strong>#</strong></td><td class='text-left'><strong>Dish Name</strong></td><td class='text-center'><strong>QTY</strong></td><td class='text-right'><strong>RATE</strong></td><td class='text-right'><strong>SUBTOTAL</strong></td></tr></thead><tbody>",custname,ctime(&t));
	for(i=1;i<j;i++)
	{
		fprintf(bill,"<tr><td>%d</td><td><strong>%s</strong><br></td><td class='text-center'>%d</td><td class='text-right'>%d</td><td class='text-right'>%d</td></tr>",i,b[i].nam, b[i].quan ,b[i].pric/b[i].quan ,b[i].pric);
	}
	fprintf(bill,"<tr><td colspan='3'></td><td class='text-right'><strong>Total</strong></td><td class='text-right'><strong>%d</strong></td></tr>",total);
	fprintf(bill,"</tbody></table></div></div><div class='row'><div class='col-md-12 text-right identity'><p>Designer identity<br><strong>Ibrahim Sayal Saad</strong></p></div></div></div></div></div><!-- END INVOICE --></div></div></body></html>");
	fclose(bill);
	getch();
	system("COLOR 07");
		return;
}
void add()
{

	int i,td=0,ar[30];
	for(i=1;i<=30;i++)
	{
		ar[i]=0;
	}
	count=0;
	for(i=1;i<=30;i++)
	{
		if(a[i].price!=0 && a[i].nm!="")
		{
		    ar[i]=1;
	    	count++;
    	}
	}
	for(i=1;i<=30;i++)
	{
		if(ar[i]==0)
		{
			td=i;
			break;
		}
	}
	if(count<30)
	{
		char wholeItem[50];
		printf("Enter Dish Name: ");
		scanf("%s",a[td].nm);
		printf("Enter Dish Price: ");
		scanf("%d",&a[td].price);
		printf("\nDish Successfully Added!!\n");
		sprintf(wholeItem,"\n%d) %s %d",td,a[td].nm,a[td].price);
		FILE* menu = fopen("menu.txt","a+");
		fputs(wholeItem,menu);
    	fclose(menu);
	}
	else 
	{
		printf("Menu is full, Cannot Add Dish");
	}
	getch();
	system("COLOR 07");
}
void del()
{
	int i,d,co;
	count=0;
	displayMenuItems();
	printf("Enter the dish # you want to Delete: ");
	dl:
	scanf("%d",&d);
	if(a[d].price==0 || a[d].nm=="")
	{
		printf("Invalid Number; Input Again: ");
		goto dl;
	}
	char item[30];
	sprintf(item,"%d) %s %d\n",d,a[d].nm,a[d].price);
	printf("%s",item);
	strcpy(a[d].nm,"");
	a[d].price = 0;


	FILE *tempfile = fopen("temp.txt","a+");
	FILE* menu = fopen("menu.txt","a+");
	char s[30];
	while(fgets(s,30,menu))
    {
	
        if(strcmp(s,item))
            fprintf(tempfile, "%s",s);   
    }
    fclose(tempfile);
	fclose(menu);

	remove("menu.txt");
	rename("temp.txt","menu.txt");

	system("COLOR 0A");
	printf("Item Successfully Deleted!\n");  getch();
	system("COLOR 07");
}
void delay(int number_of_seconds)
{
    
    int milli_seconds = 1000 * number_of_seconds;
  
 
    clock_t start_time = clock();
  
   
    while (clock() < start_time + milli_seconds)
        ;
}
void displayMenuItems()
{
	int i,co;
	for(i=1;i<=30;i++)
	{
		if(a[i].price!=0 && a[i].nm!="")
		count++;
	}
	for(i=1,co=0;i<=30 && co!=count;i++)
	{
		if(a[i].price!=0 && a[i].nm!="")
		{
			printf("%d) %s \t%d\n",i,a[i].nm,a[i].price);
			co++;
		}
	}
}