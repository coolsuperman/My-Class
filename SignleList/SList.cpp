#include "SList.h"

void* ListNode::operator new(size_t n){//重载自定义类型 new
  void*p = NULL;
  p = allocator<ListNode>().allocate(1);
  cout<<"memory pool allocate"<<endl;
  return p;
}

void ListNode::operator delete(void* p){//重载自定义类型 delete
  allocator<ListNode>().deallocate((ListNode*)p,1);
  cout<<"memory pool deallocate"<<endl;
}


SList::~SList(){
  while(_head!=NULL){
    ListNode*self = _head;
    _head = _head->next;
    delete self;

 }

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

ListNode* SList::SetNodeAfter(int nums,int val){
   ListNode* fresh = new ListNode;
  if(_ListSize==0){
    cout<<"Because List is empty,now Creat a Node to be frist!"<<endl;
    fresh->val = val;
    fresh->next = NULL;
  }else if(nums==0){
    //调用前插；
  }
  else if(nums==_ListSize){
    //调用尾插；
  }
  else{
    int count = nums-1;
    ListNode* go = _head;
    while(count--){
      go = go->next;
    }
    fresh = go->next;
    go->next = fresh;
    _ListSize++;
  }
  return _head;
}

void SList::DisplayList(){
  ListNode* go = _head;
  for(int i = 0;i<_ListSize;i++){
    cout<<go->val<<endl;
    go = go->next;
  }
}

