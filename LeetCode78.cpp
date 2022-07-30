// This is not a permutation problem! This problem only needs different/non-duplicated subsets of it parent array.
#include<iostream>
#include<vector>
using namespace std;

// Can be solved with backtracking
vector<vector<int>> ans;

void backTrack(vector<int>& set,int idx, vector<int>& curr){
    if(idx==set.size()){
        ans.push_back(curr);
        return;
    }

    // use the element
    curr.push_back(set[idx]);
    backTrack(set,idx+1,curr);

    // do not use the element
    curr.pop_back();
    backTrack(set,idx+1,curr);
}

vector<vector<int>> subsets(vector<int> set){
vector<int> curr;
backTrack(set,0,curr);
return ans;
}

void print(vector<vector<int>> outs){
    cout<<"[ ";
    for(int i=0;i<outs.size();i++){
        cout<<" [ ";
        for(int j=0;j<outs[i].size();j++){
            cout<<outs[i][j];
            if(j<outs[i].size()-1) cout<<",";
        }
        cout<<" ] ";
        if(i!=outs.size()-1) cout<<",";
    }
    cout<<" ]"<<endl;
}

void print(vector<int> outs){
    cout<<"[ ";
    for(int i=0;i<outs.size();i++) {
        cout<<outs[i];
        if(i<outs.size()-1) cout<<",";
    }
    cout<<" ]"<<endl;
}

int main(){
    vector<int> set={1,2,3};
    print(set);
    vector<vector<int>> ans2=subsets(set);
    print(ans);
    return 0;
}
