_Pragma("once");

#include<memory>

class Adaptee_
{
  public:
    virtual int operator()()const&noexcept=0;
    virtual std::unique_ptr<Adaptee_>Clone()const& =0;
    virtual~Adaptee_()=default;
};
