//11、盛最多水的容器
/*
    如题意，垂直的两条线段将会与坐标轴构成一个矩形区域，较短线段的长度将会作为矩形区域的宽度，
    两线间距将会作为矩形区域的长度，而我们必须最大化该矩形区域的面积。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//暴力方法解决
int maxArea(vector<int> &height)
{
    // sort(height.begin(),height.end());
    // for(int temp:height)
    //     cout<<temp<<endl;
    int len{(int)height.size()};
    int max = min(height[1], height[0]);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int area = min(height[j], height[i]) * (j - i);
            max = area > max ? area : max;
        }
    }
    return max;
}

//双指针法
int maxArea2(vector<int> &height)
{
    //设置左右两个指针
    int a{0};
    int b{height.size() - 1};
    int local_value = min(height[a], height[b]) * (b - a);

    while (a != b)
    {
        int temp{0};
        //大于的时候移动b
        if (height[a] > height[b])
        {
            temp = b - 1;
            if (min(height[temp], height[a]) * (temp - a) > local_value)
                local_value = min(height[temp], height[a]) * (temp - a);
            b--;
        }
        //小于的时候移动a
        else
        {
            temp=a+1;
            if(min(height[temp],height[b])*(b-temp)>local_value)
                local_value=min(height[temp],height[b])*(b-temp);
            a++;
        }
    }
    return local_value;
}
int main()
{
    min(12, 133);
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height);
    cout<<(char)10<<maxArea2(height)<<(char)10;
    system("pause");
    return 0;
}