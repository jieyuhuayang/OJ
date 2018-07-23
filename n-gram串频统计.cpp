/*描述在文本分析中常用到n-gram串频统计方法，即，统计相邻的n个单元（如单词、汉字、或者字符）在整个文本中出现的频率。假设有一个字符串，请以字符为单位，按n-gram方法统计每个长度为 n  的子串出现的频度，并输出最高频度以及频度最高的子串。所给的字符串只包含大小写字母，长度不多于500个字符，且 1 < n < 5。

如果有多个子串频度最高，则根据其在序列中第一次出现的次序依次输出，每行输出一个，如果最高频度不大于1，则输出NO。

输入第一行为n；
第二行为字符串。输出输出最高频度以及频度最高的所有子串。若最高频度不大于1，只输出一行NO。样例输入3
abcdefabcd

样例输出2
abc
bcd

提示样例中，所有的3-gram是：abc,bcd,cde,def,efa,fab,abc,bcd。最后面的cd不足以形成3-gram，则不考虑。这样，abc 和 bcd 都出现了2次，其余的只出现了1次。

*/

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

