#include<iostream>
using namespace std;
int main()
{
    float a[10][10],b[10][10],x[10],c[10];
    int n;
    cout<<"This program solves the matrix equation Ax=B where A is a nXn matrix B is a n-tuple \n";
    cout<<"This program takes A and B as input and outputs the tuple x for which Ax=B is satisfied using pivoted Gauss Elimination\n";
    cout<<"enter the size of the matrix ie n: ";
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cout<<"enter A"<<i<<j;
            cin>>a[i][j];
            cout<<"\n";
            b[i][j]=0;
        }
    cout<<"Enter the constant:";
    //Note: x and b are not the x and B in Ax=B, c is B
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
        b[i][i]=1;
    }
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

        //cout<<"\n\n";

        for(int p=i; p<n; p++)
        {

            float k=a[p][i-1]/a[i-1][i-1];
      //      cout<<"\nk is "<<k;
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
    //cout<<"\n\noutput 2\n\n";
    for(int i=n-2; i>-1; i--)
    {

        for(int p=i; p>-1; p--)
        {
            float k=a[p][i+1]/a[i+1][i+1];
            //cout<<"\nk is "<<k<<"\n";
            for(int q=i+1; q>-1; q--)
            {
                a[p][q]=a[p][q]-a[i+1][q]*k;


            }
            {
                for(int h=0; h<n; h++)
                {
                    b[p][h]=b[p][h]-b[i+1][h]*k;
                }
            }
        }
    }


    for(int i=0; i<n; i++)
    {
        //cout<<"\n";
        for(int j=0; j<n; j++)
        {
            //cout<<"\t"<<1/(a[i][i])*b[i][j];
            b[i][j]=1/(a[i][i])*b[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        c[i]=0;
        for(int j=0; j<n; j++)
        {
            c[i]=c[i]+b[i][j]*x[j];
//cout<<"b"<<b[i][j]<<"x"<<x[j];
        }
    }
    cout<<"the solutions:";
    for(int i=0; i<n; i++)
    {
        cout<<"\n";
        cout<<c[i];
    }

    cout<<"\n\n";
    return(0);
}

