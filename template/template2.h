_Pragma("once");

#include"template.h"

class Template2_ final:public Template_
{
  private:
    int Primitive1()const&noexcept override;
    int Primitive2()const&noexcept override;
    int Primitive3()const&noexcept override;
};
