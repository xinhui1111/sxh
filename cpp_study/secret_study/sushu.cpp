//����n����С������������
/*
    �������б��򣺶�������ʦɸ��
    �����壺��n>1,�������е�����p<=sqr(n)������p��=n,��n������
    ʵ�ַ�����
        �г�N���������Լ�С��sqr��n��������������ɾ����Щ�ı��������µľ�����Ҫ��Ĳ�����N������
        ����ɾ��2*p1,3*p1,...,[N/p1]*p1;
    ���ӣ��󲻳���N=100������
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//˵�����������Ҫͨ�õĻ�������Ҫ��sushu����������ͨ�õ����䣬ͬʱ��Ҳ����ؼ��Ĳ��֣����о���ini�ĳ�ʼ��
int main(){
    vector<int>sushu{2,3,5,7};
    vector<int>sushu_receive;
    //��ʼ��ini���飬1-100
    vector<int>ini{};
    for(int i=1;i<=100;++i){
        ini.push_back(i);
    }
    //��p�ı�������һ��������
    for(int i=0;i<sushu.size();++i){
        for(int j=1;j<=200/sushu[i];++j){
            sushu_receive.push_back(j*sushu[i]);
        }
    }
    //��sushu��ini���в����
    vector<int>result;
    sort(sushu_receive.begin(),sushu_receive.end());
    set_difference(ini.begin(),ini.end(),sushu_receive.begin(),sushu_receive.end(),inserter(result,result.begin()));
    cout<<"�������ǣ�"<<endl;
    for(auto temp:result){
        cout<<temp<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}