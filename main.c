//Header Files included
#include <stdio.h>
#include<process.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct customer               		//Structure to store details of customer
{
           char fname[20],add[20],lname[20];
           char occ[20],pno[10];
}c[100];
//Global Variables
float total=0;
int nc=0,bill1[10],bill2[10],n=0,q=0;
//Function Declaration
void Menu();
void bill();
void couponcode();
void billingCounter();
void Coupon();
void Feedback();
void exitprogram();
void detail();
int main()                      	//Main Function
{
           while(1)
           {
                      system("cls");                                         //command included to clear screen
                      int ch;
                      printf("************************************************************************************************************************");
                      printf("\n  ********  ********  ********  ********  *******  ********  ********  ********  ********  ********  ********  ********");
                      printf("\n   *****      *****    *****     *****     *****    *****     *****     *****     *****     *****     *****     *****");
                      printf("\n    ***        ***      ***       ***       ***      ***       ***       ***       ***       ***       ***       ***");
                      printf("\n     *          *        *         *         *        *         *         *         *         *         *         *");
                      printf("\n\n************************************************************************************************************************");
                      printf("\n\n*--------------------------------------------------HEARTY TUMMIES :))--------------------------------------------------*");
                      printf("\n\n************************************************************************************************************************");
                      printf("\n\n\tUSE:\n\t1.Menu");
                      printf("\n\t2.Purchasing counter");
                      printf("\n\t3.Coupons");
                      printf("\n\t4.Feedback");
                      printf("\n\t5.Exit");
                      printf("\n\tEnter your choice:");
                      scanf("%d",&ch);
                      switch(ch)
                      {
                                 case 1:Menu();
                                              break;
                                 case 2:detail();
                                              break;
                                 case 3:Coupon();
                                              break;
                                 case 4:Feedback();
                                              break;
                                 case 5:exitprogram();
                                              break;
                                 default:printf("Invalid number entered !!");
                      }
                      getch();
           }
           return 0;
}
void Menu()       // Function to print entire menu
{
           printf("\n\t\t<!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!>");
           printf("\n\t\t-------------------------------MENU-------------------------------");
           printf("\n\t\t<!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!><!>");
           printf("\n\n\t\t|---------------------------------------------------------------|");
           printf("\n\t\t|   S.NO   |     ITEMS     |     PRICE      |      Size         |");
           printf("\n\t\t|---------------------------------------------------------------|");
           printf("\n\t\t|     1.   |     Pizza     |     80/120     |   Small/Regular   |");
           printf("\n\t\t|     2.   |   Manchurian  |     50/80      |    Half/Full      |");
           printf("\n\t\t|     3.   |     Pasta     |     45/70      |    Half/Full      |");
           printf("\n\t\t|     4.   |    Patties    |     20/40      |   Small/Regular   |");
           printf("\n\t\t|     5.   |     Burger    |     25/40      |   Small/Regular   |");
           printf("\n\t\t|     6.   |    Noodles    |     35/50      |     Half/Full     |");
           printf("\n\t\t|     7.   |   Cold coffee |     45/70      |   Small/Regular   |");
           printf("\n\t\t|     8.   |   Oreo shake  |     65/90      |   Small/Regular   |");
           printf("\n\t\t|     9.   |     Pepsi     |     40/90      |   Small/Large     |");
           printf("\n\t\t|     10.  |  French fries |     40/75      |   Small/Regular   |");
           printf("\n\t\t|---------------------------------------------------------------|");
}
void detail()     //Function for details of customer
{
           int flag1=0,flag3=0;
           char str[20];
           printf("\n\t\t****************************************************************");
           printf("\n\t\t!!*!!*!!*!!*!!*!!*!!*!!*!! DETAILS !!*!!*!!*!!*!!*!!*!!*!!*!!*!!");
           printf("\n\t\t****************************************************************");
           printf("\n\n\n\tEnter your details:)\n");
           NAME:printf("\t1.First name:");                    //Store Details through structure
           scanf("%s",c[nc].fname);
           strcpy(str,c[nc].fname);
           for(int i=0;str[i]!='\0';i++)
           {
                      if(str[i]>='0'&&str[i]<='9')      //checking conditions for name
                      {
                                 flag1=1;
                                 break;
                      }
           }
           if(flag1==1)
           {
                      printf("\tPlease enter a valid name!!\n");
                      flag1=0;
                      goto NAME;
           }
           NAME1:printf("\t2.Last name:");
           scanf("%s",c[nc].lname);
           strcpy(str,c[nc].lname);
           for(int i=0;str[i]!='\0';i++)
           {
                      if(str[i]>='0'&&str[i]<='9')      //checking conditions for name
                      {
                                 flag3=1;
                                 break;
                      }
           }
           if(flag3==1)
           {
                      printf("\tPlease enter a valid name!!\n");
                      flag3=0;
                      goto NAME1;
           }
           printf("\t3.Phone number:");
           scanf("%s",c[nc].pno);
           int l=strlen(c[nc].pno);
           while(l!=10)                               //checking conditions for Phone number
           {
                      printf("\tPlease enter a valid phone number:");
                      scanf("%s",c[nc].pno);
                      l=strlen(c[nc].pno);
           }
           printf("\t4.Address:");
           scanf("%s",&c[nc].add);
           printf("\t5.Enter your occupation:");
           scanf("%s",c[nc].occ);
           nc++;
           billingCounter();
}
void billingCounter()   //Function to take order from customer
{
           printf("\n\t\t****************************************************************");
           printf("\n\t\t*-*-*-*-*-*-*-*-WELCOME TO THE BILLING COUNTER-*-*-*-*-*-*-*-*-*");
           printf("\n\t\t****************************************************************\n\n");
           Menu();
           int quantity=0,choice,ch,order=0;
           printf("\n\n\t\tPlace your order here: ");
           scanf("%d",&choice);
           //checking condition as per choice entered by customer
           if(choice==1)
           {
                      printf("\t\tWould you prefer a small sized pizza or a regular sized pizza?\n\t\t[1-]Small\n\t\t[2-]Regular:");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 80.00 * quantity;
                      else if(ch==2)
                                 total += 120.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();     				//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f .\n",total);
                      ORDER1:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No ");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1: billingCounter();                	//calling the function again to order more stuff
                                               break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity,ch);   //calling function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER1;
                      }
           }
           else if(choice==2)
           {
                      printf("\t\tWould you prefer a half plate Manchurian or a full plate Manchurian?\n\t\t[1-]Half\n\t\t[2-]Full");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 50.00 * quantity;
                      else if(ch==2)
                                 total += 80.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();           			//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f .\n",total);
                      ORDER2:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1: billingCounter();      		//calling the function again to order more stuff
                                               break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);       //calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER2;
                      }
           }
           else if(choice==3)
           {
                      printf("\t\tWould you prefer a half plate pasta or a full plate pasta?\n\t\t[1-]Half\n\t\t[2-]Full");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 45.00 * quantity;
                      else if(ch==2)
                                 total += 70.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();              		//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f .\n",total);
                      ORDER3:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1: billingCounter();       		//calling the function again to order more stuff
                                               break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);  	 //calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER3;
                      }
           }
           else if(choice==4)
           {
                      printf("\t\tWould you prefer a small sized patties or a regular sized patties?\n\t\t[1-]Small\n\t\t[2-]Regular");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 20.00 * quantity;
                      else if(ch==2)
                                 total += 40.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();         			//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f \n ",total);
                      ORDER4:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1: billingCounter();      		//calling the function again to order more stuff
                                               break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);      //calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER4;
                      }
           }
           else if(choice==5)
           {
                      printf("\t\tWould you prefer a small sized burger or a regular sized burger?\n\t\t[1-]Small\n\t\t[2-]Regular");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(choice==1||choice==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 25.00 * quantity;
                      else if(ch==2)
                                 total += 40.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();           			    	 //calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f \n ",total);
                      ORDER5:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1:billingCounter();       		   	//calling the function again to order more stuff
                                              break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                               couponcode(&total,quantity);      	 //calling the function to calculate bill
                                               break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER5;
                      }
           }
           else if(choice==6)
           {
                      printf("\t\tWould you prefer a half plate noodles or a full plate noodles?\n\t\t[1-]Half\n\t\t[2-]Full");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 35.00 * quantity;
                      else if(ch==2)
                                 total += 50.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();         			 //calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f .",total);
                      ORDER6:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No ");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1:billingCounter();   			//calling the function again to order more stuff
                                              break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);  	//calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER6;
                      }
           }
           else if(choice==7)
           {
                      printf("\t\tWould you prefer a small sized cold coffee or a regular sized cold coffee?\n\t\t[1-]Small\n\t\t[2-]Regular");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 45.00 * quantity;
                      else if(ch==2)
                                 total += 70.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();         				//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f \n ",total);
                      ORDER7:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1:billingCounter();       			//calling the function again to order more stuff
                                              break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);   		//calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER7;
                      }
           }
           else if(choice==8)
           {
                      printf("\t\tWould you prefer a small sized oreo shake or a regular sized oreo shake?\n\t\t[1-]Small\n\t\t[2-]Regular");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 65.00 * quantity;
                      else if(ch==2)
                                 total += 90.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();          					//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f\n ",total);
                      ORDER8:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1:billingCounter(); 					 //calling the function again to order more stuff
                                              break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);    			//calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                 goto ORDER8;
                      }
           }
           else if(choice==9)
           {
                      printf("\t\tWould you prefer a small sized pepsi or a Large sized pepsi?\n\t\t[1-]Small\n\t\t[2-]Large");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 40.00 * quantity;
                      else if(ch==2)
                                 total += 90.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();                  				//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f\n ",total);
                      ORDER9:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1:billingCounter();           				//calling the function again to order more stuff
                                              break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);   			//calling the function to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER9;
                      }
           }
           else if(choice==10)
           {
                      printf("\t\tWould you prefer a small sized french fries packet or a regular sized french fries packet?\n\t\t[1-]Small\n\t\t[2-]Regular");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d",&ch);
                      printf("\t\tEnter the quantity: ");
                      scanf("%d",&quantity);
                      if(ch==1||ch==2)
                      {
                                 bill1[n++]=choice;
                                 bill2[q++]=quantity;
                      }
                      if(ch==1)
                                 total += 40.00 * quantity;
                      else if(ch==2)
                                 total += 75.00 * quantity;
                      else
                      {
                                 printf("\t\tWrong choice");
                                 billingCounter();                  			//calling the function again to order  stuff correctly
                      }
                      printf("\t\tYour total amount is Rs.%.2f \n ",total);
                      ORDER10:printf("\n\t\tWould you like to buy anything else?\n\t\t[1]Yes\n\t\t[2]No");
                      printf("\n\t\tEnter your choice:");
                      scanf("%d", &order);
                      switch(order)
                      {
                                 case 1:billingCounter();     				 //calling the function again to order more stuff
                                              break;
                                 case 2:printf("\t\tThank you for the order! :) Please proceed with the payment of bill!");
                                              couponcode(&total,quantity);     	 	//calling the function again to calculate bill
                                              break;
                                 default:printf("\t\tINVALID CHOICE!!");
                                               goto ORDER10;
                      }
           }
           else
           {
                      printf("\n\n\tPlease make your order from the food items mentioned in the list!\n\n\n");
                      billingCounter();     //calling the function again to order  stuff correctly
           }
}
void bill(int totalbill)           //Function to print Bill
{
           printf("\n\n\n\t\t!!---------------!!--------------!!--------------!!");
           printf("\n\t\t\t\t\tBILL");
           printf("\n\t\t!!---------------!!--------------!!--------------!!");
           printf("\n\n\t\t\tItems\t\tQuantity");
           printf("\n\t\t\t******\t\t**********");
           for(int j=0,i=0;i<n;i++,j++)
           {
                      printf("\n\t\t\t");
                      if(bill1[i]==1)
                                 printf("%d.Pizza      ",i+1);
                      else if(bill1[i]==2)
                                 printf("%d.Manchurian ",i+1);
                      else if(bill1[i]==3)
                                 printf("%d.Pasta      ",i+1);
                      else if(bill1[i]==4)
                                 printf("%d.Patties    ",i+1);
                      else if(bill1[i]==5)
                                 printf("%d.Burger     ",i+1);
                      else if(bill1[i]==6)
                                 printf("%d.Noodles    ",i+1);
                      else if(bill1[i]==7)
                                 printf("%d.Cold coffee",i+1);
                      else if(bill1[i]==8)
                                 printf("%d.Oreo shake ",i+1);
                      else if(bill1[i]==9)
                                 printf("%d.Pepsi      ",i+1);
                      else if(bill1[i]==10)
                                 printf("%d.French fries",i+1);
                      printf("\t\t");
                      printf("%d",bill2[j]);
           }
           printf("\n\n\t\t\tTotal bill:%d",totalbill);
           printf("\n\n\t\t=> Thank you we received a payment of Rs.%d from your side",totalbill);
}
void Coupon()          //Function to print Coupon available
{
           printf("\n\n\n\t\t**************************************************");
           printf("\n\t\t*-*-*-*-*-*-*-*-AVAILABLE COUPON-*-*-*-*-*-*-*-*-*");
           printf("\n\t\t**************************************************\n\n");
           printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
           printf("\t\t|\t\t\tLUNCH100 \t\t  |\n\t\t|Terms & Conditions\t\t\t\t  |");
           printf("\n\t\t|*FLAT RS.100 OFF ON LUNCH ORDER\t\t  |");
           printf("\n\t\t|*Minimum food order amount of Rs.400 is required |\n\t\t|Valid till Dec 31 2020\t\t\t\t  |" );
           printf("\n\t\t|_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ | \n");
           printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
           printf("\t\t|\t\t\tPAYTM300 \t\t  |\n\t\t|Terms & Conditions\t\t\t\t  |");
           printf("\n\t\t|*GET  UPTO RS.399 CASHBACK VIA PAYTM UPI\t  |");
           printf("\n\t\t|*Minimum transaction amount required: Rs.300\t  |");
           printf("\n\t\t|*Applicable on all orders:\t\t\t  |\n\t\t|Valid till Dec 31 2020\t\t\t\t  |" );
           printf("\n\t\t|_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ | \n");
           printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
           printf("\t\t|\t\t  CHRISTMAS2020 \t\t  |\n\t\t|Terms & Conditions\t\t\t\t  |");
           printf("\n\t\t|*GET  UPTO 25 percent discount  \t\t  |");
           printf("\n\t\t|*Minimum transaction amount required: Rs.450\t  |");
           printf("\n\t\t|*Applicable on all orders:\t\t\t  |\n\t\t|Valid till Dec 25 2020\t\t\t\t  |" );
           printf("\n\t\t|_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ | \n");
           printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
           printf("\t\t|\t\t  PIZZAPARTY \t\t\t  |\n\t\t|Terms & Conditions\t\t\t\t  |");
           printf("\n\t\t|*BUY 2 PIZZAS JUST AT RS.80 \t\t\t  |");
           printf("\n\t\t|*Order only 2 regular  pan pizzas\t\t  |");
           printf("\n\t\t|*Original price of each pizza: Rs.120\t\t  |");
           printf("\n\t\t|Price under offer: Rs.80 each:\t\t\t  |\n\t\t|Valid till Dec 15 2020\t\t\t\t  |" );
           printf("\n\t\t|_ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ | \n\n");
}
void couponcode(float * x,int quan1,int order)                //Function to calculate Bill as per coupon and conditions
{
           int i=0,mode,ch,account[16],pin[4];
           float amount,bal;
           char coupon1[10],flag2[2];
           Coupon();                           //calling function to print coupon
           printf("\n\t\tWould you like to apply a coupon?(Yes/No ):");
           scanf("%s",flag2);
           if(flag2[0]=='y'||flag2[0]=='Y')
           {                                                              //Checking which coupons are available for you according to order
                      if(*x>400)
                                 printf("\n\n\t\tCOUPON: LUNCH100 APPLICABLE");
                      if(*x>300)
                                 printf("\n\t\tCOUPON: PAYTM300 APPLICABLE");
                      if(*x>450)
                                 printf("\n\t\tCOUPON: CHRISTMAS2020 APPLICABLE");
                      if(order==2&&quan1==2&&n==1)
                                 printf("\n\t\tCOUPON: PIZZAPARTY APPLICABLE");
                      if((*x<400||*x<300||x<450)&&!(order==2&&quan1==2))
                      {
                                 printf("\n\t\tNo Coupon Code applicable on your order ");
                                 goto billing;
                      }
                      printf("\n\t\tEnter your coupon code here:");
                      scanf("%s",coupon1);                        //Checking whether coupon entered is correct or not
                      if((stricmp(coupon1,"LUNCH100")==0))
                      {
                                 printf("\n\t\tHurray !!! You got Rs 100 of on your order");
                                 *x=*x-100;                         //As per coupon moderating price
                      }
                      else if((stricmp(coupon1,"CHRISTMAS2020")==0))
                      {
                                 printf("\n\t\tHurray !!! You got 25 percent discount of on your order");
                                 *x=*x*0.75;                        //As per coupon moderating price
                      }
                      else if((stricmp(coupon1,"PAYTM300")==0))
                                 printf("\n\n\t\tHurray !!! You would get a cash back of Rs 150 of on your order");
                      else if((stricmp(coupon1,"PIZZAPARTY")==0))
                      {
                                 printf("\n\tHurray !!! You are getting your pizza of Rs 80 each");
                                 *x=160;                            //As per coupon moderating price
                      }
                      else
                                 printf("\tSorry!NO such coupon exists");
           }
           do                 // Do while loop until customer enters correct value for mode
           {
                      billing:printf("\n\t\tBy Which mode are you going to pay\n");
                      printf("\t \t\t1)Cash\n\t\t\t2)Paytm\n\t\t\t3)Credit OR Debit card!\n \t\tEnter Your Choice:");
                      scanf("%d",&mode);                    //Checking conditions as per mode of payment
                      if((stricmp(coupon1,"PAYTM300")==0)&&mode==2)
                      {
                                 printf("\n\t=> Thank you we received a payment of Rs.%f from your side through PAYTM",*x);
                                 printf("\n\t=>You would get a cash back of Rs 150 of on your order ");
                      }
                      else if(mode ==1)
                      {
                                 if(stricmp(coupon1,"PAYTM300")==0)
                                 {
                                            printf("\n\t\tYou chose the WRONG method to pay :You are required to pay via Paytm\n");
                                            mode=0;
                                 }
                                else
                                {
                                         printf("\n\t\tTotal Amount to be paid  %f \t",*x );
                                         printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\t\t");
                                         printf("\n\t\t|Total Amount %f \t\t|",*x );
                                         printf("\n\t\t|Enter Amount tendered ");
                                         scanf("%f",&amount);
                                         bal=amount-*x;
                                         printf("\t\t|Balance Amount %f \t\t|",bal);
                                         printf("\n\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|");
                                }
                      }
                      else if(mode==3)
                      {
                                 if(stricmp(coupon1,"PAYTM300")==0)
                                 {
                                            printf("\n\t\t You chose the WRONG method to pay :You are required to pay via Paytm\n");
                                            mode=0;
                                 }
                                 else
                                 {
                                            printf("\n\t\tTotal Amount to be paid  %f \t",*x );
                                            printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
                                            printf("\n\t\t| \t\tAccount number  \t|\n\t\t|    ");
                                            for(i = 0;i < 20;i++)
                                            {
                                                       ch = getch();
                                                       if(i == 15)
                                                                  break;
                                                       account[i] = ch;
                                                       printf("%c ", ch);
                                            }
                                            printf("\t|");
                                            i=0;
                                            printf("\n\t\t|\t\t   Pin \t\t\t|\n\t\t|\t\t   ");
                                            while( i<4)
                                            {
                                                       pin[i]=getch();
                                                       printf("*");
                                                       i++;
                                            }
                                            printf("\t\t\t|");
                                            printf("\n\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|");
                                 }
                      }
                      else if(mode==2)
                      {
                                printf("\n\t\tTotal Amount to be paid  %f \t",*x );
                                printf("\n\t\t Please wait while we confirm your payment");
                      }
                      else
                                 printf("\t\tWrong Choice entered\n");
           }while(mode!=1&&mode!=2&&mode!=3);
           bill(*x);
           printf("\n\n\t\t!!Please wait for 10-15 minutes,while your order is being prepared");     		//Calling function to print bill
           printf("\n\n\t\t\tWould you like to give us some feedback(Y/N): ");
           scanf("%s",&flag2);
           if(flag2[0]=='y'||flag2[0]=='Y')
           {
                    Feedback();    	//calling function for feedback
                    exitprogram();
           }
           else
                    exitprogram();
}
void Feedback()          		//Function to take feed back from customer
{
           int i=0,n;
           char text[20];
           printf("\n\t\t*-*-*-*-*-*-*-*-FEEDBACK-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
           printf("\n\t\tWould you like to rate us(No. of stars)\n\t\t");
           printf("\n\t\t*     --> Very Bad :(");
           printf("\n\t\t**    --> Okay but needs improvement :(");
           printf("\n\t\t***   --> Good ");
           printf("\n\t\t****  --> Very Good :)");
           printf("\n\t\t***** --> AWESOME...Loved it ;)");
           STARS:printf("\n\t\tEnter the no. of stars you would like to give us:");
           scanf("%d",&n);
           printf("\t\t");
           for(int i=0;i<n;i++)
           {
                      if(n>5)
		{
                                 printf("\n\t\tPlease rate us on the basis of five star rating system:)\n");
                                 goto STARS;
                      }
                      printf("*");
           }
           printf("\n\t\tWe would greatly appreciate it if you kindly give us some feedback\n\t\t");
           scanf("%s",text);
}
void exitprogram()     //Function to exit program
{
           printf("\n\n\t\tTHANK YOU FOR COMING AND PLEASE VISIT US NEXT TIME:)\n\t\tDeveloped By-\n\t\t\tDevika Gupta:) \n\t\t\tDrishika Chauhan:) \n\t\t\tAnanya Gupta:)\n\n");
           exit(0);
}
