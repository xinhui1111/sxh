#include <iostream>
#include <cctype>
#include <locale>
#include <stddef.h>
using namespace std;

//判断是都是大写
bool _isupper(char c)
{
    if (c >= 65 && c <= 90)
        return true;
    else
        return false;
}
//判断是否是小写
bool _islower(char c)
{
    if (c >= 97 && c <= 122)
        return true;
    else
        return false;
}
//判断是否是字母
bool _isalpha(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;
    else
        return false;
}
//判断是否是数字
bool _isdigit(char c)
{
    if (c >= 48 && c <= 57)
        return true;
    else
        return false;
}
//判断是否是数字和字母
bool _isalnum(char c)
{
    if (_isalpha(c) && _isdigit(c))
        return true;
    else
        return false;
}
//判断是否是空白
/*
HT LF VT FF CR SP
 9 10 11 12 13 32
*/
bool _isspace(char c)
{
    if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
        return true;
    if (c == 32)
        return true;
    return false;
}
//判断是都是空格
bool isblank(char c)
{
    if (c == 32)
        return true;
    else
        return false;
}
//判断是否是标点符号
/*
SPC TAB LF VT FF CR
32   9  10 11 12 13
*/
bool _ispunct(char c)
{
    if (c == 32 || c == 0x09 || c == 0x0a || c == 0x0b || c == 0x0c || 0x0d)
        return true;
    else
        return false;
}
//返回是否是打印字符
bool _isprint(char c)
{
    if (c > 0x1f && c != 0x7f) //31 127
        return true;
    else
        return false;
}
//返回是否是控制字符
bool _iscntrl(char c)
{
    if (c == 0x00 || 0x1f || 0x7f) //NULL US DEL
        return true;
    else
        return false;
}

//基本是可以打印的字符，但是得除去空格
bool _isgraph(char c)
{
    if (c == 32) //空格的ASCII码是32
        return false;
    if (isprint(c))
        return true;
    else
        return false;
}
//将大写转换为小写
char _tolower(char c)
{
    if (_isupper(c))
        c = (char)(c + 32);
    return c;
}
//将小写转换为大写字母
bool _toupper(char c)
{
    if (_islower(c))
        c=(char)(c-32);
    return c;
}

int main()
{
    cout<<_isgraph(' ');
    isprint('a');
    ispunct('a');
    isspace('a');
    tolower('a');
    isalnum('a');

    system("pause");
    return 0;
}
