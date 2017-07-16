_Pragma("once");

#include"target.h"
#include"adaptee.h"

class Adaptor_:public Target_
{
  private:
    std::unique_ptr<Adaptee_>adaptee;
  public:
    explicit Adaptor_(std::unique_ptr<Adaptee_>)noexcept;
    Adaptor_(Adaptor_ const&);
    Adaptor_&operator=(Adaptor_ const&);
    Adaptor_(Adaptor_&&)=default;
    Adaptor_&operator=(Adaptor_&&)=default;
    int Request()const&noexcept override;
};

Adaptor_::Adaptor_(std::unique_ptr<Adaptee_>adaptee)noexcept:adaptee{std::move(adaptee)}{}

Adaptor_::Adaptor_(Adaptor_ const&Adaptor):adaptee{Adaptor.adaptee->Clone()}{}

Adaptor_&Adaptor_::operator=(Adaptor_ const&Adaptor)
{
  if(this==std::addressof(Adaptor)) return *this;
  this->adaptee=Adaptor.adaptee->Clone();
  return *this;
}

int Adaptor_::Request()const&noexcept
{
  return this->adaptee->operator()();
}
