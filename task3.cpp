#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream river("D:\\river.txt");
    ofstream basket("D:\\basket.txt", ios_base::app);
    string fish;
    if (!river.is_open()) {
        cerr << "Error open file !";
        return 0;
    }
    cout << "Enter fish:\n";
    cin >> fish;
    int countFishing = 0;
    int counter = 1;
    while (!river.eof()){
        string getFish;
        river >> getFish;
        if (getFish == fish) {
            for (; counter > 0; counter--) basket << fish << ' ';
            countFishing++;
        }
    }
    basket << countFishing << " sum." << '\n';
    cout << countFishing;
    return 0;
}