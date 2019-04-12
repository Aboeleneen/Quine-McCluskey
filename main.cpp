#include <iostream>
#include<math.h>
using namespace std;
#define max_size 10000
void tobinary(int a,int c);
int table[max_size][max_size]= {0,0};
int res[max_size];
int index=0,index2=0;
int main()
{
    int num_variable,num_minterm,minterm ;
    cout << "Enter number of variables:\n";
    cin >> num_variable ;
    cout << "Enter number of minterms:\n";
    cin >> num_minterm ;
    int c=num_minterm;
    int count1=0,count2=0,count3=0,count4=0,count5=0,y=0,x=0,max_num=pow(2,num_variable);
    cout << "Enter minterm in the range" << "( 0 ) and ( " << max_num-1 << " )\n" ;
    for(int i=0; i<num_minterm; i++)
    {
again:
        cin >> minterm ;
        if(minterm>=max_num)
        {
            cout << "Enter number in the range" << "( 0 ) and ( " << max_num-1 << " )\n" ;
            goto again ;
        }
        tobinary(minterm,num_variable);
    }
    for(int i=0; i<num_minterm; i++)
    {
        if(x==0)
        {
            count1=num_minterm;
            x=1;
        }
        for(int j=i; j<num_minterm; j++)
        {
            for(int n=0; n<num_variable; n++)
            {
                if(table[i][n]!=table[j][n]&&i!=j)
                {
                    count5++;
                    y=n;
                }
            }
            if(count5==1)
            {
                table[i][num_variable]=1;
                table[j][num_variable]=1;
                count4+=2;
                for(int k=0; k<num_variable; k++)
                {
                    if(k==y)
                        table[c][k]=2;
                    else
                        table[c][k]=table[i][k];
                }
                c++;
                count2++;
            }
            count5=0;


        }
        count3++;
        if(count3==count1)
        {
            res[index2]=num_minterm;
            index2++;
            num_minterm=num_minterm+count2;
            x=0;
            count2=0;
        }

    }
    count5=0;
    for(int i=0; i<c; i++)
    {
        for(int j=i; j<c; j++)
        {
            for (int n=0; n<num_variable; n++)
            {
                if(table[i][n]==table[j][n]&&i!=j)
                    count5++;
            }
            if(count5==num_variable)
            {
                table[j][num_variable]=1;
            }
            count5=0;
        }

    }
    cout << "------------------\n"   ;

    for(int i=0; i<c; i++)
    {

        int n=0;
        for(int j=0; j<num_variable; j++)
        {
            if(table[i][j]==2||table[i][num_variable]==1)
                cout << "",n++;
            else if (table[i][j]==1)
                cout << "X" << j <<" ";
            else
                cout << "X" <<j << "^ " ;
        }
        if(n!=num_variable)
            cout << endl ;

    }
    return 0;
}
void tobinary(int a,int c)
{
    int k=c-1;
    int b=0;
    while(a!=0)
    {
        b=a%2;
        a=a/2;
        table[index][k]=b ;
        k--;
    }
    index++;
}
