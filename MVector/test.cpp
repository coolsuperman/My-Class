#include"MVector.h"

void TestVector1(){
  MV::MVector<int> v1;
  v1.PushBack(1);
  v1.PushBack(2);
  v1.PushBack(3);
  v1.PushBack(4);
  for (size_t i = 0;i<v1.Size();i++){
    cout<<v1[i]<<endl;
  }
}

int main(){
  TestVector1();
  return 0;
}
