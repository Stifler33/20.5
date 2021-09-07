#include <iostream>
#include <fstream>
#include <string>
bool add_in_data(std::ofstream &data ,std::string flag, char sy = ' ',std::string textUser = ""){
    getline(std::cin, textUser);
    if (flag == "fullName"){
        for (int i = 0; i < textUser.size(); i++){
            if (textUser[i] >= '0' && textUser[i] <= '9'){
                std::cerr << "error format full name !\n";
                return false;
            }
        }
    }
    if (flag == "date"){
        if (textUser.size() != 10) {
            std::cerr << "error is long date\n";
            return false;
        }
        if (std::stoi(textUser.substr(0,2)) < 0 || std::stoi(textUser.substr(0,2)) > 31){
            std::cerr << "error format date - day\n";
            return false;
        }
        if (std::stoi(textUser.substr(3,2)) < 0 || std::stoi(textUser.substr(3,2)) > 12){
            std::cerr << "error format date - month\n";
            return false;
        }
        if (std::stoi(textUser.substr(6,4)) < 1999 || std::stoi(textUser.substr(6,4)) > 2024){
            std::cerr << "error format date - year\n";
            return false;
        }
    }
    if (flag == "salary"){
        for (char i : textUser){
            if (i < '0' || i > '9'){
                std::cerr << "error format salary\n";
                return false;
            }
        }
    }
    data << textUser << sy;
    return true;
}
int main() {
    std::ofstream data("D:\\register.txt", std::ios_base::app);
    std::string stopWord;
    std::ifstream file;
    while (stopWord != "n"){
        do {
            std::cout << "Enter full name :\n";
        }while(!add_in_data(data, "fullName"));
        do {
            std::cout << "Enter date :\n";
        }while(!add_in_data(data, "date"));
        do {
            std::cout << "Enter sum salary :\n";
        }while(!add_in_data(data, "salary", '\n'));
        std::cout << "proceed ?\n";
        getline(std::cin , stopWord);
    }
    data.close();
    return 0;
}