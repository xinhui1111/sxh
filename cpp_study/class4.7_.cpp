#include <iostream>
#include<bitset>
#include<climits>

#define dVersion " v1.3"
#define dUrl "http://edoyun.ke.qq.com"

int main()
{

	/*
�����յ���һλ�û��ļ��������û���Ӳ����Ϊ��930529060092641281
������Ҫ�������û�һ�������룬
����:
192E-987E-675E-3E98-9172-972E
���������Ϸ�еļ���ֳ���ͨ������ü�������Լ����û�����Ϸ.

���Ҹü����������16���ȼ��ĳ�ʼ�����������㷽ʽΪ �ȼ�*�ȼ�*10000
�������û���ʼ�������ԣ���Ϊ16���ȼ����⽫Ӱ�쵽�û��պ�����Ϸ�еı��ʡ�
ͬʱ���ǻ�����������װ�����ֱ��� ���������ף����Σ�������װ���ȼ���Ϊ16���ף����ò�ͬ�ĵȼ��׶Σ���߿���ǿ����16������������������16��ǿ��+16

ͬʱҪ�����ǵļ����뻹�߱�һ���ķ�α�������ܹ����û���Ӳ�������Ӧ�����������ĵ����в���ʹ��(���Ǽ����û��ύ��Ӳ������Ψһ��)

*/

/*
����˼��:
	����ǰ�ĸ�������������α�ģ�ʣ�¼������ξ��ǣ�
		��ҡ�����ֵ������
		װ��������
*/

	//930529060092641281
	// system("color 07");
	//setw setfill
	//���������ռ��Լ�������ʹ��
	using std::bitset;
	using std::cout;
	using std::cin;
	using std::endl;
	int a{12};
	cout<<bitset<12>(a)<<endl;
	
	
	long long m_code{930529060092641281LL};	//Ӳ���� 0x FFFF FFFFF //ffff ffff ^
	unsigned long long test_code{0xF2349876EF56CA24ULL}; //����һ��������

	cout<<std::hex<<m_code<<(char)10<<test_code<<(char)10<<LLONG_MAX<<endl;
	//long long end = m_code ^ test_code; //����֤�㷨 fedd 7f36 ef56 ca25 2556 595f f=15
	//std::cout <<std::hex<< end;
	//end ^= test_code;
	//std::cout << end;
	unsigned short in_code1, in_code2, in_code3, in_code4, in_code5, in_code6;
	std::cout << "����������鼤����(��һ��):";
	std::cin >> std::hex; //�л�����?16����ģʽ����
	std::cin >> in_code1;
	std::cout << "����������鼤����(�ڶ���?):";
	std::cin >> in_code2;
	std::cout << "����������鼤����(������?):";
	std::cin >> in_code3;
	std::cout << "����������鼤����(������?):";
	std::cin >> in_code4;
	std::cout << "����������鼤����(������?):";
	std::cin >> in_code5;
	std::cout << "����������鼤����(������?):";
	std::cin >> in_code6;
	long long end{};
	long long ls{}; //��ʱ����
	//����ls����,ע��λ�����ǽ��ж����ƶ����м���ģ�
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
	//������֮������������
	end ^= test_code;

	//2556 595f f=15

	unsigned gMoney;//���
	char gluck;//����ֵ
	gMoney = (in_code5 & 0xF000) >> 12;
	gMoney *= gMoney;
	gMoney *= 10000;

	gluck = (in_code5 & 0x0F00) >> 8;

	char weaponlv; //�����Ľ�
	char weaponev; //������ǿ��

	char armylv, armyev; //װ���Ľ��� ǿ��ֵ
	char necklv, neckev; //���εĽ��� ǿ��ֵ

	weaponlv = (in_code5 & 0x00F0) >> 4;
	weaponev = (in_code5 & 0xF);

	armylv = (in_code6 & 0xF000) >> 12;
	armyev = (in_code6 & 0x0F00) >> 8;

	necklv = (in_code6 & 0x00F0) >> 4;
	neckev = (in_code6 & 0xF);

	std::cout << "���Լ����Ӳ����Ϊ:" << end << std::endl;
	std::cout << "�������" << gMoney << "�Ľ�����?!" << std::endl;
	std::cout << "��������ֵΪ" << (short)gluck << "!" << std::endl;
	std::cout << "�������ǿ��ֵ?" << (short)weaponev << "��Ϊ:" << (short)weaponlv << "������?"
			  << "!" << std::endl;
	std::cout << "�������ǿ��ֵ?" << (short)armyev << "��Ϊ:" << (short)armylv << "��װ��?"
			  << "!" << std::endl;
	std::cout << "�������ǿ��ֵ?" << (short)neckev << "��Ϊ:" << (short)necklv << "������?"
			  << "!" << std::endl;
	system("pause");
	return 0;
}
