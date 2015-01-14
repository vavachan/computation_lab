using namespace std;
#include<iostream>
#include<math.h>

float a[10][10],q[10];
int  n=3;

float alpha(float r[10])
{

    float r1;
    float c;
    c=0;
    for(int i=0; i<n; i++)
    {
        c=c+pow(r[i],2);
    }
    float d=0,b=0;
    for(int i=0; i<n; i++)
    {
        d=0;
        for(int j=0; j<n; j++)
        {
            d=d+a[i][j]*r[j];

        }
        ;
        b=b+r[i]*d;
    }

    r1=c/b;
    return r1;
}

int main()
{
    float m;
    cout<<"We are trying to find the minima of the function x^2+y^2+z^2-xy-zy-3x-2y-5z+18.";
    cout<<"\nWe are finding this using steepest decsent method";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            a[i][j]=0;
        }
    q[0]=3;
    q[1]=2;
    q[2]=5;
    float x[10],r[10],g;
    for(int i=0; i<n; i++)
    {
        x[i]=0;
        a[i][i]=2;
    }

    a[0][1]=-1;
    a[1][2]=-1;
    a[1][0]=-1;
    a[2][1]=-1;
    for(int i=0; i<10; i++)
    {

        g=0;
        for(int k=0; k<n; k++)
        {
            m=0;
            for(int j=0; j<n; j++)
            {
                m=m+a[k][j]*x[j];
            }
            r[k]=q[k]-m;

        }

        g=alpha(r);


        for(int j=0; j<n; j++)
        {

            x[j]=x[j]+g*r[j];

        }

    }
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<"\t"<<x[i];
    return (0);

}

