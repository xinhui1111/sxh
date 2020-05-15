#include <iostream>
using namespace std;

int main()
{
    cout << "first  example:\n";
    int a{500};
    int b{1000};
    if (a > b)
        cout << "you have many money\n";
    else
        cout << "b have better money\n";

    cout << "second example:\n";
    cout << "请输入您的取款金额\n";
    cin >> a;
    //bool表达式就是一个int值，其实质就是通过判断该值是否为0，这里需要理解bool的本质
    if (a)
    {
        cout << "您本次取款" << a << "元" << endl;
    }
    else
        cout << "捣乱\n";

    //用于说明a==b与a=b容易犯错的情况，b为0的时候a=b不会执行，b不为0的时候a=b会执行
    cout << "thrond  example:\n";
    if (a == b)
        cout << "我们一样有钱\n";
    if (a = b)
        cout << "a=b我们一样有钱\n";
    system("pause");
    return 0;
}