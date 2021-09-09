#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int getRandNumb(){
    double x = 1.0 / RAND_MAX;
    return int(rand() * x * 6 + 1);
}
void addMoney(ofstream &atm, ifstream &getAtm){
    int countMoney = 0;
    getAtm >> countMoney;
    for (int i = 10 - countMoney; i > 0; i--) {
        countMoney++;
        switch (getRandNumb()) {
            case 1:
                atm << 100 << '\n';
                break;
            case 2:
                atm << 200 << '\n';
                break;
            case 3:
                atm << 500 << '\n';
                break;
            case 4:
                atm << 1000 << '\n';
                break;
            case 5:
                atm << 2000 << '\n';
                break;
            case 6:
                atm << 5000 << '\n';
                break;
        }
    }
    atm.seekp(2, ios_base::beg);
    atm << countMoney;
}
int main() {
    ofstream atm ("D:\\ATM\\money.txt", ios_base::binary | ios_base::app);
    ifstream getAtm ("D:\\ATM\\money.txt");
    getRandNumb();
    addMoney(atm, getAtm);
    return 0;
}