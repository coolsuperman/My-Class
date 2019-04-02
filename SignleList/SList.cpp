#include "SList.h"

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


SList::~SList(){
  while(_head!=NULL){
    ListNode*self = _head;
    _head = _head->next;
    delete self;
  }
}
SList& SList::operator=(const SList& target){
  if(&target!=this){
  this->_data = target._data;
  this->_cur = target._cur;
  this->_head = target._head;
  this->_ListSize = target._ListSize;
  }
  return *this;
}

SList::SList(const SList& target){
  this->_data = target._data;
  this->_cur = target._cur;
  this->_head = target._head;
  this->_ListSize = target._ListSize;
}
ListNode* SList::CreatAList(){
  for(int i=0;i<_ListSize;i++){
    if(i==0){
      _cur = new ListNode;
      _cur->val = *(_data+i);
      _head = _cur;

    }else{
      ListNode* fresh = new ListNode;
      fresh->val = *(_data+i);
      _cur->next = fresh;
      _cur = _cur->next;

    }

  }
  _cur->next = NULL;
  return _head;
}

ListNode* SList::CreatAList_Loop(int num){
  for(int i=0;i<_ListSize;i++){
    if(i==0){
      _cur = new ListNode;
      _cur->val = *(_data+i);
      _head = _cur;

    }else{
      ListNode* fresh = new ListNode;
      fresh->val = *(_data+i);
      _cur->next = fresh;
      _cur = _cur->next;

    }
  }
  ListNode* loop_in = this->TakeNode(num);
  _cur->next = loop_in;
  return _head;
}

ListNode* SList::SetNodeHead(int val){
  ListNode* fresh = new ListNode;
  fresh->val = val;
  fresh->next = _head;
  _head = fresh;
  _ListSize++;
  return _head;
}

ListNode* SList::SetNodeTail(int val){
  if(_ListSize==0){
    return this->SetNodeHead(val);
  }
  ListNode* fresh = new ListNode;
  fresh->val=val;
  ListNode* go = _head;
  while(go->next){
    go =go->next;
  }
  fresh->next = NULL;
  go->next = fresh;
  _ListSize++;
  return _head;
}

ListNode* SList::SetNodeAfter(int nums,int val){
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
    ListNode* go = _head;
    while(count--){
      go = go->next;
    }
    fresh->next= go->next;
    go->next = fresh;
    _ListSize++;
  }
  return _head;
}

ListNode* SList::SetNodeBerfore(int nums,int val){
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
    ListNode* go =_head;
    while(count--){
      go = go->next;
    }
    fresh->next= go->next;
    go->next = fresh;
    _ListSize++;
  }
  return _head;
}

ListNode* SList::DelNodeHead(){
  if(!_head){return NULL;}
  ListNode*get = _head;
  _head = _head->next;
  delete get;
  _ListSize--;
  return _head;
}

ListNode* SList::DelNodeTail(){
  if(!_head){return NULL;}
  if(_ListSize==1){return DelNodeHead();}
  ListNode*get = TakeNode(_ListSize-2),*last = get->next;
  get->next =NULL;
  delete last;
  return _head;
}

ListNode* SList::DelNodeInsert(int pos){
  if((!_head)||pos==0){return DelNodeHead();}
  if(pos<0||pos>_ListSize-1){
    cout<<"input inleagel"<<endl;
    return NULL;
  }
  ListNode*get = TakeNode(pos-1),*last = get->next;
  get->next =NULL;
  delete last;
  return _head;
}

ListNode* SList::TakeNode(int num){
  if(!_head){
    cout<<"Is empty!"<<endl;
    return NULL;
  }
  if(num<0||num>=_ListSize){
    cout<<"0~ListSize-1!"<<"_ListSize ="<<_ListSize<<endl;
    return NULL;
  }
  int count = num;
  ListNode* last = _head;
  while(count--){
    last = last->next;
  }
  return last;
}

ListNode* SList::TakeHalf(ListNode*start,ListNode* end){
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

void SList::CheckNode_ByAddress(ListNode*address){
  cout<<"val:"<<address->val<<endl;
  cout<<"Address:"<<address<<endl;
  cout<<"next->Address:"<<address->next<<endl;
}

void SList::CheckNode_Bynum(int num){
  if(num<0||num>=_ListSize){
    cout<<"0~ListSzie!"<<_ListSize<<endl;
    return;
  }
  int count = num;
  ListNode* go = _head;
  while(--count){
    go = go->next;
  }
  cout<<"val:"<<go->val<<endl;
  cout<<"Address:"<<go<<endl;
  cout<<"next->Address:"<<go->next<<endl;
}

void SList::DisplayList(){
  if(_head==NULL){
    cout<<"Empty!"<<endl;
    return;
  }
  ListNode* go = _head;
  for(int i = 0;i<_ListSize;i++){
    cout<<go<<"-"<<go->val<<"-"<<go->next<<endl;
    go = go->next;
  }
}

