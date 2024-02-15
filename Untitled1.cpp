//                                                    Libraires
#include<iostream>
#include<iomanip>
#include<cstring>
#include<time.h>
#include<fstream>
#include<windows.h>
using namespace std;
//                                                    Variables
int enter_pin;
char log[20];
struct accounter
{
    int save_pin;
    long double balance;
    string name;
    double loan;
    double refund;
};
double lone_limit=50000;
char value;
int chose_button;
int count=0;
int opt;
int opt2;
int dpos_money;
int limit=500000;
int slect_opt;
char cash_receipt;
int bill_opt;
int city_opt;
string bill_num;
string companyname;
string enter_id;
double tax=0.05;
accounter person;


time_t ct=time(0);
string Time=ctime(&ct);


//                                                fucntion Prototype

void menu();
void check_balance();
void cash_dpos();
void cheque();
void bill_pay();
void transfer();
void trans_history();
void fee();
void challan();
void my_pin();
void LOAN();
void ATM();
void delet();

//                                                   Main Body
int main(){
	system("color F9");
	cout<<"\t\t\t\t\t   POROGRAM IS LOADING\n";Sleep(600);
	for(int i=0;i<1680;i++)
		cout<<"*";Sleep(1);
	Sleep(300);
	cout<<"\n\t\t\t\t\t   JUST FEW SECOND MORE\n";
	Sleep(1699);
	for(int i=0;i<1680;i++)
		cout<<"*";Sleep(1);
	system("cls");
	cout<<"\n\n\t\t\t|======================================================================|\n";
    cout<<"\t\t\t|                   WELCOME  TO  BANK  OF  LAHORE                      |\n";
    cout<<"\t\t\t|======================================================================|\n\n\n\n";
    cout<<"\t|=====================================================|\n";
    cout<<"\t|   1.  OPEN A NEW ACCOUNT.                           |\n";
    cout<<"\t|   2.  ALREADY  HAVE  AN  ACCOUNT.                   |\n";
    cout<<"\t|=====================================================|\n";
    cout<<"\n\n\n\t|-------  SELECT  ANY  OPTION  -------|\n\t :  ";
    cin>>opt;
    cout<<endl<<endl;
    if(opt==1)
    {
        ofstream file1;
        file1.open("Account.bat");
        cout<<"\t\t|=================================================================|\n";
        cout<<"\t\t|                      ACCOUNT   CREATION                         |\n";
        cout<<"\t\t|=================================================================|\n\n\n\n";
        cout<<"\t\t|----> ENTER  YOUR  FULL  NAME  :  ";
        cin.ignore();
        getline(cin,person.name);
        cout<<"\n\n\t\t|----> CREATE    YOUR   LOGIN ( A*** ) :  ";
        cin.get(log,20);
        cout<<"\n\n\t\t|-------- CREAT  YOUR  [4]  DIGIT  PIN  (****)  :  ";
        cin>>person.save_pin;
        file1<<person.save_pin<<endl;
        cout<<"\n\n\t\t|------ ENTER  INITIAL  AMOUNT  DIPOSIT  IN  YOUR  ACCOUNT   :  ";
        cin>>person.balance;
        file1<<person.balance;
        file1<<person.name<<endl;
        file1<<log<<endl;
        cout<<"\n\n\n|===================-_-_-_-_-_-_-_-A C C O U N T  H A S  B E E N  C R E A T E D-_-_-_-_-_-_-_-==================|\n\n\n";
        file1.close();
        ofstream fa;
        fa.open("transaction.txt",ios ::out);
        fa.close();
        cout<<"\n\t\t|---- PRESS  [0]  TO  LOGIN  OR  [1]  TO  EXIT  :  ";
        cin>>opt2;
    }
    if(opt2 == 1)
        return 0;
    else if (opt2==0||opt==2)
    {
        cout<<"\n\n\t\t|----  ENTER  YOUR  LOGIN  ID (A***)----| : ";
        cin.ignore();
        cin.get(log,20);
        fstream file ("Account.bat",ios :: in);
        file.seekg(5,ios :: beg);
        file>>person.balance;
        getline(file,person.name);
        getline(file,enter_id);
        if(log==enter_id)

        {
 			Sleep(600);
            while(count<3)
            {
                cout<<"\n\n\t\t|---- ENTER  YOUR  [4]  DIGIT  PIN ----| : ";
                cin>>enter_pin;
                ifstream file2;
                file2.open("Account.bat");
                file2>>person.save_pin;
                if(enter_pin==person.save_pin){
                    system("cls");
					Sleep(2000);
                        cout<<"                                               HELLO,   "<<person.name<<endl<<endl;
                        Sleep(3000);

                    for(value='y'||'Y';;)
                    {
                        menu();
                        cout<<"\n\n\n\t\t\t|----------------- SELECT  ANY  OPTION -------------------| :  ";
                        cin>>chose_button;
                        switch(chose_button)
                        {
                        case 1:
                            check_balance();
                            break;
                        case 2 :
                            cash_dpos();
                            break;
                        case 3 :
                            cheque();
                            break;
                        case 4 :
                            bill_pay();
                            break;
                        case 5:
                            transfer();
                            break;
                        case 6:
                            trans_history();
                            break;
                        case 7:
                            fee();
                            break;
                        case 8:
                            challan();
                            break;
                        case 9:
                            my_pin();
                            break;
                        case 10:
                            LOAN();
                            break;
                        case 11:
                            ATM();
                            break;
                        case 12:
                            delet();
                            return 0;
                            break;
                        default:
                        
                            cout<<"\n\n\t\t|-------- WORNG  OPTION SELECT ! -------|";
                        }
                        cout<<"\n\n\t\t\t|---- THANKS  FOR  CHOOSING  OUR  SERVICE. ----|";
                        Sleep(2000);
                        cout<<"\n\n\n\t\t|---- PRESS (Y/y) TO GO  TO  MAINMENU  OR  (E/e) TO EXIT .....   :  ";
                        cin>>value;
                        system("cls");
                        if(value == 'E'|| value == 'e' || !cin)
                        {
                            return 0;
                        }
                    }
                }
                 else
                {
                    cout<<endl<<endl<<endl;
                    cout<<"\n\n\n\t\t|-------- ENTER   WORNG    PIN ! -------|\n\n\n";
                    count++;
                }
            }
            }
        else
            cout<<"\n\n\n\t\t|------- ACCOUNT   DOES-NOT   EXISTS ! ---------|";
    return 0;
}
}

//                                           Function 

void menu()
{
    cout<<"|============================================  HOW  CAN  I  HELP  YOU   ===============================================|"<<endl;
    cout<<"| 1.     BALANCE INQUIRY                                                            2.    CASH DEPOSIT                 |";
    cout<<endl<<endl;
    cout<<"| 3.     CASH A CHEQUE                                                              4.    UTILITY BILL PAYMENT         |";
    cout<<endl<<endl;
    cout<<"| 5.     TRANSFER MONEY                                                             6.    TRANSACTION HISTORY          |";
    cout<<endl<<endl;
    cout<<"| 7.     FEE_CHALLAN                                                                8.    TRAFFIC_CHALLAN              |";
    cout<<endl<<endl;
    cout<<"| 9.     CHANGE MY PIN                                                             10.    LONE_OFFERS                  |";
    cout<<endl<<endl;
    cout<<" 11.     ATM MECHINE                                                               12.    DELETE  ACCOUNT              |";
    cout<<endl;
    cout<<"|======================================================================================================================|";
}

void check_balance()
{
    fstream file ("account.txt",ios :: in);
    file.seekg(5,ios :: beg);
    file>>person.balance;
    file.seekg(0);
    file.close();
    cout<<endl<<endl;
     Sleep(1000);
     cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
//here i used fixed because the largest value is not save in oringial form
     cout<<fixed;
    cout<<"\n\n\t\t|-----YOUR  CURRENT  BALANCE  IS  = "<<person.balance<<" Rs-----|";
	cout<<endl<<endl;
}

void cash_dpos()
{
	cout<<"\n\n\t\t|---YOU CANNOT  DEPOSIT  MORE  THAN  50000 Rs  AT  ONE  TIME.---|\n\n\n" ;
    cout<<"\n\t\t|---ENTER  AMOUNT  IN  NUMBERS  YOU  WANT  TO  DEPOSIT  :  ";
    cin>>dpos_money;
    if(dpos_money>=limit)
        cout<<"\n\n\t\t|---YOU CANNOT  DEPOSIT  MORE  THAN  50000 Rs  AT  ONE  TIME.---|\n\n\n" ;
	    else if(dpos_money<=limit)
		{
	    	Sleep(200);
	    	cout<<"|-----ENTER  YOUR  PIN  TO  PROCEED : ";
	    	cin>>enter_pin;
	   	   	if(enter_pin==person.save_pin)
	   		{
	        	person.balance=person.balance+dpos_money;
	        	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
		        cout<<"\n\n\t\tAmount  Has been Deposited to your Account...\n\n";
		        ofstream f;
		        f.open("Account.bat",ios ::out);
		        f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
		        f.close();
		        ifstream file1 ("Account.bat",ios :: in);
		        file1.seekg(5,ios :: beg);
		        file1>>person.balance;
		        file1.seekg(0);
		        file1.close();
		        cout<<endl<<endl<<endl;
		        Sleep(1000);
		        cout<<"\t\t|----YOUR  CURRENT  BALANCE  IS  = "<< person.balance<< " Rs----|\n\n";
		        fstream fa;
		        fa.open("transaction.txt",ios ::out|ios:: app);
		        fa<<endl<<endl;
		        fa<<"AMOUNT DEPOSIT ";
		        fa<<"\t\t\t\t            "<<dpos_money<<endl;
		        fa<<" TIME ";
		        fa<<"\t\t\t\t            "<<Time<<endl;
		        fa.close();
		    }
		}
    else
        cout<<"\n\t\t|-----WRONG  PIN  HAS  BEEN  ENTERED.-----|\n";
}

void cheque()
{
    cout<<"\n\t\t|--- ENTER  AMOUNT  IN  NUMBERS  YOU  WANT  TO  WITHDRAW ---| :  ";
    cin>>dpos_money;
    cout<<endl<<endl;
    if(dpos_money>limit)
		cout<<"\t\t|---YOU CANNOT  WITH  DRAW  MORE  THAN  50000 Rs---|\n";
	if(dpos_money>person.balance)
        cout<<"\n\n\t\t|---SORRY ! YOUR   BALANCE  IS  LOWER   THAN  "<<dpos_money<<" Rs";
    else
    {
 Sleep(200);
        cout<<"\n\t\t|------ENTER  YOUR  PIN  : ";
        cin>>enter_pin;
        if(enter_pin==person.save_pin)
        {
        	Sleep(1000);
    cout<<"\t____________________________________________________________________________\n";
    cout<<"\t|CHEQUE                                                                     |\n";
    cout<<"\t|                          BANK  OF LAHORE                                  |\n";
    cout<<"\t|PAY TO THE ODER OF : "<<setw(20)<<person.name<<"                                  |\n";
    cout<<"\t|RUPEES :              |"<<setw(5)<<dpos_money<<"|                                              |\n";
    cout<<"\t| PAK701AD33984600                          PIN : "<<setw(6)<<enter_pin<<"                    |\n";
    cout<<"\t|___________________________________________________________________________|\n";
    		cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|----YOUR   CASH   HAS   BEEN   WITH-DRAW  .....|\n\n";
            person.balance=person.balance-dpos_money;
            cout<<endl;
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<endl<<endl<<endl;
            Sleep(600);
               cout<<"\t\t|----YOUR  CURRENT  BALANCE  IS  = "<< person.balance<< " Rs----|\n\n";
		        fstream fa;
		        fa.open("transaction.txt",ios ::out|ios:: app);
		        fa<<endl<<endl;
		        fa<<"AMOUNT DEPOSIT ";
		        fa<<"\t\t\t\t            "<<dpos_money<<endl;
		        fa<<" TIME ";
		        fa<<"\t\t\t\t            "<<Time<<endl;
		        fa.close();
		    }
        else
        	cout<<"\n\n\t\t|-----WRONG  PIN  HAS  BEEN  ENTERED.-----|\n";
		}
    }

void bill_pay()
{
    cout<<endl<<endl;
    cout<<"|===========================================================================================================|\n";
    cout<<"|   1.   WATER & SEVERAGE                                                             2.    GAS             |\n";
    cout<<endl<<endl;
    cout<<"|   3.   INTERNET BILLING                                                             4.    ELECTRICITY     |\n";
    cout<<"|===========================================================================================================|\n";
    cout<<endl<<endl;
    cout<<"\t\tSELECT  ANY  OPTION  :  ";
    cin>>bill_opt;
    switch(bill_opt)
    {
    	case 1:
    	{
	        cout<<endl;
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"|   1.   Lahore [WASA]                                                     2.    PESHAWAR [WSSP]     |\n";
	        cout<<endl<<endl;
	        cout<<"|   3.   MULTAN [WASA]                                                     4.    Rawlpndi [WASA]     |\n";
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"\n\n\t\t|----SELECT  YOUR  CITY  : ";
	        cin>>city_opt;
	        if(city_opt<5)
	        {
	        	cout<<"\n\t\t|----ENTER  BILL  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER   BILL  AMOUNT.... :  ";
	        	cin>>dpos_money;
	        		if(city_opt==1)
	            	companyname="Lahore [WASA]";
		        	else if(city_opt==2)
		            companyname="PESHAWAR [WSSP]";
		        	else   if(city_opt== 3)
		            companyname="MULTAN [WASA]";
		        	else  if(city_opt== 4)
		            companyname="Rawlpndi [WASA]";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                WATER   BILLING "<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  BILL    NUMBER                                                "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|  CITY  &  COMPANY  NAME                                        "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- WRONG   NUMBER   ENTER---------------------|\n\n";
    	}
		break;
	    case 2:
	    {
	        cout<<endl;
	        cout<<"|****************************************************************|\n";
	        cout<<" 1.   SUI SOUTHERN GAS COMPANY\n 2.    SUI NORTHERN GAS COMPANY\n";
		    cout<<"|****************************************************************|\n";        
			cout<<endl<<endl;
	        cout<<"\t\t|---SELECT   YOUR   COMPANY   NO....| : ";
	        cin>>city_opt;
	        if(city_opt<3){
		        cout<<"\n\t\t|--- ENTER   BILL  REFR-NUMBER  (A129*****)  : ";
		        cin.ignore();
			    getline(cin,bill_num);
			    cout<<"\n\t\t|---ENTER   BILL  AMOUNT.... :  ";
			    cin>>dpos_money;
			        if(city_opt==1)
			            companyname="SUI SOUTHERN GAS COMPANY";
				    else if(city_opt==2)
				        companyname="SUI NORTHERN GAS COMPANY";
		 		Sleep(500);
		        cout<<endl;
		        cout<<endl;
		        cout<<"|**********************************************************************************|"<<endl;
		        cout<<"|                                   GAS  BILLING "<<endl;
		        cout<<"|  ACCOUNT  HOLDER  NAME                                    "<<person.name<<endl<<endl;
		        cout<<"|  BILL   NUMBER                                            "<<bill_num<<endl<<endl;
		        cout<<"|  AMOUNT   OF   BILL                                       "<<dpos_money<<endl<<endl;
		        cout<<"|  COMPANY   NAME                                           "<<companyname<<endl<<endl;
		        cout<<"|**********************************************************************************|"<<endl;
		        cout<<endl;
		    }
	    	else
	    		cout<<"\n\t\t|--------------- WRONG   NUMBER   ENTER---------------------|\n\n";
	    }
	    break;	
	    case 3:
	    {
	        cout<<endl;
		    cout<<"|****************************************************************|\n";
		    cout<<" 1.   PAKISTAN TELECOMMUNACITION COMPANY\n 2.    STORM-FIBER\n";
			cout<<"|****************************************************************|\n";    
			cout<<endl<<endl;
		        cout<<"\t\t|---SELECT   YOUR   COMPANY   NO....| : ";
				cin>>city_opt;
		    if(city_opt<3){
			    cout<<"\n\t\t|--- ENTER   BILL  REFR-NUMBER  (042*****)  : ";
			    cin.ignore();
				getline(cin,bill_num);
				cout<<"\n\t\t|---ENTER   BILL  AMOUNT.... :  ";
				cin>>dpos_money;
				    if(city_opt==1)
				    	companyname="PAKISTAN TELECOMMUNACITION COMPANY";
					else if(city_opt==2)
					    companyname="STORM-FIBER";    
		        cout<<endl<<endl;
		        Sleep(500);
		        cout<<"|**********************************************************************************|"<<endl;
		        cout<<"|                                   INTERNET   BILLING "<<endl<<endl;
		        cout<<"|  ACCOUNT   HOLDER   NAME                                   "<<person.name<<endl<<endl;
		        cout<<"|  BILL   NUMBER                                             "<<bill_num<<endl<<endl;
		        cout<<"|  AMOUNT   OF   BILL                                        "<<dpos_money<<endl<<endl;
		        cout<<"|  COMPANY   NAME                                            "<<companyname<<endl<<endl;
		        cout<<"|**********************************************************************************|"<<endl;
		        cout<<endl;
	    	}
	        else
	        cout<<"\n\t\t|--------------- WRONG   NUMBER   ENTER---------------------|\n\n";
		}
		break;
    case 4:
    {
    	cout<<endl;
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"|   1.   Lahore [ESC]                                                     2.    KARACHI [ESC]        |\n";
	        cout<<endl<<endl;
	        cout<<"|   3.   GUJRANWALA [EPC]                                                 4.    FAISALABAD [EPC]     |\n";
	        cout<<"|****************************************************************************************************|\n";
	    cout<<"\t\t|---SELECT   YOUR   COMPANY   NO....| : ";
	    cin>>city_opt;
		if(city_opt<5)
	        {
	        	cout<<"\n\t\t|----ENTER  BILL  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER   BILL  AMOUNT.... :  ";
				cin>>dpos_money;
	        		if(city_opt==1)
	            	companyname="Lahore [ESC]";
		        	else if(city_opt==2)
		            companyname="KARACHI [ESC]";
		        	else   if(city_opt== 3)
		            companyname="GUJRANWALA [EPC]";
		        	else  if(city_opt== 4)
		            companyname="FAISALABAD [EPC]";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                              ELELCTRICITY   BILLING "<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  BILL    NUMBER                                                "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|  CITY  &  COMPANY  NAME                                        "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- WRONG   NUMBER   ENTER---------------------|\n\n";
    	}
		break;		                
	default:
        cout<<"\n\t\t|---------------- WRONG  OPTION ENTER --------------------|\n";
    }
    cout<<"\n\t\t|--- ENTER   YOUR   PIN   TO   PROCEED---|  : ";
    cin>>enter_pin;
    if(enter_pin==person.save_pin)
    {
        if(dpos_money>person.balance)
            cout<<"\n\n\t|--- SORRY ! YOUR   BALANCE  IS  LOWER   THAN  "<<dpos_money<<" Rs ---|\n\n";
        else
        {
			Sleep(500);
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|---- YOUR BILL HAS BEEN PAID ....|\n\n";
            person.balance=person.balance-dpos_money;
            cout<<endl;
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<endl;
        	Sleep(500);
            cout<<"\n\t\t|--- YOUR  CURRENT  BALANCE  IS  =  "<< person.balance<<" Rs ---|\n\n";
            ofstream fa;
            fa.open("transaction.txt",ios ::out|ios:: app);
            fa<<endl<<endl;
            fa<<" BILL PAYMENT "<<companyname;
            fa<<"\t\t\t\t     "<<dpos_money<<endl;
            fa<<" Time ";
            fa<<"\t\t\t\t       "<<Time<<endl;
            fa.close();
        }
    }
    else
        cout<<"\n\n\t\t|--- WRONG  PIN  HAS  BEEN   ENTERED ! ---|\n\n";
}

void transfer()
{
	cout<<endl;
	cout<<"|****************************************************************************************************|\n";
	cout<<"|                                [5 % TAX WILL CUT FORM YOUR BALANCE]                                |\n";
	cout<<"|   1.   ALLIED BANK                                                     2.    BANK OF AL HABIB      |\n";
	cout<<endl<<endl;
	cout<<"|   3.   HBL BANK                                                        4.    MCB BANK              |\n";
	cout<<"|                                         5.  TO ANOTHER ACCOUNT                                     |\n";
	cout<<"|****************************************************************************************************|\n";
    cout<<"\n\n\t\t|--- SELECT  BANK  TO  TRANSFER MONEY ---|  : ";
    cin>>city_opt;
    if(city_opt<6)
{
	cout<<"\n\n\t\t|--- PLZ  ENTER  14  DIGIT  ACCOUNT  NUMBER  (0604323235676..)  ......  :  ";
    cin.ignore();
    getline(cin,bill_num);
	if(city_opt==1)
	companyname="ALLIED BANK";
	else if(city_opt==2)
	companyname="BANK OF AL HABIB";
	else   if(city_opt== 3)
	companyname="HBL BANK";
	else  if(city_opt== 4)
	companyname="MCB BANK";
	else if(city_opt==5)
	companyname="TO ANOTHER ACCOUNT";
    cout<<"\n\t|--- ENTER   AMOUNT   TRANSFER  TO  BANK ....  : ";
	cin>>dpos_money;
    cout<<endl<<endl;
    Sleep(500);
    cout<<"|**********************************************************************************|"<<endl;
    cout<<"|  ACCOUNT  HOLDER  NAME                                     "<<person.name<<endl<<endl;
    cout<<"|  AMOUNT[NUMBER]   TRANSFER  TO                             "<<bill_num<<endl<<endl;
    cout<<"|  AMOUNT                                                    "<<dpos_money<<endl<<endl;
    cout<<"|         TAX                                                "<<tax<<endl<<endl;
    cout<<"|  TRANSFER  TO  [BANK]                                      "<<companyname<<endl<<endl;
    cout<<"|**********************************************************************************|"<<endl;
    dpos_money=dpos_money+(dpos_money*tax);
    cout<<"\n\t\t|--- ENTER   YOUR   PIN   TO   PROCEED---|  : ";
	cin>>enter_pin;
    if(enter_pin==person.save_pin)
    {
        if(dpos_money>person.balance)
            cout<<"\n\n\t\t|--- SORRY ! YOUR   BALANCE  IS  LOWER   THAN  "<<dpos_money<<" Rs ---|\n\n";
        else
        {
        	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|------ YOUR  AMOUNT  HAS  BEEN  TRANSFER ...\n\n";
            person.balance=person.balance-dpos_money;
            cout<<endl;
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<"\n\n\n\t\t|----- YOUR  CURRENT  BALANCE  IS  :    "<< person.balance<< " Rs -----|";
            cout<<endl<<endl;
            ofstream fa;
            fa.open("transaction.txt",ios ::out|ios:: app);
            fa<<endl<<endl;
            fa<<"FUNDS TRANSFER TO "<<companyname;
            fa<<"\t\t\t\t              "<<dpos_money<<endl;
            fa<<" Time";
            fa<<"\t\t\t\t              "<<Time<<endl<<endl;
        	fa<<"Account number         "<<bill_num<<endl;
            fa.close();
        }
    }
    else
        cout<<"\n\n\t\t|--- WRONG  PIN  HAS  BEEN   ENTERED ! ---|\n\n";
	}
	
}

void trans_history()
{
	cout<<"\n\t|--------------------- TRANSCESTION DETAILES ------------------------|";
    cout<<endl;
    cout<<"  TRANSECTION \t\t\t\t\t\t      Amount";
    cout<<endl;
 	Sleep(900);
    ifstream fin;
    char read;
    fin.open("transaction.txt");
    if(fin)
    {
        while(fin.eof()==0)
        {
            fin.get(read);
            cout<<read;
        }
    }
    else
        cout<<"\t\t\t[error opening in file.]";
    fin.close();
}

void fee()
{ 
    cout<<endl<<endl;
    cout<<"|===========================================================================================================|\n";
    cout<<"|   1.   SCHOOL                                                             2.    COLLAGE                   |\n";
    cout<<endl<<endl;
    cout<<"|                                            3.UNIVERSITY                                                   |\n";
    cout<<"|===========================================================================================================|\n";
    cout<<endl<<endl;
    cout<<"\t\tSELECT  YOUR   INSITUTE  :  ";
	cin>>bill_opt;
    switch(bill_opt)
    {
    	case 1:
    	{
	        cout<<endl;
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"|   1.   GOVERNMENT                                                  2.    PRIVATE                   |\n";
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"\n\n\t\t|----SELECT  YOUR  SECTOR  : ";
	        cin>>city_opt;
	        if(city_opt<3)
	        {
	        	cout<<"\n\t\t|----ENTER  VOUCHER  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER    AMOUNT.... :  ";
				cin>>dpos_money;
	        		if(city_opt==1)
	            	companyname="GOVERNMENT";
		        	else if(city_opt==2)
		            companyname="PRIVATE";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                               SCHOOL  FEE  VOUCHER"<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  VOUCHER    NUMBER                                             "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|       SECTOR                                                   "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- WRONG   SECTOR   ENTER---------------------|\n\n";
    	}
		break;
	    case 2:
	    {
	        cout<<endl;
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"|   1.   GOVERNMENT                                                  2.    PRIVATE                   |\n";
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"\n\n\t\t|----SELECT  YOUR  SECTOR  : ";
			cin>>city_opt;
	        if(city_opt<3)
	        {
	        	cout<<"\n\t\t|----ENTER  VOUCHER  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER    AMOUNT.... :  ";
	        	cin>>dpos_money;
	        		if(city_opt==1)
	            	companyname="GOVERNMENT";
		        	else if(city_opt==2)
		            companyname="PRIVATE";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                COLLAGE  FEE  VOUCHER"<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  VOUCHER    NUMBER                                             "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|       SECTOR                                                   "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- WRONG   SECTOR   ENTER---------------------|\n\n";
    	}
		break;	
	    case 3:
	    {
	        cout<<endl;
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"|   1.   GOVERNMENT                                                  2.    PRIVATE                   |\n";
	        cout<<"|****************************************************************************************************|\n";
	        cout<<"\n\n\t\t|----SELECT  YOUR  SECTOR  : ";
	        cin>>city_opt;
	        if(city_opt<3)
	        {
	        	cout<<"\n\t\t|----ENTER  VOUCHER  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER    AMOUNT.... :  ";
				cin>>dpos_money;
	        		if(city_opt==1)
	            	companyname="GOVERNMENT";
		        	else if(city_opt==2)
		            companyname="PRIVATE";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                UNIVERSITY  FEE  VOUCHER "<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  VOUCHER    NUMBER                                             "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|       SECTOR                                                   "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- WRONG   SECTOR   ENTER---------------------|\n\n";
    	}
		break;		                
	default:
        cout<<"\n\t\t|---------------- WRONG  OPTION ENTER --------------------|\n";
    }
    cout<<"\n\t\t|--- ENTER   YOUR   PIN   TO   PROCEED---|  : ";
    cin>>enter_pin;
    if(enter_pin==person.save_pin)
    {
        if(dpos_money>person.balance)
            cout<<"\n\n\t|--- SORRY ! YOUR   BALANCE  IS  LOWER   THAN  "<<dpos_money<<" Rs ---|\n\n";
        else
        {
			Sleep(500);
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|---- YOUR BILL HAS BEEN PAID ....|\n\n";
            person.balance=person.balance-dpos_money;
            cout<<endl;
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<endl;
        	Sleep(500);
            cout<<"\n\t\t|--- YOUR  CURRENT  BALANCE  IS  =  "<< person.balance<<" Rs ---|\n\n";
            ofstream fa;
            fa.open("transaction.txt",ios ::out|ios:: app);
            fa<<endl<<endl;
            fa<<" BILL PAYMENT "<<companyname;
            fa<<"\t\t\t\t     "<<dpos_money<<endl;
            fa<<" Time ";
            fa<<"\t\t\t\t        "<<Time<<endl;
            fa.close();
        }
    }
    else
        cout<<"\n\n\t\t|--- WRONG  PIN  HAS  BEEN   ENTERED ! ---|\n\n";
}

void challan()
{ 
    cout<<endl<<endl;
    cout<<"|===========================================================================================================|\n";
    cout<<"|                                             TRAFIC_CHALLAN                                                |\n";
    cout<<"|  1. E_CHALLAN                                                               2.  REGULAR_CHALLAN           |\n";
    cout<<"|===========================================================================================================|\n";
    cout<<endl<<endl;
    cout<<"\t\tSELECT  YOUR   INSITUTE  :  ";
    cin>>bill_opt;
    switch(bill_opt)
    {
    	case 1:
    	{
	        cout<<endl;
	        	cout<<"\n\t\t|----ENTER  CHALLAN  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER    AMOUNT.... :  ";
				cin>>dpos_money;
	            	companyname="E_CHALLAN";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                  TRAFIC_CHALLAN"<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  CHALLAN    NUMBER                                             "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|  CHALLAN  YYPE                                                 "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
		break;
	    case 2:
	    {
	        cout<<endl;
	        	cout<<"\n\t\t|----ENTER  CHALLAN  REFR-NUMBER (B0231****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	cout<<"\n\t\t|---ENTER    AMOUNT.... :  ";
				cin>>dpos_money;
	            	companyname="REGULAR";
	 				Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                  TRAFIC_CHALLAN"<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|  CHALLAN    NUMBER                                             "<<bill_num<<endl<<endl;
			        cout<<"|  AMOUNT  OF  BILL                                              "<<dpos_money<<endl<<endl;
			        cout<<"|  CHALLAN  YYPE                                                 "<<companyname<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	    }
		break;		                
	default:
        cout<<"\n\t\t|---------------- WRONG  OPTION ENTER --------------------|\n";
    }
    cout<<"\n\t\t|--- ENTER   YOUR   PIN   TO   PROCEED---|  : ";
	cin>>enter_pin;
    if(enter_pin==person.save_pin)
    {
        if(dpos_money>person.balance)
            cout<<"\n\n\t|--- SORRY ! YOUR   BALANCE  IS  LOWER   THAN  "<<dpos_money<<" Rs ---|\n\n";
        else
        {
			Sleep(500);
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|---- YOUR BILL HAS BEEN PAID ....|\n\n";
            person.balance=person.balance-dpos_money;
            cout<<endl;
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<endl;
        	Sleep(500);
            cout<<"\n\t\t|--- YOUR  CURRENT  BALANCE  IS  =  "<< person.balance<<" Rs ---|\n\n";
            ofstream fa;
            fa.open("transaction.txt",ios ::out|ios:: app);
            fa<<endl<<endl;
            fa<<" BILL PAYMENT "<<companyname;
            fa<<"\t\t\t\t     "<<dpos_money<<endl;
            fa<<" Time ";
            fa<<"\t\t\t\t      "<<Time<<endl;
            fa.close();
        }
    }
    else
        cout<<"\n\n\t\t|--- WRONG  PIN  HAS  BEEN   ENTERED ! ---|\n\n";
}

void my_pin()
{
    cout<<endl;
    cout<<"\t\t*****|--ENTER  YOUR  PREVIOUS  PIN--|*****\n\t\t\t\t\t";
	cin>>enter_pin;
    if(enter_pin==person.save_pin)
    {
        cout<<endl;
        cout<<endl<<endl;
        cout<<"\t\t*****|--CREATE  NEW   [4]  DIGIT   PIN--|*****\n\t\t\t\t\t";
        cin>>person.save_pin;
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
        cout<<"\n\n\t\t*****|--PIN  HAS  BEEN  UPDATED--|*****\n\t\t\t\t\t";
        cout<<endl;
        ofstream f;
        f.open("data.txt",ios ::out);
        f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
        f.close();
    }
    else
        cout<<endl<<endl<<"\t\t*****|--PIN  DOES  NOT  MATCHED--|*****\n ";
}

void LOAN()
{ 
    cout<<endl<<endl;
    cout<<"|===========================================================================================================|\n";
    cout<<"|   1.   NEED  A  LOAN                                                                                      |\n";
    cout<<"|                                                                      2.  REFUND A LOAN                    |\n";
    cout<<"|===========================================================================================================|\n";
    cout<<endl<<endl;
    cout<<"\t\tSELECT  YOUR   NEED  :  ";
	cin>>bill_opt;
    switch(bill_opt)
    {
    	case 1:
    	{
    		cout<<endl<<endl;
    		cout<<"|=============================================================================|\n";
    		cout<<"|          YOU HAVE TO PAY [5%] TAX                                           |\n";
    		cout<<"|                                   WHEN YOU RETURN THE AMOUNT                |\n";
    		cout<<"|=============================================================================|\n";
   	 		cout<<endl<<endl;
    		cout<<"\n\n\t\t|--- LONE LIMIT IS 50000 Rs ONLY -----|\n\n";
	        cout<<"\n\n\t\t|---- ENTER  YOUR  REQUIRD  AMOUNT  : ";
	        cin>>person.loan;
	        if(person.loan<=lone_limit)
	        {
	        	cout<<"\n\t\t|----ENTER  PHONE_NUMBER (0300****)-----| : ";
	        	getline(cin,bill_num);
	        	person.balance=person.balance+person.loan;
					Sleep(500);
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                  LONE OFFERS"<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|    PHONE  NUMBER                                               "<<bill_num<<endl<<endl;
			        cout<<"|    NEED   AMOUNT                                               "<<person.loan<<endl<<endl;
			        cout<<"|  YOUR  BALANCE  IS                                             "<<person.balance<<" Rs"<<endl;
			        cout<<"|        TIME                                                    "<<Time<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- INVILAD AMOUNT ENTER ---------------------|\n\n";
    	}
		break;
	    case 2:
	    {
	    	cout<<"\n\t\t|----- YOU GET A LOAN  : "<<person.loan<<endl;
	    	cout<<"\n\t\t|----- ACCORDING TO BANK POLICIES [5] TAX IN ADDED ON AMOUNT----|\n";
	    	person.loan=person.loan+(person.loan*tax);
	        cout<<endl;
	        cout<<"\n\n\t\t|--- SIR YOU HAVE TO PAY --------  : "<<person.loan<<endl<<endl;
	        cout<<"\t\t\t\t|--- SIR PLEASE ENTER EXACT AMOUNT ---|\n\n";
	        cout<<"\n\n\t\t|---- ENTER  YOUR  AMOUNT  : ";
			cin>>person.refund;	        
	        if(person.refund=person.loan)
	        {	
	        	cout<<"\n\t\t|----ENTER  PHONE_NUMBER (0300****)-----| : ";
	        	cin.ignore();
	        	getline(cin,bill_num);
	        	person.balance=person.balance-person.refund;
			        cout<<endl<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<"|                                LONE  REFUND"<<endl;
			        cout<<"|  ACCOUNT HOLDER  NAME                                          "<<person.name<<endl<<endl;
			        cout<<"|    PHONE  NUMBER                                               "<<bill_num<<endl<<endl;
			        cout<<"|          TAX                                                   "<<tax<<endl<<endl;
			        cout<<"|    AMOUNT +   TAX                                              "<<person.loan<<endl<<endl;
			        cout<<"|    AMOUNT  RETURN                                              "<<person.refund<<endl<<endl;
			        cout<<"|  YOUR  BALANCE  IS                                             "<<person.balance<<" Rs"<<endl;
			        cout<<"|        TIME                                                    "<<Time<<endl;
			        cout<<"|**********************************************************************************|"<<endl;
			        cout<<endl;
	        }
	        else
	       		cout<<"\n\t\t|--------------- AMOUNT YOU ENTER IS NOT CORRECT ---------------------|\n\n";
    	}
		break;		                
	default:
        cout<<"\n\t\t|---------------- WRONG  OPTION ENTER --------------------|\n";
    }
    cout<<"\n\t\t|--- ENTER   YOUR   PIN   TO   PROCEED---|  : ";
	cin>>enter_pin;
    if(enter_pin==person.save_pin)
    {
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<person.loan<<endl<<person.refund<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<endl;
        	Sleep(500);
            cout<<"\n\t\t|--- YOUR  CURRENT  BALANCE  IS  =  "<< person.balance<<" Rs ---|\n\n";
            ofstream fa;
            fa.open("transaction.txt",ios ::out|ios:: app);
            fa<<endl<<endl;
            fa<<" LAON ";
            fa<<"\t\t\t\t     "<<person.loan<<endl;
            fa<<" REFUND ";
            fa<<"\t\t\t\t     "<<person.refund<<endl;
            fa<<" Time ";
            fa<<"\t\t\t\t      "<<Time<<endl;
            fa.close();
        }
    else
        cout<<"\n\n\t\t|--- WRONG  PIN  HAS  BEEN   ENTERED ! ---|\n\n";
}

void ATM()
{
    cout<<endl<<endl;
    cout<<"|==========================================     A  T  M     ================================================|\n";
    cout<<"|     1.     10,000.                                                                    2.    8000          |\n";
    cout<<endl<<endl;
    cout<<"|     3.     5000.                                                                      4.    2000          |\n";
    cout<<endl<<endl;
    cout<<"|     5.     1000.                                                                      6.    500           |\n";
    cout<<"|===========================================================================================================|\n";
    cout<<endl<<endl;
    cout<<"\t\tSELECT  ANY  OPTION  :  ";
	cin>>slect_opt;
    switch(slect_opt)
    {
    case 1:
        dpos_money=10000;
        break;
    case 2 :
        dpos_money=5000;
        break;

    case 3 :
        dpos_money=2000;
        break;
    case 4:
        dpos_money=1000;
        break;
    case 5 :
        dpos_money=1500;
        break;
    case 6 :
        dpos_money=500;
        break;
    default:
                cout<<"\n\n\t\t\t|-------W R O N G  O P T I O N !-------|\n\n";
    }
    if(dpos_money>limit)
        cout<<"\t\t|---YOU CANNOT  WITH  DRAW  MORE  THAN  50000 Rs---|\n";

    if(dpos_money>person.balance)
        cout<<"\n\n\t\t|---SORRY ! YOUR   BALANCE  IS  LOWER   THAN  "<<dpos_money<<" Rs";
    else
    {
 Sleep(200);
        cout<<"\n\t\n\t|------ENTER  YOUR  PIN  : ";
		cin>>enter_pin;
        if(enter_pin==person.save_pin)
        {
            cout<<"\n\t\t|---Press  YES(Y/y) OR  NO(N/n)  FOR  CASH  RECEIPT  : ";
            cin>>cash_receipt;
            if(cash_receipt=='Y'||cash_receipt=='y')
            {
 																Sleep(800);
                cout<<endl<<endl;
                cout<<"                           |=================================================================|\n\t\t\t\t\t\t        R E C E P I T "<<endl;
                cout<<"                           |ACCOUNT   HOLDER   NAME                        "<<person.name<<endl;
                cout<<"                           |AMOUNT    RECIEVE    BY                          U S E R "<<endl;
                cout<<"                           |AMOUNT                                          "<<dpos_money<< "Rs "<<endl;
                cout<<"                           |TIME                                            "<<Time<<endl;
                cout<<"                           |=================================================================|"<<endl;
            }
             Sleep(900);
             cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|----YOUR   CASH   HAS   BEEN   WITH-DRAW  .....|\n\n";
            person.balance = person.balance - dpos_money;
            cout<<endl;
            ofstream f;
            f.open("Account.bat",ios ::out);
            f<<person.save_pin<<endl<<person.balance<<person.name<<endl<<log<<endl<<Time<<endl;
            f.close();
            ifstream file1 ("Account.bat",ios :: in);
            file1.seekg(5,ios :: beg);
            file1>>person.balance;
            file1.seekg(0);
            file1.close();
            cout<<endl<<endl<<endl;
            cout<<"\t\t|------YOUR  CURRENT  BALANCE  IS  :  "<< person.balance<< " Rs\n\n";
            fstream fa;
            fa.open("transaction.txt",ios ::out|ios:: app);
            fa<<endl<<endl;
            fa<<"AMOUNT WITHDRAW ";
            fa<<"\t\t\t\t     "<<dpos_money<<endl;
            fa<<" TIME";
            fa<<"\t\t\t\t     "<<Time<<endl;
            fa.close();
        }
        else
        	cout<<"\n\t\t|----WRONG  PIN  HAS  BEEN   ENTERED----|\n";
    }
}

void delet()
{
    cout<<"\n\n\n\t|--- WELCOME  TO  ACCUNT  DELETION  PROCESS ---|\n\n\n";
    cout<<"\t\t\t|====================================================|"<<endl;
    cout<<"\t\t\t|                ACCOUNT INFORMATION                 |"<<endl;
    cout<<"\t\t\t|====================================================|"<<endl;
    cout<<"\n\n\n";
     Sleep(1000);
    cout<<"|**********************************************************************************|"<<endl;
    cout<<"|   ACCOUNT  HOLDER  NAME                                "<<person.name<<endl<<endl;
    cout<<"|   ACCOUNT  LOGIN   ID                                      "<<enter_id<<endl<<endl;
    cout<<"|   CURRENT  PIN                                                ****"<<endl<<endl;
    cout<<"|**********************************************************************************|"<<endl;
    cout<<endl;
    cout<<"\tPress YES(y/y) Or NO(N/n) T o Delete Account Permanently (Factory Data Reset) : ";
	cin>>cash_receipt;
    if(cash_receipt == 'Y'|| cash_receipt == 'y')
    {
        cout<<endl;
        cout<<"\t\t|---- ENTER  YOUR  PIN  TO  PROCEED  : ";
		cin>>enter_pin;
        if(enter_pin==person.save_pin)
        {
            ofstream f;
            f.open("Account.bat",ios ::out);
            f.close();
            remove("transaction.txt");
            cout<<"\n\n";
            Sleep(900);
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\tTIME  :"<<Time;
            cout<<"\n\n\t\t|-------- ACCOUNT  HAS  BEEN  DELETED  SUCEESS  FULLY ---------|";
            cout<<endl<<endl;
        }
        else
        cout<<endl<<endl<<"\t\t*****|--PIN  DOES  NOT  MATCHED--|*****\n\t\t\t\t\t";
	}
    else exit(0);
}
//                                                        The End
