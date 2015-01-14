using namespace std;
#include<iostream>
float z[10][10];
float b[10][10];
int n;
void inverse ()
{

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            z[i][j]=0;
        }
    for(int i=0; i<n; i++)
        z[i][i]=1;

    for(int i=1; i<n+1; i++)
    {



        for(int p=i; p<n; p++)
        {
            float k=b[p][i-1]/b[i-1][i-1];

            for(int q=i-1; q<n; q++)
            {
                b[p][q]=b[p][q]-b[i-1][q]*k;
            }
            {
                for(int h=0; h<n; h++)
                {
                    z[p][h]=z[p][h]-z[i-1][h]*k;
                }
            }


        }
    }

    cout<<"\n\ninverse by inverse:\n\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\n";
        for(int j=0; j<n; j++)
        {
            z[i][j]=1/(b[i][i])*z[i][j];
            cout<<"\t"<<z[i][j];
        }
    }
}
int main()
{
    float a[10][10],x[10],A[10][10],s[10];
    cout<<"enter the size of the matrix";
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cout<<"enter";
            cin>>a[i][j];
            b[i][j]=0;
        }
    cout<<"Enter the constant:";
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        b[i][i]=1;
    }

    for(int i=1; i<n+1; i++)
    {
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

    cout<<"Lower triangular";
    inverse();
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            a[i][j]=0;
    cout<<"\nupper triangular";
    for(int i=0; i<n; i++)
    {
        cout<<"\n";
        for(int j=0; j<n; j++)
        {
            cout<<"\t"<<a[i][j];
        }
    }

    cout<<"\n";
    float k=0;

    x[0]=s[0]/z[0][0];
    for(int i=1; i<n; i++)
    {
        k=0;
        for(int j=0; j<i; j++)
        {
            k=k+z[i][j]*x[j];
        }
        x[i]=(s[i]-k)/z[i][i];
    }
    for(int i=0; i<n; i++)

        k=0;
    for(int i=0; i<n; i++)
    {
        s[i]=x[i];
    }
    x[n-1]=s[n-1]/a[n-1][n-1];
    for(int i=n-2; i>-1; i--)
    {
        k=0;
        for(int j=i+1; j<n; j++)
        {
            k=k+a[i][j]*x[j];
        }
        x[i]=(s[i]-k)/a[i][i];
    }

        cout<<"solutions are ";
    for(int i=0; i<n; i++)
        cout<<"x["<<i<<"]="<<x[i]<<"\n";


    return(0);
}

