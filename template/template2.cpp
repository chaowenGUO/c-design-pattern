#include"template2.h"

int Template2_::Primitive1()const&noexcept
{
  return this->Template_::Primitive1()+20;
}

int Template2_::Primitive2()const&noexcept
{
  return 22;
}

int Template2_::Primitive3()const&noexcept
{
  return 23;
}
