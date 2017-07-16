class Implementor_
{
  public:
    virtual int operator()()const&noexcept=0;
};

class Implementor1_ final:public Implementor_
{
  public:
    int operator()()const&noexcept override;
};

int Implementor1_::operator()()const&noexcept
{
  return 1;
}

class Implementor2_ final:public Implementor_
{
  public:
    int operator()()const&noexcept override;
};

int Implementor2_::operator()()const&noexcept
{
  return 2;
}

#include<memory>

class Abstraction_
{
  private:
    std::unique_ptr<Implementor_>implementor;
  public:
    Abstraction_(std::unique_ptr<Implementor_>);
    virtual int operator()()const&noexcept=0;
};

Abstraction_::Abstraction_(std::unique_ptr<Implementor_>implementor):implementor{std::move(implementor)}{}
