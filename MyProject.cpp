#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
class management{
	
	protected:
		string temp,name, id, contact, subject, password;
		int  i=0, salary, fees, lectures;
		float marks, obtainmarks, percentage, sub1, sub2, sub3, sub4;
	public:
			string ids[6];
			management()
			{
				int j=0;
				ifstream op;
				op.open("Z:/AAAAAAA/sids.txt");
				while(getline(op, temp))
				{
					ids[i]=temp;
					j++;
				}
				op.close();
				name="Name";
				id="ID";
				contact="0313";
				marks=0.0;
				salary=5000;
				fees=2500;
			}
		 void nameid()
		{
			cout<<"Enter Your Name: ";
			cin>>name;
			cout<<"Enter Your ID: ";
			cin>>id;
		}
		virtual void setdata(){
		}
		virtual void getdata(){
		}
};

class admissions:public management{
	public:
		void setdata(void)
		{
			cout<<"Enter Your Name: ";
			cin>>name;
			cout<<"Enter discipline of subject: ";
			cin>>subject;
			cout<<"Provide Your Contact no: ";
			cin>>contact;
		}
		void getdata (void)
		{
			system("cls");
			cout<<name<<" you have submitted admission request successfully in "<<subject<<endl
			    <<"You will get notified with further information on text to "<<contact<<endl;
		}
};

class students:protected management{
	public:
		void setdata()
		{
			nameid();
			cout<<"Login with "<<name<<" "<<id<<endl;
			cout<<"Enter Marks of four subjects: ";
			cin>>sub1>>sub2>>sub3>>sub4;
			obtainmarks=sub1+sub2+sub3+sub4;
			percentage=obtainmarks/4;
		}

		void getdata (void)
		{
			
			if(percentage>=60 && percentage<80)
			{
				cout<<"Your monthly fee is 1600/-PKR"<<endl;
			}
			else if(percentage>=80) 
			{
				cout<<"Your monthly fee is 1000/-PKR"<<endl;
			}
			else
			{
				cout<<"Your monthly fee is 2500/-PKR"<<endl;
			}
	}
		
};

class teachers:public management{
	public:
		void setdata (void)
		{
			nameid();
			cout<<"Number of Your Daily Lectures: ";
			cin>>lectures;
			salary=lectures*26*750;
		}
		void getdata(void)
		{
			cout<<"Your Monthaly salary is ";
			if(lectures>3)
			{
				salary=salary+3000;
			}
			 cout<<salary<<endl;
		}		
};

class workers:public management{
	public:
		void setdata()
		{
			nameid();
			cout<<"Enter Your Daily Working Hours: ";
			cin>>lectures;
			salary=lectures*26*200;
	    }
	    void getdata()
	    {
			cout<<"Your Monthaly salary is ";
			if(lectures>9)
			{
				salary=salary+4000;
			}
			 cout<<salary<<endl;
		}
};

class menu:protected management,protected admissions,protected students,protected teachers,protected workers{
	private:
		int choice;
	public:
		management *ptr;
		admissions admobj;
		students stuobj;
		teachers teaobj;
		workers workobj;
		void choose(void)
		{
		do{
			cout<<"1.New Admissions\n2.Students portal\n3.Teachers Profile\n4.Worker Status\n5.EXIT";
		//	cout<<ids[1]<<" "<<ids[2]<<endl;
			cin>>choice;
				switch(choice)
				{
				case 1:
					{
						ptr=&admobj;
						break;
					}
				case 2:
					{
						ptr=&stuobj;
						break;
					}
				case 3:
					{
						ptr=&teaobj;
						break;
					}
				case 4:
				{
					ptr=&workobj;
					break;
				}
				case 5:
					{
						exit(1);
					}
				default:
					{
						cout<<"Invalid Input."<<endl;
					}
				}
		
			ptr->setdata();
			ptr->getdata();
		}
		while(getch()=='\r');
		}
		

};
main()
{  menu obj;
	obj.choose();
}                                      
			
