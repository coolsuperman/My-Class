#include<iostream>
#include<cassert>
#include<cstring>

using namespace std;
namespace MS{
 // const size_t npos = -1;
  class MString{
    public:
      MString(const char*str="")
      {
        _size  = Strlen(str);
        _capacity = _size;
        _str =new char[_capacity+1];
        Strcpy(_str,str);
      }

      MString(const MString& s)
        :_str(NULL)
         ,_size(0)
         ,_capacity(0)
    {
      MString tmp(s._str);
      Swap(tmp);
    }

      ~MString(){
        delete[] _str;
        _size = _capacity = 0;
        _str = NULL;
      }

      MString& operator=(MString s)//传值拷贝了一个临时拷贝所以用这个临时拷贝当中间量
      {
        Swap(s);
        return *this;
      }

      char& operator[](size_t pos){
        assert(pos<_size);
        return _str[pos];
      }

      const char& operator[](size_t pos)const{
        assert(pos<_size);
        return _str[pos];
      }
      size_t Size()const{
        return _size;
      }

      size_t Capacity() const{
        return _capacity;
      }

      void Swap(MString& s){
        swap(_str,s._str);
        swap(_size,s._size);
        swap(_capacity,s._capacity);
      }

      typedef char* iterator;
      typedef const char* const_iterator;
      iterator begin(){
        return _str;
      }
      iterator end(){
        return _str+_size;
      }

      MString& operator+=(char ch);
      MString& operator+=(const char*str);
      void PushBack(char ch);
      void Append(const char* str);
      size_t Find(char ch,size_t pos = 0);
      size_t RFind(char ch,size_t pos = -1);
      size_t Find(const char* str,size_t pos = 0);
      void Insert(size_t pos,char ch);
      void Insert(size_t pos,const char* str);
      void Erase(size_t pos ,size_t len = -1);
      void Reserve(size_t n);
      void Resize(size_t n,char ch = '\0');
      MString SubStr(size_t pos,size_t len);

      char* C_str();
      void Strcpy(char*dst,const char*src);
      size_t Strlen(const char*src);
    private:
      char* _str;
      size_t _size;
      size_t _capacity;//不含\0容量
    //  static const size_t npos;
  };

}
