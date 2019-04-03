#include"DList.h"

int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  DList test(arr,arrSize);
  ListNode* head = test.CreatAList_Loop();
  //ListNode* newhead = test.SetNodeHead(11);
  test.DisplayList();
  //ListNode* end = test.TakeNode(10);
  //ListNode* check = test.TakeHalf(newhead,end);
  //cout<<check<<"-"<<check->val<<endl;
  //test.DisplayList();
  return 0;

}
