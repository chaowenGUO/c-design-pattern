_Pragma("once");

#include"component.h"

class Leaf1_:public Component_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Component_>Clone()const&override;
};

int Leaf1_::operator()()const&noexcept
{
  return 1;
}

std::unique_ptr<Component_>Leaf1_::Clone()const&
{
  return std::make_unique<Leaf1_>(*this);
}
