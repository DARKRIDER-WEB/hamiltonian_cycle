#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n);
bool issafe(int graph[5][5],int pos,int v,int arr[])
{
    if(graph[arr[pos-1]][v]==0)
        return false;

    for(int i=0;i<pos;i++)
        if(arr[i]==v)
        return false;

    return true;
}
bool hamil(int graph[5][5],int arr[],int n,int pos)
{
    if(pos==n)
    {
        if(graph[0][arr[pos-1]]==1)
            return true;

            else
            return false;
    }
    for(int i=1;i<n;i++)
    {
        if(issafe(graph,pos,i,arr))
        {
            arr[pos]=i;

            if(hamil(graph,arr,n,pos+1)==true)
            {
                return true;
            }

            arr[pos]=-1;
        }

    }
    return false;
}

bool hamilcycle(int graph[5][5])
{
    int *arr=new int[5];
 for (int i = 0; i < 5; i++)
        arr[i] = -1;
   // memset(arr,sizeof(arr),-1);
    arr[0]=0;

    if(hamil(graph,arr,5,1)==false)
    {
        cout<<"false";
        return false;
    }
    print(arr,5);
    return true;
}
void print(int arr[],int n)
{
    cout<<"SOLUTION IS"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[0];
    cout<<endl;
}
int main()
{
    int graph[5][5]= {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
    /*{{0, 1, 0, 1, 0},
                {1, 0, 1, 1, 1},
                {0, 1, 0, 0, 1},
                {1, 1, 0, 0, 1},
                {0, 1, 1, 1, 0}};*/

                hamilcycle(graph);

    return 0;
}

