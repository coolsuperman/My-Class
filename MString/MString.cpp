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
 // size_t len = Strlen(str);//20 maybe cant take it;
 // if(_size+len>_capacity){
 //   Reserve(_size+len);
 // }
 // Strcpy(_str+_size,str);
 // _size+=len;
 Insert(_size,str);//diff;
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
  while (pos<_size){
    if(_str[pos]==ch){
      return pos;
    }
    ++pos;
  }
  return -1;
}
size_t MString::RFind(char ch,size_t pos){
  int end = _size-1;
  if(pos!=(size_t)-1){
    end = pos;
  }
  while(end>=0){
    if(_str[end]==ch){
      return end;
    }
    --end;
  }
  return -1;
}
size_t MString::Find(const char* str,size_t pos){
  assert(pos<_size);
  char* pmatch = strstr(_str+pos,str);//BF算法实现
  if(pmatch==NULL){
    return -1;
  }else{
    return pmatch -_str;
  }
}
void MString::Insert(size_t pos,char ch){
  assert(pos<_size);
  if(_size==_capacity){
    Reserve(_capacity*2);
  }
  int end = _size;
  while(end>=(int)pos){
    _str[end+1] = _str[end];
    --end;
  }
  _str[pos] = ch;
  _size++;
}
void MString::Insert(size_t pos,const char* str){
  assert(pos<=_size);
  size_t len = Strlen(str);
  if(_size+len>_capacity){
    Reserve(_size+len);
  }
  int end = _size;
  while(end>=(int)pos){
    _str[end+len] = _str[end];
    --end;
  }
  while(*str){
    _str[pos++] = *str++;
  }
  _size+=len;
}
void MString::Erase(size_t pos ,size_t len ){
  assert(pos<_size);
  if(len>=_size-pos){
    _str[pos] = '\0';
    _size = pos;
  }else{
    for(size_t i= 0;i<len;++i){
      _str[pos] = _str[pos+len];
      pos++;
    }
    _size -=len;
    _str[_size] = '\0';
  }
}
MString MString::SubStr(size_t pos,size_t len){
  if(_size-pos<len){
    len  =_size-pos;
  }
  MString sub;
  sub.Reserve(len);
  for(size_t i = pos;i<pos+len;++i){
    sub += _str[i];
  }
  return sub;
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



