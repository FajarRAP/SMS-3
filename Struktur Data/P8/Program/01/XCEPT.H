// exception classes for various error types

#ifndef Xcept_
#define Xcept_

// #include <except.h>
#include <new.h>

// bad initializers
class BadInitializers
{
public:
   BadInitializers() {}
};

// insufficient memory
class NoMem
{
public:
   NoMem()
   {
      // std::cout << "Memori tidak tersedia" << std::endl;
      // exit(1);
   }
};

// change new to throw NoMem instead of xalloc
void my_new_handler()
{
   throw NoMem();
};

std::new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

// improper array, find, insert, or delete index
// or deletion from empty structure
class OutOfBounds
{
public:
   OutOfBounds()
   {
      // std::cout << "Data Kosong" << std::endl;
      // exit(1);
   }
};

// use when operands should have matching size
class SizeMismatch
{
public:
   SizeMismatch() {}
};

// use when zero was expected
class MustBeZero
{
public:
   MustBeZero() {}
};

// use when zero was expected
class BadInput
{
public:
   BadInput() {}
};

#endif
