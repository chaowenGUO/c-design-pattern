_Pragma("once");

#include"observer.h"
#include<list>

class Subject_
{
  private:
    std::list<>
  public:
    virtual void registerObserver(std::unique_ptr<Observer_>)=0;
    virtual void removeObserver(std::unique_ptr<Observer_>)=0;
    virtual void notifyObservers()const& =0;
  protected:
    virtual~Subject_()=default;	
};
