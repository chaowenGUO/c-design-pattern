_Pragma("once");

#include<memory>

class Component_
{
  public:
    virtual int operator()()const&noexcept=0;
    virtual std::unique_ptr<Component_>Clone()const& =0;
    virtual~Component_()=default;
};
