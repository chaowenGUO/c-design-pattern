_Pragma("once");

#include"strategy.h"

class Strategy1_ final:public Strategy_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Strategy_>Clone()const&override;
};

int Strategy1_::operator()()const&noexcept
{
  return 1;
}

std::unique_ptr<Strategy_>Strategy1_::Clone()const&
{
  return std::make_unique<Strategy1_>(*this);
}
