#include <iostream>
#include <vector>
using namespace std;

//节点定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//翻转函数定义
ListNode *reverseList(ListNode *head)
{
    vector<int> rec{};
    //头结点存入数组
    if (head == nullptr)
        return nullptr;
    else
        rec.push_back(head->val);
    //将节点都存入数组
    ListNode *next = head->next;
    while (next)
    {
        rec.push_back(next->val);
        if(next->next)
            next=next->next;
        else
            break;
    }
    
    cout<<"output:"<<endl;
    for(auto temp:rec)
        cout<<temp<<endl;
    
    ListNode *head2=new ListNode(*(rec.end()-1));rec.pop_back();
    ListNode *next2=head2;
    //翻转导入数组,其中顶部一个已经进行了pop
    for(auto temp=rec.end()-1;temp>=rec.begin();temp--){
        next2->next=new ListNode(*temp);
        next2=next2->next;
    }
    return head2;
}

int main()
{
    vector<int>rec{1,2,3,4};
    cout<<*(rec.end()-1)<<"  "<<*rec.begin()<<endl;

    ListNode *head=new ListNode(1);
    ListNode *next=head;
    next->next=new ListNode(2);next=next->next;
    next->next=new ListNode(3);next=next->next;
    next->next=new ListNode(4);next=next->next;
    next->next=new ListNode(5);next=next->next;

    ListNode *l=reverseList(head);
    system("pause");
    return 0;
}