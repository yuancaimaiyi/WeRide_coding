
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//思路是先找重复元素，分为三种情况
//1、p,q至少一个重复元素个数为3
//2、p,q至少有一个重复元素个数为2
//3、p,q 没有重复元素，这个时候就是对其各自排序，从最大值开始比较。
int findRepetNum(vector<int> arr)
{
    int size1=arr.size();
    vector<int> arr_temp;
    arr_temp=arr;
    auto it =std::unique(arr_temp.begin(),arr_temp.end());
    arr_temp.erase(it,arr_temp.end());
    int size2=arr_temp.size();
    return (size1-size2+1);
}
int deleteRepetnum(vector<int> arr)
{
    auto it=std::unique(arr.begin(),arr.end());
    arr.erase(it-1,arr.end());
    if(arr.size()==1)//3个元素有两个重复
    {
        return arr[0];
    }
    else{
        return 0;
    }
}
vector<int> cmp(vector<int> p,vector<int> q)
{
    int num1=findRepetNum(p);
    int num2=findRepetNum(q);
    // 情况1 num1 num2 至少有一个重复元素为3
    if(num1==3 && num2==3)
    {
        if(p[0]>q[0])
        {
            return p;
        }
        else
        {
            return q;
        }
    }
    if(num1==3 && num2!=3)
    {
        return p;
    }
    if(num1!=3 && num2==3)
    {
        return q;
    }
// 情况2 p,q至少有一个重复元素为2；
    if(num1==2 && num2==2)
    {
        auto it_p=std::unique(p.begin(),p.end());
        auto it_q=std::unique(q.begin(),q.end());
        if(*it_p > *it_q)
        {
            return p;
        }
        else if(*it_p < *it_q){
            return q;

        }
        else//两对子相等,比较剩下一个元素
        {
            if(deleteRepetnum(p)>deleteRepetnum(q))
            {
                return p;
            }
            else{
                return q;
            }

        }
    }
    if(num1==2 && num2!=2)
    {
        return p;
    }
    if(num1!=2 && num2==2)
    {
        return q;
    }
//情况3 p,q元素都没有重复
 if(num1==1 && num2==1)
 {
     std::sort(p.begin(),p.end());
     std::sort(q.begin(),q.end());
     if(p[2]>q[2])
     {
         return p;
     }
     else if(p[2]==q[2])
     {
         if(p[1]>q[1])
         {
             return p;
         }
         else if(p[1]<q[1])
         {
             return q;
         }
         else
         {
             if(p[0]>q[0])
             {
                 return p;
             }
             else {
                 return q;
             }
         }
     }
 }

}

int main()
{
    vector<int> p{3,3,3};
    vector<int>q{1,4,4};
    vector<int> r;
    r=cmp(p,q);
    cout<<"最大的牌是:";
    for(auto i:r)
    {
        printf("%d ",i);
    }
    return 0;
}
