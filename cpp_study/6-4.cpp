#include <iostream>
using namespace std;

int main()
{
    bool a{};
    int c{500};

    int a1{1};int a2{2};
    if(a1^a1)
        cout<<"a^b is yes"<<endl;
    else
        cout<<"is a problem"<<(char)10;

    if ((c * 500 + 200 + c++) && a)
    {
        cout << "first";
    }

    if (a && (c * 500 + 200 + c++))
    {
        cout << "second";
    }
    system("pause");

    return 0;
}