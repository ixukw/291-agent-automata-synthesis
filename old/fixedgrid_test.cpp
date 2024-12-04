#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "vops.h"
#include "fixedgrid.h"

using namespace std;

void main__Wrapper_ANONYMOUSTest(Parameters& _p_) {
  for(int _test_=0;_test_< _p_.niters ;_test_++) {
    int  posX;
    posX=abs(rand()) % 32;
    if(_p_.verbosity > 2){
      cout<<"posX="<<posX<<endl;
    }
    int  posY;
    posY=abs(rand()) % 32;
    if(_p_.verbosity > 2){
      cout<<"posY="<<posY<<endl;
    }
    try{
      ANONYMOUS::main__WrapperNospec(posX,posY);
      ANONYMOUS::main__Wrapper(posX,posY);
    }catch(AssumptionFailedException& afe){  }
  }
}

int main(int argc, char** argv) {
  Parameters p(argc, argv);
  srand(time(0));
  main__Wrapper_ANONYMOUSTest(p);
  printf("Automated testing passed for fixedgrid\n");
  return 0;
}
