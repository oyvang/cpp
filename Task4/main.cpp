//
// main.cpp  E.L.
//

#include <iostream>
#include <string>

#include "Hus.h"

int main() {
  Person eier("Anne Ås", "Storgt 4, 7020 Trondheim", "23456783");
  Person budgiver1("Anders Jensen", "Karl Johans gt 6, 7020 Trondheim", "23456784");
  Person budgiver2("Åse Heim", "Oles gt 6, 7050 Trondheim", "23456785");
  Person budgiver3("Truls Hansen", "Karl Johans gt 8, 7020 Trondheim", "23456786");
  Person budgiver4("Inger Ås", "Heia, 7020 Trondheim", "23456787");
  Person budgiver5("Anne Lia", "Karl Johans gt 9, 7020 Trondheim", "23456788");

  Hus etHus(3, "Solskinnsveien 8, 7080 Heimdal", eier);
  Person person;
  long pris;
  if (!etHus.finnHoyesteBud(pris, person)) cout << "Ingen bud lagt inn ennå\n";

  etHus.leggInnNyttBud(15600000, budgiver1);
  etHus.leggInnNyttBud(14600000, budgiver2);
  etHus.leggInnNyttBud(15800000, budgiver3);
  etHus.leggInnNyttBud(16100000, budgiver4);
  etHus.leggInnNyttBud(14700000, budgiver5);

  for (int i = 0; i < etHus.finnAntallBud(); i++) {
    etHus.finnBudNr(i, pris, person);
    cout << "Pris: " << pris << " Budgiver: " << person.finnNavn() <<
       ", " << person.finnAdresse() << ", " << person.finnTelefon() << endl;
  }

  cout << "\nHøyeste bud:\n";
  etHus.finnHoyesteBud(pris, person);
  cout << "Pris: " << pris << " Budgiver: " << person.finnNavn() <<
       ", " << person.finnAdresse() << ", " << person.finnTelefon() << endl;

  // Prøver kopikonstruktøren. H1 er 16100000
  Hus kopiAvEtHus = etHus;

  // Legger inn et nytt bud i originalen som er høyere enn H1
  Person nyBudgiver1("Ole Olsen", "Ulvgata 56, 7000 Trondheim", "56565656");
  etHus.leggInnNyttBud(19900000, nyBudgiver1);  // H2 er 19900000

  // Legger inn et nytt bud i kopien som er lavere enn H1
  Person nyBudgiver2("Ole Olsen", "Ulvgata 56, 7000 Trondheim", "56565656");
  kopiAvEtHus.leggInnNyttBud(14000000, nyBudgiver2);

  cout << "\nHøyeste bud i det opprinnelige objektet:\n";
  etHus.finnHoyesteBud(pris, person);
  cout << "Pris: " << pris << " Budgiver: " << person.finnNavn() <<
       ", " << person.finnAdresse() << ", " << person.finnTelefon() << endl;

  cout << "\nHøyeste bud i kopien:\n";
  kopiAvEtHus.finnHoyesteBud(pris, person);
  cout << "Pris: " << pris << " Budgiver: " << person.finnNavn() <<
       ", " << person.finnAdresse() << ", " << person.finnTelefon() << endl;

  // Skal teste static-variabelen
  Hus nesteHus(3, "Solskinnsveien 9, 7080 Heimdal", eier);
  Hus endaEtHus(3, "Solskinnsveien 10, 7080 Heimdal", eier);
  cout << "Her kommer husnumrene: " << etHus.finnHusnr() << ", "
       << nesteHus.finnHusnr() << ", " << endaEtHus.finnHusnr() << endl;
  cout << "Høyeste husnr er " << Hus::finnHusnrMaks() << endl;
  return 0;
}

/* Utskrift:
Ingen bud lagt inn ennå
Pris: 15600000 Budgiver: Anders Jensen, Karl Johans gt 6, 7020 Trondheim, 23456784
Pris: 14600000 Budgiver: Åse Heim, Oles gt 6, 7050 Trondheim, 23456785
Pris: 15800000 Budgiver: Truls Hansen, Karl Johans gt 8, 7020 Trondheim, 23456786
Pris: 16100000 Budgiver: Inger Ås, Heia, 7020 Trondheim, 23456787
Pris: 14700000 Budgiver: Anne Lia, Karl Johans gt 9, 7020 Trondheim, 23456788

Høyeste bud:
Pris: 16100000 Budgiver: Inger Ås, Heia, 7020 Trondheim, 23456787

Høyeste bud i det opprinnelige objektet:
Pris: 19900000 Budgiver: Ole Olsen, Ulvgata 56, 7000 Trondheim, 56565656

Høyeste bud i kopien:
Pris: 16100000 Budgiver: Inger Ås, Heia, 7020 Trondheim, 23456787
Her kommer husnumrene: 1, 2, 3
Høyeste husnr er 3
*/
