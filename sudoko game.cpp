#include<bits/stdc++.h>
using namespace std;
bool check(int i,int j,char k,vector<vector<char>>&sudoko)
{
    for(int m=0;m<9;m++)
    {
        if(sudoko[i][m]==k)return false;
        if(sudoko[m][j]==k)return false;
        if(sudoko[3*(i/3)+m/3][3*(j/3)+m%3]==k)return false;
    }
    return true;
}
bool solve(vector<vector<char>>&sudoko)
{
    for(int i=0;i<sudoko.size();i++)
    {
        for(int j=0;j<sudoko[0].size();j++)
        {
            if(sudoko[i][j]=='*')
            {
                for(char k='1';k<='9';k++)
                {
                    if(check(i,j,k,sudoko))
                    {
                        sudoko[i][j]=k;
                        if(solve(sudoko)==true)return true;
                        else{ sudoko[i][j]='*';}
                    }

                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>>sudoko(9,vector<char>(9,'*'));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>sudoko[i][j];
        }
    }

    solve(sudoko);
    for(int i=0;i<sudoko.size();i++)
    {
        for(char j:sudoko[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
