_Pragma("once");

#include"strategy.h"

class Strategy2_ final:public Strategy_
{
  public:
    int operator()()const&noexcept override;
    std::unique_ptr<Strategy_>Clone()const&override;
};

int Strategy2_::operator()()const&noexcept
{
  return 2;
}
    
std::unique_ptr<Strategy_>Strategy2_::Clone()const&
{
  return std::make_unique<Strategy2_>(*this);
}
