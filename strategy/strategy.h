_Pragma("once");

#include<memory>

class Strategy_
{
  public:
    virtual int operator()()const&noexcept=0;
    virtual std::unique_ptr<Strategy_>Clone()const& =0;
    virtual~Strategy_()=default;
};
