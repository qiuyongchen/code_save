#include "PersonalAccount.h"
#include <iostream>
using namespace std;

int PersonalAccount::_total_per_account = 0;

int PersonalAccount::_acc_id_ptr = 12010000;

int PersonalAccount::get_total_per_account() {
  return _total_per_account;
}

PersonalAccount::PersonalAccount() {
  _id = _acc_id_ptr;
  _balance = 10;
  _valid = true;
  _acc_id_ptr++;
  _total_per_account++;
}

PersonalAccount::~PersonalAccount() {
  _total_per_account--;
}

string PersonalAccount::profile() const {
  string temp;
  temp += Account::profile() + "TYPE:PERSONAL\n";
  return temp;
}
void PersonalAccount::reset() {
  _balance = 10;
  _valid = true;
  _total_per_account = 0;
}

