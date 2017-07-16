_Pragma("once");

#include"template.h"

class Template1_ final:public Template_
{
  private:
    int Primitive1()const&noexcept override;
    int Primitive2()const&noexcept override; 
};
