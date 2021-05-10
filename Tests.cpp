#include <iostream>
#include "Domain.h"
#include "Business.h"
#include "Persistence.h"
#include <cassert>
#include <vector>
using namespace std;
using namespace Controller;
using namespace Domain;

void test_add_car()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  assert(repo.size() == 11);
}

void test_remove_car()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  assert(repo.remove(car1) == true);
  assert(carctrl.remove(car2) == true);
  assert(carctrl.remove(car3) == true);
  assert(repo.size() == 8);
}

void test_find_car()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  assert(carctrl.find(car8) == true);
  assert(carctrl.find(car9) == true);
  assert(carctrl.find(car10) == true);

  carctrl.remove(car1);
  assert(carctrl.find(car1) == false);
}

void test_update_kilometers()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  repo.update_Kilometers(car4, 800);
  car4.set_Kilometers(800);
  assert(repo.find(car4) == true);

  repo.update_Kilometers(car5, 800);
  car5.set_Kilometers(800);
  assert(repo.find(car5) == true);

  repo.update_Kilometers(car6, 800);
  car6.set_Kilometers(800);
  assert(repo.find(car6) == true);

  repo.update_Kilometers(car7, 800);
  car7.set_Kilometers(800);
  assert(repo.find(car7) == true);

  repo.update_Kilometers(car9, 800);
  car9.set_Kilometers(800);
  assert(repo.find(car9) == true);

  repo.update_Kilometers(car10, 800);
  car10.set_Kilometers(800);
  assert(repo.find(car10) == true);
}

void test_update_price()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  repo.update_Price(car4, 80000);
  car4.set_Price(80000);
  assert(repo.find(car4) == true);

  repo.update_Price(car5, 5000);
  car5.set_Price(5000);
  assert(repo.find(car5) == true);

  repo.update_Price(car6, 76500);
  car6.set_Price(76500);
  assert(repo.find(car6) == true);

  repo.update_Price(car7, 90000);
  car7.set_Price(90000);
  assert(repo.find(car7) == true);

  repo.update_Price(car9, 20000);
  car9.set_Price(20000);
  assert(repo.find(car9) == true);

  repo.update_Price(car10, 31000);
  car10.set_Price(31000);
  assert(repo.find(car10) == true);
}

void test_findBrand()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.findBrand("Volkswagen");
  assert(cars.size() == 2); 

  cars = carctrl.findBrand("BMW");
  assert(cars.size() == 2); 

  cars = carctrl.findBrand("Audi");
  assert(cars.size() == 3); 

  cars = carctrl.findBrand("Land Rover");
  assert(cars.size() == 1);

  cars = carctrl.findBrand("Porsche");
  assert(cars.size() == 2); 
}

void test_findModel()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.findModel("Cabriolet");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("Polo");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("Q7");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("X6");
  assert(cars.size() == 1);

  cars = carctrl.findModel("Range Rover Velar");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("A6");
  assert(cars.size() == 1);

  cars = carctrl.findModel("Macan Facelift");
  assert(cars.size() == 1);
}

void test_findBrandAndModel()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.findBrandAndModel("Cabriolet", "BMW");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Polo", "Volkswagen");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Q7", "Audi");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("X6", "BMW");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Range Rover Velar", "Land Rover");
  assert(cars.size() == 1);

  cars = carctrl.findBrandAndModel("A6", "Audi");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Macan Facelift", "Porsche");
  assert(cars.size() == 1); 
}

void test_filterByAge()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.filterByAge(2020);
  assert(cars.size() == 2); 

  cars = carctrl.filterByAge(2015);
  assert(cars.size() == 2); 

  cars = carctrl.filterByAge(2018);
  assert(cars.size() == 2); 

  cars = carctrl.filterByAge(2021);
  assert(cars.size() == 2); 
}

void test_filterByKilometers()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.filterByKilometers(80000);
  assert(cars.size() == 1); 
}

void test_filterByAgeAndKilometers()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.filterByAgeAndKilometers(2020, 700);
  assert(cars.size() == 1); 

  cars = carctrl.filterByAgeAndKilometers(2015, 100000);
  assert(cars.size() == 1); 

  cars = carctrl.filterByAgeAndKilometers(2018, 10000);
  assert(cars.size() == 1); 

  cars = carctrl.filterByAgeAndKilometers(2021, 0);
  assert(cars.size() == 2); 
}

void test_sortByPrice()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.add(car1);
  carctrl.add(car2);
  carctrl.add(car3);
  carctrl.add(car4);
  carctrl.add(car5);
  carctrl.add(car6);
  carctrl.add(car7);
  carctrl.add(car8);
  carctrl.add(car9);
  carctrl.add(car10);
  carctrl.add(car11);

  vector<Car> cars = carctrl.sortByPrice();
  assert(cars[0].get_Price() == 2000);

  assert(cars[cars.size() - 1].get_Price() == 80000);
}

void test_all()
{
  cout << "Beginning of tests!" << endl;
  test_add_car();
  test_remove_car();
  test_find_car();
  test_update_kilometers();
  test_update_price();
  test_findBrand();
  test_findModel();
  test_findBrandAndModel();
  test_filterByAge();
  test_filterByKilometers();
  test_filterByAgeAndKilometers();
  test_sortByPrice();
  cout << "End of tests!" << endl;
}