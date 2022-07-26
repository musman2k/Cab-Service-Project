#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
//declaring global variables
char captain_name[20], captain_num[20], car[20], name_customer[20], num_customer[20], id_car[10];
int option=0;
//declaring functions
int go(int km, int wt);
void customer();
void confirm_diag();
int total();
void line()
{
	int j;
	for(j=1;j<=100;j++)
	printf("*");
}


///reciept
int main()
{
    int fare=0;
    int disfare=0;
    customer();
    system("cls");
    confirm_diag();
    fare = total();
    disfare = discount(fare);
    system("cls");
    printf("\n============================================\n\n");
    printf("*************  <<< Receipt >>> *************\n");
    printf("\n============================================\n\n");
    printf("Customer Name: \t\t%s\n", name_customer);
    printf("Customer Contact: \t%s\n", num_customer);
    printf("Captain Name: \t\t%s\n", captain_name);
    printf("Captain Contact: \t%s\n", captain_num);
    printf("Car Name: \t\t%s\n", car);
    printf("Car Name: \t\t%s\n", id_car);
    printf("Total Fare: \t\tRs.%d\n", fare);
    printf("Discount:\t\tRs.%d\n", disfare);
    printf("Discounted Fare:\tRs.%d\n", fare-disfare);
    printf("\n\n============================================\n\n");
    printf("*******THANK YOU FOR RIDING WITH US!********\n");
    printf("\n============================================\n");

}
 //customer's input

void customer()
{
line();
printf("\n\t\t\t\t\t***Droporama***\n");
line();
int count=0;
    while(count<3)
{
    printf("\n\nCustomer's Name:\t\t");
    scanf("%s", name_customer);
    printf("\nContact Number[03xxxxxxxxx]:\t");
    scanf("%s", num_customer);

    ///To take the number of 11 digits...

    if(strlen(num_customer)==11)
    {
        break;
    }
    if (strlen(num_customer)!=11)
    {
        printf("\nIncorrect Number...\n");
        printf("\n*******THANK YOU!********\n");
        count++;
    }
}
if(count==3)
{
    printf("\nToo Many Tries...\nPlease Try Again Later.\n\n");
    exit(0);
}
    printf("\n\n\n\tWhich of the following class you want to ride:\n");
    printf("\t\t1.Go\n");
    printf("\t\t2.Go+\n");
    printf("\t\t3.Business\n");
    printf("\t\t4.Exit\n\n");
    printf("\tEnter the number: ");
    scanf("%d", &option);
    char go_cars[3][100]={"Mehran 2005","Cultus 2009","Alto 2007"};
    char go_captains[3][100]={"Mr.Ahmed", "Babar", "Zeeshan"};
    char go_id[3][20]={"AVU-796","BFH-042","ALP-604"};
    char go_cap_num[3][12]={"03130000000","03121111111","03443333333"};
    char go_plus_cars[3][100]={"Civic 2013","Prius 2015","City 2011"};
    char go_plus_captains[3][100]={"Taha", "Sameer", "Tayyab"};
    char go_plus_id[3][20]={"AVE-068","890-255","CBA-321"};
    char go_plus_cap_num[3][12]={"03130000001","03121111112","03453333333"};
    char business_cars[3][100]={"Prius 2019","Premio 2018","Civic 2017"};
    char business_captains[3][100]={"Jabbar","Adil", "Hussain"};
    char business_id[3][20]={"CAB-1868","AAH-747","AFR-420"};
    char business_cap_num[3][12]={"03130000002","03121111115","03463333333"};
    if(option==1)
    {
        printf("\n\n\tAvailable cars are: \n\n");
        int n=0;
        for(int i=0;i<3;i++)
            {
                printf("\t\t%d. ",i+1);
                puts(go_cars[i]);
                }

        printf("\n\tEnter your choice: ");
        scanf("%d", &n);
        n=n-1;
        strcpy(car, go_cars[n]);
        strcpy(captain_name, go_captains[n]);
        strcpy(captain_num, go_cap_num[n]);
        strcpy(id_car, go_id[n]);
    }
    else if(option==2)
    {
        printf("\n\n\tAvailable cars are: \n\n");
        int n;
        for(int i=0;i<3;i++)
{
    printf("\t\t%d. ",i+1);
  puts(go_plus_cars[i]);
}

    printf("\n");

    printf("\n\tEnter your choice: ");
    scanf("%d", &n);
    n=n-1;
    strcpy(car, go_plus_cars[n]);
    strcpy(captain_name, go_plus_captains[n]);
    strcpy(captain_num, go_plus_cap_num[n]);
    strcpy(id_car, go_plus_id[n]);
    }
    else if(option==3)
    {
        printf("\n\n\tAvailable cars are: \n\n");
        int n=0;
        for(int i=0;i<3;i++)
{
    printf("\t\t%d. ",i+1);
  puts(business_cars[i]);
}

    printf("\n");
    printf("\n\tEnter your choice: ");
    scanf("%d", &n);
    n=n-1;
    strcpy(car, business_cars[n]);
    strcpy(captain_name, business_captains[n]);
    strcpy(captain_num, business_cap_num[n]);
    strcpy(id_car, business_id[n]);
    }
    else if(option==4)
    {
        printf("\n*******THANK YOU!********\n");
        exit(0);
    }
    else{
        printf("Invalid Code...");
        printf("\n*******THANK YOU!********\n");
        exit(0);
    }

    }

//Confirmation
void confirm_diag()
{
    char n[10];
    printf("\nCaptain %s will be on his way \n want to confirm your ride? Y/N: ", captain_name);
    scanf("%s",&n);
    if(!strcmp("Y",n) || !strcmp("y",n))
    {
        printf("\nYour Captain %s is on his way", captain_name);
        printf("\nCaptain Contact Number");
        printf("\nHave you safe ride-------\n");
        getch();
        system("cls");
    }
    else{
        printf("\n Searching another captain in the area");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf("\n No new captains found...\nPlease try again in a while.\n\n");
        printf("\n*******THANK YOU!********\n");
        exit(0);
    }

}

///Fare
int total()
{
    int d,t,cost;
    printf("\nEnter Total distance covered(km): ");
    scanf("%d", &d);
    printf("\nEnter Total time waited(m): ");
    scanf("%d", &t);
    if(option==1)
    {
        cost= go(d,t);
        return cost;
    }
    else if(option==2)
    {
        cost= go_plus(d,t);
        return cost;
    }
    else if(option==3)
    {
        cost= business(d,t);
        return cost;
    };
}
//formulas
int go(int km, int wt)
{
    return (km*8)+wt+20;
}
int go_plus(int km, int wt)
{
    return (km*10)+(wt*2)+25;
}
int business(int km, int wt)
{
    return (km*15)+(wt*3)+40;
}
//coupon input
int discount(int fare)
{

printf("\nTotal Fare Was: %d",fare);
char b[100];
int result=0;
char n[10];
coupon:
    printf("\nDo you have a coupon? Y/N: ");
    scanf("%s",&n);
    if(!strcmp("Y",n) || !strcmp("y",n))
    {
            printf("\nEnter the coupon code that you have(xxxxxxxx):  ", b);
            scanf("%s", &b);
            if(!strcmp("pewdiepie",b))
            {
                result=fare*0.2;
            }
            else if(!strcmp("HAPPY2021",b))
            {
                result=fare*0.05;
            }
            else if(!strcmp("HAPPYRIDE",b))
            {
                    result=fare*0.01;
            }
            else{
                printf("\nInvalid Code... Try Again\n");
                goto coupon;
            }
        }
        return result;
}



