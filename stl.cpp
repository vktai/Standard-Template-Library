#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stdexcept>
#include<list>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<stack>
#include<queue>
#include<cstdlib>
#include<ctime>
#define t cout<<'\n'
using namespace std;
ostream_iterator<int> c{cout,"  "};
void vectorFunc(){
	vector<int> val{1,2,3,4,5,6,7,8,9};
	vector<int> inte=val;
	vector<int> g{inte.begin(),inte.end()};
	ostream_iterator<int> a{cout," $ "};
	copy(val.begin(),val.end(),a);
	t;
	copy(inte.begin(),inte.end(),a);
	t;
	copy(g.begin(),g.end(),a);
	for(int i=0;i<3;i++){
		val.push_back(i+1);
	}
	t;
	copy(val.begin(),val.end(),a);
	val.erase(val.begin());
	t;
	copy(val.begin(),val.end(),a);
	val.erase(val.begin(),val.end());
	t;
	cout<<"val "<<((val.empty())?"is ":"is not ")<<"empty";
	inte.clear();
	t;
	cout<<"inte "<<((inte.empty())?"is ":"is not ")<<"empty";
}

void listFunc(){
	list<int> a;
	list<int> b;
	for(int i=0;i<5;i++){
		a.push_front(i+1);
	}
	ostream_iterator<int> c{cout,"  "};
	copy(a.begin(),a.end(),c);
	t;
	a.sort();
	
	vector<int> in{1,2,3,4,4,5};
	b.insert(b.begin(),in.begin(),in.begin()+3);
	t;
	copy(b.begin(),b.end(),c);
	t;
	cout<<"size a:"<<a.size()<<"\nsize b:"<<b.size();
	a.splice(a.end(),b);
	t;
	copy(a.begin(),a.end(),c);
	t;
	cout<<"b "<<(b.empty() ? "is ":"is not ")<<"empty\n";
	a.sort();
	copy(a.begin(),a.end(),c);
	b.insert(b.begin(),in.begin(),in.end());
	a.merge(b);
	t;
	copy(a.begin(),a.end(),c);
	t;
	cout<<"b "<<(b.empty() ? "is ":"is not ")<<"empty\n";
	a.pop_front();
	a.pop_back();
	t;
	copy(a.begin(),a.end(),c);
	t;
	a.unique();
	copy(a.begin(),a.end(),c);
	a.swap(b);
	t;
	copy(a.begin(),a.end(),c);
	t;
	copy(b.begin(),b.end(),c);
	a=b;
	copy(a.begin(),a.end(),c);
	a.merge(b);
	t;
	copy(a.begin(),a.end(),c);
	a.remove(4);
	t;
	copy(a.begin(),a.end(),c);
}
void dequeFunc(){
	deque<double> a{1,2,3,4,5};
	copy(a.begin(),a.end(),c);
	t;
	a.push_front(3);
	copy(a.begin(),a.end(),c);
	t;
	a.push_back(6);
	copy(a.begin(),a.end(),c);
	t;
	a.pop_front();
	copy(a.begin(),a.end(),c);
	t;
	a.pop_back();
	copy(a.begin(),a.end(),c);
	t;
}
void multisetFunc(){
	multiset<int,less<int> > multi;
	for(int i=0;i<5;i++){
		multi.insert(3);
	} 
	multi.insert(4);
	copy(multi.begin(),multi.end(),c);
	auto res=multi.find(3);
	t;
	cout<<*res;
	t;
	cout<<multi.count(3);
	t;
	
	auto r=*(multi.lower_bound(3));
	cout<<"Lower bound"<<r;
	t;
	cout<<"Upper bound"<<*(multi.upper_bound(3));
	auto p=multi.equal_range(3);
	t;
	cout<<*(p.first);
	t;
	cout<<*(p.second);
}
void setFunc(){
	vector<int> a{2,3,4,5,2,3,5,6,1,2};
	set<int> s{a.begin(),a.end()};
	copy(s.begin(),s.end(),c);
	auto p=s.insert(5);
	cout<<*(p.first)<<'\n';
	cout<<(((p.second))?" is ":" isnot ")<<"inserted";
}
template<class T,class K>
void multimapOutput(multimap<T,K> a){
	for(auto p:a){
		cout<<p.first<<"  "<<p.second<<'\n';
	}
}
void multimapFunc(){
	multimap<string,int,less<string>> p;
	multimap<int,double> u{{1,2.2},{2.3,4.5},{3,7.7}};
	multimapOutput(u);
	p.insert(make_pair("sele",10));
	p.insert(make_pair("mole",10));
	multimapOutput(p);
	p.insert({"honey",89});
	t;
	multimapOutput(p);
	t;
	cout<<p.count("sele");
}
template<class T,class K>
void Outputmap(map<T,K> a){
	for(auto p:a){
		cout<<p.first<<"  "<<p.second<<'\n';
	}
}
void mapFunc(){
	map<int,int> a;
	a.insert(make_pair(1,2));
	a.insert(make_pair(1,3));
	Outputmap(a);
	t;
	for(int i=0;i<5;i++){
		a.insert({i,i+2});
	}
	t;
	Outputmap(a);
	cout<<a[2]<<'\n';
	cout<<a[4]<<'\n';
}
template <class T>
void pushEle(T& a){
	for(int i=0;i<5;i++){
		a.push(i);
		cout<<a.top()<<" ";
	}
	cout<<'\n';
}
template <class T>
void popEle(T& a){
	while(!a.empty()){
		
		cout<<a.top()<<" ";
		a.pop();
	}
	cout<<'\n';
}
void stackFunc(){
	 stack<int> destack;
	 stack<int,vector<int>> vecstack;
	 stack<int,list<int>> liststack;
	 cout<<"into vector stack ";
	 pushEle(destack);
	 cout<<"into vector stack ";
	 pushEle(vecstack);
	 cout<<"into vector stack ";
	 pushEle(liststack);
	 
	 cout<<"into vector stack ";
	 popEle(destack);
	 cout<<"into vector stack ";
	 popEle(vecstack);
	 cout<<"into vector stack ";
	 popEle(liststack);
	 
}
void queueFunc(){
	queue<int> val;
	srand(time(NULL));

	for(int i=0;i<5;i++){
		
		val.push(1+rand()%10);
	}	
	cout<<"front "<<val.front()<<'\n'<<"back "<<val.back();
	t;
	while(!val.empty()){
		cout<<val.front()<<" ";
		val.pop();
	}
	
}
void priorityqueueFunc(){
	priority_queue<int> val;
	srand(time(NULL));

	for(int i=0;i<19;i++){
		
		val.push(1+rand()%6);
	}

	t;
	while(!val.empty()){
		cout<<val.top()<<" ";
		val.pop();
	}
}
int main(){
	vectorFunc();
	t;
	listFunc();
	t;
	dequeFunc();
	t;
	multimapFunc();
	t;
	mapFunc();
	t;
	queueFunc();
	t;
	setFunc();
	t;
	multisetFunc();
	t;
	stackFunc();
	t;
	priorityqueueFunc();
}













