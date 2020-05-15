#include <iostream>
#include<bitset>
#include<climits>

#define dVersion " v1.3"
#define dUrl "http://edoyun.ke.qq.com"

int main()
{

	/*
我们收到了一位用户的激活请求，用户的硬件码为：930529060092641281
我们需要回馈给用户一个激活码，
例如:
192E-987E-675E-3E98-9172-972E
设计我们游戏中的激活部分程序，通过输入该激活码可以激活用户的游戏.

并且该激活码包含了16个等级的初始金币礼包，计算方式为 等级*等级*10000
包含了用户初始幸运属性，分为16个等级，这将影响到用户日后在游戏中的爆率。
同时我们还赠送了三件装备，分别是 武器，护甲，首饰，这三件装备等级分为16个阶，适用不同的等级阶段，最高可以强化至16，比如武器，可以是16阶强化+16

同时要求我们的激活码还具备一定的防伪能力，能够与用户的硬件码相呼应，即再其他的电脑中不能使用(我们假设用户提交的硬件码是唯一的)

*/

/*
基本思想:
	就是前四个就是用来做防伪的，剩下几个依次就是：
		金币、幸运值、武器
		装备、首饰
*/

	//930529060092641281
	// system("color 07");
	//setw setfill
	//设置命名空间以及变量的使用
	using std::bitset;
	using std::cout;
	using std::cin;
	using std::endl;
	int a{12};
	cout<<bitset<12>(a)<<endl;
	
	
	long long m_code{930529060092641281LL};	//硬件码 0x FFFF FFFFF //ffff ffff ^
	unsigned long long test_code{0xF2349876EF56CA24ULL}; //内置一个测试码

	cout<<std::hex<<m_code<<(char)10<<test_code<<(char)10<<LLONG_MAX<<endl;
	//long long end = m_code ^ test_code; //简单验证算法 fedd 7f36 ef56 ca25 2556 595f f=15
	//std::cout <<std::hex<< end;
	//end ^= test_code;
	//std::cout << end;
	unsigned short in_code1, in_code2, in_code3, in_code4, in_code5, in_code6;
	std::cout << "依次输入各组激活码(第一组):";
	std::cin >> std::hex; //切换进制?16进制模式输入
	std::cin >> in_code1;
	std::cout << "依次输入各组激活码(第二组?):";
	std::cin >> in_code2;
	std::cout << "依次输入各组激活码(第三组?):";
	std::cin >> in_code3;
	std::cout << "依次输入各组激活码(第四组?):";
	std::cin >> in_code4;
	std::cout << "依次输入各组激活码(第五组?):";
	std::cin >> in_code5;
	std::cout << "依次输入各组激活码(第六组?):";
	std::cin >> in_code6;
	long long end{};
	long long ls{}; //临时变量
	//计算ls变量,注意位运算是进行二进制而进行计算的，
	ls = in_code1;
	ls <<= 48;
	end = ls;
	ls = in_code2;
	ls <<= 32;
	end |= ls;
	ls = in_code3;
	ls <<= 16;
	end |= ls;
	end |= in_code4;
	//计算完之后进行异或运算
	end ^= test_code;

	//2556 595f f=15

	unsigned gMoney;//金币
	char gluck;//幸运值
	gMoney = (in_code5 & 0xF000) >> 12;
	gMoney *= gMoney;
	gMoney *= 10000;

	gluck = (in_code5 & 0x0F00) >> 8;

	char weaponlv; //武器的阶
	char weaponev; //武器的强化

	char armylv, armyev; //装备的阶数 强化值
	char necklv, neckev; //首饰的阶数 强化值

	weaponlv = (in_code5 & 0x00F0) >> 4;
	weaponev = (in_code5 & 0xF);

	armylv = (in_code6 & 0xF000) >> 12;
	armyev = (in_code6 & 0x0F00) >> 8;

	necklv = (in_code6 & 0x00F0) >> 4;
	neckev = (in_code6 & 0xF);

	std::cout << "可以激活的硬件码为:" << end << std::endl;
	std::cout << "您获得了" << gMoney << "的金币礼金?!" << std::endl;
	std::cout << "您的幸运值为" << (short)gluck << "!" << std::endl;
	std::cout << "您获得了强化值?" << (short)weaponev << "阶为:" << (short)weaponlv << "的武器?"
			  << "!" << std::endl;
	std::cout << "您获得了强化值?" << (short)armyev << "阶为:" << (short)armylv << "的装备?"
			  << "!" << std::endl;
	std::cout << "您获得了强化值?" << (short)neckev << "阶为:" << (short)necklv << "的首饰?"
			  << "!" << std::endl;
	system("pause");
	return 0;
}
