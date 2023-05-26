
#include <iostream>
using namespace std;

class Money {
public:
    int dollars;
    int cents;
};

Money withdraw_money(Money balance, Money withdrawal) {
    Money newMoney;
    
    newMoney.dollars = balance.dollars - withdrawal.dollars;
    if ((balance.cents - withdrawal.cents) < 0) {
        newMoney.dollars = newMoney.dollars - 1;
        newMoney.cents = (balance.cents - withdrawal.cents) + 100;
    }
    if ((balance.cents - withdrawal.cents) > 0){
        newMoney.cents = balance.cents - withdrawal.cents;
    }
    if (newMoney.dollars < 0) {
        newMoney.dollars = 0;
        newMoney.cents = 0;
    }
    return newMoney;
}
int main()
{
    std::cout << "Hello World!\n";
}