#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int getRandNumb(){
    double x = 1.0 / RAND_MAX;
    return int(rand() * x * 2);
}
int main(){
    ofstream outDrawing ("D:\\Drawing.txt", ios_base::app);
    srand(time(nullptr));
    int W;
    int H;
    cout << "Width and Height\n";
    cin >> W >> H;
    for (int h = 0; h < H; h++){
        for (int w = 0; w < W; w++){
            outDrawing << getRandNumb() << " ";
        }
        outDrawing << '\n';
    }
    outDrawing << "*************************\n";
    outDrawing.close();
    return 0;
}