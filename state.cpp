class State_;

#include<memory>

class Context_
{
  private:
    int context;
    std::unique_ptr<State_>state;
  public:
    Context_(int const,std::unique_ptr<State_>);
  friend class State_;
};

Context_::Context_(int const Context,std::unique_ptr<State_>state):context{Context},state{std::move(state)}{}

class State_
{
  public:
    virtual int operator()(int const)const&noexcept=0;
    virtual~State_()=default;
};

class State1_:public State_
{
  public:
    int operator()(int const)const&noexcept override;
};

int State1_::operator()(int const Argument)const&noexcept
{
  return Argument+1;
}
