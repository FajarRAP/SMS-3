// file stack.h
// formula-based stack

#ifndef Stack_
#define Stack_

#include "xcept.h"

template <class T>
class Stack
{
   // LIFO objects
public:
   Stack(int MaxStackSize = 10);
   ~Stack()
   {
      delete[] stack;
   }
   bool IsEmpty() const
   {
      return top == -1;
   }
   bool IsFull() const
   {
      return top == MaxTop;
   }
   T Top() const;
   Stack<T> &Add(const T &x);
   Stack<T> &Delete(T &x);
   void print()
   {
      for (int a = top; a >= 0; a--)
      {
         std::cout << *(stack + a);
      }
   }
   auto getData()
   {
      return *(stack + top);
   }

private:
   int top;    // current top of stack
   int MaxTop; // max value for top
   T *stack;   // element array
};

template <class T>
Stack<T>::Stack(int MaxStackSize)
{ // Stack constructor.
   this->MaxTop = MaxStackSize - 1;
   this->stack = new T[MaxStackSize];
   this->top = -1;
}

template <class T>
T Stack<T>::Top() const
{ // Return top element.
   if (IsEmpty())
   {
      throw OutOfBounds(); // Top fails
   }
   else
   {
      return *(stack + top);
   }
}

template <class T>
Stack<T> &Stack<T>::Add(const T &x)
{ // Add x to stack.
   if (IsFull())
   {
      throw NoMem(); // add fails
   }
   *(stack + (++top)) = x;
   return *this;
}

template <class T>
Stack<T> &Stack<T>::Delete(T &x)
{ // Delete top element and put in x.
   if (IsEmpty())
   {
      throw OutOfBounds(); // delete fails
   }
   x = *(stack + top--);
   return *this;
}

#endif
