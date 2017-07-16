_Pragma("once");

#include"component.h"
#include<list>

class Composite_:public Component_
{
  private:
    std::list<std::unique_ptr<Component_>>composite;
  public:
    int operator()()const&noexcept override;
    Composite_()=default;
    Composite_(Composite_ const&);
    Composite_&operator=(Composite_ const&);
    Composite_(Composite_&&)=default;
    Composite_&operator=(Composite_&&)=default;
    void emplace_back(std::unique_ptr<Component_>); 
    std::unique_ptr<Component_>Clone()const&override;
};

#include<algorithm>

int Composite_::operator()()const&noexcept
{
  return std::accumulate(this->composite.cbegin(),this->composite.cend(),0,[](int const Sum,auto const&Component){return Sum+Component->operator()();});
}

Composite_::Composite_(Composite_ const&Composite):composite(Composite.composite.size())
{
  std::transform(Composite.composite.cbegin(),Composite.composite.cend(),this->composite.begin(),[](auto const&Element){return Element->Clone();});
}

Composite_&Composite_::operator=(Composite_ const&Composite)
{
  if(this==std::addressof(Composite)) return *this;
  std::transform(Composite.composite.cbegin(),Composite.composite.cend(),this->composite.begin(),[](auto const&Element){return Element->Clone();});
  return *this;
}

void Composite_::emplace_back(std::unique_ptr<Component_>component)
{
  this->composite.emplace_back(std::move(component));
}

std::unique_ptr<Component_>Composite_::Clone()const&
{
  return std::make_unique<Composite_>(*this);
}

