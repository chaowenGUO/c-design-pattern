_Pragma("once");

#include"adaptee.h"

class Adaptee2_:public Adaptee_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Adaptee_>Clone()const&override;
};

int Adaptee2_::operator()()const&noexcept
{
  return 2;
}

std::unique_ptr<Adaptee_>Adaptee2_::Clone()const&
{
  return std::make_unique<Adaptee2_>(*this);
}
