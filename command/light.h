_Pragma("once");

#include<string>

class Light_
{
  public:
    std::string On()const&noexcept
    {
      return "on";
    }
    std::string Off()const&noexcept
    {
      return "off";
    }
};
