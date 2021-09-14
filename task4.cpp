#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int countMoney;
int getRandNumb(){
    double x = 1.0 / RAND_MAX;
    return int(rand() * x * 6 + 1);
}
void addMoney(){
    fstream atm("D:\\ATM\\money.bin", ios_base::binary | ios::in | ios::out | ios::ate);
    atm.is_open() ? cout << "file open !\n" : cout << "Error open file !\n";
    int endPos = atm.tellp();
    atm.seekg(0, ios::beg);
    atm >> countMoney;
    atm.seekp(endPos, ios::beg);
    for (int i = 1000 - countMoney; i > 0; i--) {
        countMoney++;
        switch (getRandNumb()) {
            case 1:
                atm << "100" << '\n';
                break;
            case 2:
                atm << "200" << '\n';
                break;
            case 3:
                atm << "500" << '\n';
                break;
            case 4:
                atm << "1000" << '\n';
                break;
            case 5:
                atm << "2000" << '\n';
                break;
            case 6:
                atm << "5000" << '\n';
                break;
        }
    }
    atm.seekp(0, ios::beg);
    atm << countMoney;
    atm.close();
}
int main() {
    getRandNumb();
    addMoney();
    return 0;
}