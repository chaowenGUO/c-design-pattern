_Pragma("once");

#include"adaptee.h"

class Adaptee1_:public Adaptee_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Adaptee_>Clone()const&override;
};

int Adaptee1_::operator()()const&noexcept
{
  return 1;
}

std::unique_ptr<Adaptee_>Adaptee1_::Clone()const&
{
  return std::make_unique<Adaptee1_>(*this);
}
