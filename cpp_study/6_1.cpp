#include <iostream>
using namespace std;

int main()
{
    cout<<"first example"<<endl;
    int a{500};
    int b{1000};
    bool c = a == b;//对的是true，错的是false，表达式的本质：bool c = (a == b);
    std::cout<<std::boolalpha;
    cout<<c<<(char)10;

    //bool与int之间的转换
    cout<<"second example"<<endl;
    bool bA{int{100}};
    int nA{bA};
    cout<<"nA's value is:"<<nA<<(char)10;

    //当赋值的时候当成了判断语句，造成的严重后果,赋值取决于b的值（去赋值的值），
    b=0;//b的赋值影响了接下来的a=b的值
    if(a=b){
        cout<<"a==b but also a=b"<<(char)10;
    }else
    cout<<"else yuju"<<(char)10;
    system("pause");
    return 0;
}