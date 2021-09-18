#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
using namespace std;
int countMoney = 0;
int allSumMoney = 0;
int getRandNumb(){
    double x = 1.0 / RAND_MAX;
    return int(rand() * x * 6 + 1);
}
void initFile(int countStr = 1000){
    countStr += 4;
    fstream init("D:\\ATM\\money.bin", ios::binary | ios::trunc | ios::out);
    for (int i = 0; i < countStr; i++){
        if (i == 0) {
            init << "c0   \n";
        }else if (i == 1){
            init << "a0      \n";
        }else if (i == 2){
            init << "n                     \n";
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
    char sy;
    int numberBills[6] = {0};
    /*
    numberBills[5] one;
    numberBills[4] two;
    numberBills[3] five;
    numberBills[2] oneTh;
    numberBills[1] twoTh;
    numberBills[0] fiveTh;
     */
    while (sy != 'q') {
        atm.read(&sy, 1);
        if (sy == 'm') {
            countMoney++;
            switch (getRandNumb()) {
                case 1:
                    atm << "100 ";
                    allSumMoney += 100;
                    numberBills[5]++;
                    break;
                case 2:
                    atm << "200 ";
                    allSumMoney += 200;
                    numberBills[4]++;
                    break;
                case 3:
                    atm << "500 ";
                    allSumMoney += 500;
                    numberBills[3]++;
                    break;
                case 4:
                    atm << "1000";
                    allSumMoney += 1000;
                    numberBills[2]++;
                    break;
                case 5:
                    atm << "2000";
                    allSumMoney += 2000;
                    numberBills[1]++;
                    break;
                case 6:
                    atm << "5000";
                    allSumMoney += 5000;
                    numberBills[0]++;
                    break;
            }
        }
    }

    atm.seekp(1, ios::beg);
    atm << countMoney;
    atm.seekp(7, ios::beg);
    atm << allSumMoney;
    atm.seekp(16,ios::beg);
    for (int i = 0; i < size(numberBills); i++){
        atm << numberBills[i] << " ";
    }
    atm.close();
}
void initVecMoney(int *note,int sizeNote, vector<int> &money){
    int pos = 0;
    for (int i = 0; i < sizeNote;i++){
        switch (i){
            case 0:
                while(note[i] > 0){
                    note[i]--;
                    money.push_back(5000);
                    pos++;
                }
            case 1:
                while(note[i] > 0){
                    note[i]--;
                    money.push_back(2000);
                    pos++;
                }
            case 2:
                while(note[i] > 0){
                    note[i]--;
                    money.push_back(1000);
                    pos++;
                }
            case 3:
                while(note[i] > 0){
                    note[i]--;
                    money.push_back(500);
                    pos++;
                }
            case 4:
                while(note[i] > 0){
                    note[i]--;
                    money.push_back(200);
                    pos++;
                }
            case 5:
                while(note[i] > 0){
                    note[i]--;
                    money.push_back(100);
                    pos++;
                }
        }
    }
}
void getMoney(int summ = 0){
    fstream get("D:\\ATM\\money.bin", ios_base::binary | ios::in | ios::out);
    int numberBills[6] = {0};
    get.seekg(1, ios::beg);
    get >> countMoney;
    get.seekp(7, ios::beg);
    get >> allSumMoney;
    get.seekp(16, ios::beg);
    for (int i = 0; i < size(numberBills); i++){
        get >> numberBills[i];
    }
    cout << "Enter sum money :\n";
    std::cin >> summ;
    /*
    note[5] one=0;
    note[4] two=0;
    note[3] five=0;
    note[2] oneTh=0;
    note[1] twoTh=0;
    note[0] fiveTh=0;
     */
    int note[6] = {0};
//если сумма больше 5000 но меньше 150 000
    if (summ <= allSumMoney){
        //Проверяем корректна ли сумма
        if (summ % 100 == 0){
            //5000
            while (numberBills[0] != 0 && (summ / 5000 > 0)){
                summ -= 5000;
                numberBills[0]--;
            }
            if (numberBills[0] != 0) {
                note[0] = summ / 5000;
                summ -= note[0] * 5000;
                if (note[0] != 0) numberBills[0] -= note[0];
            }
            //2000
            if (numberBills[1] != 0) {
                note[1] = summ / 2000;
                summ -= note[1] * 2000;
                if (note[1] != 0) numberBills[1] -= note[1];
            }
            //1000
            if (numberBills[2] != 0) {
                note[2] = summ / 1000;
                summ -= note[2] * 1000;
                if (note[2] != 0) numberBills[2] -= note[2];
            }
            //500
            if (numberBills[3] != 0) {
                note[3] = summ / 500;
                summ -= note[3] * 500;
                if (note[3] != 0) numberBills[3] -= note[3];
            }
            //200
            if (numberBills[4] != 0) {
                note[4] = summ / 200;
                summ -= note[4] * 200;
                if (note[4] != 0) numberBills[4] -= note[4];
            }
            //100
            if (numberBills[5] != 0) {
                note[5] = summ / 100;
                summ -= note[5] * 100;
                if (note[5] != 0) numberBills[5] -= note[5];
            }
        }else std::cout << "incorrect sum\n";
    }else if (summ > allSumMoney) std::cout << "sum big\n";
    get.seekp(16,ios::beg);
    for (int i = 0; i < size(numberBills); i++){
        get << numberBills[i] << " ";
    }
    vector<int> vecMoney;
    initVecMoney(note, size(note), vecMoney);
    char sy;
    while(sy != 'q'){
        int number = 0;
        get.read(&sy,1);
        if (sy == 'm'){
            int posCur = (int)get.tellg();
            get >> number;
            for (int i = vecMoney.size() - 1; i >= 0; i--){
                if (number == vecMoney[i]){
                    allSumMoney -= vecMoney[i];
                    countMoney--;
                    get.seekp(1, ios::beg);
                    get << "0   ";
                    get.seekp(1, ios::beg);
                    get << countMoney;
                    get.seekp(7, ios::beg);
                    get << "0      ";
                    get.seekp(7, ios::beg);
                    get << allSumMoney;
                    vecMoney.pop_back();
                    get.seekp(posCur, ios::beg);
                    get << "0   ";
                    break;
                }
            }
        }
    }
    if (vecMoney.size() > 0){
        cout << "not all issued!\n";
    }else cout << "all issued\n";
}
int main() {
    getRandNumb();
    string userAns;
    cout << "enter action:\n";
    cin >> userAns;
    if (userAns == "init"){
        initFile(20);
    }
    if (userAns == "add"){
        addMoney();
        cout << "Total money in ATM :\n";
        cout << allSumMoney;
    }
    if (userAns == "get"){
        getMoney();
    }
    return 0;
}