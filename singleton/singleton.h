_Pragma("once");

class Singleton_ final
{
  private:
    int a{1};
    Singleton_()=default;
  public:
    static Singleton_&instance()noexcept;
    Singleton_(Singleton_&&)=delete;
    int operator()()const&noexcept;
};
