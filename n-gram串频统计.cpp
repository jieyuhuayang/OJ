#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string text;
    int i,j,n,num=0,flag=1;//num:目前有多少个统计频率的数组
    cin>>n;
    cin>>text;
    int length=text.size()-n+1;
    string sub[length];
    vector <int> freq(length,0); //词频统计数组
    for(i=0;i<length;i++)
    {
        for(j=0;j<num;j++)
        {
            if(text.substr(i,n)==sub[j])
            {
                flag=0;
                freq[j]++;
                break;
            }
        }
        if(flag==1)     //说明没有匹配的
        {
            sub[j]=text.substr(i,n);
            freq[j]++;
            num++;

        }
        if(flag==0)
            flag=1;
    }

    vector<int>::iterator ite;

    vector<int>::iterator max= max_element(freq.begin(),freq.begin()+num);
    if(*max<=1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        for(j=0;j<num;j++)
        {

        if(freq[j]==*max)
            cout<<sub[j]<<':'<<freq[j]<<endl;
        }
    }



    return 0;
}

