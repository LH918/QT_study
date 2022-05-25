#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>
#include <QDebug>
using namespace std;
void do_app(){
    string name;
    cout<<"Please enter your name:";
    cin>>name;
    cout<<"Hello"<<name<<endl;
}//注意要使用terminal，自带的是不能获取输入的
void do_qt(){
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    qout<<"Please enter your name:";
    qout.flush();//每次在输出后加一个刷新语句
    QString name=qin.readLine();
    qout<<"hello"<<name;
    qout.flush();
}
void do_mixed(){
    QTextStream qin(stdin);
    qInfo()<<"Please enter your name:";//QDebug的这种输出方式不需要flush进行刷新
    QString name = qin.readLine();
    qInfo()<<"Hello"<<name;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do_mixed();
    return a.exec();
}
