//整数n的最小正因数是素数
/*
    素数的判别法则：厄拉托赛师筛法
    法则定义：设n>1,若对所有的素数p<=sqr(n)，其中p！=n,则n是素数
    实现方法：
        列出N个整数，以及小于sqr（n）的整数，从中删除这些的倍数，余下的就是所要求的不超过N的素数
        依次删除2*p1,3*p1,...,[N/p1]*p1;
    例子：求不超过N=100的素数
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//说明：如果是想要通用的话，就需要对sushu这个数组进行通用的适配，同时这也是最关键的部分，还有就是ini的初始化
int main(){
    vector<int>sushu{2,3,5,7};
    vector<int>sushu_receive;
    //初始化ini数组，1-100
    vector<int>ini{};
    for(int i=1;i<=100;++i){
        ini.push_back(i);
    }
    //将p的倍数放入一个数组中
    for(int i=0;i<sushu.size();++i){
        for(int j=1;j<=200/sushu[i];++j){
            sushu_receive.push_back(j*sushu[i]);
        }
    }
    //将sushu与ini进行差集计算
    vector<int>result;
    sort(sushu_receive.begin(),sushu_receive.end());
    set_difference(ini.begin(),ini.end(),sushu_receive.begin(),sushu_receive.end(),inserter(result,result.begin()));
    cout<<"输出结果是："<<endl;
    for(auto temp:result){
        cout<<temp<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}