#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "vops.h"
#include "fixedgrid.h"

using namespace std;

void try_transition_ANONYMOUSTest(Parameters& _p_) {
  for(int _test_=0;_test_< _p_.niters ;_test_++) {
    if(2==0){ continue; }
    int*  pos_now= new int [2];
    for(int _i_=0;_i_<2;_i_++) {
      pos_now[_i_]=abs(rand()) % 32;
    }
    if(_p_.verbosity > 2){
      cout<<"pos_now=[";
      for(int _i_=0;_i_<2;_i_++) {
        cout<<pos_now[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    if(2==0){ continue; }
    int*  action= new int [2];
    for(int _i_=0;_i_<2;_i_++) {
      action[_i_]=abs(rand()) % 32;
    }
    if(_p_.verbosity > 2){
      cout<<"action=[";
      for(int _i_=0;_i_<2;_i_++) {
        cout<<action[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    if(2==0){ continue; }
    int*  _out_outsk= new int [2];
    if(2==0){ continue; }
    int*  _out_outsp= new int [2];
    for(int _i_=0;_i_<2;_i_++) {
      _out_outsk[_i_]=0U;
    }
    if(_p_.verbosity > 2){
      cout<<"_out_outsk=[";
      for(int _i_=0;_i_<2;_i_++) {
        cout<<_out_outsk[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    for(int _i_=0;_i_<2;_i_++) {
      _out_outsp[_i_]=0U;
    }
    if(_p_.verbosity > 2){
      cout<<"_out_outsp=[";
      for(int _i_=0;_i_<2;_i_++) {
        cout<<_out_outsp[_i_]<<", ";
      }
      cout<<"]"<<endl;
    }
    try{
      ANONYMOUS::true_transition(pos_now,action,_out_outsk);
      ANONYMOUS::try_transition(pos_now,action,_out_outsp);
    }catch(AssumptionFailedException& afe){  }
    for(int _i_=0;_i_<2;_i_++) {
      if(_out_outsk[_i_]!=_out_outsp[_i_]) {
        printf("Automated testing failed in try_transition_ANONYMOUSTest\n");
        cout<<"pos_now = "<<printArr(pos_now, 2)<<endl;
        cout<<"action = "<<printArr(action, 2)<<endl;
        cout<<"_out_outsk = "<<printArr(_out_outsk, 2)<<endl;
        cout<<"_out_outsp = "<<printArr(_out_outsp, 2)<<endl;
        exit(1);
      }
    }
    delete[] pos_now;

    delete[] action;

    delete[] _out_outsk;

    delete[] _out_outsp;

  }
}

void main__Wrapper_ANONYMOUSTest(Parameters& _p_) {
  for(int _test_=0;_test_< _p_.niters ;_test_++) {
    try{
      ANONYMOUS::main__WrapperNospec();
      ANONYMOUS::main__Wrapper();
    }catch(AssumptionFailedException& afe){  }
  }
}

int main(int argc, char** argv) {
  Parameters p(argc, argv);
  srand(time(0));
  main__Wrapper_ANONYMOUSTest(p);
  try_transition_ANONYMOUSTest(p);
  printf("Automated testing passed for fixedgrid\n");
  return 0;
}
