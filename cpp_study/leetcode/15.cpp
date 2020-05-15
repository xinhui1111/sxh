/*
问题描述：
    给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
    使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：
    答案中不可以包含重复的三元组。

*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using std::cin;
using std::cout;
using std::set;
using std::vector;

typedef struct logo_three
{
    int a;
    int b;
    int c;
} Logo_T;

vector<vector<int>> threeSum(vector<int> &nums)
{
    //对nums进行排序
    std::sort(nums.begin(), nums.end());
    //用于保存符合要求的三个一组的数
    set<Logo_T> logo_num;
    int a1, a2, a3; //用于标记
    for (int i = 0; i < nums.size(); ++i)
    {
        int now = nums[i];
        //left从0开始，right从最大值开始
        int left{nums[0]}, right{nums.size() - 1};
        bool succcessed{true};
        while (left != right)
        {
            if (left + right + now > 0)
            {
                if(right-1!=now)
                    right--;
                else
                    break;
                while (right == right - 1 && right-1 != now)
                {
                    right--;
                }
            }
            else if (left + right + now < 0)
            {
                //判断left接下来的值是不是超限
                if(left+1!=now)
                    left++;
                else
                    break;
                
                while (left == left + 1 && left+1 != now)
                {
                    left++;
                }
            }
            else
            {
                logo_num.insert({left, now, right});
                bool sign1{true};bool sign2{true};
                while (sign1 || sign2)
                {
                    if (left == left + 1)
                        left++;
                    else
                        sign1=false;
                    if (right == right - 1)
                        right--;
                    else
                        sign2=false;
                }
            }
        }
    }
}

int main()
{

    system("pause");
    return 0;
}