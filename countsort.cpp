#include<iostream>
using namespace std;

//计数排序总结，算法思想基于桶排序，适合数范围小，数量大。总结起来就是以每个不同的数为一种“桶”
//相应的数在数组中出现多少次，计数为多少。最后将计数数组变现为实际数组

void countsort(int arr[], int length, int num)
{
    int count[num]={0};
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[j] == i)
            {
                count[i]++;
            }
            
        }
    }

    //现在有数组count，其中每一个位置对应相应位置数的个数，接下来应该把count数组转换为真实数组
    for (int i = 0, k = 0; i < num; i++)
    {
        for (int j =0; j < count[i]; j++, k++)
        {
            arr[k] = i;
        }
        
        
    }

}

int findlength(int arr[], int num)
{
    int a[num];
    int b=0;//b为数组a中的元素个数
    a[0] = arr[0];
    b++;

    for (int i = 1; i < num; i++)
    {
        int temp = 0;
        for (int j = 0; j < b; j++)
        {
            if (a[j] == arr[i])
            {
                temp++;
                break;
            }
            
        }
        if (temp==0)
        {
            b++;
            a[b] = arr[i];
        } 
    }
    return b;
    
}

void print(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

void test01()
{
    int arr[] ={9,2,0,1,6,9,8,5,2,3,0,1,4,7,8,9,6,4,3,2,1};
    int num = findlength(arr,21);
    //cout<<"数值中不同元素的个数为"<<num<<endl;
    countsort(arr, 21, num);
    print(arr,21);

}



int main()
{
    test01();


    return 0;
}