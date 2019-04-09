#include"MString.h"
using namespace MS;
char*MString:: C_str(){
  return _str;
}
void MString::PushBack(char ch){
  if(_size==_capacity){
    Reserve(_capacity*2);
  }
  _str[_size] = ch;
  ++_size;
  _str[_size] = '\0';
}
void MString::Append(const char* str){
  size_t len = Strlen(str);
  if(_size+len>_capacity){
    Reserve(_size+len);
  }
  Strcpy(_str+_size,str);
  _size+=len;
}
MString& MString::operator+=(char ch){
  PushBack(ch);
  return *this;
}
MString& MString::operator+=(const char*str){
  Append(str);
  return *this;
}

size_t MString::Find(char ch,size_t pos ){

}
size_t MString::Find(const char* str,size_t pos){
}
void MString::Insert(size_t pos,char ch){
}
void MString::Insert(size_t pos,const char* str){
}
void MString::Erase(size_t pos ,size_t len ){
}

void MString::Reserve(size_t n){
  if(n>_capacity){
    char* newstr = new char[n+1];
    Strcpy(newstr,_str);
    delete[] _str;
    _str = newstr;
    _capacity = n;
  }
}

void MString::Resize(size_t n,char ch){
  if(n<=_size){
    _str[n]='\0';
    _size = n;
  }
  else{
    if(n>_capacity){
      Reserve(n);
    }
    size_t pos = _size;
    while (pos<n){
      _str[pos++] = ch;
    }
    _size = n;
    _str[n] = '\0';
  }
}

void MString::Strcpy(char*dst,const char*src){
  while(*(dst++)=*(src++)){
    ;
  }
}

size_t MString::Strlen(const char*src){
  size_t count=0;
  while(*(src++)){
    count++;
  }
  return count;
}

/* MString(const MString&s)
   :_str(new char[Strlen(s._str)+1])
   {
   Strcpy(_str,s._str);//深拷贝；
   }
   MString& operator = (const MString& b){
   if(&b!=this){
   delete[] _str;
   _str = new char[Strlen(b._str)+1];
   Strcpy(_str,b._str);
   }
   return *this;
   }
MString& operator =(const MString& s){//自己不做给别人做；
  if(this!=&s){
  MString tmp(s._str);
  swap(_str,tmp._str);
  }
  return *this;
  }*/



