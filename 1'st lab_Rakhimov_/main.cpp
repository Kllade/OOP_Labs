#include <iostream>
#include "include/divisible.h"

using namespace std;

int main()
{
  int divider, bound;
  cout << "enter divider:";
  cin  >> divider;
  cout << "enter bound:";
  cin  >> bound;


  cout << "result: " << findMaxDivisible(divider, bound) << endl;

  return 0;
}
