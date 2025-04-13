#include "account_util.hpp"
void display(vector<trust_account>& accounts){
    for (size_t i=0; i<accounts.size(); ++i){
        cout<<accounts.at(i)<<endl;
    }
}
void deposit(vector<trust_account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if(accounts[i].deposit(amount)){
            cout<<"Deposit of "<<amount<<" to "<<accounts[i]<<endl;
        }else{
            cout<<"Deposit failed in favor of "<<accounts[i]<<endl;
        }
    }
}
void withdraw(vector<trust_account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if (accounts.at(i).withdraw(amount)){
            cout<<"Withdraw of "<<amount<< " from "<<accounts.at(i)<<endl;
        }else{
            cout<<"Failed Withdraw of "<<amount<< " from " <<accounts.at(i)<<endl;
        }
    }
}
void display(const vector<saving_account>& accounts){
    for (size_t i=0; i<accounts.size(); ++i){
        cout<<accounts[i]<<endl;
    }
}
void deposit(vector<saving_account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if(accounts[i].deposit(amount)){
            cout<<"Deposit of "<<amount<<" to "<<accounts[i]<<endl;
        }else{
            cout<<"Deposit failed in favor of "<<accounts[i]<<endl;
        }
    }
}
void withdraw(vector<saving_account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if (accounts.at(i).withdraw(amount)){
            cout<<"Withdraw of "<<amount<< " from "<<accounts.at(i)<<endl;
        }else{
            cout<<"Failed Withdraw of "<<amount<< " from " <<accounts.at(i)<<endl;
        }
    }
}
void display(const vector<checking_account>& accounts){
    for (size_t i=0; i<accounts.size(); ++i){
        cout<<accounts[i]<<endl;
    }
}
void deposit(vector<checking_account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if(accounts[i].deposit(amount)){
            cout<<"Deposit of "<<amount<<" to "<<accounts[i]<<endl;
        }else{
            cout<<"Deposit failed in favor of "<<accounts[i]<<endl;
        }
    }
}
void withdraw(vector<checking_account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if (accounts.at(i).withdraw(amount)){
            cout<<"Withdraw of "<<amount<< " from "<<accounts.at(i)<<endl;
        }else{
            cout<<"Failed Withdraw of "<<amount<< " from " <<accounts.at(i)<<endl;
        }
    }
}
void display(const vector<Account>& accounts){
    for (size_t i=0; i<accounts.size(); ++i){
        cout<<accounts[i]<<endl;
    }
}
void deposit(vector<Account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if(accounts[i].deposit(amount)){
            cout<<"Deposit of "<<amount<<" to "<<accounts[i]<<endl;
        }else{
            cout<<"Deposit failed in favor of "<<accounts[i]<<endl;
        }
    }
}
void withdraw(vector<Account>& accounts, double amount){
    for (size_t i=0; i<accounts.size(); ++i){
        if (accounts.at(i).withdraw(amount)){
            cout<<"Withdraw of "<<amount<< " from "<<accounts.at(i)<<endl;
        }else{
            cout<<"Failed Withdraw of "<<amount<< " from " <<accounts.at(i)<<endl;
        }
    }
}