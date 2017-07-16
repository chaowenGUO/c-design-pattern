#include"singleton.h"

//can not inline such function, inline means compiler can copy such function, copy such function also copy local static object inside such function, that is not singleton
Singleton_&Singleton_::instance()noexcept
{
  static Singleton_ instance;
  return instance;
}

int Singleton_::operator()()const&noexcept
{
  return this->a;
}
