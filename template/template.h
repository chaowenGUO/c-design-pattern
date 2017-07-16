_Pragma("once");

class Template_
{
  public:
    int operator()()const&noexcept;
    virtual~Template_()=default;
  protected:
    virtual int Primitive1()const&noexcept=0;
  private:
    virtual int Primitive2()const&noexcept=0;
    virtual int Primitive3()const&noexcept;
};
