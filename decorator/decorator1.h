_Pragma("once");

#include"decorator.h"

class Decorator1_ final:public Decorator_
{
  public:
    using Decorator_::Decorator_;
    int operator()()const&noexcept override;
    std::unique_ptr<Component_>Clone()const&override;
};

int Decorator1_::operator()()const&noexcept
{
  return this->Decorator_::operator()()+1;
}

std::unique_ptr<Component_>Decorator1_::Clone()const&
{
  return std::make_unique<Decorator1_>(*this);
}
