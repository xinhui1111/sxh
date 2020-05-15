#include <iostream>

enum class SCHOOL :char
{
     wudang,
	 emei,
	 edoyun,
	 kuihua,
	 tangmen
};

struct Equip
{
	unsigned char lv{ 0 };
	unsigned char ev{ 0 };
};

struct RoleState
{
	int           value{ 1000 };//100 500-400 455000000>0
	unsigned      maxValue{ 1000 };
};

struct Role
{
	unsigned char lv{ 1 };
	SCHOOL        school{ SCHOOL::edoyun };
	Equip         weapon{ 1,1 };
	Equip         army{ 1,10 };
	Equip         neck{ 1,10 };
	long long     exp{ 0 };//1-255
	RoleState     HP{ 1000,1000 };
	RoleState     MP{ 1000,1000 };
	unsigned      x{ 500 };
	unsigned      y{ 500 };
	unsigned      Money{ 1000 };
	unsigned      Diamond{ 100 };
	unsigned char luck{ 2 };
	unsigned      vip_exp{0};
};

int main()
{
	Role user;
	std::cout << "生命"<<user.HP.value << "/" << user.HP.maxValue<<std::endl;
	std::cout << "内力" << user.MP.value << "/" << user.MP.maxValue << std::endl;
	std::cout << "坐标[" << user.x << "][" << user.y << "]"<<std::endl;

	user.school = SCHOOL::kuihua;

	Role userMaster;
	Role userWife;

}


