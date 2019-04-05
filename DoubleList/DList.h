#include<iostream>
using namespace std;
template<class T>
struct ListNode{
  T val;
  ListNode<T>* next;
  ListNode<T>* pre;
  void* operator new(size_t n){//重载自定义类型 new
    void*p = NULL;
    p = allocator<ListNode>().allocate(1);
    cout<<"+"<<endl;
    return p;
  }

  void operator delete(void* p){//重载自定义类型 delete
    allocator<ListNode>().deallocate((ListNode<T>*)p,1);
    cout<<"-"<<endl;
  }
};

template<class T>
struct DLHead{
  ListNode<T>* head;
};

template<class T>
class DList{
  friend class Solution;
  typedef ListNode<T> Node ;
  private:
  T* _data;
  int _ListSize;
  Node* _cur = NULL;
  Node* _first = NULL;
  DLHead<T> _Head;
  public:
  DList(T* data_arr=NULL,int arrSize=0 )
    :_data(data_arr)
     ,_ListSize(arrSize)
  {}
  ~DList(){
    while(_ListSize){
      Node*self = _first;
      _first = _first->next;
      _ListSize--;
      delete self;
    }
  }
  DList& operator=(const DList& target){
    if(&target!=this){
      this->_data = target._data;
      this->_cur = target._cur;
      this->_first = target._first;
      this->_ListSize = target._ListSize;
    }
    return *this;
  }

  DList(const DList& target){
    this->_data = target._data;
    this->_cur = target._cur;
    this->_first = target._first;
    this->_ListSize = target._ListSize;
  }
  Node* CreatAList(){
    for(int i = 0;i<_ListSize;i++){
      if(i==0){
        _cur = new Node;
        _cur->val = *(_data+i);
        _cur->pre = NULL;
        _first = _cur;
        _Head.head = _first;
      }else{
        Node* fresh = new Node;
        fresh->val = *(_data+i);
        fresh->pre = _cur;
        _cur->next = fresh;
        _cur = _cur->next;
      }
    }
    _cur->next = NULL;
    return _first;
  }
  Node* CreatAList_Loop(){
    for(int i=0;i<_ListSize;i++){
      if(i==0){
        _cur = new Node;
        _cur->val = *(_data+i);
        _cur->pre = NULL;
        _first = _cur;
        _Head.head = _first;
      }else{
        Node* fresh = new Node;
        fresh->val = *(_data+i);
        fresh->pre =_cur;
        _cur->next = fresh;
        _cur = _cur->next;
      }
    }
    _cur->next =_first;
    _first->pre = _cur;
    return _first;
  }

  Node* SetNodeHead(T val){
    Node* fresh = new Node;
    fresh->val = val;
    if(_ListSize==0){
      fresh->next = fresh;
      fresh->pre = fresh;
    }else{
      fresh->next = _first;
      fresh->pre = _first->pre;
      _first->pre = fresh;
    }
    _first = fresh;
    _first->pre->next = _first;
    _Head.head = _first;
    _ListSize++;
    return _first;
  }

  Node* SetNodeTail(T val){
    if(_ListSize==0){
      return this->SetNodeHead(val);
    }
    Node* fresh = new Node;
    fresh->val=val;
    fresh->pre = _first->pre;
    fresh->next = _first;
    _first->pre = fresh;
    fresh->pre->next = fresh;
    _ListSize++;
    return _first;
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
      int count = pos;
      Node* go = _first;
      while(count--){
        go = go->next;
      }
      fresh->next= go->next;
      go->next = fresh;
      fresh->next->pre = fresh;
      fresh->pre = go;
      _ListSize++;
    }
    return _first;
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
      int count = pos-1;
      Node* go =_first;
      while(count--){
        go = go->next;
      }
      fresh->next= go->next;
      go->next = fresh;
      fresh->next->pre = fresh;
      fresh->pre = go;
      _ListSize++;
    }
    return _first;
  }

  Node* DelNodeHead(){
    if(!_first){return NULL;}
    Node*get = _first;
    _first = _first->next;
    _first->pre = get->pre;
    _first->pre->next = _first;
    delete get;
    _ListSize--;
    return _first;
  }

  Node* DelNodeTail(){
    if(!_first){return NULL;}
    if(_ListSize==1){return DelNodeHead();}
    Node*get = _first->pre;
    _first->pre=get->pre;
    get->pre->next =_first;
    _ListSize--;
    delete get;
    return _first;
  }

  Node* DelNodeInsert(int pos){
    if((!_first)||pos==0){return DelNodeHead();}
    if(pos<0||pos>_ListSize-1){
      cout<<"input inleagel"<<endl;
      return NULL;
    }
    Node*get = TakeNode(pos-1),*last = get->next;
    get->next =last->next;
    last->next->pre = get;
    _ListSize--;
    delete last;
    return _first;
  }

  Node* TakeNode(int pos){
    if(!_first){
      cout<<"Is empty!"<<endl;
      return NULL;
    }
    if(pos<0||pos>=_ListSize){
      cout<<"0~ListSize-1!"<<"_ListSize ="<<_ListSize<<endl;
      return NULL;
    }
    int count = pos;
    Node* last = _first;
    while(count--){
      last = last->next;
    }
    return last;
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

  void CheckNode_Bynum(int pos){
    if(pos<0||pos>=_ListSize){
      cout<<"0~ListSzie!"<<_ListSize<<endl;
      return;
    }
    int count = pos;
    Node* go = _first;
    while(--count){
      go = go->next;
    }
    cout<<"val:"<<go->val<<endl;
    cout<<"Address:"<<go<<endl;
    cout<<"next->Address:"<<go->next<<endl;
  }

  void DisplayList(){
    if(_first==NULL){
      cout<<"Empty!"<<endl;
      return;
    }
    Node* go = _first;
    for(int i = 0;i<_ListSize;i++){
    cout<<go->pre<<"-"<<go<<"-"<<go->val<<"-"<<go->next<<endl;
      go = go->next;
    }
  }
  int ListSize(){
    return _ListSize;
  }
};





