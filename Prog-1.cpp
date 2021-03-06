#include<iostream>
#include<stdio.h>
#include<fstream>  // for test

using namespace std;


void quiksort(int* N, int p, int r);  // N[p.......r]
int partition(int* N, int p, int r); 

int main()
{
    /*
    ifstream fin;
    ofstream fout;
    fin.open("testbench");
    fout.open("output");
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

    int N[100010];
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
        int q = partition(N,p,r); // N[p...q-1] q N[q+1...r]
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
