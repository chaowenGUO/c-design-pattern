#include<iostream>
#include<array>
#include<functional>
#include"light.h"
#include"door.h"

class Invoke_
{
  private:
    std::array<std::function<std::string()>,2>execute,stop;
  public:
    Invoke_(decltype(execute)const&Execute,decltype(stop)const&Stop):execute(Execute),stop(Stop){}
    void set(std::size_t const Slot,decltype(execute)::value_type const&Execute,decltype(stop)::value_type const&Stop)
    {
      this->execute.at(Slot)=Execute;
      this->stop.at(Slot)=Stop;
    }
    auto Execute(std::size_t const Slot)
    {
      return this->execute.at(Slot)();
    }
    auto Stop(std::size_t const Slot)
    {
      return this->stop.at(Slot)();
    }
};

int main()
{
  Light_ const Light;
  Door_ const Door;
  Invoke_ invoke{{std::bind(&Light_::On,Light),std::bind(&Door_::Open,Door)},{std::bind(&Light_::Off,Light),std::bind(&Door_::Close,Door)}};
  std::cout<<invoke.Execute(1)<<std::endl;
}
