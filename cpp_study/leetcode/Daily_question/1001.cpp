/*
面试题10.01
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

*/

#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

/*
void merge(vector<int> &A, int m, vector<int> &B, int n)
{
    
    for (auto i = B.begin() ; i < B.end(); i++)
        for (auto j = A.begin() ; j < A.end(); j++)
        {
            cout<<"i="<<*i<<"-------"<<"j="<<*j<<endl;
            if (*i == *j)
                A.insert(j + 1, *i);
            else if (*i > *j)
                if (i<A.end() && *i < *(j + 1))
                    A.insert(j + 1, *i);
                else
                    continue;
        }
    for (int i = 0; i < m-n-n; ++i)
        A.pop_back();
}
*/

void merge(vector<int> &A, int m, vector<int> &B, int n){
    for(int i=0;i<n;++i){
        A[m-n+i]=B[i];
        cout<<m-n+i<<"A[m-n+i]"<<A[m-n+i]<<endl;
    }
    sort(A.begin(),A.end());
}
int main()
{
    //A、B数组初始化
    vector<int> A{1, 2, 3, 0, 0, 0};
    vector<int> B{2, 5, 6};

     for(auto temp:A)
        cout<<temp<<endl;
    merge(A,6, B, 3);

    cout<<"result is :"<<(char)10;
    for(auto temp:A)
        cout<<temp<<endl;
    system("pause");
    return 0;
}