#include <iostream>
#include <limits>
using namespace std;

/*
项目设计
    为我们的游戏，设计一下我们的角色属性，我们的角色包括以下属性：
    门派（武当，峨眉，易云，葵花，唐门）
    武器（0-15阶，0-15强化），护甲（0-15阶，0-15强化），首饰（0-15阶，0-15强化）经验值生命值
    生命最大值
    内力值
    内力最大值
    坐标金币钻石
    幸运值
    累计消费
*/



//学派
//更加容易更换，而不必要关注背后的操作
enum class SCHOOL : char
{
    wudang,
    emei,
    edaoyun,
    kuihua,
    tangmen
};

//装备
struct Equip
{
    unsigned char lv{0}; //等级
    unsigned char ev{0}; //属性
};

//角色信息
struct RoleState
{
    int value{1000};         //生命值
    unsigned maxValue{1000}; //内力
};

//角色
struct Role
{
    unsigned char lv{1};
    SCHOOL school{SCHOOL::edaoyun};
    Equip weapon{1, 1};       //武器
    Equip army{1, 10};        //装备
    Equip neck{1, 10};        //首饰
    long long exp{0};         //经验值
    RoleState HP{1000, 1000}; //血量，生命
    RoleState MP{1000, 1000}; //内力
    //坐标
    unsigned x{500};
    unsigned y{500};
    //金币，money、diamond、luck就是之前进行保护的地方
    unsigned money{1000};  //钱是在购买的时候花掉的，当不够的时候可以不让你花，而生命值敌人就可能使你的血量变为负数，所以血量就有可能产生负数
    unsigned diamond{100}; //钻石
    unsigned char luck{2};
    unsigned vip_exp{0}; //表示本账号不是vip，只是普通用户
};

int main()
{
    Role user;
    using std::cin;
    using std::cout;
    cout<<"输入i的值";
    int i;
    cin>>i;
    cout << "当前生命值：" << user.HP.value << "/" << user.HP.maxValue << (char)10;
    cout << "当前内力值：" << user.MP.value << "/" << user.MP.maxValue << (char)10;
    cout << "坐标："
         << "[" << user.x << "] [" << user.y << "]" << (char)10;
    system("pause");
    return 0;
}