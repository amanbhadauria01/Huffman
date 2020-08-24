#include<bits/stdc++.h>
using namespace std;

class node{
  public :
  string ch;
  node * left;
  node * right;
  node(string ch){
      left = NULL;
      right = NULL;
      this->ch = ch;
  }
};

void print(node * root,vector<int> & code){
    if(root==NULL)
    return;
    if(root->left != NULL){
        code.push_back(0);
        print(root->left,code);
        code.pop_back();
    }
    if(root->right != NULL){
        code.push_back(1);
        print(root->right,code);
        code.pop_back();
    }
    if(root->left == NULL && root->right == NULL){
       cout << root->ch << " : " ;
       for(int i = 0 ; i < code.size() ; i++)
        cout << code[i] ;
       cout << endl;    
    }
}

node * HuffmanEncodeTree(string s){
    unordered_map<string,int> Table ;
    for(int i = 0 ; i < s.size() ; i++){
        Table[s.substr(i,1)]++;
    }
    priority_queue<pair<int,node*>,vector<pair<int,node*>> , greater<pair<int,node*>>> pq;
    for(auto i : Table){
        node * temp = new node(i.first);
        pq.push({i.second,temp});
    }
    while(pq.size()!=1){
        pair<int,node*> l , r;
        l = pq.top();
        pq.pop();
        r = pq.top();
        pq.pop();
        node * temp = new node("&");
        temp->left = l.second;
        temp->right = r.second;
        pq.push({l.first+r.first,temp});
    }
    return pq.top().second;
}


int main(){
    string s;
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(data) / sizeof(data[0]);
    for(int i = 0 ; i < size ; i++){
        string temp(1,data[i]);
        for(int j = 0 ; j < freq[i] ; j++){
            s = s + temp;
        }
    }
    node * root = HuffmanEncodeTree(s);
    vector<int> code;
    print(root,code);
}
 
