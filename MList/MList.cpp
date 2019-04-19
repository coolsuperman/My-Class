#include<list>
#include<iostream>
using namespace std;

template<class T>
struct ListNode{
  ListNode(const T& val = T())//?什么操作？
    :_next(NULL)
     ,_pre(NULL)
     ,_val(val)
  {}
  ListNode<T>* _next;
  ListNode<T>* _pre;
  T _val;
};

template<class T,class Ref,class Ptr>
struct ListIterator{//构建迭代器
  typedef ListNode<T>* pNode;
  pNode _node;
  ListIterator(pNode node)
    :_node(node)
  {}
  ListIterator<T,Ref,Ptr>& operator++(){//前置++
    _node= _node->_next;
    return *this;
  }
  ListIterator<T,Ref,Ptr>& operator--(){//前置--
    _node = _node->_pre;
    return *this;
  }
  ListIterator<T,Ref,Ptr> operator--(int){//后置--
    ListIterator<T,Ref,Ptr> tmp(*this);
    _node = _node->_pre;
    return tmp;
  }
  ListIterator<T,Ref,Ptr> operator++(int){//返回变之前的值,就用int区别
    ListIterator<T,Ref,Ptr> tmp(*this);//默认拷贝的浅拷贝就够用了，里面放的是地址啊，_node后面改了的是地址，所以可以
    _node = _node->_next;
    return tmp;
  }
  Ref operator*(){//解引用操作
    return _node->_val;
  }
  Ptr operator->(){//当key是一个结构体时；??????????????/？？？？
    return &_node->_val;
  }
  bool operator!=(const ListIterator<T,Ref,Ptr>& target){//Node*不用重载吗？
    if(_node==target._node)
      return false;
    return true;
  }
};

template<class T>
class List{
  public:
    typedef ListNode<T> Node;
    typedef ListIterator<T,T&,T*> iterator;
    //const 对象不能调用非const成员函数，只能调用const成员函数。
    //但是const成员函数operator++，--，就不能修改node的值了
    //导致const无法执行++，所以得再写一个const类
    typedef ListIterator<T,const T&,const T*> const_iterator;

    const_iterator begin()const{
      return const_iterator(_head->_next);
    }

    const_iterator end()const{
      return const_iterator(_head);
    }
    iterator begin(){
      return iterator(_head->_next);
    }

    iterator end(){
      return iterator(_head);//封装一个头结点，因为最后一个节点过来就是头结点！
    }

    List(const T& val = T())
      :_head(new Node(val))
    {
      _head->_next = _head;
      _head->_pre = _head;
    }
    List(const List<T>& b){
      _head = new Node;
      _head->_next = _head;
      _head->_pre = _head;
      const_iterator cit = b.begin();
      while(cit!=b.end()){
        PushBack(*cit.operator->());
        cit++;
      }
    }
    ~List(){
      Clear();
      if(_head){
        delete _head;
        _head = NULL;
      }
    }
   // List<T>& operator = (const List<T>& b){
   //   if(this!=&b){
   //     Clear();  
   //     const_iterator cit = b.begin();
   //     while(cit!=b.end()){
   //       PushBack(*cit.operator->());
   //       cit++;
   //     }
   //   }
   //   return *this;
   // }
    List<T>& operator =(List<T> b){
      swap(_head,b._head);
      return *this;
    }
    void Insert(iterator pos,const T& val){
      Node* fresh = new Node(val);
      Node* cur = pos._node;
      Node* pre = cur->_pre;
      pre->_next = fresh;
      fresh->_pre = pre;
      fresh->_next = cur;
      cur->_pre = fresh;
    }
    void PushBack(const T& val){
      Insert(end(),val);
    }
    void PushFront(const T& val){
      Insert(begin(),val);
    }
    iterator Erase(iterator pos){//迭代器会失效
      if (pos != end()){
        Node* cur = pos._node;
        Node* pre = cur->_pre;
        Node* next = cur->_next;
        pre->_next = next;
        next->_pre = pre;
        delete cur;
        //更新迭代器
        pos = iterator(next);
      }
      return pos;
    }
    void PopFront(){
      Erase(begin());
    }
    void PopBack(){
      Erase(--end());
    }
    void Clear(){
      if(_head){
        Node* cur = _head->_next;
        while(cur!=_head){
          Node* next = cur->_next;
          delete cur;
          cur = next;
        }
        _head->_next = _head;
        _head->_pre = _head;
      }
    }
    void PrintList(){
      iterator it = begin();
      while(it!=end()){
        cout<<*it<<" ";
        ++it;
      }
      cout<<endl;
    }
  private:
    Node* _head;
};


int main(){
  List<int> test;
  test.PushBack(1);
  test.PushBack(2);
  test.PushBack(3);
  test.PushBack(4);
  test.PushBack(5);
  test.PushBack(6);
  test.PopBack();
  test.PrintList();
  List<int> newl(test);
  newl.PrintList();
  List<int> newk;
  newk = newl;
  newk.PrintList();
  return 0;
}
