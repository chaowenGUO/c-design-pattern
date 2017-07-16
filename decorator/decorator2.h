_Pragma("once");

#include"decorator.h"

class Decorator2_ final:public Decorator_
{
  public:
    using Decorator_::Decorator_;
    int operator()()const&noexcept override;
    std::unique_ptr<Component_>Clone()const&override;
};

int Decorator2_::operator()()const&noexcept
{
  return this->Decorator_::operator()()+2;
}

std::unique_ptr<Component_>Decorator2_::Clone()const&
{
  return std::make_unique<Decorator2_>(*this);
}
