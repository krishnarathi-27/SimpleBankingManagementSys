//Program to manage the bank data using inheritance
#include<iostream>
#include<math.h>

using namespace std;

class Account 
{
    protected:
    
    char name[20],acc_type[10];
    long int acc_no;
    float balance;

    public:

    void input();
    void display();
    void deposit();
    void rating();

};

class saving_acc : public Account 
{
    public:
    
    float interest;

    float compound_int();
    void update_bal();
    void withdrawal();

};

class current_acc : public Account 
{
    int cheque_book, penalty;

    public:

    void min_balance();
    void withdrawal1();
    void chq_book();

};

void Account ::  input()
{
    cout << "Enter the name of the customer " << endl;
    cin >> name;

    cout << "Enter the account number " << endl;
    cin >> acc_no;

   /* cout << "enter the account type the customer have " << endl;
    cin >> acc_type;
*/
    cout << "Enter the balance " << endl;
    cin >> balance;
} 

void Account :: display()
{
   cout << "Name of account holder is : " << name << endl;

   cout << "Account number is : " << acc_no << endl;

 /*  cout << "Account type is : " << acc_type << endl; */

   cout << "Balance in your account is : " << balance << endl;

}

void Account :: deposit()
{
    int choice,amt;

    cout << "Do you want to deposit any amount " << endl;
    cout << "If yes then press 1 " << endl << "If no then press 0 " << endl;

    cin >> choice;

    if (choice == 1)
    {
        
        cout << "Enter the amount you want to deposit " << endl;

        cin >> amt;
        balance=balance+amt;

    }

} 

void Account :: rating()
{
    int n;
                cout << "Enter the rating of our bank service out of 5 " << endl;
                cin >> n;

                for(int i =1; i<=n ;i++ )
                {
                    cout << " * " ; 
                }

    cout << "Thank-You for visiting our bank " << endl;
}

float saving_acc :: compound_int()
{
   cout << "To check the balance after the interest is being added kindly " << endl;

   float rate =8 , interest;
   int time;
   
   cout << " Enter the time period" << endl;
   cin >> time;

   interest=balance * pow(1+rate/100,time) - balance ;

   cout << "Interest amount in your account is  : " << interest << endl;

   return interest;

} 
void saving_acc :: update_bal()
{
    balance = balance + compound_int();

    cout << " The balance in your account is :  " << balance << endl;

}

void saving_acc :: withdrawal()
{
    int amount ,ch3;

     cout << "Do you want to withdraw any amount from your account " << endl;

    cout << "If yes then press 1 " << endl;
    cout << "If no press 0" << endl;

    cin >> ch3;

       if(ch3==1)
     {
      cout << "Enter the amount of withdrawal " << endl;
      cin >> amount;

           if(balance>=amount)
      {
        balance = balance- amount;

        cout << "Your current balance is : " << balance << endl;

      }

          else
      {
        cout << "You dont have this amount available in your account " << endl;

      }

       }
}

void  current_acc :: min_balance()
{

    if (balance<500)
    {
        penalty = 10;

        balance=balance-penalty ;

        cout << "Balance after imposing the penalty is : " <<  balance << endl ;

    }

    else
    {
        cout << "You have minimum balance in your account . So, no penalty is imposed " << endl;

    }

}

void current_acc :: withdrawal1()
{
    int amount1,ch2;

    cout << "Do you want to withdraw any amount from your account " << endl;

    cout << "If yes then press 1 " << endl;
    cout << "If no press 0" << endl;

    cin >> ch2;

if(ch2==1)
{
    cout << "Enter the amount to be withdrawed " << endl;
    cin >> amount1;

    if(amount1<500)
    {
        cout << "Sorry you dont have enough minimum balnce " << endl;
       min_balance();
    }

    else if (balance<amount1)
    {
        cout << "You dont have this much balance in your account " << endl;
    }
    
    else 
    {
       cout << "After withdrawaing balance in your acccount wil be : " << endl;
       balance=balance-amount1;

       cout << balance << endl ;
    }

}


}

void current_acc :: chq_book()
{
    int cq;

    cout << "Do you want to get a cheque book \n If yess press 1 \n if no press 0 "<< endl;
    cin >> cq;

    if(cq==1)
    {
        cout << "Cheque book will be delivered at yyour home " << endl;

    }
     
}

int main()
{
    int ch,ch2,ch1;
    char ch3,ch4;

    saving_acc s;
    saving_acc *ptr=&s;  
    
     // saving_acc *ptr= new s     this new operator will assigns the address of memory space to the pointer 
     // saving_acc *ptr=new s[10]   this s[10] is an array of the object

    current_acc c;
    current_acc *ptr1=&c;

    cout << "Welcome to ABC bank " << endl;

    cout << "If you have a savings account then press 1 " << endl;
    cout << "If you have a current account press 2 " << endl;

    cin >> ch;

     switch(ch)
     {
         case 1 :      {
                          ptr -> input();
                      do{
                                        
                          
                          cout << " To display data :-1 " << endl;
                          cout << " To Deposit amount to your account :- 2 " << endl;
                          cout << " To know about your interest :-3 " << endl;
                          cout << " To check your updated balance :- 4 " << endl;
                          cout << " To withdraw any amount :- 5 " << endl;
                          cout << " To rate about our service :- 6 " << endl;
                          cout << " Enter your choice " << endl;
                          cin >> ch2;

                          switch(ch2)
                          {
                                case 1 : ptr -> display();
                                         break;

                                case 2 : ptr -> deposit();
                                         break;

                                case 3 : ptr -> compound_int();
                                         break;

                                case 4 : ptr -> update_bal();
                                         break;
               
                                case 5 : ptr -> withdrawal();
                                         break;

                                case 6 : ptr -> rating();
                                         break;

                                
                                default : cout << "You have entered wrong choice " << endl;
                                          break;

                            }

                     cout << "Do you want to continue if yes then press 'y' if not then press 'n' " << endl;

                     cin >> ch3;

                    }
                       while (ch3=='y');
                       
         } 
           break;
        
        case 2: {
                        (*ptr1).input();

                  do{

                          cout << " To display data :-1 " << endl;
                          cout << " To check the minimum balance  in your  account ;- 2" << endl;
                          cout << " To Deposit amount to your account :- 3 " << endl;
                          cout << " For cheque book related queries please enter :- 4" << endl;
                          cout << " To withdraw any amount from account :-5 " << endl;
                          cout << " To rate about our service :- 6 " << endl;
                          cout << " Enter your choice " << endl;
                           
                          cin >> ch1;

                             switch(ch1)
                             {

                                     case 1 :  (*ptr1).display();
                                               break;

                                    
                                     case 2 :  (*ptr1).min_balance();
                                               break;
                
                                     case 3 :  (*ptr1).deposit();
                                               break;

                                     case 4 :  (*ptr1).chq_book();
                                               break;

                                     case 5 :  (*ptr1).withdrawal1();
                                               break;

                                     case 6 :  (*ptr1).rating();
                                               break;

                                     default :  cout << "You have entered wrong choice kindly enter correct choice " << endl;
                                               break;
                             }

                             cout << "To continue press 'y' and to exit press 'n' " << endl;

                             cin >> ch4;

                    }
                       while(ch4=='y'); 
     } 
        break;

        default: cout << "You have entered wrong choice " << endl;
                break;


     }

     return 0;
}