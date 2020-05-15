#include<iostream>
using namespace std;

//条件判断表示异或的情况，其中判断的必须是两个bool值，可以是单个值也可以是表达式
int main(){
    bool a,b;
    if(1==true)
        cout<<"this is true"<<endl;
    else if(2==true)
        cout<<"this is 2"<<endl;
    while (1)
    {
        cin>>a>>b;
        cout<<(a^b)<<std::endl;
        if (a^b)
        {
            cout<<"this is true :a^b"<<endl;
        }
        
        if(((a==true)&&(b==false))||(a==false)&&(b==true))
            cout<<"this is true 1"<<endl;
        if ((a==true||b==true)&&!(a==true&&b==true))
            cout<<"this is true 2"<<endl;
    }


   
    
    
    system("pause");
    return 0;
}


