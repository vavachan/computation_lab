using namespace std;
#include<iostream>
#include<math.h>
float a[10][10],q[10];
float n=3;

float alpha(float r[10],float d[10])
{

    float r1;
    float c;
    c=0;
    for(int i=0; i<n; i++)
    {
        c=c+pow(r[i],2);
    }
    float v=0,b=0;
    for(int i=0; i<n; i++)
    {
        v=0;
        for(int j=0; j<n; j++)
        {
            v=v+a[i][j]*d[j];

        }

        b=b+d[i]*v;
    }
    r1=c/b;
    return r1;
}
float beta(float r[10],float r1[10])
{

    float beta;
    float c;
    c=0;
    for(int i=0; i<n; i++)
    {
        c=c+pow(r[i],2);
    }
    float b=0;
    for(int i=0; i<n; i++)
    {
        b=b+pow(r1[i],2);
    }
    beta=b/c;
    return beta;
}

int main()
{
    float m=0;
    float x[10],r[10],r1[10],d[10],ad[10],alp,bet;
    cout<<"We are trying to find the minima of the function x^2+y^2+z^2-xy-zy-3x-2y-5z+18.";
    cout<<"\nWe are finding this using conjugate gradient method";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            a[i][j]=0;
        }
    q[0]=3;
    q[1]=2;
    q[2]=5;

    for(int i=0; i<n; i++)
    {

        a[i][i]=2;
    }

    a[0][1]=-1;
    a[1][2]=-1;
    a[1][0]=-1;
    a[2][1]=-1;


    for(int i=0; i<n; i++)
    {
        x[i]=1;
    }
    for(int k=0; k<n; k++)
    {
        m=0;
        for(int j=0; j<n; j++)
        {
            m=m+a[k][j]*x[j];
        }
        d[k]=r[k]=q[k]-m;

    }
    for(int i=0; i<n; i++)
    {



        alp=alpha(r,d);

        for(int j=0; j<n; j++)
        {

            x[j]=x[j]+alp*d[j];

        }
        for(int k=0; k<n; k++)
        {
            m=0;
            for(int j=0; j<n; j++)
            {
                m=m+a[k][j]*d[j];
            }
            ad[k]=m;

        }
        for(int j=0; j<n; j++)
        {

            r1[j]=r[j]-alp*ad[j];

        }

        bet=beta(r,r1);

        for(int j=0; j<n; j++)
        {

            d[j]=r1[j]+bet*d[j];

        }


        for(int k=0; k<n; k++)
            r[k]=r1[k];
    }
    cout<<"\n";
    cout<<"The minima is (x,y,z)";
    for(int i=0; i<n; i++)
        cout<<"\t"<<x[i];
    return 0;


}

