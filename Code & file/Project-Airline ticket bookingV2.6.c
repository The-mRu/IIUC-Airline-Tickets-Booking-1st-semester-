#include<stdio.h>
#include<string.h>
#define p printf
#define new printf("\n");
#define s scanf
#define clear system("cls");

#define pp printf("\t\t==================================================================================================\n");
#define pp2 printf("\t\t\t\t\t\tIIUC Airline Tickets Booking\n");
#define pp3 printf("\t\t==================================================================================================\n\n\n");

struct passenger
{
    char name[50];
    char seat[10];
    //char ticket [20];
    int passport;
    unsigned long long int nid;

};
int i,j,k,n,n2;
int t=0;
int ticketdc[100] ;
int ticketcd[100] ;

struct passenger dc[100];
struct passenger cd[100];

void writeDC()
{

    FILE *file;
    file=fopen("DC.txt","w");
    fprintf(file,"%d\n",n);
    for(i=0; i<n; i++)
    {
        fprintf(file,"%s\n%llu\n%d\n",dc[i].name,dc[i].nid,ticketdc[i]);
    }
    fclose(file);
}
void readDC()
{

    FILE *file;
    file=fopen("DC.txt","r");
    fscanf(file,"%d",&n);
    for(i=0; i<n; i++)
    {
        fscanf(file,"%s%llu%d",dc[i].name,&dc[i].nid,&ticketdc[i]);

    }
    fclose(file);
}

void showDC()
{
    for(i=0; i<n; i++)
    {
        p("\n\tName     : %s\n",dc[i].name);
        p("\tNID No   : %llu\n",dc[i].nid);
        p("\tTicket No: %d\n",ticketdc[i]);
        // printf("%s\n%d",dc[i].name,dc[i].nid);
    }
}
void writeCD()
{

    FILE *file;
    file=fopen("CD.txt","w");
    fprintf(file,"%d\n",n2);
    for(i=0; i<n2; i++)
    {
        fprintf(file,"%s\n%llu\n%d\n",cd[i].name,cd[i].nid,ticketcd[i]);
    }
    fclose(file);
}
void readCD()
{

    FILE *file;
    file=fopen("CD.txt","r");
    fscanf(file,"%d",&n2);
    for(i=0; i<n2; i++)
    {
        fscanf(file,"%s%llu%d",cd[i].name,&cd[i].nid,&ticketcd[i]);

    }
    fclose(file);
}

void showCD()
{
    for(i=0; i<n2; i++)
    {
        p("\n\tName     : %s\n",cd[i].name);
        p("\tNID No   : %llu\n",cd[i].nid);
        p("\tTicket No: %d\n",ticketcd[i]);
        // printf("%s\n%d",dc[i].name,dc[i].nid);
    }
}
char pass[50];
void setPass()
{
    //char pass[32]="12345";

    FILE *pass1;
    pass1=fopen("pass.txt","w");

    fprintf(pass1,"%s",pass);
    fclose(pass1);
}
void ReadPass()
{
    FILE *pass1;
    pass1=fopen("pass.txt","r");
    fscanf(pass1,"%s",pass);// scanf("%[^\n]", last_line);
    fclose(pass1);
}




int main()
{
    int q,first_step,f,fk;

    for(;;)
    {
homeMenu:
        clear;
        pp; //p("==================================================================================================\n");
        pp2;//p("\t\t\t\tIIUC Airline Tickets Booking\n");
        pp3;// p("==================================================================================================\n\n");

        p("\t%c 1.Passenger      :\n",254);
        p("\t%c 2.Administration :\n",254);
        p("\t%c 3.Info           :\n",254);
        p("\t%c 4.Exit           :\n",254);
        p("\nPress : ");


        scanf("%d",&first_step);
        if(first_step==1)   /// passenger menu
        {
PassengerMenu:
            clear;
            pp;
            pp2;
            pp3;
            p("\nPassenger Menu---------------\n\n");
            p("\t1.Buying Ticket        :\n");
            p("\t2.Checking Ticket      :\n");
            p("\t3.Canceling Ticket     :\n");
            p("\t4.Upadate Ticket's info:\n");
            p("\t5.Back to home menu    :\n");

            int second_stepP;
            scanf("%d",&second_stepP);

            if(second_stepP==1) ///Buying Ticket passenger
            {
                clear;
                pp;
                pp2;
                pp3;
                int payment;
                p("\n   #Buying Ticket \n");
                p("   Select your Airline\n");
                p("\t 1.Dhaka to Chittagong (DC): \n");
                p("\t 2.Chittagong to Dhaka (CD): \n");
                p("\t 3.Back                    :\n");
                int p1;
                s("%d",&p1);
                if(p1==1) // buying ticket dc.....................................   Buying T. DC   ..........  Passenger ......................
                {
                    readDC();
                    if(n<20)//as DC airline has only 20 seat, so n<21;
                    {
                        //ticketdc[1]=2211;
                        p("  #Enter your\n");
                        p("\tName       : ");
                        s("%s",dc[i].name);
                        p("\tNID Number : ");
                        s("%llu",&dc[i].nid);
                        //t=n;
                        n++;
                        //t++;
                        for(j=0,k=2211; j<n; k++,j++)
                        {
                            ticketdc[j]=k;
                        }
                        p("\n\t***Payment(10,000TK )\n\n");
                        p("\tEnter amount (10000)  : ");
                        s("%d",&payment);

                        if(payment==10000)
                        {
                            p("\n\tPayment completed\n\tClick any botton to continue ");
                            getch();

                            clear;
                            pp;
                            pp2;
                            pp3;

                            p("\n\n\t\tName           : %s \n",dc[i].name);
                            p("\t\tNID Number     : %llu\n",dc[i].nid);
                            p("\t\tTicket No      :%d\n",ticketdc[i]);
                            p("\t\tPayment        : 10,000tk \n");
                            p("\n\t\tYour ticket is booked in DC Airline\n\t\tThank You\n");


                            writeDC();

                        }
                        else p("\n\tPayment not complete, try latter\n\n");


                    }
                    else p("\n\t***Tickets are not available*** \n\n");


                    getch();

                    goto PassengerMenu;

                }// ending of buying ticket dc

                else if(p1==2)   //  buying ticket cd..........................................PPPPPPPPPP.....................buying CD
                {
                    readCD();
                    if(n2<20)//as DC airline has only 20 seat, so n2<21;
                    {
                        // n=n-1;
                        //ticketdc[1]=2211;
                        p("  #Enter your\n");
                        p("\tName       : ");
                        s("%s",cd[i].name);
                        p("\tNID Number : ");
                        s("%llu",&cd[i].nid);
                        //t=n;
                        n2++;
                        //t++;
                        for(j=0,k=2311; j<n2; k++,j++)
                        {
                            ticketcd[j]=k;
                        }

                        /// p(" You have to complete your payment first ");
                        p("\n\t***Payment(10,000TK )\n\n");
                        p("\tEnter amount (10000)  : ");
                        s("%d",&payment);
                        //  p("\n\tPayment completed\n\tClick any botton  ");

                        if(payment==10000)
                        {
                            p("\n\tPayment completed\n\tClick any botton  ");
                            getch();

                            clear;
                            pp;
                            pp2;
                            pp3;

                            p("\n\n\t\tName           : %s \n",cd[i].name);
                            p("\t\tNID Number     : %llu\n",cd[i].nid);
                            p("\t\tTicket No      :%d\n",ticketcd[i]);
                            p("\t\tPayment        : 10,000tk \n");

                            p("\n\t\tYour ticket is booked in CD Airline  \n\n\t\tThank You\n");


                            writeCD();

                        }

                        else p("\n\tPayment not complete, try latter\n\n");


                    }
                    else p("\n\t***Tickets are not available*** \n\n");

                    getch();
                    goto PassengerMenu;

                } /// ending of buying ticket cd
                else if(p1==3)
                {
                    goto PassengerMenu; /// back to passenger menu
                }
                else
                {
                    p("Not valid, try latter\n");
                    getch();
                    goto PassengerMenu;

                }

                getch();


            }///ending of passenger buying ticket

            if(second_stepP==2)///Checking Ticket p///////////////////////////////////////checking.............///// passenger   ..................
            {
                clear;
                pp;
                pp2;
                pp3;
                p("#Checking tickets\n\n");
                p("   Select your Airline\n");
                p("\t 1.Dhaka to Chittagong (DC): \n");
                p("\t 2.Chittagong to Dhaka (CD): \n");
                p("\t 3.Back                    :\n");
                int ckn;
                s("%d",&ckn);
                if(ckn==1)
                {

                    int ck;
                    int posi = -1;
                    readDC();

                    p("Searching Ticket:-\n\n");
                    p("Enter your ticket no : ");
                    s("%d",&ck);
                    for(i=0; i<n; i++)
                    {
                        if(ck==ticketdc[i]) /// if(strcmp(a[i].id,id)==0)
                        {
                            posi=i;
                        }
                    }
                    if(posi!=-1)
                    {
                        p("\n\tName     : %s\n",dc[posi].name);
                        p("\tNID No   : %llu\n",dc[posi].nid);
                        p("\tTicket No: %d\n",ticketdc[posi]);
                        p("\t           DC AIRLINE\n");
                    }
                    else p("\n\tNot found\n");
                    getch();
                    goto PassengerMenu;

                } // p checking dc

                else if ( ckn == 2)
                {
                    int ck;
                    int posi = -1;
                    readCD();

                    p("Searching Ticket:-\n\n");
                    p("Enter your ticket no : ");
                    s("%d",&ck);
                    for(i=0; i<n2; i++)
                    {
                        if(ck==ticketcd[i]) /// if(strcmp(a[i].id,id)==0)
                        {
                            posi=i;
                        }
                    }
                    if(posi!=-1)
                    {
                        p("\n\tName     : %s\n",cd[posi].name);
                        p("\tNID No   : %llu\n",cd[posi].nid);
                        p("\tTicket No: %d\n",ticketcd[posi]);
                        p("\t           CD  AIRLINE\n");
                    }
                    else p("\n\tNot found\n");

                    getch();

                    goto PassengerMenu;

                } // p checking cd
                else if (ckn == 3)
                {
                    goto PassengerMenu;
                }
                else p("\n\n\t****Invalid****\n\tTry latter");

                getch();
                goto PassengerMenu;

            }//ending of checking Ticket

            else if(second_stepP==3)///         .    .      .   .     .      Canceling Ticket............  Passenger   .....................
            {
                clear;
                pp;
                pp2;
                pp3;
                p("\n   Select your Airline for cancel your ticket  \n\n");
                p("\t 1.Dhaka to Chittagong (DC): \n");
                p("\t 2.Chittagong to Dhaka (CD): \n");
                p("\t 3.Back to home menu       :\n");

                int del;
                s("%d",&del);

                if(del==1) // canceling dc ticket
                {

                    int ID;
                    int posi=-1;
                    readDC();

                    p("Which Ticket do you want to cancel? \nEnter your ticket no :");

                    for(int k=0; k<3; k++)
                    {
                        s("%d",&ID);
                        for(i=0; i<n; i++)
                        {
                            if(ID==ticketdc[i])
                            {
                                posi=i;
                            }
                        }
                        if(posi!=-1)
                        {
                            for(i=posi; i<n-1; i++)
                            {
                                dc[i]=dc[i+1];
                            }
                            n--;
                            writeDC();
                            readDC;

                            p("\nTicket no %d is canceled\n",ticketdc[posi]);
                            getch();
                            goto PassengerMenu;
                        }

                        else
                        {
                            p("\nID does not match\n");

                        }
                        if(posi==-1)
                            p("\n\t***Try latter***\n");
                        getch();
                        goto PassengerMenu;
                    }
                } // ending of canceling dc ticket

                else if(del==2)//canceling cd ticket
                {
                    int ID;
                    int posi=-1;
                    readCD();

                    p("Which Ticket do you want to cancel? \nEnter your ticket no :");

                    for(int k=0; k<3; k++)
                    {
                        s("%d",&ID);
                        for(i=0; i<n2; i++)
                        {
                            if(ID==ticketcd[i])
                            {
                                posi=i;
                            }
                        }
                        if(posi!=-1)
                        {
                            for(i=posi; i<n2-1; i++)
                            {
                                cd[i]=cd[i+1];
                            }
                            n2--;
                            writeCD();
                            readCD;

                            p("\nTicket no %d is canceled\n",ticketcd[posi]);
                            getch();
                            goto PassengerMenu;
                        }

                        else
                        {
                            p("\nID does not match\n");

                        }
                        if(posi==-1)
                            p("\n\t***Try latter***\n");
                        getch();
                        goto PassengerMenu;
                    }

                }// ending of canceling cd ticket
                else if (del ==3)
                {
                    goto PassengerMenu;
                }
                else p("\n\n\t***invalid***\n\tTry latter ");

                getch();
                goto PassengerMenu;

            }// . . . ending of canceling ticket

            else if (second_stepP==4) // update info
            {
                clear;
                pp;
                pp2;
                pp3;

                p("\nSelect your Airline for update info\n\n");
                p("\t 1.Dhaka to Chittagong (DC): \n");
                p("\t 2.Chittagong to Dhaka (CD): \n");
                p("\t 3.Back                    :\n");
                int up;
                s("%d",&up);
                if(up==1)//   ...........update of dc p...................
                {
                    readDC();
                    int ck;
                    int posi=-1;


                    p("Which Ticke's Info do you want to Update? \nEnter you Ticket no :");

                    s("%d",&ck);
                    for(i=0; i<n; i++)
                    {
                        if(ck==ticketdc[i])
                        {
                            posi=i;
                        }
                    }
                    if(posi!=-1)
                    {
                        p("\nEnter your\n");
                        p("\tName       : ");
                        s("%s",dc[posi].name);
                        p("\tNID Number : ");
                        s("%llu",&dc[posi].nid);

                        writeDC();

                        clear;
                        pp;
                        pp2;
                        pp3;

                        p("\n\tYour updated Ticket's info:-");
                        p("\n\n\t\tName           : %s \n",dc[posi].name);
                        p("\t\tNID Number     : %llu\n",dc[posi].nid);
                        p("\t\tTicket No      :%d in DC Airline\n",ticketdc[posi]);

                    }
                    else p("\n\tNot found\n");

                    getch();
                    goto PassengerMenu;


                }//ending of update dc

                else if(up==2)//   ...........update of cd p...................
                {
                    readCD();
                    int ck;
                    int posi=-1;

                    p("Which Ticke's Info do you want to Update? \nEnter you Ticket no :");

                    s("%d",&ck);
                    for(i=0; i<n2; i++)
                    {
                        if(ck==ticketcd[i])
                        {
                            posi=i;
                        }
                    }
                    if(posi!=-1)
                    {
                        p("\nEnter your\n");
                        p("\tName       : ");
                        s("%s",cd[posi].name);
                        p("\tNID Number : ");
                        s("%llu",&cd[posi].nid);

                        writeCD();
                        clear;
                        pp;
                        pp2;
                        pp3;
                        p("\n\tYour updated Ticket's info:-");
                        p("\n\n\t\tName           : %s \n",cd[posi].name);
                        p("\t\tNID Number     : %llu\n",cd[posi].nid);
                        p("\t\tTicket No      :%d in DC Airline\n",ticketcd[posi]);

                    }
                    else p("\n\tNot found\n");
                    getch();
                    goto PassengerMenu;

                }//ending of update cd

                else if (up==3)
                {
                    goto PassengerMenu;
                }
                else p("\n\tNot found\n");
                getch();
                goto PassengerMenu;








                getch();
            } //eding of update p
            else if(second_stepP==5)///back to mainMenu;
            {
                goto homeMenu;
            }
            else
            {
                p("Invalid Number");
                getch();
                goto PassengerMenu;
            }

        }

        else if(first_step==2) ///administration login
        {
            clear;
            pp;
            pp2;
            pp3;
            p("\n\n\t\t\t\t    ==========ADMINISTRATION LOGIN==========\n\n");

            ReadPass();
            char Entpass[50];
            // char pass[] ="12345";
            p("\tEnter your password : ");
            f=0;

            for(i=0; i<5; f++, i++) ///password loop
            {


                s("%s",Entpass);
                if(strcmp(Entpass,pass)==0)
                {
                    int payment;
                    clear;
                    pp;
                    pp2;
                    pp3;
                    printf("\n\t\t\t\t    ***Login successful***\n\n");
                    p("%c Click any button to continue ",254);
                    getch();

                    for(;;) ///infinitive loop
                    {
                        //p("==================================================================================================\n");
                        //p("\t\t\t\tIIUC Airline Tickets Booking\n");
                        // p("==================================================================================================\n\n");
adMenu:
                        clear;
                        pp;
                        pp2;
                        pp3;
                        p("\nAdministration Menu---------------\n\n");

                        p("\t1.Buying Ticket          :\n");
                        p("\t2.Checking Ticket        :\n");
                        p("\t3.Canceling Ticket       :\n");
                        p("\t4.show tickets           :\n");
                        p("\t5.show availale tickets  :\n");
                        p("\t6.Changing password      :\n");
                        p("\t7.Back to home menu      :\n");

                        scanf("%d",&q);

                        if(q==1) //  .   .  .    .     .    .    .   .   .  .///#Buying Ticket...................................................
                        {
                            clear;
                            pp;
                            pp2;
                            pp3;
                            p("\n   #Buying Ticket \n");
                            p("   Select your Airline\n");
                            p("\t 1.Dhaka to Chittagong (DC): \n");
                            p("\t 2.Chittagong to Dhaka (CD): \n");
                            p("\t 3.Back                    :\n");
                            int p1;
                            s("%d",&p1);
                            if(p1==1) // buying ticket dc...........................................................Buying DC....................................
                            {
                                readDC();
                                if(n<20)//as DC airline has only 20 seat, so n<21;
                                {
                                    //ticketdc[1]=2211;
                                    p("  #Enter your\n");
                                    p("\tName       : ");
                                    s("%s",dc[i].name);
                                    p("\tNID Number : ");
                                    s("%llu",&dc[i].nid);
                                    //t=n;
                                    n++;
                                    //t++;
                                    for(j=0,k=2211; j<n; k++,j++)
                                    {
                                        ticketdc[j]=k;
                                    }
                                    p("\t\n***Payment(10,000TK )\n\n");
                                    p("\tEnter amount (10000)  : ");
                                    s("%d",&payment);

                                    if(payment==10000)
                                    {
                                        p("\n\tPayment completed\n\tClick any botton to continue ");
                                        getch();

                                        clear;
                                        pp;
                                        pp2;
                                        pp3;

                                        p("\n\n\t\tName           : %s \n",dc[i].name);
                                        p("\t\tNID Number     : %llu\n",dc[i].nid);
                                        p("\t\tTicket No      :%d\n",ticketdc[i]);
                                        p("\t\tPayment        : 10,000tk \n");
                                        p("\n\t\tYour ticket is booked in DC Airline\n\n\t\tThank You\n");


                                        writeDC();

                                    }
                                    else p("\n\tPayment not complete, try latter\n\n");


                                }
                                else p("\n\t***Tickets are not available*** \n\n");


                                getch();

                                goto adMenu;

                            }// ending of buying ticket dc



                            else if(p1==2)  //tct cd
                            {
                                readCD();
                                if(n2<20)//as DC airline has only 20 seat, so n2<21;
                                {
                                    //ticketdc[1]=2211;
                                    p("  #Enter your\n");
                                    p("\tName       : ");
                                    s("%s",cd[i].name);
                                    p("\tNID Number : ");
                                    s("%llu",&cd[i].nid);
                                    //t=n;
                                    n2++;
                                    //t++;
                                    for(j=0,k=2311; j<n2; k++,j++)
                                    {
                                        ticketcd[j]=k;
                                    }

                                    p("\n\t***Payment(10,000TK )\n\n");
                                    p("\tEnter amount (10000)  : ");
                                    s("%d",&payment);

                                    if(payment==10000)
                                    {
                                        p("\n\tPayment completed\n\tClick any botton to continue ");
                                        getch();

                                        clear;
                                        pp;
                                        pp2;
                                        pp3;

                                        p("\n\n\t\tName           : %s \n",cd[i].name);
                                        p("\t\tNID Number     : %llu\n",cd[i].nid);
                                        p("\t\tTicket No      :%d\n",ticketcd[i]);
                                        p("\t\tPayment        : 10,000tk \n");

                                        p("\n\t\tYour ticket is booked in CD Airline\n\n\t\tThank You\n");


                                        writeCD();

                                    }
                                    else p("\n\tPayment not complete, try latter\n\n");


                                }
                                else p("\n\t***Tickets are not available*** \n\n");
                                getch();

                                goto adMenu;


                            }//ending of buying ticket cd
                            else if(p1==3)
                            {
                                goto adMenu;
                            }
                            else
                            {
                                p("Not valid, try latter\n");
                                getch();
                                goto adMenu;
                            }
                            getch();


                        }///ending of Buying Ticket (q=1)...............................................................ad...............




                        else if(q==2)// .  .  .  . . .  . . . . . . . . . . .administration checking ticket'''''''''''''///////
                        {
                            clear;
                            pp;
                            pp2;
                            pp3;

                            p("\n#Checking Ticket\n\n");
                            p("   Select your Airline\n");
                            p("\t 1.Dhaka to Chittagong (DC): \n");
                            p("\t 2.Chittagong to Dhaka (CD): \n");
                            p("\t 3.Back                    :\n");
                            int ckn;
                            s("%d",&ckn);
                            if(ckn==1)
                            {

                                int ck;
                                int posi = -1;
                                readDC();
                                // clear;//system("cls");
                                //pp;
                                p("Searching Ticket:-\n\n");
                                p("Enter your ticket no : ");
                                s("%d",&ck);
                                for(i=0; i<n; i++)
                                {
                                    if(ck==ticketdc[i]) /// if(strcmp(a[i].id,id)==0)
                                    {
                                        posi=i;
                                    }
                                }
                                if(posi!=-1)
                                {
                                    p("\n\tName     : %s\n",dc[posi].name);
                                    p("\tNID No   : %llu\n",dc[posi].nid);
                                    p("\tTicket No: %d\n",ticketdc[posi]);
                                    p("\t           DC AIRLINE\n");

                                }
                                else p("\n\tNot found\n");
                                getch();
                                goto adMenu;

                            } // checking dc

                            else if ( ckn == 2)
                            {
                                int ck;
                                int posi = -1;
                                readCD();
                                //clear;
                                // pp;
                                p("Searching Ticket:-\n\n");
                                p("Enter your ticket no : ");
                                s("%d",&ck);
                                for(i=0; i<n2; i++)
                                {
                                    if(ck==ticketcd[i]) /// if(strcmp(a[i].id,id)==0)
                                    {
                                        posi=i;
                                    }
                                }
                                if(posi!=-1)
                                {
                                    p("\n\tName     : %s\n",cd[posi].name);
                                    p("\tNID No   : %llu\n",cd[posi].nid);
                                    p("\tTicket No: %d\n",ticketcd[posi]);
                                    p("\t           CD  AIRLINE\n");
                                }
                                else p("\n\tNot found\n");

                                getch();
                                goto adMenu;



                            } // checking cd
                            else if(ckn==3)
                            {
                                goto adMenu;
                            }
                            else p("\n\n\t****Invalid\n\tTry latter");

                            getch();
                            goto adMenu;


                        }// ending ad checking ticket

                        else if(q==3)// ad .............................canceling ticket................................administration
                        {
                            clear;
                            pp;
                            pp2;
                            pp3;
                            p("\n   Select your Airline for cancel your ticket  \n\n");
                            p("\t 1.Dhaka to Chittagong (DC): \n");
                            p("\t 2.Chittagong to Dhaka (CD): \n");
                            p("\t 3.Back to home menu       :\n");

                            int del;
                            s("%d",&del);

                            if(del==1) // canceling dc ticket
                            {

                                int ID;
                                int posi=-1;
                                readDC();

                                p("Which Ticket do you want to cancel? \nEnter your ticket no :");

                                for(int k=0; k<3; k++)
                                {
                                    s("%d",&ID);
                                    for(i=0; i<n; i++)
                                    {
                                        if(ID==ticketdc[i])
                                        {
                                            posi=i;
                                        }
                                    }
                                    if(posi!=-1)
                                    {
                                        for(i=posi; i<n-1; i++)
                                        {
                                            dc[i]=dc[i+1];
                                        }
                                        n--;
                                        writeDC();
                                        readDC;
                                        p("\n \t%d no ticket is canceled\n",ticketdc[posi]);


                                        // p("\nname :%s \nTicket no %d is canceled\n",dc[posi].name,ticketdc[posi]);
                                        getch();
                                        goto adMenu;
                                    }

                                    else
                                    {
                                        p("\nID does not match\n");

                                    }
                                    if(posi==-1)
                                        p("\n\t***Try latter***\n");
                                    getch();
                                    goto adMenu;
                                }
                            } // ending of canceling dc ticket

                            else if(del==2)//canceling cd ticket
                            {
                                int ID;
                                int posi=-1;
                                readCD();

                                p("Which Ticket do you want to cancel? \nEnter your ticket no :");

                                for(int k=0; k<3; k++)
                                {
                                    s("%d",&ID);
                                    for(i=0; i<n2; i++)
                                    {
                                        if(ID==ticketcd[i])
                                        {
                                            posi=i;
                                        }
                                    }
                                    if(posi!=-1)
                                    {
                                        for(i=posi; i<n2-1; i++)
                                        {
                                            cd[i]=cd[i+1];
                                        }
                                        n2--;
                                        writeCD();
                                        readCD;
                                        p("\n \t%d no ticket is canceled\n",ticketcd[posi]);


                                        // p("\nname : %s \nTicket no %d is canceled\n",cd[posi].name,ticketcd[posi]);
                                        getch();
                                        goto adMenu;
                                    }

                                    else
                                    {
                                        p("\nID does not match\n");

                                    }
                                    if(posi==-1)
                                        p("\n\t***Try latter***\n");
                                    getch();
                                    goto adMenu;
                                }

                            }// ending of canceling cd ticket
                            else if (del ==3)
                            {
                                goto adMenu;
                            }
                            else p("\n\n\t***invalid***\n\tTry latter ");

                            getch();
                            goto adMenu;



                        } //  ending of canceling ticket..........................................


                        else if(q==4)///showing///////////////////////////////////............Administration.............////////////////////////
                        {
                            p("1.Sold tickets of DC AIR\n");
                            p("2.Sold tickets of CD AIR\n");
                            int qq;
                            s("%d",&qq);
                            if(qq==1)
                            {
                                clear;
                                pp;
                                pp2;
                                pp3;
                                readDC();
                                p("\n%c Total ticket sold in DC AIRLINE : %d \n\n",254,n);
                                showDC();
                            }
                            else if(qq==2)
                            {
                                clear;
                                pp;
                                pp2;
                                pp3;
                                readCD();
                                p("\n%c Total ticket sold in CD AIRLINE : %d \n\n",254,n2);
                                showCD();
                            }
                            else
                                p("Not valid\n");

                            // getch();

                        }
                        else if(q==5) //  ..............showing available ticket...........................Administration..............................
                        {
availableMenu:
                            clear;
                            pp;
                            pp2;
                            pp3;
                            p("Please select Airline for knowing available tickets\n");
                            p("\t 1.Dhaka to Chittagong (DC): \n");
                            p("\t 2.Chittagong to Dhaka (CD): \n");
                            p("\t 3.Back                    :\n");

                            int showing;
                            s("%d",&showing);
                            if(showing==1) //..........avail dc.............
                            {
                                readDC();
                                p("\n\tAvailable tickets in DC Airline : %d",20-n);

                            } //ending of avail. dc........

                            else if(showing==2)//..........avail cd.............
                            {
                                readCD();
                                p("\n\tAvailable tickets in CD Airline : %d",20-n2);

                            }//ending of avail. cd........

                            else if(showing==3)
                            {
                                goto adMenu;
                            }
                            else
                            {
                                p("\n\t***Pressed invalid number***\n");
                                p("\tTry again.....");
                                getch();
                                goto availableMenu;

                            }
                            getch();
                            goto adMenu;

                        }//   ending of ...showing available ticket.......................................

                        else if(q==6)//5.Changing password
                        {

                            p("\n\tEnter new Password : ");
                            s("%s",pass);
                            setPass();

                            ReadPass();
                            p("\nPassword changed\n");

                            //getch();
                        }
                        else if(q==7)
                        {
                            goto homeMenu;

                        }
                        else
                            p("Invalid number\n");
                        getch();


                    } //ending of infinitive loop

                } // password if statement


                else p("\tWrong Password\n");


                if(f==4)
                {
                    p("\n\"Try latter\n");
                    getch();
                    //break;
                }

            }//ending of password loop



        }   ///ending of q=2


        else if(first_step==3)
        {
            clear;
            pp;
            pp2;
            pp3;
            int info;
            p("\n\n  #INFO :-\n");
            p("\t1.Team info                          : \n");
            p("\t2.About IIUC AIRLINE TICKETS BOOKING : \n");
            p("\t3.Back                               : \n");

            s("%d",&info);
            if(info==1){

            clear;
            p("\n\t%c Project Name: AIRLINE TICKET BOOKING\n\n",254);
            p("\n\t%c Team Information\n\n",254);
            p("\tName : Md.Rayhan Uddain                 ID:C221050 \n\n");
            p("\tName : Mohammad Istiaque Ahmed Mahi     ID:C221073  \n\n");

            p("\tName : Nazrul Islam Sajib               ID:C221074\n\n");

            //getch();
            }
            else if(info==2){
                    clear;
                p("\n\n %c IIUC AIRLINE TICKETS BOOKING\n",254);
                p("\n\tTwo airlines are available in IIUC Airlines. Each of them has only 20 seat capacity. Name(without space),\n\tNID number will be needed to buy a ticket. Then 10,000tk(BDT) has to pay to confirm the ticket.");
            }
            else if(info==3){
                goto homeMenu;
            }
            else p("\n\tNot valid\n");
            getch();

        }
        else if(first_step==4)
        {
            p("\nThank you\n\n");
            break;

        }
        else
        {
            p("Invalid number\n\n");
            getch();
        }

    }

    getch();

}
