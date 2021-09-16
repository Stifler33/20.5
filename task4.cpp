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
void initFile(int countStr = 1000){
    countStr += 2;
    fstream init("D:\\ATM\\money.bin", ios::binary | ios::trunc | ios::out);
    for (int i = 0; i < countStr; i++){
        if (i == 0) {
            init << "c0   \n";
        }else if (i < countStr - 1){
            init << "m    \n";
        }else init << "q";
    }
    init.close();
    cout << "File initialized !\n";
}
void addMoney(){
    fstream atm("D:\\ATM\\money.bin", ios_base::binary | ios::in | ios::out);
    atm.is_open() ? cout << "file open !\n" : cout << "Error open file !\n";
    atm.seekg(1, ios::beg);
    atm >> countMoney;
    char sy;
    while (sy != 'q') {
        atm.read(&sy, 1);
        //atm.seekp(-1, ios::cur);
        if (sy == 'm') {
            countMoney++;
            switch (getRandNumb()) {
                case 1:
                    atm << "100 ";
                    break;
                case 2:
                    atm << "200 ";
                    break;
                case 3:
                    atm << "500 ";
                    break;
                case 4:
                    atm << "1000";
                    break;
                case 5:
                    atm << "2000";
                    break;
                case 6:
                    atm << "5000";
                    break;
            }
        }
    }
    atm.seekp(1, ios::beg);
    atm << countMoney;
    atm.close();
}
int main() {
    getRandNumb();
    string userAns;
    cout << "enter action:\n";
    cin >> userAns;
    if (userAns == "init"){
        initFile(10);
    }
    if (userAns == "add"){
        addMoney();
    }
    return 0;
}