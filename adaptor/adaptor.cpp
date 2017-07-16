#include<iostream>
#include"adaptee1.h"
#include"adaptee2.h"
#include"adaptor.h"

int main()
{
  std::cout<<client(Adaptor_{std::make_unique<Adaptee1_>()})<<std::endl;
}
