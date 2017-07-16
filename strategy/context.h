_Pragma("once");

#include"strategy.h"

class Context_ final//template (1) 可以在编译时选择 Strategy (2) 它不需在运行时改变
{
  private:
    std::unique_ptr<Strategy_>strategy;
  public:
    explicit Context_(std::unique_ptr<Strategy_>)noexcept;
    Context_(Context_ const&);
    Context_&operator=(Context_ const&);
    Context_(Context_&&)=default;
    Context_&operator=(Context_&&)=default;//if a class defines its own copy constructor, copy-assignment operator, or destructor, the move constructor and move-assignment operator are not synthesized//primer 666
    auto Strategy()const&noexcept;
    void setStrategy(std::unique_ptr<Strategy_>)noexcept;
};

Context_::Context_(std::unique_ptr<Strategy_>strategy)noexcept:strategy{std::move(strategy)}{}

Context_::Context_(Context_ const&Context):strategy{Context.strategy->Clone()}{}

Context_&Context_::operator=(Context_ const&Context)
{
  if(this==std::addressof(Context)) return *this;
  this->strategy=Context.strategy->Clone();
  return *this;
}

auto Context_::Strategy()const&noexcept
{
  return this->strategy->operator()();
}

void Context_::setStrategy(std::unique_ptr<Strategy_>strategy)noexcept
{
  this->strategy=std::move(strategy);
}
