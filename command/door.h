_Pragma("once");

#include<string>

class Door_
{
  public:
    std::string Open()const&noexcept
    {
      return "open";
    }
    std::string Close()const&noexcept
    {
      return "close";
    }
};
