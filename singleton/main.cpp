#include<iostream>
#include"singleton.h"

int main()
{
  std::cout<<Singleton_::instance()()<<std::endl;
}
