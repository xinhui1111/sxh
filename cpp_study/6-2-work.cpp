//6-2�κ���ҵ
#include <iostream>
using namespace std;

// int main()
// {
//     char c{' '};
//     cout<<"�����ַ�c:";
//     cin>>c;
//     if ((int)c >= '0' && (int)c <= '9')
//         cout << "�������֣�" << c << (char)10;
//     else if ((int)c >= 65 && (int)c <= 97)
//         cout << "���Ǵ�дתСд���ʣ�" << (char)(c + 32);
//     else if ((int)c >= 90 && (int)c <= 122)
//         cout << "����Сдת��д���ʣ�" << (char)(c - 32);
//     else
//         cout << "��������ж�" << (char)10;

//     // cout<<(int)'a'<<"------"<<(int)'A'<<(char)10;
//     // cout<<(int)'z'<<"------"<<(int)'Z'<<(char)10;
//     system("pause");
//     return 0;
// }

int main(){
    char c{' '};
    cout << "Enter character c:";
    cin >> c;
    //��ʼ�����ж�
    if(c>=48)   {
        if(c<=57)
            cout<<"This is the number:"<<(int)c<<(char)10;
       if(c>=65)
           if(c<=90)
                cout<<"This is an uppercase to lowercase word:"<<(char)(c+32)<<endl;
        if(c>=97)
            if(c<=122)
                cout<<"This is a lowercase to uppercase word:"<<(char)(c-32)<<endl;   
            else
                cout<<"This is the symbol";                 
    }
    else
    {
        cout<<"This is the symbol";
    }
    
    system("pause");
    return 0;
}