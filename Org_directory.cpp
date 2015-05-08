#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct employee {
	int id;
	string name;
	string post;
	employee *child[5];
};

employee *root = NULL;

struct trie{
	trie* child[26];	
	vector < employee* > empDataAddress;
};
trie* trie_root = NULL;

map <int, employee*> empMap;

employee* insertInEmplyeeTree(int id, string name, string post, string managerName, employee* node){

	employee* n = new employee;
	n->id = id;
	n->name = name;
	n->post = post;
	for(int i = 0; i < 5; i++){
			n->child[i] = NULL;
	}
	if(root == NULL){
		root = n;
		//cout<<"inserted root"<<n->name<<endl;
		return n;
	}

	if(node == NULL){
		return NULL;
	}

	if(node->name == managerName){
		for(int i = 0; i < 5; i++){
			if(node->child[i] == NULL){
				node->child[i] = n;
				//cout<<"inserted "<<n->name<<endl;
				return n;
			}
		}
	} else {
		for(int i = 0; i < 5; i++){
			return insertInEmplyeeTree(id, name, post, managerName, node->child[i]);
		}
	}

}


void initializeTrieRoot(){
	trie* node = new trie;
	trie_root = node;
	for(int i = 0; i < 26; i++){
		trie_root->child[i] = NULL; 
	}
	trie_root->empDataAddress.push_back(NULL);
}

void insertNameInTrie(trie* n, string name, int index, employee* nodeAdress){
	//cout<<"index"<<index<<endl;
	if(index == name.length()){
		//cout<<"inside trie"<<endl;
		n->empDataAddress.push_back(nodeAdress);
		return;
	}
	int pos = (int)(name[index] - 'a');
	if(n->child[pos] == NULL){
		trie *node = new trie;
		for(int i = 0; i < 26; i++){
			node->child[i] = NULL; 
		}
		n->child[pos] = node;
	} 
	insertNameInTrie(n->child[pos], name, index+1, nodeAdress);
	
}

void searchNameInTrie(trie*n, string name, int index){
	if(index == name.length()){
		for(int i = 0; i < n->empDataAddress.size(); i++){
			employee* emp = n->empDataAddress[i];
			cout<<"id "<<emp->id<<endl;
			cout<<"name "<<emp->name<<endl;
			cout<<"post "<<emp->post<<endl;
		}
		return;
	}
	int pos = (int)(name[index] - 'a');
	//cout<<pos<<endl;
	if(n->child[pos] != NULL){
		searchNameInTrie(n->child[pos], name, index+1);
	} else {
		cout<<"name not found "<<endl;
		return;
	}
}

void insertIDInHashMap(int id, employee* nodeAdress){
	empMap[id] = nodeAdress;
}

employee* searchIdInMap(int empId){
	if(empMap[empId]){
		employee* node = empMap[empId];
		return node;
	} else {
		cout<<"invalid employee ID "<<endl;
		return NULL;
	}
}

void findSubOrdinatesInTree(employee* node){
	if(node == NULL){
		return;
	}
	for(int i = 0; i < 5; i++){
		employee* n = node->child[i];
		if(n){
			cout<<"1.ID: "<<n->id<<endl;
			cout<<"2.Name "<<n->name<<endl;
			cout<<"3.Post: "<<n->post<<endl;
			findSubOrdinatesInTree(n);
		}
	}
}

int main(){
	int id, n;
	string name, post, manager;	
	initializeTrieRoot();
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>id;
		cin>>name;
		cin>>post;
		cin>>manager;
		employee* nodeInserted = insertInEmplyeeTree(id, name, post, manager, root);
		insertIDInHashMap(id, nodeInserted);
		insertNameInTrie(trie_root, name, 0, nodeInserted);
	}
	//searchNameInTrie(trie_root,"fg", 0);	
	//searchNameInTrie(trie_root,"de", 0);
	//searchNameInTrie(trie_root,"bc", 0);
	while(1){
		cout<<"1. Enter Id to see employee details"<<endl;
		cout<<"2. Enter Id to see employee sub-ordinates"<<endl;
		cout<<"3. Enter name for prefix search"<<endl;
		int x;
		cin>>x;
		switch(x){
			case 1: { 	int empId;
						cin>>empId;
						employee* emp = searchIdInMap(empId);
						if(emp){
							cout<<"emplyee details: "<<endl;
							cout<<"1.ID: "<<emp->id<<endl;
							cout<<"2.Name "<<emp->name<<endl;
							cout<<"3.Post: "<<emp->post<<endl;
						}
						break;
					}
			case 2: {	int empId;
						cin>>empId;
						employee* emp = searchIdInMap(empId);
						if(emp){
							findSubOrdinatesInTree(emp);
						}
						break;
					}
			case 3: {
						string prefx;
						cin>>prefx;
						searchNameInTrie(trie_root,prefx, 0);
						break;
					}
			default: break;
		}
	}
	

}



