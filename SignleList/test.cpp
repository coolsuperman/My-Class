#include"SList.h"

int main(){
  int choose = 0;
  char arr[]={'A','B','C','D','E','F'};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  SList<char> test(arr,arrSize);
  ListNode<char>* head = test.CreatAList();
  cout<<"List Creat Succeed,Now begin test function!"<<endl;
  cout<<"1.CheckNode_Bypos"<<" "<<"3.DelNodeHead"<<endl;
  cout<<"4.DelNodeTail"<<" "<<"5,DelNodeInsert"<<endl;
  cout<<"6.TakeHalf"<<" "<<"7,SetNodeAfter"<<" "<<"8.SetNodeBerfore"<<endl;
  do{
    cin>>choose;
    switch(choose){
      case 1:
        {
          cout<<"test CheckNode_Bypos!"<<endl;
          int input1 = 0;
          cin>>input1;
          test.CheckNode_Bypos(input1);
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 2:
        {  cout<<"test CheckNode_ByAddress!"<<endl;
         // ListNode<char>*address = NULL;
         // cin>>address;
         // test.CheckNode_ByAddress(address);
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 3:
        {
          cout<<"test DelNodeHead!"<<endl;
          test.DelNodeHead();
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 4:
        {
          cout<<"test DelNodeTail!"<<endl;
          test.DelNodeTail();
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 5:
        {
          cout<<"test DelNodeInsert!"<<endl;
          int pos = 0;
          cin>>pos;
          test.DelNodeInsert(pos);
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 6:
        {
          cout<<"test TakeHalf!"<<endl;
          ListNode<char>*start=test.TakeNode(0);
          ListNode<char>*end=test.TakeNode(test.ListSize()-1);
          cout<<test.TakeHalf(start,end)->val<<endl;
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 7:
        {
          cout<<"test SetNodeAfter"<<endl;
          int pos = 0;
          char val = 0;
          cin>>pos>>val;
          test.DisplayList();
          test.SetNodeAfter(pos,val);
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 8:
        {
          cout<<"test SetNodeBerfore"<<endl;
          int pos = 0;
          char val = 0;
          cin>>pos>>val;
          test.DisplayList();
          test.SetNodeBerfore(pos,val);
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 9:
        {
          cout<<"test SetNodeHead"<<endl;
          char val = 0;
          cin>>val;
          test.SetNodeHead(val);
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      case 10:
        {
          cout<<"test SetNodeTail"<<endl;
          char val = 0;
          cin>>val;
          test.SetNodeTail(val);
          test.DisplayList();
          cout<<"This function test finish!"<<endl;
          break;
        }
      default:
        cout<<"Type test fun number!"<<endl;
    }
  }while(choose!=0);
  return 0;

}
