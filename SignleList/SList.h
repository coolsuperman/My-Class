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
  ~SList();
  ListNode*CreatAList();
  ListNode*SetNodeAfter(int nums,int val);  
  ListNode*SetNodeBerfore(int nums,int val);
  ListNode*SetNodeBack(int val);
  ListNode*SetNodeFront(int val);
  void DisplayList();
  private:
  int* _data;
  int _ListSize;
  ListNode* _cur = NULL;
  ListNode* _head = NULL;
};
