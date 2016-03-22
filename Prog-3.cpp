#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctime>
using namespace std;


void quiksort(int* N, int p, int r);  // N[p.......r]
int partition(int* N, int p, int r); 
int BM_partition(int* N, int p, int r);
int mid(int* N,int q1,int q2,int q3);

int main()
{
/*
    ofstream fout;
    ifstream fin;
    fout.open("output3");
    fin.open("testbench");
                    
    int N[10001];
    int n = 1;
    while(fin>>N[n])n++;
                                   
    quiksort(N,1,10000);
                          
    for(int i=1;i<n;i++)
    {
       fout<<N[i]<<endl;
    }  

    fin.close();
    fout.close();

*/
    int N[1010];
    int n = 1;
    char tmp;
                
    while(cin>>tmp,tmp != 'x')
    {
        cin.putback(tmp);
        cin>>N[n++];
    }
    
    quiksort(N,1,n-1);
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<N[i]<<" ";
    }

}

void quiksort(int* N, int p, int r)
{
    //如果p < r代表還沒sort結束
    if(p < r){
        int q = BM_partition(N,p,r); // N[p...q-1] q N[q+1...r]
        quiksort(N,p,q-1);        //q已經在正確位置，繼續sort左右兩半
        quiksort(N,q+1,r);
    }
}
    

int partition(int* N, int p, int r)
{
    //   i     j
    //N[..p....r..]
    int i=p-1 , x=N[r], tmp; 
    for(int j = p; j<r ;j++)
    {
        //i要先++ 再交換 ，因為如果i,j只差1就只是同一個交換 N[...ij...]
        //這常的case應該是N[mmmissssj] m是小於X(含i),s相反,所以當j小於要跟i+1換=>N[mmmmissssj...]
        if( N[j] <= x)
        {
            i++;
            tmp = N[i];
            N[i] = N[j];
            N[j] = tmp;
        }
    }
    tmp = N[i+1];
    N[i+1] = x;
    N[r] = tmp;
    
    return i+1;  //q 就是 i+1
}

int BM_partition(int* N, int p, int r)
{
    int q, tmp, b = (r-p+1)/3 , b2; // b2 for record the block in the 3 group 
    if(b>=3)
    {
        b2 = b/3;
        int q1=p,q2=p+b2,q3=p+2*b2,
            q4=(p+b),q5=(p+b)+b2,q6=(p+b)+2*b2,
            q7=(p+2*b),q8=(p+2*b)+b2,q9=(p+2*b)+2*b2;
        q1 = mid(N,q1,q2,q3);
        q2 = mid(N,q4,q5,q6);
        q3 = mid(N,q7,q8,q9);
        q = mid (N,q1,q2,q3);
        tmp = N[q];
        N[q] = N[r];
        N[r] = tmp;
    }
    return partition(N,p,r);
}

int mid(int* N,int q1,int q2,int q3)
{
    int tmp;
     if(N[q1] < N[q3])
     {
         tmp = q1; q1=q3; q3 = tmp;
     }
     if(N[q2] < N[q3])
     {
         tmp = q2; q2=q3; q3 = tmp;
     }
     if(N[q1] < N[q2])
     {
         tmp = q1; q1=q2; q2 = tmp;
     }

     return q2;
}
