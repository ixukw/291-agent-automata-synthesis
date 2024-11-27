#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "vops.h"
#include "test.h"

using namespace std;

void main__Wrapper_ANONYMOUSTest(Parameters& _p_) {
  for(int _test_=0;_test_< _p_.niters ;_test_++) {
    try{
      ANONYMOUS::main__WrapperNospec();
      ANONYMOUS::main__Wrapper();
    }catch(AssumptionFailedException& afe){  }
  }
}

void transition__Wrapper_ANONYMOUSTest(Parameters& _p_) {
  for(int _test_=0;_test_< _p_.niters ;_test_++) {
    if(2 * 1==0){ continue; }
    int*  grid= new int [2 * 1];
    for(int _i_=0;_i_<2 * 1;_i_++) {
      grid[_i_]=abs(rand()) % 32;
    }
    if(_p_.verbosity > 2){
      cout<<"grid=[";
      for(int _i_=0;_i_<2 * 1;_i_++) {
        cout<<grid[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    if(2==0){ continue; }
    int*  pos= new int [2];
    for(int _i_=0;_i_<2;_i_++) {
      pos[_i_]=abs(rand()) % 32;
    }
    if(_p_.verbosity > 2){
      cout<<"pos=[";
      for(int _i_=0;_i_<2;_i_++) {
        cout<<pos[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    if(2==0){ continue; }
    int*  true_next_pos= new int [2];
    for(int _i_=0;_i_<2;_i_++) {
      true_next_pos[_i_]=abs(rand()) % 32;
    }
    if(_p_.verbosity > 2){
      cout<<"true_next_pos=[";
      for(int _i_=0;_i_<2;_i_++) {
        cout<<true_next_pos[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    try{
      ANONYMOUS::transition__WrapperNospec(grid,pos,true_next_pos);
      ANONYMOUS::transition__Wrapper(grid,pos,true_next_pos);
    }catch(AssumptionFailedException& afe){  }
    delete[] grid;

    delete[] pos;

    delete[] true_next_pos;

  }
}

int main(int argc, char** argv) {
  Parameters p(argc, argv);
  srand(time(0));
  main__Wrapper_ANONYMOUSTest(p);
  transition__Wrapper_ANONYMOUSTest(p);
  printf("Automated testing passed for test\n");
  return 0;
}
