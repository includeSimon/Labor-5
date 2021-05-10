#include "Business.h"
#include "Domain.h"
#include "Kunde.h"
#include "Persistence.h"
#include "Presentation.h"
#include "RepoError.h"
#include "Tests.h"
#include <iostream>
using namespace std;

int main(){

   Repository::CarRepo repo;
   Controller::CarController ctrl(repo);
   UI::Console ui(ctrl);

   ui.manager_run();
}