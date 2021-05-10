#include "Business.h"
#include "Domain.h"
#include "Kunde.h"
#include "Persistence.h"
#include "Presentation.h"
#include "RepoError.h"
#include "Tests.h"
#include <iostream>
using namespace std;

int main()
{

  Repository::CarRepo repo;
  Controller::CarController ctrl(repo);
  UI::Console ui(ctrl);

  Client::Kunde Ana("anamaria05");

  int choice = 0;

  cout << "1. Manager" << endl;
  cout << "2. Client" << endl;
  cout << "0. Exit" << endl;

  vector<Client::Kunde> clients;

  while (true)
  {
    cout << "Enter option: " << endl;
    cin >> choice;

    if (choice == 0)
      break;

    if (choice == 1)
      ui.manager_run();

    if (choice == 2)
    {
      string name;
      bool ok = false;
      cout << "Enter the name of the user: " << endl;
      cin >> name;

      for (auto elem : clients)
        if (elem.get_name() == name)
        {
          ui.customer_run(elem);
          ok = true;
        }

      if (!ok){
        Client::Kunde newClient(name);
        clients.push_back(newClient);

        ui.customer_run(newClient);
      }
    }
  }

  return 0;
}