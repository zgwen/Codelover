/*
 *×Ö·û´®¼ÓÃÜ 
 */ 

#include <iostream>
#include <string>
#include <cstdio>
#include <ctype.h>
using namespace std;
int main()
{
    string key,str;
    string code="";
    int hashtab[26]={0};
    while(cin >> key >> str)
    {
        int len1=key.length();
        for(int i=0;i<len1;i++)
        {
            char c=toupper(key[i]);
            if(hashtab[c-'A']==0)
            {
				code+=c;
                hashtab[c-'A']=1;
            }
        }
        /*****/
        for(int i=0;i<26;i++)
        {
            if(hashtab[i]==0)
            {
                code+=(i+'A');
            }
        }
        /*****/
        int len2=str.length();
        for(int i=0;i<len2;i++)
        {
            if((str[i]>='a') && (str[i]<='z'))
                printf("%c",code[str[i]-'a'] + 32);
                //printf("%c#",str[i]);
            else if((str[i]>='A') && (str[i]<='Z'))
                printf("%c",code[str[i]-'a']);
                //printf("%c$",str[i]);
            if(i==len2-1)
                cout << endl;
        }
    }
    return 0;
}
