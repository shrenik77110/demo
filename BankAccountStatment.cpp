/* Bank Account Transaction */

#include<iostream>
#include<string.h>

using namespace std;

class BankAccount
{
	public:
	int accno;
	char accname[20];
	double balance;
	
	void openAccount();
	void showAccount();	
};

	void BankAccount :: openAccount()
	{
		cout<<"\n Enter Account number :";
		cin>>accno;
		
		cout<<"\n Enter Account Name :";
		cin>>accname;
		
		cout<<"\n Enter Opening Balance :";
		cin>>balance;		
	}
	
	void BankAccount :: showAccount()
	{
		cout<<"\n Account Detais ....";
		cout<<"\n Account Number :"<<accno;
		cout<<"\n Account Name : "<<accname;
		cout<<"\n Balance = Rs."<<balance;
	}


class Log
{
	public:
	char transtype[20];	
	double amt;
	
	void createLog(char transtype[],double amt)
	{
		strcpy(this->transtype,transtype);
		this->amt = amt;
	}
};

int main()
{
	int choice;
	BankAccount acc1;
	double amt,total;
	Log log[10];
	int index=0;
	
	while(1)
	{
		

	cout<<"\n 1. Open Account";
	cout<<"\n 2. Show Account";
	cout<<"\n 3. Withdraw Amount";
	cout<<"\n 4. Depost Amount";
	cout<<"\n 5. Statement";
	cout<<"\n 6. Exit";
	
	cout<<"\n Enter Choice :";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			acc1.openAccount();
			cout<<"\n Account Opened Successfully";
			break;
		case 2:
			acc1.showAccount();
			break;
		case 3:
			cout<<"\n Enter amount to withdraw amount :";
			cin>>amt;
			
			if(acc1.balance>amt)
			{
				acc1.balance-=amt;
				cout<<"\n Amount Rs. "<<amt<<" debited from Account number "<<acc1.accno;
				log[index].createLog("debit",amt);
				index++;
			}
			else
			{
				cout<<"\n Less Balance....";
			}
			break;
		case 4:
			cout<<"\n Enter amount to withdraw amount :";
			cin>>amt;
			
			acc1.balance+=amt;
			cout<<"\n Amount Rs. "<<amt<<" credited from Account number "<<acc1.accno;
			
			log[index].createLog("credit",amt);
			index++;
			break;			
		case 5:
			cout<<"\n\n ________ Bank Account Statement ________";
			total=0.0;
			for(int i=0;i<index;i++)
			{
				cout<<"\n Rs."<<log[i].amt<<" "<<log[i].transtype;
				total=total+log[i].amt;
			}
			cout<<"\n ___________________________________________";
			cout<<"\n Total Transaction = "<<total;
			break;
		case 6:
			exit(0);
			
		default:
			cout<<"\n Invalid Choice..";
	}
	}
	
	
	return 0;
}
