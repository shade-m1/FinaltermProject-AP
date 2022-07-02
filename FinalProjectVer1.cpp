#include <bits/stdc++.h>
using namespace std;
// ---- A Drunk Man Will Find His Way Home but a Drunk Bird May Get Lost Forever =) ----

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
    void setname (string n)
    {
        name = n ; 
    }
    void setLname(string ln)
    {
        Lname = ln ; 
    }
    void setID(string i)
    {
        ID = i ; 
    }
    void setCCnum(string cc)
    {
        CCnum = cc ; 
    }
    void setShaba(string sh)
    {
        shaba = sh ; 
    }
    void Deposit(int n )
    {
        wallet += n ; 
    }
    void withdraw(int n )
    {
        wallet -= n ; 
    }
    void setDebt(int n)
    {
        debt = n ; 
    }
    int getDebt()
    {
        return debt ; 
    }
    user (string u , string pas) 
    {
        uid = u ;
        pass = pas ; 
    }
    void setverified (int n)
    {
        isverified = n ; 
    }
    int getverified()
    {
        return isverified ; 
    }

    
private : 
    string name ; 
    string Lname ; 
    string uid;
    string pass;
    string shaba ; 
    string ID ; 
    string CCnum ; 
    static int debt  ; 
    static int wallet ; 
    bool isverified ; 
    
};
int user::wallet = 0 ; 
int user::debt = 0 ;

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


private : 
    string namad ; 
    string fullname ; 
    int price ; 
    int volume ; 
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
    vector<user> users ; 
    bool lf = 0 ; // checks if user is logged in or not  
    cout<<"Menu : \n register = 1 \n login = 2 \n" ; 
    int CurrentUser = -1 ; // saving current user index 
    string op ; 
    while (op != "exit")
    {
        if (lf == 0) getline(cin >> ws  , op) ;
        else op = "2" ; 

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
                        users[CurrentUser].setname(name) ; 
                        users[CurrentUser].setLname(Lname) ; 
                        users[CurrentUser].setID(ID) ;
                        users[CurrentUser].setCCnum(CCnum) ; 
                        users[CurrentUser].setShaba(Shaba) ; 
                        users[CurrentUser].setverified(1) ; 
                        cout<<"profile completed successfully\n" ; 
                        // cout<<CurrentUser<<"\n" ;
                        cout<<"menu \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n" ;
                        // users[CurrentUser].printuser() ; 
                    }

            }            

        }
        else 
        {
            if (op == "1")
            {
                cout<<"Buy panel";
            }
            if (op =="2")
            {
                cout<<"sell panel" ;
            }
            if(op == "3")
            {
                // users[CurrentUser].test() ; 
                cout<<"1- deposit \n 2- withdraw \n" ; 
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
                    cout<<"Withdrawed successfully ! " ;
                }
            }
            if(op == "4")
            {
                cout<<"your balance" ; 
            }
            if(op == "5")
            {
                cout<<"view market" ; 
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
                cout<<"menu \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n" ;

            }
                if(op == "10") users[CurrentUser].printuser() ;

        }









    
    }












    return 0 ;    
}