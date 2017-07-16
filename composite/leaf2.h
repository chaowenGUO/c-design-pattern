_Pragma("once");

#include"component.h"

class Leaf2_:public Component_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Component_>Clone()const&override;
};

int Leaf2_::operator()()const&noexcept
{
  return 2;
}

std::unique_ptr<Component_>Leaf2_::Clone()const&
{
  return std::make_unique<Leaf2_>(*this);
}
