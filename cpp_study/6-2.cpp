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
    cout << "����������ȡ����\n";
    cin >> a;
    //bool���ʽ����һ��intֵ����ʵ�ʾ���ͨ���жϸ�ֵ�Ƿ�Ϊ0��������Ҫ���bool�ı���
    if (a)
    {
        cout << "������ȡ��" << a << "Ԫ" << endl;
    }
    else
        cout << "����\n";

    //����˵��a==b��a=b���׷���������bΪ0��ʱ��a=b����ִ�У�b��Ϊ0��ʱ��a=b��ִ��
    cout << "thrond  example:\n";
    if (a == b)
        cout << "����һ����Ǯ\n";
    if (a = b)
        cout << "a=b����һ����Ǯ\n";
    system("pause");
    return 0;
}