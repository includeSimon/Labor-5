#include "Presentation.h"
#include <iomanip>
using namespace UI;
using namespace std;
using namespace Client;
Car Console::reader() {
    string model,brand,fuel;
    int yearofregistration,kilometers,price,power;
    cout<<"Write the model : ";
    cin>>model;
    cout<<"\n Write the brand : ";
    cin>>brand;
    cout<<"\n Write the fuel type : ";
    cin>>fuel;
    cout<<"\n Write the year of registration : ";
    cin>>yearofregistration;
    cout<<"\n Write the kilometers of the car : ";
    cin>>kilometers;
    cout<<"\n Write the price : ";
    cin>>price;
    cout<<"\n Write the power of the car : ";
    cin>>power;
    Car result(model,brand,fuel,yearofregistration,kilometers,price,power);
    return result;

}


void Console::add(const Car &car) {


    this->_ctrl.add(car);
}

bool Console::remove(const Car &car) {
    return this->_ctrl.remove(car);
}

bool Console::find(const Car &car) {
    return this->_ctrl.find(car);
}

void Console::update_Price(Car &car, int _price) {
    this->_ctrl.update_Price(car,_price);
}

void Console::update_Kilometers(Car &car, int _kilometers) {
    this->_ctrl.update_Kilometers(car,_kilometers);
}

vector<Car> Console::getAll() {

    return this->_ctrl.getAll();
}

vector<Car> Console::findBrand(string brand) {
    this->_ctrl.findBrand(brand);
}

vector<Car> Console::findModel(string model) {
    this->_ctrl.findModel(model);
}

vector<Car> Console::findBrandAndModel(string brand, string model) {
    return this->_ctrl.findBrandAndModel(brand,model);
}

vector<Car> Console::filterByAge(int age) {
    return this->_ctrl.filterByAge(age);
}

vector<Car> Console::filterByKilometers(int kilometers) {
    return this->_ctrl.filterByKilometers(kilometers);
}
vector<Car> Console::filterByAgeAndKilometers(int age, int kilometers) {
    return this->_ctrl.filterByAgeAndKilometers(age,kilometers);
}

vector<Car> Console::sortByPrice(int price) {
    return this->_ctrl.sortByPrice(price);
}

void printer(vector<Car> my_vector){
    cout<<fixed;
    cout<<setprecision(8);
    cout<<left<<setw(15)<<"Model";
    cout<<right<<setw(13)<<"Brand";
    cout<<right<<setw(15)<<"Fuel";
    cout<<right<<setw(15)<<"Year";
    cout<<right<<setw(17)<<"Kilometers";
    cout<<right<<setw(15)<<"Price";
    cout<<right<<setw(15)<<"Power";
    cout<<"\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"\n";
    for(int i=0;i<my_vector.size();i++)
    {   cout<<fixed;
        cout<<setprecision(8);
        cout<<left<<setw(15)<<my_vector[i].get_Model();
        cout<<right<<setw(13)<<my_vector[i].get_Brand();
        cout<<right<<setw(15)<<my_vector[i].get_Fuel();
        cout<<right<<setw(15)<<my_vector[i].get_Year();
        cout<<right<<setw(17)<<my_vector[i].get_Kilometers();
        cout<<right<<setw(15)<<my_vector[i].get_Price();
        cout<<right<<setw(15)<<my_vector[i].get_Power();
        cout<<"\n";
    }

}
Kunde Console::find_client(string name) {
    for(int i=0;i<client_list.size();i++)
    {
        if(client_list[i].get_name()==name)
            return client_list[i];
    }
    throw exception();
}
void Console::manager_run() {
    string command,model,brand;
    vector<Car> result;
    Car new_car("","","",0,0,0,0);
    int yearofregistration,km;
    cout<<"Enter one of the commands to execute the specific command and write exit to end the program \n";
    cout<<"Write add to add a car to the list of all cars \n";
    cout<<"Write remove to remove one of the cars in the list \n";
    cout<<"Write find to find a specific car in the list \n";
    cout<<"Write update price in order to update the price of a specific car \n";
    cout<<"Write update kilometers in order to update the kilometers of a specific car \n";
    cout<<"Write all to see a list of all cars \n";
    cout<<"Write find1 to see all the cars of a specific brand \n";
    cout<<"Write find2 to see all the cars of a specific model \n ";
    cout<<"Write find3 in order to see all the cars of a specific brand and model \n ";
    cout<<"Write filter1  to find the cars from one specific year \n ";
    cout<<"Write filter2 to find all the cars with that number of kilometers driven \n ";
    cout<<"Write filter3 to find all the cars from a specific year and the amount of kilometers specified \n ";
    cin>>command;
    while(command != "exit")
    {
        if(command=="add"){
             new_car=reader();
            _ctrl.add(new_car);
        }

        if(command == "remove"){
            new_car=reader();
            _ctrl.remove(new_car);
        }

        if(command == "find"){
            new_car=reader();
            if(_ctrl.find(new_car))
                cout<<"The car is in the list\n";
            else
                cout<<"The car isn't in the list\n";

        }
        if(command == "update price"){
            new_car=reader();
            cout<<"pick a new price : ";
            int new_price;
            cin>>new_price;
            _ctrl.update_Price(new_car,new_price);
        }

        if(command == "update kilometers"){

            new_car=reader();
            cout<<"set the new number of kilometers : ";
            int new_km;
            cin>>new_km;
            _ctrl.update_Kilometers(new_car,new_km);
        }

        if(command == "all"){
            result=_ctrl.getAll();
            printer(result);

        }

        if(command == "find1"){

            cout<<"Select the brand you want to find  : ";
            cin>>brand;
            result=_ctrl.findBrand(brand);
            printer(result);
        }

        if(command == "find2"){


            cout<<"Select the model you want to find";
            cin>>model;
            result=_ctrl.findModel(model);
            printer(result);
        }

        if(command == "find3"){


            cout<<"Select the model and the brand you want to find \n";
            cout<<"Brand is : ";
            cin>>brand;
            cout<<"Model is : ";
            cin>>model;
            result=_ctrl.findBrandAndModel(brand,model);
            printer(result);
        }

        if(command == "filter1"){


            cout<<"Choose the age of the cars you want to filter";
            cin>>yearofregistration;
            result=_ctrl.filterByAge(yearofregistration);
            printer(result);
        }

        if(command == "filter2"){

            int km;
            cout<<"Choose the number of kilometers you want to filter";
            cin>>km;
            result=_ctrl.filterByKilometers(km);
            printer(result);
        }
        if(command == "filter3"){


            cout<<"Choose the age and the number of kilometers \n";
            cout<<"The age is : ";
            cin>>yearofregistration;
            cout<<"The nubmer of kilometers is : ";
            cin>>km;
            result=_ctrl.filterByAgeAndKilometers(yearofregistration,km);
            printer(result);

        }
        cout<<"Choose another command or write exit to stop using the program";
        cin>>command;
    }
}

void Console::customer_run(Kunde client) {
    string command,username,brand,model;
    Car new_car("","","",0,0,0,0);
    int yearofregistration,km;
    vector<Car> result;

    cout<<"Write find to find a specific car in the list \n";
    cout<<"Write update price in order to update the price of a specific car \n";
    cout<<"Write update kilometers in order to update the kilometers of a specific car \n";
    cout<<"Write all to see a list of all cars \n";
    cout<<"Write find1 to see all the cars of a specific brand \n";
    cout<<"Write find2 to see all the cars of a specific model \n ";
    cout<<"Write find3 in order to see all the cars of a specific brand and model \n ";
    cout<<"Write filter1  to find the cars from one specific year \n ";
    cout<<"Write filter2 to find all the cars with that number of kilometers driven \n ";
    cout<<"Write filter3 to find all the cars from a specific year and the amount of kilometers specified \n ";
    cout<<"Write add favourite to add a car to the favourite list \n";
    cout<<"Write delete favourite to delete a car from the favourite list \n";
    cin>>command;
    while(command != "exit"){
        if(command == "find"){
            new_car=reader();
            if(_ctrl.find(new_car))
                cout<<"The car is in the list\n";
            else
                cout<<"The car isn't in the list\n";

        }
        if(command == "update price"){
            new_car=reader();
            cout<<"pick a new price : ";
            int new_price;
            cin>>new_price;
            _ctrl.update_Price(new_car,new_price);
        }

        if(command == "update kilometers"){

            new_car=reader();
            cout<<"set the new number of kilometers : ";
            int new_km;
            cin>>new_km;
            _ctrl.update_Kilometers(new_car,new_km);
        }

        if(command == "all"){
            result=_ctrl.getAll();
            printer(result);

        }

        if(command == "find1"){

            cout<<"Select the brand you want to find  : ";
            cin>>brand;
            result=_ctrl.findBrand(brand);
            printer(result);
        }

        if(command == "find2"){


            cout<<"Select the model you want to find";
            cin>>model;
            result=_ctrl.findModel(model);
            printer(result);
        }

        if(command == "find3"){


            cout<<"Select the model and the brand you want to find \n";
            cout<<"Brand is : ";
            cin>>brand;
            cout<<"Model is : ";
            cin>>model;
            result=_ctrl.findBrandAndModel(brand,model);
            printer(result);
        }

        if(command == "filter1"){


            cout<<"Choose the age of the cars you want to filter";
            cin>>yearofregistration;
            result=_ctrl.filterByAge(yearofregistration);
            printer(result);
        }

        if(command == "filter2"){


            cout<<"Choose the number of kilometers you want to filter";
            cin>>km;
            result=_ctrl.filterByKilometers(km);
            printer(result);
        }
        if(command == "filter3"){


            cout<<"Choose the age and the number of kilometers \n";
            cout<<"The age is : ";
            cin>>yearofregistration;
            cout<<"The nubmer of kilometers is : ";
            cin>>km;
            result=_ctrl.filterByAgeAndKilometers(yearofregistration,km);
            printer(result);

        }

        if(command == "add favourite") {
            cout<<"Pick the car you want to add \n";
            new_car=reader();
            client.add_favourite(new_car);

        }

        if(command == "remove favourite"){

            cout<<"Pick the car you want to remove\n";
            new_car=reader();
            client.delete_favourite(new_car);
        }

        if(command == "show all") {

            result=client.show_all();
            printer(result);

        }

        if(command == "change")
        {
            cout<<"select a new user";
            cin>>username;
            client=find_client(username);
            customer_run(client);

        }
            cout << "Choose another command or write exit to stop using the program";
            cin >> command;

    }

}



