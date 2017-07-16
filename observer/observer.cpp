#include<boost/signals2.hpp>
#include<iostream>

class Subject_
{
  private:
    boost::signals2::signal<void(int const)>signal;
  public:
    auto connect(decltype(signal)::slot_function_type const&Slot)
    {
      return this->signal.connect(Slot);
    }
    void notify(int const Information)noexcept
    {
      this->signal(Information);
    }
};

class Observer1_
{
  private:
    boost::signals2::scoped_connection connection;
    int information;
  public:
    Observer1_(Subject_&subject):connection{subject.connect(std::bind(&Observer1_::Update,this,std::placeholders::_1))}{}
    void Update(int const Information)noexcept
    {
      this->information=Information;
    }
    auto Display()const&noexcept
    {
      return this->information;
    }
};

int main()
{
  Subject_ subject;
  Observer1_ observer(subject);
  subject.notify(1);
  std::cout<<observer.Display()<<std::endl;
}
