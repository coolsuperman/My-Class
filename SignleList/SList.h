#include<iostream>
using namespace std;
template <class T>
struct ListNode{
  T val;
  ListNode<T> * next;
  void* operator new(size_t n){//重载自定义类型 new
    void*p = NULL;
    p = allocator<ListNode>().allocate(1);
    cout<<"allocate！"<<endl;
    return p;
  }

//  istream& opetator>>(istream&ins,ListNode<T> target){
//    ins>>
//  }

  void operator delete(void* p){//重载自定义类型 delete
    allocator<ListNode>().deallocate((ListNode<T>*)p,1);
    cout<<"deallocate！"<<endl;
  }
  
};

template <class T>
class SList{
  typedef ListNode<T> Node;
friend class Solution;
private:
  T* _data;
  int _ListSize;
  Node* _cur = NULL;
  Node* _head = NULL;
public:
  SList(T* data_arr=NULL,int arrSize=0 )
    :_data(data_arr)
     ,_ListSize(arrSize)
  {}
  ~SList(){
    while(_head!=NULL){
      Node*self = _head;
      _head = _head->next;
      delete self;
    }
  }

  SList(const SList& target){
    this->_data = target._data;
    this->_cur = target._cur;
    this->_head = target._head;
    this->_ListSize = target._ListSize;
  }
  int ListSize(){
    return _ListSize;
  }
  SList& operator=(const SList& target){
    if(&target!=this){
      this->_data = target._data;
      this->_cur = target._cur;
      this->_head = target._head;
      this->_ListSize = target._ListSize;
    }
    return *this;
  }

  Node* CreatAList(){
    for(int i=0;i<_ListSize;i++){
      if(i==0){
        _cur = new Node;
        _cur->val = *(_data+i);
        _head = _cur;

      }else{
        Node* fresh = new Node;
        fresh->val = *(_data+i);
        _cur->next = fresh;
        _cur = _cur->next;

      }

    }
    _cur->next = NULL;
    return _head;
  }

  Node* CreatAList_Loop(int pos){
    for(int i=0;i<_ListSize;i++){
      if(i==0){
        _cur = new Node;
        _cur->val = *(_data+i);
        _head = _cur;

      }else{
        Node* fresh = new Node;
        fresh->val = *(_data+i);
        _cur->next = fresh;
        _cur = _cur->next;

      }
    }
    Node* loop_in = this->TakeNode(pos);
    _cur->next = loop_in;
    return _head;
  }

  Node* SetNodeHead(T val){
    Node* fresh = new Node;
    fresh->val = val;
    fresh->next = _head;
    _head = fresh;
    _ListSize++;
    return _head;
  }

  Node* SetNodeTail(T val){
    if(_ListSize==0){
      return this->SetNodeHead(val);
    }
    Node* fresh = new Node;
    fresh->val=val;
    Node* go = TakeNode(_ListSize-1);
    fresh->next = NULL;
    go->next = fresh;
    _ListSize++;
    return _head;
  }

  Node* SetNodeAfter(int pos,T val){
    Node* fresh = new Node;
    fresh->val = val;
    if(pos<0||pos>_ListSize){
      cout<<"出入位置错误"<<"_ListSize ="<<_ListSize<<endl;
      delete fresh;
    }
    else if(_ListSize==0){
      return this->SetNodeHead(val);
    }
    else if(pos==_ListSize){
      return this->SetNodeTail(val);
    }
    else{
      Node* go = TakeNode(pos);
      fresh->next= go->next;
      go->next = fresh;
      _ListSize++;
    }
    return _head;
  }

  Node* SetNodeBerfore(int pos,T val){
    Node*fresh = new Node;
    fresh->val = val;
    if(pos<0||pos>_ListSize){
      cout<<"0~ListSize-1!"<<"_ListSize ="<<_ListSize<<endl;
      delete fresh;
    }
    else if(_ListSize==0||pos==0){
      return this->SetNodeHead(val);
    }else if(pos==_ListSize){
      return this->SetNodeTail(val);
    }
    else{
      Node* go =TakeNode(pos-1);
      fresh->next= go->next;
      go->next = fresh;
      _ListSize++;
    }
    return _head;
  }

  Node* DelNodeHead(){
    if(!_head){return NULL;}
    Node*get = _head;
    _head = _head->next;
    delete get;
    _ListSize--;
    return _head;
  }

  Node* DelNodeTail(){
    if(!_head){return NULL;}
    if(_ListSize==1){return DelNodeHead();}
    Node*get = TakeNode(_ListSize-2),*last = get->next;
    get->next =NULL;
    _ListSize--;
    delete last;
    return _head;
  }

  Node* DelNodeInsert(int pos){
    if((!_head)||pos==0){return DelNodeHead();}
    if(pos<0||pos>_ListSize-1){
      cout<<"input inleagel"<<endl;
      return NULL;
    }
    Node*get = TakeNode(pos-1),*last = get->next;
    get->next =last->next;
    _ListSize--;
    delete last;
    return _head;
  }

  Node* TakeNode(int pos){
    if(!_head){
      cout<<"Is empty!"<<endl;
      return NULL;
    }
    if(pos<0||pos>=_ListSize){
      cout<<"0~ListSize-1!"<<"_ListSize ="<<_ListSize<<endl;
      return NULL;
    }
    int count = pos;
    Node* go = _head;
    while(count--){
      go = go->next;
    }
    return go;
  }

  Node* TakeHalf(Node*start,Node* end){
    Node*fast = start;
    Node*slow = start;
    while(fast!=end){
      fast = fast->next;
      if(fast==end){return slow;}
      slow = slow->next;
      fast = fast->next;
    }
    if(slow==start){
      cout<<"cha=0 or 1"<<endl;
    }
    return slow;
  }

  void CheckNode_ByAddress(Node*address){
    cout<<"val:"<<address->val<<endl;
    cout<<"Address:"<<address<<endl;
    cout<<"next->Address:"<<address->next<<endl;
  }

  void CheckNode_Bypos(int pos){
    if(pos<0||pos>=_ListSize){
      cout<<"0~ListSzie!"<<_ListSize<<endl;
      return;
    }
    Node* go = TakeNode(pos);
    cout<<"val:"<<go->val<<endl;
    cout<<"Address:"<<go<<endl;
    cout<<"next->Address:"<<go->next<<endl;
  }

  void DisplayList(){
    if(_head==NULL){
      cout<<"Empty!"<<endl;
      return;
    }
    Node* go = _head;
    for(int i = 0;i<_ListSize;i++){
      cout<<go<<"-"<<go->val<<"-"<<go->next<<endl;
      go = go->next;
    }
  }
};
