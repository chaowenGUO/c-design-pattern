_Pragma("once");

#include"component.h"

class Decorator_:public Component_
{
  private:
    std::unique_ptr<Component_>component;
  public:
    explicit Decorator_(std::unique_ptr<Component_>)noexcept;
    Decorator_(Decorator_ const&);
    Decorator_&operator=(Decorator_ const&);
    Decorator_(Decorator_&&)=default;
    Decorator_&operator=(Decorator_&&)=default;
    int operator()()const&noexcept override;
};

Decorator_::Decorator_(std::unique_ptr<Component_>component)noexcept:component{std::move(component)}{}

Decorator_::Decorator_(Decorator_ const&Decorator):component{Decorator.component->Clone()}{}
    
Decorator_&Decorator_::operator=(Decorator_ const&Decorator)
{
  if(this==std::addressof(Decorator)) return *this;
  this->component=Decorator.component->Clone();
  return *this;
}

int Decorator_::operator()()const&noexcept
{
  return this->component->operator()();
}
