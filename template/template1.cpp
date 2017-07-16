#include"template1.h"

int Template1_::Primitive1()const&noexcept
{
  return this->Template_::Primitive1()+10;
}

int Template1_::Primitive2()const&noexcept
{
  return 12;
}
