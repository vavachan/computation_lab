#include<iostream>
using namespace std;
int main()
{

    float a[10][10],b[10][10],x[10],c[10],s[10];
    int n;
    cout<<"This program solves the matrix equation Ax=B where A is a nXn matrix B is a n-tuple \n";
    cout<<"This program takes A and B as input and outputs the tuple x for which Ax=B is satisfied using Gauss Elimination\n";
    cout<<"enter the size of the matrix ie n: ";
    cin>>n;
    //Please note The B in Ax=B is not the b in the program.
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cout<<"enter";
            cin>>a[i][j];
            b[i][j]=0;
        }
    for(int i=0; i<n; i++)
        b[i][i]=1;

    for(int i=1; i<n+1; i++)
    {
        for(int w=0; w<n; w++)
        {
            if(a[w][w]==0)
                for(int l=w+1; l<n; l++)
                {
                    if(a[l][w]!=0)
                    {
                        for(int d=0; d<n; d++)
                        {
                            float o,p;
                            o=a[w][d];
                            a[w][d]=a[l][d];
                            a[l][d]=o;
                            p=b[w][d];
                            b[w][d]=b[l][d];
                            b[l][d]=p;
                        }
                        break;
                    }
                }
        }
        /*cout<<"and the output is :";
        for(int i=0; i<n; i++)
        {
            cout<<"\n";
            for(int j=0; j<n; j++)
            {
                cout<<"\t"<<a[i][j];
            }
        }
        cout<<"\n\n";
        cout<<"and the output2 is :";
        for(int i=0; i<n; i++)
        {
            cout<<"\n";
            for(int j=0; j<n; j++)
            {
                cout<<"\t"<<b[i][j];
            }
        }
        cout<<"\n\n";
*/
        for(int p=i; p<n; p++)
        {
            float k=a[p][i-1]/a[i-1][i-1];
            //cout<<"\nk is "<<k;
            for(int q=i-1; q<n; q++)
            {
                a[p][q]=a[p][q]-a[i-1][q]*k;
            }
            {
                for(int h=0; h<n; h++)
                {
                    b[p][h]=b[p][h]-b[i-1][h]*k;
                }
            }


        }
    }
    float k=0;
    cout<<"enter the tuple B";
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
    {
        c[i]=0;
        for(int j=0; j<n; j++)
        {
            c[i]=c[i]+b[i][j]*s[j];
//cout<<"b"<<b[i][j]<<"x"<<x[j];
        }
    }
    x[n-1]=c[n-1]/a[n-1][n-1];
    for(int i=n-2; i>-1; i--)
    {
        k=0;
        for(int j=i+1; j<n; j++)
        {
            k=k+a[i][j]*x[j];
        }
        x[i]=(c[i]-k)/a[i][i];
    }
    cout<<"x is ";
    for(int i=0; i<n; i++)
        cout<<"x["<<i<<"]="<<x[i]<<"\n";


    return (0);
}
