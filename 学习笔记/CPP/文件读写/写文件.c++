#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// istream派生出 ifstream 读文件 
// ostream派生出 ofstream 写文件 
// istream 和 ostream 派生出 iostream 其派生出 fstream可以用来读写文件
// ios_base -> ios -> (istream/ostream)

int main(){
    ofstream fout;
    fout.open("test.txt"); // 打开文件不存在会自动创建 若vitamink@vitaminkdembp CPP % ./文件读写/main 则新建的test保存在CPP目录下
    fout << "this is rookie\n"; 
    
    
    ofstream fout2;
    char filename[] = "./log/new.txt"; // 如果指定不存的文件夹则会打开失败
    fout2.open(filename); // 需要指定文件路径才不会根据运行时的文件夹创建新文件
    fout2 << "this is right\n";
    

    ofstream fout3("3.txt", ios::app);
    fout3 << "this can append";

    
    // 打开文件之后判断是否打开成功
    if(fout2.is_open() == false) {  // 目录不存在 磁盘空间满 没有权限
        cout << " 打开文件" << filename <<  "失败 " << endl;  
    }

    fout.close(); // 关闭文件 outf对象失效前会自动调用close()
    fout2.close();
    fout3.close();
    cout <<  "done\n";  

}