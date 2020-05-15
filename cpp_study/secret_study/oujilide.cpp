//实现欧几里得算法
/*
算法说明：
    使用辗转相除法；
*/
#include <iostream>
using namespace std;

//非递归算法
int gcd(int a, int b)
{
    //将a、b取绝对值
    a=abs(a);
    b=abs(b);

    if (a == b)
        return a;
    //将a永远置为大值，b就是小的值
    if (a < b)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    //开始进行辗转相除法，其中q为乘数r为余数
    int q{0}, r{1};
    while (1)
    {
        q = a / b;
        r = a % b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    }
}

//递归算法
int gcd2(int a, int b)
{
    //将a、b取绝对值
    a=abs(a);
    b=abs(b);

    if (a > b)
    {
        if(a%b==0)
            return b;
        else
            return gcd2(b, a % b);
    }
    else if (a < b){
        if(b%a==0)
            return a;
        else
            return gcd2(a,b%a);
    }
    else
        return a;
}

//扩展欧几里得算法
int ex_gcd(int a,int b){
    
}

int main()
{
    int a = -1859;
    int b = 1573;
    cin>>a>>b;
    cout << gcd(a, b) << (char)10;
    cout<<gcd2(a,b)<<endl;
    system("pause");
    return 0;
}
