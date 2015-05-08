#include <iostream>
#include <cstring>
using namespace std;

struct trie_node{
 string meaning;
 trie_node* child[26];
};
trie_node *root = NULL;

void intializeRoot(){
 trie_node *node = new trie_node;
 root = node;
 for(int i = 0; i < 26; i++){
  root->child[i] = NULL;
 }
 root->meaning = '\0';
}

void insert(string input, trie_node* n,  int index, string meaning){
 cerr<<"index "<<index<<endl;
    if(index == input.length()){
      n->meaning = meaning;
      return;
    }
 int arrayPosition = (int)(input[index] - 'a');
 cerr<<arrayPosition<<endl;
 if(n->child[arrayPosition] == NULL){
        trie_node *node =  new trie_node;
        for(int i = 0; i < 26; i++){
          node->child[i] = NULL;
        }
    n->child[arrayPosition] = node;
 }
 
 insert(input, n->child[arrayPosition], index+1, meaning);
}

string Retrieve(string input, trie_node* n , int index){
   int arrayPosition = (int)(input[index] - 'a');
   if(index == input.length()){
    //if(n->meaning != '\0'){
     return n->meaning;
    /*} else {
     return "word is a prefix";
    }*/
   }
   if(n->child[arrayPosition] == NULL){
    return "word not found";
   }
   
   return Retrieve(input, n->child[arrayPosition] , index+1);
}

int main(){
 int x;
 cout<<"select option:"<<endl;
 cout<<" 1. Insert"<<endl;
 cout<<" 2. Retrieve prefix counts"<<endl;
 intializeRoot();
 while(1){
  string input;
  string meaning;
        string res;
        cin>>x;
  cin>>input;
  switch(x){
   case 1: cin>>meaning;
     insert(input, root, 0, meaning);
     cerr<<"here"<<endl;
     break;
   case 2: res = Retrieve(input, root ,0);
     cout<<res<<endl;
     break;
   default: break;
  }
 }
 system("pause");
}