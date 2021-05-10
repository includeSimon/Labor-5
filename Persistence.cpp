#include "Persistence.h"

using namespace Repository;

CarRepo::CarRepo()
{
  this->list = {};
}

void CarRepo::add(const Car &car)
{

  this->list.push_back(car);
}

bool CarRepo::remove(const Car &car)
{
  for (int i = 0 ; i < list.size(); i++)
    if (list[i].checker(car)){
      list.erase(list.begin() + i);
      return true;
    }

  return false;
}

bool CarRepo::find(const Car &car)
{

  for (int i = 0; i < this->list.size(); i++)
  {
    if (this->list[i].checker(car))
      return true;
  }
  return false;
}

void CarRepo::update_Kilometers(Car &car, int _kilometers)
{

  if (find(car) == false)
    throw exception();

  for (int i = 0; i < this->list.size(); i++)
  {
    if (this->list[i].checker(car))
    {
      this->list[i].set_Kilometers(_kilometers);
    }
  }
}

void CarRepo::update_Price(Car &car, int _price)
{

  if (find(car) == false)
    throw exception();

  for (int i = 0; i < this->list.size(); i++)
  {
    if (this->list[i].checker(car))
      this->list[i].set_Price(_price);
  }
}

vector<Car> CarRepo::getAll()
{
  return this->list;
}

CarRepo::~CarRepo() = default;

int CarRepo::size(){
  return list.size();
}