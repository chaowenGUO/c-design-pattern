#include"template.h"

int Template_::operator()()const&noexcept
{
  return this->Primitive1()+this->Primitive2()+this->Primitive3();
}

int Template_::Primitive1()const&noexcept
{
  return 1;
}

int Template_::Primitive3()const&noexcept
{
  return 3;
}
