#include<iostream>
#include<fstream>
#include<string>
#include <locale.h>
#include <windows.h>
using namespace std;

string usn;
int tm;
void valid(string str)
{
    string dir,user;
    ifstream file;
    dir = str+".txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>usn;
        //file.close();
        valid(usn);
    }
}

void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}


int main()
{
	setlocale(LC_ALL, "portuguese");
    int choice,i,exit=0,op1,op2,op3,op4;
    string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    cout<<"-----------------------------------------------------\n";
    cout<<"---            Welcome to Exed Spoofer!           ---\n";
    cout<<"-----------------------------------------------------\n";
    while(exit==0)
    {
        cout<<"\nChoose one option:\n1. Login\n2. Register\n\npress any key and enter to exit\n";
        cin>>choice;
        if(choice==1)
        {
        	setcolor( 0x01 );
            cout<<"Enter your username:";
            cin>>usn;
            setcolor( 0x02 );
            cout<<"\nEnter your password:";
            cin>>psd;
            setcolor( 0x03 );
            system("cls");
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
            	setcolor( 0x04 );
            	cout<<"\nYou are successfully logged in:)";
            	setcolor( 0x04 );
                cout<<"\n\nWelcome to our spoofer!\n\n";
            	setcolor( 0x08 );
            	cout<<"\n----------------------------------";
            	setcolor( 0x08 );
                cout<<"\nYOUR PROFILE SAYS:                |\n";
                setcolor( 0x08 );
                cout<<"                                  |\n";
                setcolor( 0x08 );
                cout<<"Logged in as: "<<usern<<"                 |"<<endl;
                setcolor( 0x08 );
                cout<<"Name: "<<line<<"                     |"<<endl;
                setcolor( 0x08 );
                getline(filei,line);
                setcolor( 0x08 );
                cout<<"Bio: "<<line<<"                    |"<<endl;
                setcolor( 0x08 );
                cout<<"----------------------------------\n\n";
                setcolor( 0x03 );
                filei.close();
                setcolor( 0x06 );
                cout<<"1 - Spoof System & FiveM\n";
                setcolor( 0x05 );
                cout<<"2 - Discord :)\n";
                setcolor( 0x07 );
                cout<<"3 - About Us :)\n";
                setcolor( 0x08 );
                cout<<"\n\nSelect the option that that you want:\n\n";
                cin>>op1;
                setcolor( 0x09 );
				{
				
				if (op1==1){
				
                		setcolor( 0x00 );
                				cout<<"Spoofing..."<<endl;
                		setcolor( 0x01 );
                						MessageBox(NULL, "System Spoofed!", "ExedSpoofer.exe", MB_ICONINFORMATION);
                						MessageBox(NULL, "FiveM Spoofed!", "ExedSpoofer.exe", MB_ICONINFORMATION); }
                		setcolor( 0x03 );
    			if (op1==2){				 
                		setcolor( 0x04 );
                				cout<<"Discord: https://discord.gg/DBmEJwmHhm\n\n"<<endl;}
               	 		setcolor( 0x05 );
                if (op1==3){
                				cout<<"Done By fGs AKA Gonçalo Inacio 11ºI ESAC";}
            
		}
	}
            
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username:";
            cin>>usn;
            tm=0;
            valid(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password:";
            cin>>psd;
            fname=usn+".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered:)";
            cout<<"\nAdd to your bio and press enter when you are done:";
            cin.ignore();
            getline(cin,bio);
            fileo<<bio<<endl;
            cout<<"\nYour bio is saved as: "<<bio;
            fileo.close();
        }
        else
        {
            exit=1;
        }
    }
    cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
}
