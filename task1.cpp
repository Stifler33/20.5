#include <iostream>
#include <fstream>
void add_in_data(std::ofstream &data ,char sy = ' ',std::string textUser = ""){
    getline(std::cin, textUser);
    data << textUser << sy;
}
int main() {
    std::ofstream data("D:\\register.txt");
    std::string stopWord;
    while (stopWord != "n"){
        std::cout << "Enter full name :";
        add_in_data(data);
        std::cout << "Enter date :";
        add_in_data(data);
        std::cout << "Enter sum salary :";
        add_in_data(data, '\n');
        std::cout << "proceed ?\n";
        getline(std::cin , stopWord);
    }
    data.close();
    return 0;
}
