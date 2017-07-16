_Pragma("once");

class Observer_
{
  public:
    virtual void update(double const,double const,double const)=0;
  protected:
    virtual~Observer_()=default;
};
