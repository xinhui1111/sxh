#include <iostream>
using namespace std;

//大神技巧1
int great_skill(int val)
{
    int c;
    // return (10000/val);容易造成漏洞，就是val==0的时候
    return (c = val ? 10000 / val : 0);
}

int main()
{
    //测试大神技巧1
    int val;
    cout<<"input a integer: "<<(char)10;
    cin>>val;
    cout<<"The result after 10000 division: "<<great_skill(val);

    //求出最大值
    int a, b, c, k;
    cout << "please input four integer:";
    cout << ((char)10) << "Where k is the kth method" << ((char)10);
    cin >> a >> b >> c >> k;
    switch (k)
    {
    //通过if_else求最大值
    case 1:
        if (a > b)
            c = a;
        else
            c = b;
        cout << "max is: " << c;
        break;
    //通过条件判断求最大值-三元运算符
    default:
        c = a > b ? a : b + 5000;
        // c=a>b?a:b+5000;//三元运算符号优先级最低
        cout << "max is: " << c;
        break;
    }

    system("pause");
    return 0;
}