_Pragma("once");

class Target_
{
  public:
    virtual int Request()const&noexcept=0;
    virtual ~Target_()=default;
};

int client(Target_ const&Target)
{
  return Target.Request();
}
