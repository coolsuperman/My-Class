#include"MVector.h"

void TestVector1(){
  MV::MVector<int> v1;
  v1.PushBack(1);
  cout<<v1.Size()<<endl;
  v1.PushBack(2);
  cout<<v1.Size()<<endl;
  v1.PushBack(3);
  cout<<v1.Size()<<endl;
  v1.PushBack(4);
  cout<<v1.Size()<<endl;
  for (size_t i = 0;i<v1.Size();i++){
    cout<<v1[i]  ;
  }
  cout<<endl;
  cout<<v1.Size()<<endl;
}

int main(){
  TestVector1();
  return 0;
}
