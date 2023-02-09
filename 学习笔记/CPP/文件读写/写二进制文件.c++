#include <fstream>
#include <iostream>
#include <string>
using namespace std;

 // 向文件中写入数据
struct lifeline{
    int ban;
    double size;
};

// 文本文件存放的是字符串以行考虑 单个字节都有意义
// 二进制文件存放的不一定是字符串 以数据类型组织数据 内容作为一个整体考虑 单个字节没有意义 
int main() {
    // 二进制文件的后缀很多 没有限制
    string filename = "./log/new.dat";
    // 打开文件
    // ios::binary 表示以二进制的方式打开文件
    ofstream fout(filename, ios::out | ios::app | ios::binary);

    if(fout.is_open() == false) {
        cout << " 打开文件" << filename <<  "失败 " << endl;  
    }

    lifeline ano;
    ano.ban = 1;
    ano.size = 10;
    
    // 将数据以二进制的方式写入文件需要用输出流的write函数
    while( cin >> ano.ban >> ano.size){  // 将void * 转换成char *
       fout.write((char *)&ano, sizeof(ano));
    }   
    fout.close();
}
