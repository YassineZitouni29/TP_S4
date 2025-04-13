#include <iostream>
#include <vector>
#include "account.hpp"
#include "saving_account.hpp"
#include "checkin_account.hpp"
#include "trust_account.hpp"
#include "account_util.hpp"

int main() {
std::cout.precision(2);
std::cout << std::fixed;
// Accounts
std::vector<Account> accounts { Account{}, Account{"Larry"},
Account{"Moe", 2000}, Account{"Curly", 5000} };
display(accounts);
std::cout<<std::endl;
deposit(accounts, 1000);
std::cout<<std::endl;
withdraw(accounts, 2000);
// Savings
std::vector<saving_account> sav_accounts {
saving_account{},
saving_account{"Superman"},
saving_account{"Batman", 2000},
saving_account{"Wonderwoman", 5000, 5.0}
};
std::cout<<"=========================================================="<<std::endl;
display(sav_accounts);
std::cout<<std::endl;
deposit(sav_accounts, 1000);
std::cout<<std::endl;
withdraw(sav_accounts, 2000);
// Checking
std::vector<checking_account> check_accounts {
checking_account{},
checking_account{"Kirk"},
checking_account{"Spock", 2000},
checking_account{"Bones", 5000}
};
std::cout<<"==========================================================="<<std::endl;
display(check_accounts);
std::cout<<std::endl;
deposit(check_accounts, 1000);
std::cout<<std::endl;
withdraw(check_accounts, 2000);
std::cout<<std::endl;
// Trust
std::vector<trust_account> trust_accounts {
trust_account{},
trust_account{"Athos", 10000, 5.0},
trust_account{"Porthos", 20000, 4.0},
trust_account{"Aramis", 30000}
};
std::cout<<"============================================================"<<std::endl;
display(trust_accounts);
std::cout<<std::endl;
deposit(trust_accounts, 1000);
std::cout<<std::endl;
withdraw(trust_accounts, 3000);
for (int i = 1; i <= 5; ++i)
withdraw(trust_accounts, 1000);
return 0;
}
