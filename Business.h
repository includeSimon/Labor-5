#pragma once
#include "Persistence.h"
#include <iostream>
using namespace std;
using namespace Repository;

#define AN_CURENT 2021;

namespace Controller{
  class CarController{
    public:
      CarController(CarRepo &_repo) : repo(_repo){};
      
      //methods of car repo
      void add(const Car &car);
      bool remove(const Car &car);
      bool find(const Car &car);
      void update_Kilometers(Car &car, int _kilometers); //oare const din add ne deranjeaza in update? (l-am introdus ca si constant, iar noi vrem sa il stergem)
      void update_Price(Car &car, int _price);           //do we need const here too? - intrebare pentru prof
      vector<Car> getAll();

      //individual methods of controller
      vector<Car> findBrand(string brand);
      vector<Car> findModel(string model);
      vector<Car> findBrandAndModel(string model, string brand);
      vector<Car> filterByAge(int age);
      vector<Car> filterByKilometers(int kilometers);
      vector<Car> filterByAgeAndKilometers(int age, int kilometers);
      vector<Car> sortByPrice();

      ~CarController(){};

    private:
      CarRepo & repo;
  };
};
