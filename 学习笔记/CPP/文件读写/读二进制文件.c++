#include <fstream>
#include <iostream>
using namespace std;

struct lifeline{
    int ban;
    double size;
};

int main() {
    string filename = "./log/new.dat";
    ifstream fin(filename, ios::in | ios::app | ios::binary);
    if(fin.is_open() == false) {
        cout << "打开文件错误" << endl;
    }    
    lifeline ano;
    while(fin.read((char *)&ano, sizeof(ano))){
        cout << ano.ban << ano.size;
    }
    fin.close();
}