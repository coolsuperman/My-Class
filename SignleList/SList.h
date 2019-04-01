#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  void* operator new(size_t n);//重载自定义类型 new
  void operator delete(void* p);//重载自定义类型 delete
};

class SList{
  friend class Solution;
  public:
  SList(int* data_arr=NULL,int arrSize=0 )
    :_data(data_arr)
     ,_ListSize(arrSize)
  {}
  SList(const SList& target);
  ~SList();
  ListNode*CreatAList();
  ListNode*CreatAList_Loop(int num);
  ListNode*SetNodeAfter(int nums,int val);  
  ListNode*SetNodeBerfore(int nums,int val);
  ListNode*SetNodeTail(int val);
  ListNode*SetNodeHead(int val);
  ListNode*TakeNode(int num);
  ListNode*TakeHalf(ListNode*start,ListNode*end);
  void CheckNode_ByAddress(ListNode* address);
  void CheckNode_Bynum(int num);
  void DisplayList();
  SList& operator=(const SList& d);
  private:
  int* _data;
  int _ListSize;
  ListNode* _cur = NULL;
  ListNode* _head = NULL;
};
