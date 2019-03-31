#include"SList.h"

int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  SList test(arr,arrSize);
  test.DisplayList();
  ListNode* head = test.CreatAList();
  return 0;

}
