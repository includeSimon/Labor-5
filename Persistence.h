#pragma once
#include "Domain.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace Domain;

namespace Repository
{
  class CarRepo
  {
  public:
    CarRepo();
    void add(const Car &car);
    bool remove(const Car &car);
    bool find(const Car& car);
    void update_Kilometers(Car &car, int _kilometers);    //oare const din add ne deranjeaza in update? (l-am introdus ca si constant, iar noi vrem sa il stergem)
    void update_Price(Car &car, int _price);              //do we need const here too? - intrebare pentru prof
    int size();
    vector<Car> getAll();
    ~CarRepo();

  private:
    vector<Car> list;
  };
};