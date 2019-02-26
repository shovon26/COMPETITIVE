#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int sz=3;

void swap_row(double mat[sz][sz+1],int i,int j)
{
     for(int k=0;k<=sz;k++)
     {
         double temp=mat[i][k];
         mat[i][k]=mat[j][k];
         mat[j][k]=temp;
     }
}

int forwardElim(double mat[sz][sz+1])
{
    for(int k=0;k<sz;k++)
    {
        int i_max=k;
        int v_max=mat[i_max][k];

        for(int i=k+1;i<sz;i++)
        {
            if(abs(mat[i][k])>v_max)
                v_max=mat[i][k],i_max=i;
        }

        if(!mat[k][i_max])return k;///matrix is singular

        if(i_max!=k)swap_row(mat,k,i_max);

        for(int i=k+1;i<sz;i++)
        {
            double f=mat[i][k]/mat[k][k];

            for(int j=k+1;j<=sz;j++)
            mat[i][j]-=mat[k][j]*f;

            mat[i][k]=0;
        }
    }
    return -1;
}

void backSub(double mat[sz][sz+1])
{
    double sol[sz+1];
    for(int i=sz-1;i>=0;i--)
    {
        sol[i]=mat[i][sz];
        for(int j=i+1;j<sz;j++)
        {
            sol[i]-=mat[i][j]*sol[j];
        }
        sol[i]/=mat[i][i];
    }

    ///print solution

    for(int i=0;i<sz;i++)
        printf("%lf\n",sol[i]);
}

void gaussian_elim(double mat[sz][sz+1])
{
    int singular_flag=forwardElim(mat);

    if(singular_flag!=-1)
    {
        cout<<"Singular MAtrix."<<endl;

        if(mat[singular_flag][sz])cout<<"no solution"<<endl;
        else cout<<"Many solution"<<endl;

        return ;
    }

    backSub(mat);
}

int main()
{
    
     double mat[sz][sz+1] = {{3.0, 2.0,-4.0, 3.0},
                          {2.0, 3.0, 3.0, 15.0},
                          {5.0, -3, 1.0, 14.0}
                         };

     gaussian_elim(mat);

    return 0;
}
