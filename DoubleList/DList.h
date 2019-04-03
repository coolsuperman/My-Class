#include<iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode* pre;
  void* operator new(size_t n);//重载自定义类型 new
  void operator delete(void* p);//重载自定义类型 delete
};
struct DLHead{
  ListNode* head;
};
class DList{
  friend class Solution;
  public:
  DList(int* data_arr=NULL,int arrSize=0 )
    :_data(data_arr)
     ,_ListSize(arrSize)
  {}
  DList(const DList& target);
  ~DList();
  ListNode*CreatAList();
  ListNode*CreatAList_Loop();
  ListNode*SetNodeAfter(int nums,int val);  
  ListNode*SetNodeBerfore(int nums,int val);
  ListNode*SetNodeTail(int val);
  ListNode*SetNodeHead(int val);
  ListNode*DelNodeHead();
  ListNode*DelNodeTail();
  ListNode*DelNodeInsert(int pos);
  ListNode*TakeNode(int num);
  ListNode*TakeHalf(ListNode*start,ListNode*end);
  void CheckNode_ByAddress(ListNode* address);
  void CheckNode_Bynum(int num);
  void DisplayList();
  DList& operator=(const DList& d);
  private:
  int* _data;
  int _ListSize;
  ListNode* _cur = NULL;
  ListNode* _first = NULL;
  DLHead _Head;
};
