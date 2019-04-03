#include "DList.h"

void* ListNode::operator new(size_t n){//重载自定义类型 new
  void*p = NULL;
  p = allocator<ListNode>().allocate(1);
  cout<<"allocate！"<<endl;
  return p;
}

void ListNode::operator delete(void* p){//重载自定义类型 delete
  allocator<ListNode>().deallocate((ListNode*)p,1);
  cout<<"deallocate！"<<endl;
}


DList::~DList(){
  while(_first!=NULL){
    ListNode*self = _first;
    _first = _first->next;
    delete self;
  }
}
DList& DList::operator=(const DList& target){
  if(&target!=this){
  this->_data = target._data;
  this->_cur = target._cur;
  this->_first = target._first;
  this->_ListSize = target._ListSize;
  }
  return *this;
}

DList::DList(const DList& target){
  this->_data = target._data;
  this->_cur = target._cur;
  this->_first = target._first;
  this->_ListSize = target._ListSize;
}

ListNode* DList::CreatAList_Loop(){
  ListNode*Save_prev=NULL,*Save_first = NULL;
  for(int i=0;i<_ListSize;i++){
    if(i==0){
      _cur = new ListNode;
      _cur->val = *(_data+i);
      _cur->pre = NULL;
      _first = _cur;
      _Head.head = _first;
      Save_prev = _first;
      Save_first = _first;
    }else{
      ListNode* fresh = new ListNode;
      fresh->val = *(_data+i);
      _cur->next = fresh;
      _cur->pre = Save_prev;
      Save_prev = _cur;
      _cur = _cur->next;

    }
  }
  _cur->next = Save_first;
  return _first;
}

ListNode* DList::SetNodeHead(int val){
  ListNode* fresh = new ListNode;
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
  _Head.head = _first;
  _ListSize++;
  return _first;
}

ListNode* DList::SetNodeTail(int val){
  if(_ListSize==0){
    return this->SetNodeHead(val);
  }
  ListNode* fresh = new ListNode;
  fresh->val=val;
  fresh->pre = _first->pre;
  fresh->next = _first;
  _first->pre = fresh;
  fresh->pre->next = fresh;
  _ListSize++;
  return _first;
}

ListNode* DList::SetNodeAfter(int nums,int val){
  ListNode* fresh = new ListNode;
  fresh->val = val;
  if(nums<0||nums>_ListSize){
    cout<<"出入位置错误"<<"_ListSize ="<<_ListSize<<endl;
    delete fresh;
  }
  else if(_ListSize==0){
    return this->SetNodeHead(val);
  }
  else if(nums==_ListSize){
    return this->SetNodeTail(val);
  }
  else{
    int count = nums;
    ListNode* go = _first;
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

ListNode* DList::SetNodeBerfore(int nums,int val){
  ListNode*fresh = new ListNode;
  fresh->val = val;
  if(nums<0||nums>_ListSize){
    cout<<"0~ListSize-1!"<<"_ListSize ="<<_ListSize<<endl;
    delete fresh;
  }
  else if(_ListSize==0||nums==0){
    return this->SetNodeHead(val);
  }else if(nums==_ListSize){
    return this->SetNodeTail(val);
  }
  else{
    int count = nums-1;
    ListNode* go =_first;
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

ListNode* DList::DelNodeHead(){
  if(!_first){return NULL;}
  ListNode*get = _first;
  _first = _first->next;
  _first->pre = get->pre;
  _first->pre->next = _first;
  delete get;
  _ListSize--;
  return _first;
}

ListNode* DList::DelNodeTail(){
  if(!_first){return NULL;}
  if(_ListSize==1){return DelNodeHead();}
  ListNode*get = _first->next;
  _first->pre=get->pre;
  get->pre =_first;
  _ListSize--;
  delete get;
  return _first;
}

ListNode* DList::DelNodeInsert(int pos){
  if((!_first)||pos==0){return DelNodeHead();}
  if(pos<0||pos>_ListSize-1){
    cout<<"input inleagel"<<endl;
    return NULL;
  }
  ListNode*get = TakeNode(pos-1),*last = get->next;
  get->next =last->next;
  last->next->pre = get;
  _ListSize--;
  delete last;
  return _first;
}

ListNode* DList::TakeNode(int num){
  if(!_first){
    cout<<"Is empty!"<<endl;
    return NULL;
  }
  if(num<0||num>=_ListSize){
    cout<<"0~ListSize-1!"<<"_ListSize ="<<_ListSize<<endl;
    return NULL;
  }
  int count = num;
  ListNode* last = _first;
  while(count--){
    last = last->next;
  }
  return last;
}

ListNode* DList::TakeHalf(ListNode*start,ListNode* end){
  ListNode*fast = start;
  ListNode*slow = start;
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

void DList::CheckNode_ByAddress(ListNode*address){
  cout<<"val:"<<address->val<<endl;
  cout<<"Address:"<<address<<endl;
  cout<<"next->Address:"<<address->next<<endl;
}

void DList::CheckNode_Bynum(int num){
  if(num<0||num>=_ListSize){
    cout<<"0~ListSzie!"<<_ListSize<<endl;
    return;
  }
  int count = num;
  ListNode* go = _first;
  while(--count){
    go = go->next;
  }
  cout<<"val:"<<go->val<<endl;
  cout<<"Address:"<<go<<endl;
  cout<<"next->Address:"<<go->next<<endl;
}

void DList::DisplayList(){
  if(_first==NULL){
    cout<<"Empty!"<<endl;
    return;
  }
  ListNode* go = _first;
  for(int i = 0;i<_ListSize;i++){
    cout<<go<<"-"<<go->val<<"-"<<go->next<<endl;
    go = go->next;
  }
}

