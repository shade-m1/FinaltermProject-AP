#include <bits/stdc++.h>
using namespace std;
// ---- A Drunk Man Will Find His Way Home but a Drunk Bird May Get Lost Forever =) ----

class sahm
{
public : 
    sahm(string n , string fn , int p , int v )
    {
        namad = n ; 
        fullname = fn ; 
        price = p ; 
        volume = v ; 
    }
    void save(ofstream &data)
    {
        data<<namad<<"\n"<<fullname<<"\n"<<price<<"\n"<<volume<<"\n";
    }
    sahm(ifstream &data)
    {
        data>>namad>>fullname>>price>>volume ;
    }
    void print()
    {
        cout<<"Symbol : "<<namad<<"\n"<<"shortname : "<<fullname<<"\n"<<"price :"<<price<<"\n"<<"volume :"<<volume<<"\n" ; 
    }
    bool has_symbol(string s)
    {
        return namad == s ;
    }
    int getprice()
    {
        return price ; 
    }
    string getsymbol()
    {
        return namad ; 
    }
private : 
    string namad ; 
    string fullname ; 
    int price ; 
    int volume ; 
};

class user  // creating a class for user 
{
public : 
    void printuser()
    {
        cout<<uid<<"\n"<<pass<<"\n"<<name<<"\n"<<Lname<<"\n"<<ID<<"\n"<<CCnum<<"\n"<<shaba<<"\n"<<wallet<<"\n"<<isverified ; 
    }
    bool has_username(string un) 
    {
        return un == uid ; 
    }
    bool has_password(string up) 
    {
        return up == pass ; 
    }
    void Deposit(int n )
    {
        wallet += n ; 
    }
    void withdraw(int n )
    {
        wallet -= n ; 
    }
    void AddDebt(int n)
    {
        debt += n ; 
    }
    void paydebts(int n )
    {
        debt -= n ;
    }
    void setverified (int n)
    {
        isverified = n ; 
    }
    void save(ofstream &data)
    {
        data<<name<<" "<<Lname<<"\n"<<uid<<"\n"<<pass<<"\n"<<ID<<"\n"<<shaba<<"\n"<<CCnum<<"\n"<<wallet<<"\n"<<debt<<"\n"<<isverified<<"\n" ; 
        data << UserStocks.size()<<"\n" ; 
        for (int i = 0 ; i < UserStocks.size() ; i ++) 
        {
            data<< UserStocks[i]<<" " ; 
        }
    }
    int getverified()
    {
        return isverified ; 
    }
    int getDebt()
    {
        return debt ; 
    }    
    int getMoney()
    {
        return wallet ; 
    }
    void addstock(string n)
    {
        UserStocks.push_back(n) ; 
    }
    void setuser(string n , string ln , string i , string cc , string sh )
    {
        name = n ;
        Lname = ln ; 
        ID = i ; 
        CCnum = cc ; 
        shaba = sh ;
        isverified = 1 ;
        wallet = 0 ; 
        debt = 0; 
    }
    user (string u , string pas) 
    {
        uid = u ;
        pass = pas ; 
    }      
    user(ifstream &data)
    {
        data>>name>>Lname>>uid>>pass>>ID>>shaba>>CCnum>>wallet>>debt>>isverified ; 
        int tedad = 0 ;
        data >> tedad ; 
        for(int i = 0 ; i < tedad ; i++)
        {
            string s ; 
            data>>s ;
            UserStocks.push_back(s) ;  

        }
    }
private : 
    string name ; 
    string Lname ; 
    string uid;
    string pass;
    string shaba ; 
    string ID ; 
    string CCnum ; 
    int debt  ; 
    int wallet ; 
    bool isverified ; 
    vector<string> UserStocks ; 
};


int passcheck(string str) // validate chosen password 
{ 
    int l_case=0, u_case=0, digit=0, special=0;
    int l=str.length(),i;
  
  for(i=0;i<l;i++)
  {
        if(islower(str[i]))
            l_case=1;
        if(isupper(str[i]))
            u_case=1;
        if(isdigit(str[i]))
            digit=1;
        if(!isalpha(str[i]) && !isdigit(str[i]))
            special=1;  
  }
  return(l_case + u_case + digit + special) ; 
};



int main()
{

    ifstream UserData ("users.txt") ;
    ifstream Stocks_file ("stock_market_data.csv") ;
    vector<sahm> stocks ; 
    vector<user> users ; 
    int tedad = 0 ;
    UserData >> tedad ; 
    for(int i = 0 ; i < tedad ; i++)
    {
        user newuser(UserData) ;
        users.push_back(newuser) ; 
    }
    UserData.close() ; 
    string line ; 
    getline(Stocks_file, line) ; 
    while(getline(Stocks_file, line))
    {
        string id ; 
        string namad ;
        string fullname ;
        string price ;
        string volume ;
        stringstream line_stream (line) ;
        getline(line_stream , id , ',') ;
        getline(line_stream , namad , ',') ;
        getline(line_stream , fullname , ',') ;
        getline(line_stream , price , ',') ;
        getline(line_stream , volume , ',') ;
        sahm newsahm(namad,fullname,atoi(price.c_str()),atoi(volume.c_str())) ;
        stocks.push_back(newsahm) ; 
    }
    bool lf = 0 ; // checks if user is logged in or not  
    cout<<"Menu : \n register = 1 \n login = 2 \n" ; 
    int CurrentUser = -1 ; // saving current user index 
    string op ; 
    while (op != "exit")
    {
        
        if (lf == 0) getline(cin >> ws  , op) ;
        else op = "2" ; 

        ofstream UserData("users.txt") ; 
        UserData << users.size()<<"\n" ; 
        for(int i = 0 ; i < users.size() ; i++)
        {
            users[i].save(UserData) ; 
        }
        UserData.close() ; 
        if(CurrentUser == -1 ) 
        {
            if (op == "1")  // sign up 
            {
                string un ; 
                string up ; 
                cout<<"please enter your desired username : \n";
                getline(cin , un) ; 
                cout<<"please enter a strong password \n (your password should have at least one capital letter , one digit and one special character ) \n" ;
                getline(cin , up) ; 
                while (passcheck(up) <= 2) // checks if user password is strong enough or not 
                {
                    cout<<"weak password , try another one \n";
                    getline(cin , up) ; 
                } 

                user newuser (un , up) ; 
                cout<<"succsesfully Done ! to complete your profile and access panel please login  \n register = 1 \n login = 2 \n " ;
                users.push_back(newuser) ; // saving new user data 
            }
            
            if(op =="2")
            {   
                int userindex = -1 ; 
                string un ;
                string up ; 
                cout<<"username : " ; 
                getline(cin , un) ; 

                
                 for(int i = 0 ; i < users.size() ; i++) // finding username among all users 
                 {
                     if(users[i].has_username(un))
                     {
                        userindex = i ; 
                        break ; 
                     }
                 }
                if(userindex != -1 ) // check is chosen username is available or not 
                {
                    lf = 0 ;
                    cout<<"password : " ; 
                    getline(cin , up) ; 
                    if(users[userindex].has_password(up) == true) // checks if chosen password for chosen username is correct or not 
                    {
                        cout<<"login succsecful !\n " ; 
                        CurrentUser = userindex ; 
                        if(users[CurrentUser].getverified() == 1)
                        {
                            cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                        }
                    }
                    else  // if first input was wrong , get a new one 
                    {
                        cout<<"invalid password for this username \n Try again : " ;    
                        int flag = 0 ; 
                        while (flag == 0)
                        {
                            
                            getline(cin , up) ; 
                            if(users[userindex].has_password(up) == true) 
                            {
                                cout<<"login successful !\n " ; 
                                flag = 1 ; 
                                CurrentUser = userindex ; 
                            }
                            else
                            {
                                cout<<"invalid password for this username \n password : " ;  
                            }
                        }
                        
                    }
                }
                else 
                {
                    cout << " invalid username \n" ;   
                    lf = 1 ; 
                }    
                    if(users[CurrentUser].getverified() != 1)
                    {
                        cout<<"in order to access your panel , please complete your profile \n " ; 
                        cout <<"please enter your name \n"; 
                        string name ; 
                        cin>>name ; 
                        cout<<"please enter your last name \n" ; 
                        string Lname ; 
                        cin>>Lname ;
                        cout<<"please enter your ID number\n" ; 
                        string ID ;
                        cin>>ID ;
                        ID = ID.substr(0,10) ; 
                        cout<<"please enter your CC number \n " ; 
                        string CCnum ; 
                        cin>>CCnum ; 
                        CCnum = CCnum.substr(0,10) ;  
                        cout<<"please enter your SHABA\n" ; 
                        string Shaba ;
                        cout<<"IR" ; 
                        cin>>Shaba ; 
                        Shaba = Shaba.substr(0,10) ; 
                        /*users[CurrentUser].setname(name) ; 
                        users[CurrentUser].setLname(Lname) ; 
                        users[CurrentUser].setID(ID) ;
                        users[CurrentUser].setCCnum(CCnum) ; 
                        users[CurrentUser].setShaba(Shaba) ; 
                        users[CurrentUser].setverified(1) ; */
                        users[CurrentUser].setuser(name,Lname,ID,CCnum,Shaba);
                        cout<<"profile completed successfully\n" ; 
                        // cout<<CurrentUser<<"\n" ;
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                        // users[CurrentUser].printuser() ; 
                    }

            }            

        }
        else 
        {
            if (op == "1")
            {
                cout<<"Buy panel \n please enter the symbol you want to buy" ; 
                string symbol ;
                cin>>symbol ; 
                int index = -1 ; 
                for(int i = 0 ; i < stocks.size() ; i++)
                {
                    if(stocks[i].has_symbol(symbol))
                    {
                        index = i ;
                        break ;
                    }
                }
                if(index == -1)
                {
                    cout<<"symbol not found ";
                }
                else 
                {
                    int UserMoney = users[CurrentUser].getMoney() ; 
                    cout<<"your money : "<<UserMoney<<"\n"; 
                    cout<<"how much of "<<stocks[index].getsymbol()<<" do you want to buy : \n";
                    int n ; 
                    cin>>n ;
                    if( n*stocks[index].getprice() < UserMoney)
                    {
                        stringstream stream ; 
                        stream << n ; 
                        string temp ; 
                        stream>>temp ; 
                        users[CurrentUser].withdraw(n*stocks[index].getprice()) ;
                        users[CurrentUser].addstock(temp+" "+stocks[index].getsymbol()+"\n") ;

                    }


                }



            }
            if (op =="2")
            {
                cout<<"sell panel" ;
            }
            if(op == "3")
            {
                // users[CurrentUser].test() ; 
                cout<<"1- deposit \n 2- withdraw \n 3- loan \n 4- pay debts \n" ; 
                string o ; 
                cin>>o ; 
                if(o == "1")
                {
                    cout<<"how much do you want to deposit in tomans : \n" ;
                    int Dmoney ; 
                    cin >> Dmoney ; 
                    users[CurrentUser].Deposit(Dmoney) ;  
                    cout<<"Deposited successfully !" ;
                }
                if(o == "2")
                {
                    cout<<"how much do you want to withdraw in tomans : \n" ;
                    int Wmoney ; 
                    cin >> Wmoney ; 
                    users[CurrentUser].withdraw(Wmoney) ; 
                    cout<<"Withdrawed successfully ! \n" ;
                }
                if(o == "3")
                {

                    

                   /* if(users[CurrentUser].getDebt() + n < 1000000 )
                    {
                        int n ;
                        cin>>n ;
                        cout<<"how much do you want to borrow: \n " ; 
                        users[CurrentUser].AddDebt(n) ;
                        users[CurrentUser].Deposit(n) ;
                        cout<<"borrowed successfully !\n " ; 
                    }
                    else 
                    {
                        cout<<"you've already reached the maximum amount you can borrow \n please pay your debt so you can borrown again \n " ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit\n" ; 
                    } */ 
                }
                if(o == "4")
                {
                    int debt = users[CurrentUser].getDebt() ; 
                    cout<<debt<<" Tomans" ;
                    cout<<"how much money do you want to pay for your debt \n " ; 
                    int n ;
                    cin>>n ;
                    if (debt < n)

                    {
                        int r = n - debt ; 
                        users[CurrentUser].Deposit(r);
                        users[CurrentUser].paydebts(debt);
                        cout<<"you have paid your debt and you've added "<<r<<" Tomans to your wallet \n" ; 
                    }
                    else 
                    {
                        users[CurrentUser].paydebts(n) ;
                        if(users[CurrentUser].getDebt() == 0)
                        {
                            cout<<"you've paid your debt" ; 
                        }                        
                        else 
                        {
                            cout<<"you have paid"<<n<<" Tomans \n remaining debt :"<<users[CurrentUser].getDebt() ;
                        }
                    }


                }
            }
            if(op == "4")
            {
                cout<<"your balance" ; 
            }
            if(op == "5")
            {
                cout<<"viewing market ( first 10 stocks ) \n" ;
                for(int i = 0 ; i< 10 ; i++) 
                {
                    stocks[i].print() ;
                    cout<<"\n" ;  
                }
            }
            if(op == "6")
            {
                cout<<"please enter your information again\n" ;
                cout <<"please enter your name \n"; 
                string name ; 
                cin>>name ; 
                cout<<"please enter your last name \n" ; 
                string Lname ; 
                cin>>Lname ;
                cout<<"please enter your ID number\n" ; 
                string ID ;
                cin>>ID ;
                ID = ID.substr(0,10) ; 
                cout<<"please enter your CC number \n " ; 
                string CCnum ; 
                cin>>CCnum ; 
                CCnum = CCnum.substr(0,10) ;  
                cout<<"please enter your SHABA\n" ; 
                string Shaba ;
                cout<<"IR" ; 
                cin>>Shaba ; 
                Shaba = Shaba.substr(0,10) ; 
                users[CurrentUser].setname(name) ; 
                users[CurrentUser].setLname(Lname) ; 
                users[CurrentUser].setID(ID) ;
                users[CurrentUser].setCCnum(CCnum) ; 
                users[CurrentUser].setShaba(Shaba) ; 
                users[CurrentUser].setverified(1) ; 
                cout<<"profile completed successfully\n" ; 
                cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit\n" ;

            }
            if(op == "0")
            {
                CurrentUser = -1 ; 
            }
            
            if(op == "10") users[CurrentUser].printuser() ;

        }









    
    }












    return 0 ;    
}
