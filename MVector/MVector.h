
//#pragma once
#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;

namespace MV{
  template<class T>
    class MVector{
      public:
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin(){
          return _start;
        }
        iterator end(){
          return _finish;
        }
        const_iterator cbegin()const{
          return _start;
        }
        const_iterator cend()const{
          return _finish;
        }
        size_t Size(){
          return _finish-_start;
        }
        size_t Capacity(){
          return _end_of_storage-_start;
        }
        T& operator[](size_t pos){
          assert(pos<Size());
          return _start[pos];
        }
        const T& operator[](size_t pos)const{
          assert(pos<Size());
          return _start[pos];
        }
        MVector()
          :_start(NULL)
           ,_finish(NULL)
           ,_end_of_storage(NULL)
      {}
        MVector(const MVector<T>& v);
        MVector<T>& operator=(MVector<T> v){
          Swap(v);
          return *this;
        }
        ~MVector(){
          if(_start){
            delete[] _start;
            _start = _finish = _end_of_storage = NULL;
          }
        }
        void Swap(const MVector<T>& v){
          swap(_start,v._start);
          swap(_finish,v._finish);
          swap(_end_of_storage,v._end_of_storage);
        }
        void Reserve(size_t n){
          size_t size = Size();
          if(n>Capacity()){
            T* tmp = new T[n];
            if(_start){
              memcpy(tmp,_start,sizeof(T)*size);
              delete[] _start;
            }
            _start = tmp;
            _finish = _start+size;
            _end_of_storage = _start+n;
          }
        }
        void Resize(size_t n,const T& val = T()){
          if(n<Size()){
            _finish = _start+n;
          }else{
            if(n>Capacity()){
              Reserve(n);
            }
            iterator begin = _finish;
            while(begin<_start+n){
              *begin = val;
              ++begin;
            }
            _finish = _start+n;
          }
        }
        void PushBack(const T& x){
          Insert(_finish,x);
        }
        void PopBack(){
          Erase(_finish);
        }
        void Insert(iterator pos,const T& x){
          assert(pos<=_finish);
          size_t offset = pos-_start;
          if(_finish == _end_of_storage){
            size_t newcapacity = Capacity()==0?1:Capacity()*2;
            Reserve(newcapacity);
            pos = _start+offset;//Die Dai Qi Shi Xiao
          }
          iterator end = _finish;
          while(end>pos){
            *end = *(end-1);
            --end;
          }
          *pos = x;
          ++_finish;
          //pos++;
        }
        iterator Erase(iterator pos){
          assert(pos<_finish);
          iterator begin = pos;
          while(begin<_finish-1){
            *begin = *(begin+1);
            ++begin;
          }
          --_finish;
          return pos;
        }
      private:
        T* _start;
        T* _finish;
        T* _end_of_storage;
    };
}
