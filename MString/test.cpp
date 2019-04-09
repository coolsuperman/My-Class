#include"MString.h"

int main(){
  MS:: MString s1("hello");
  MS::MString s2(s1);
  cout<<s1.C_str()<<endl;
  cout<<s2.C_str()<<endl;
  s1+=' ';
  s1+="world";
  cout<<s1.C_str()<<endl;
  return 0;
}
