#include <iostream>
using std::cin;
using std::cout;

int main()
{
    unsigned long long Iuser, Ipassword;
    //输入密码,注册
    cout << "Please enter your username and password register, separated by spaces:"; //输入用户名以及密码，中间空格隔开
    cin >> std::hex >> Iuser >> Ipassword;

    //登陆
    if (Iuser > 0xFFFFF && Ipassword > 0xFFFFF)
    {
        system("cls");
        unsigned long long _Iuser, _Ipassword;
        cout << "Enter the user name and password to log in, separated by spaces"; //输入用户名与密码进行登陆，中间用空格隔开
        cin >> std::hex >> _Iuser >> _Ipassword;//输入之后应该再检测一次是否是五个16位，这里没有做，大项目需要做
        if (Iuser == _Iuser)
        {
            cout << "log in game" << std::endl;//登陆游戏
            if (Ipassword == _Ipassword)
                cout << "log in is success" << std::endl;//登陆成功
            else
                cout << "log in is failed" << std::endl;//登陆失败
        }
        else
            cout << "Sorry, your password was entered incorrectly" << std::endl; //对不起，您的密码输入错误
    }
    else
    {
        cout << "Sorry, your account number was entered incorrectly." << std::endl; //对不起您的账号输入错误
    }

    system("pause");
    return 0;
}