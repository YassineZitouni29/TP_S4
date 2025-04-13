#ifndef UTIL
#define UTIL
#include <vector>
#include "account.hpp"
#include "saving_account.hpp"
#include "checkin_account.hpp"
#include "trust_account.hpp"
using namespace std;

void display(const vector<Account>& accounts);
void display(const vector<saving_account>& accounts);
void display(const vector<checking_account>& accounts);
void display(vector<trust_account>& accounts);

void deposit(vector<Account>& accounts, double amount);
void deposit(vector<saving_account>& accounts, double amount);
void deposit(vector<checking_account>& accounts, double amount);
void deposit(vector<trust_account>& accounts, double amount);


void withdraw(vector<Account>& accounts, double amount);
void withdraw(vector<saving_account>& accounts, double amount);
void withdraw(vector<checking_account>& accounts, double amount);
void withdraw(vector<trust_account>& accounts, double amount);
#endif