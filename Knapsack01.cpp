#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
/*
int max(int a, int b){ //if i don't include math.h lib
    if(a>b){
        return a;
    }else{
        return b;
    }
}
*/
void knapsack(vector<vector<int>>& value,vector<int>& weight,vector<int>& val, int capacity, int item){
    for(int i=1; i<=item;i++){    //table filling in matrix form
        for(int j=1; j<=capacity;j++){
            if(weight[i-1] <= j){
                value[i][j] = max(val[i-1]+value[i-1][j-weight[i-1]], value[i-1][j]);
            }else{
                value[i][j] = value[i-1][j];
            }
        }
    }

    for(int i=0; i<=item;i++){  //for matrix display
        for(int j=0;j<=capacity;j++){
            cout<<value[i][j]<<"\t";
        }   cout<<endl;
    }
    cout<<"\nMax Value: "<<value[item][capacity]<<endl;

    //finding the selected items
    int i=item, j = capacity;
    while(i>0 && j>0){
        if(value[i][j] != value[i-1][j]){
            cout<<"Item-"<<i<<" is selected -- value: "<<val[i-1]<<"\tweight: "<<weight[i-1]<<endl;
            j = j-weight[i-1];
        }   i--;
    }
}

int main(){
    int item = 4;
    vector<int> w = {2,3,5,7};
    vector<int> v = {10,5,15,7};
    int capacity = 10;

    vector<vector<int>> value(item+1, vector<int>(capacity+1));
    knapsack(value,w,v,capacity,item);
    return 0;
}