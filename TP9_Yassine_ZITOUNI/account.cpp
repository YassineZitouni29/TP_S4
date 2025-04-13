#include "account.hpp"
Account::Account(string name, double balance): name{name}, balance{balance}{}
bool Account::deposit(double amount){
    if (amount>=0){
        balance+=amount;
        return true;
    } 
    return false;
}
bool Account::withdraw(double amount){
    if (amount<0) return false;
    if (balance-amount>=0){
        balance-=amount;
        return true;
    }else{
        return false;
    }
}
ostream& operator<<(ostream& os, const Account& acc){
    if (acc.name!= "------"){
    os<<"[Account: name "<<acc.name<<", balance "<<acc.balance<<"]";
    return os;
    }else{
        os<<"[Account: name Unnamed account, balance "<<acc.balance<<"]";
        return os;
    }
}