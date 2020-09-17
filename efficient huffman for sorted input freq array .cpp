#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> freq;
int arr[100100];
class node {
   public :
   string s;
   node * left;
   node * right;
   node(string a){
       s = a;
       left = NULL;
       right = NULL;
   }
};

pair<int,node * > finder(queue<pair<int,node * >> & q1,queue<pair<int,node * >> & q2 ){
   if(q1.empty()){
       pair<int,node * > p = q2.front();
       q2.pop();
       return p;
   }
   if( q2.empty() || (q1.front().first < q2.front().first)){
       pair<int,node * > p = q1.front();
       q1.pop();
       return p;
   }else{
       pair<int,node * > p = q2.front();
       q2.pop();
       return p;
   }
}

node * buildtree(vector<pair<int,string>> & orderedfreq){
   queue<pair<int,node * >> q1,q2;
   cout << "push order" << endl;
   for(auto i : orderedfreq){
      cout << i.first << " " << i.second << endl;
       q1.push({i.first, new node(i.second)});
   }
   while( !( (q1.empty()) && (q2.size() == 1)) ){
       pair<int,node * > l = finder(q1,q2);
       pair<int,node * > r = finder(q1,q2);
       cout << "here3" << endl;
       node * parent = new node("&");
       parent->left = l.second;
       parent->right = r.second;
       q2.push({l.first+r.first , parent});
   }
   return q2.front().second;
}

void printarr(int n){
    for(int i = 0 ; i< n ; i++){
        cout << arr[i] ;
    }
    cout << endl;
}

void print(node * root, int i){
    if(root->left != NULL){
        arr[i]=0;
        print(root->left,i+1);
    }
    if(root->right != NULL){
        arr[i] = 1 ;
        print(root->right,i+1);
    }
    if(root->left == NULL && root->right==NULL){
        cout << root->s << " : " ;
        printarr(i);
    }
}

void huffmanCode(string s){
    for(int i = 0 ; i < s.size() ; i++){
        freq[s.substr(i,1)]++;
    }
    vector<pair<int,string>> orderedfreq;
    for(auto i : freq){
      cout << i.first << " " << i.second << endl;
        orderedfreq.push_back({i.second,i.first});
    }
    sort(orderedfreq.begin(),orderedfreq.end() );
    node * root = buildtree(orderedfreq);
    print(root,0);
}

int main(){
    string s="";
    pair<string,int> arr[] = {{"a",5},{"b",9},{"c",12},{"d",13},{"e",16},{"f",45}};
    for(int i = 0 ; i <= 5; i++){
        for(int j = 0 ; j < arr[i].second ; j++){
            s.append(arr[i].first);
        }
    }
    cout << s << endl;
    huffmanCode(s);
}
