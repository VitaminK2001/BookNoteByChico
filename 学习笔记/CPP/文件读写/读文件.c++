#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 将输出的ofstream 改成 输入的ifstream
    string filename = "./log/new.txt";
    // 打开文件
    ifstream fin(filename, ios::in); // ios::in写或不写都一样
    // 判断是否打开成功
    if(fin.is_open() == false) {
        cout << "打开文件" << filename << "失败" << endl;
    }

    // 从文件中读数据
        // 第一种方法
        string buffer;
        // 输入流 + 存放内容的输入字符串
        // 一行行读数据
        while(getline(fin, buffer)) { // 如果文件结束 getline函数返回空
            cout << buffer << endl;        
        }
    
        // 第二种方法
        char buffer2[101];
        while(fin.getline(buffer2, 20)) { //geline函数变成fin的成员函数 第一个参数是buffer第二个参数是最多读取的字节数
            // 需要保证存放数据的缓冲区足够大 不然不会写数据
            cout << buffer2 << endl;
        }

        // 第三种方法
        string buffer3;
        while(fin >> buffer3) { // 这种方法逐个单词输出
            cout << buffer3 << endl;
        }

    fin.close();
}
