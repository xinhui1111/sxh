#include<iostream>
using namespace std;

int main(){
    unsigned int Uid,Ubouns;
    //今天我们将举行抽奖活动!!!请输入您的学生编号以获得匹配的奖金
    cout<<"We will hold our lucky draw today.!!!\n"<<"Please enter your student number for matching bonus\n";
    cin>>Uid;
    switch (Uid)
    {
    case 15692:
        Ubouns=500;
        break;
    case 65421:
        Ubouns=450;
        break;
    case 98741:
        Ubouns=250;
        break;
    case 2531:
        Ubouns=150;
        break;
    case 666:
    case 321:
        Ubouns=Uid<<2;//比Ubouns=Uid*2更加快速
    case 1:
        [[fallthrough]];//作用是用来标志此处不使用break
        Ubouns=11;
    default:
        // Ubouns=0;
        cout<<"You did not win\n";//你没有赢
        break;
    }

    if(Ubouns)
        cout<<"your bonus is:"<<Ubouns<<"\n";
    system("pause");
    return 0;
}