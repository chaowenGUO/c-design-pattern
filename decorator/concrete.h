_Pragma("once");

#include"component.h"

class Concrete_ final:public Component_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Component_>Clone()const&override;
};

int Concrete_::operator()()const&noexcept
{
  return 10;
}

std::unique_ptr<Component_>Concrete_::Clone()const&
{
  return std::make_unique<Concrete_>(*this);
}
