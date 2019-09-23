#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void shellSort(vector<int> &arr, int n){
    int gap =n;
    int flag ;
    while (gap>=1)
    {
        gap =gap/2;
        for(int i=0;i<arr.size()-gap-1;i++)
        {
            int j=i+gap;
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }  
        
    }
    

}

int main() {

    int a[10] = {1,9,8,7,6,5,4,3,2,10};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    shellSort(vec,10);
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}