
#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace MV{
  template<class T>
    class MVector{
      public:
        typedef T* iterator;
        iterator begin(){
          return _start;
        }
        iterator end(){
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
        void Reserve(size_t n);
        void Resize(size_t n,const T& val = T());
        void PushBack(const T& x);
        void PopBack();
        void Insert(iterator pos,const T& x);
        iterator Erase(iterator pos);
      private:
        T* _start;
        T* _finish;
        T* _end_of_storage;
    };
}
