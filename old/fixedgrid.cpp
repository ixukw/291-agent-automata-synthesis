#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "fixedgrid.h"
namespace str{

template<typename T_0>
Str* Str::create(int  n_, T_0* buf_, int buf_len){
  int tlen_buf = n_; 
  void* temp= malloc( sizeof(Str)   + sizeof(char )*tlen_buf); 
  Str* rv = new (temp)Str();
  rv->n =  n_;
  CopyArr(rv->buf, buf_, tlen_buf, buf_len ); 
  return rv;
}
void intAsChar(int x, char& _out) {
  _out = x % 10;
  return;
}
void newStr(int n, char* w/* len = n */, Str*& _out) {
  _out = Str::create(n, w, n);
  return;
}
void println(Str* s) { printf("%s \n ", s->buf); }

}
namespace ANONYMOUS{

<<<<<<< Updated upstream
void main__Wrapper() {
  _main();
}
void main__WrapperNospec() {}
void _main() {
  bool _tt0[2] = {0, 0};
  int*  pos= new int [2]; CopyArr<int >(pos,_tt0, 2, 2);
  bool _tt1[2] = {0, 0};
  int*  pos_next_s3= new int [2]; CopyArr<int >(pos_next_s3,_tt1, 2, 2);
  bool _tt2[2] = {1, 0};
  int * _tt3= new int [2]; 
  CopyArr<int>(_tt3,_tt2, 2, 2);
  true_transition(pos, _tt3, pos_next_s3);
  bool _tt4[2] = {0, 0};
  int*  action_s5= new int [2]; CopyArr<int >(action_s5,_tt4, 2, 2);
  transition(pos, pos_next_s3, action_s5);
  assert ((((action_s5[0])) >= (-1)) && (((action_s5[0])) <= (1)));;
  assert ((((action_s5[1])) >= (-1)) && (((action_s5[1])) <= (1)));;
  assert ((((action_s5[0])) == (1)) && (((action_s5[1])) == (0)));;
  str::Str*  _out_s7=NULL;
  char _tt5[7] = {'A', 'C', 'T', 'I', 'O', 'N', '\0'};
  str::newStr(7, _tt5, _out_s7);
  str::println(_out_s7);
  str::Str*  _out_s9=NULL;
  char _tt6[2] = {(action_s5[0]), '\0'};
  str::newStr(2, _tt6, _out_s9);
  str::println(_out_s9);
  str::Str*  _out_s11=NULL;
  char _tt7[2] = {(action_s5[1]), '\0'};
  str::newStr(2, _tt7, _out_s11);
  str::println(_out_s11);
  str::Str*  _out_s13=NULL;
  char _tt8[4] = {'p', 'o', 's', '\0'};
  str::newStr(4, _tt8, _out_s13);
  str::println(_out_s13);
  str::Str*  _out_s15=NULL;
  char _tt9[2] = {(pos[0]), '\0'};
  str::newStr(2, _tt9, _out_s15);
  str::println(_out_s15);
  str::Str*  _out_s17=NULL;
  char _tt10[2] = {(pos[1]), '\0'};
  str::newStr(2, _tt10, _out_s17);
  str::println(_out_s17);
  str::Str*  _out_s19=NULL;
  char _tt11[9] = {'p', 'o', 's', '_', 'n', 'e', 'x', 't', '\0'};
  str::newStr(9, _tt11, _out_s19);
  str::println(_out_s19);
  str::Str*  _out_s21=NULL;
  char _tt12[2] = {(pos_next_s3[0]), '\0'};
  str::newStr(2, _tt12, _out_s21);
  str::println(_out_s21);
  str::Str*  _out_s23=NULL;
  char _tt13[2] = {(pos_next_s3[1]), '\0'};
  str::newStr(2, _tt13, _out_s23);
  str::println(_out_s23);
}
void true_transition(int* pos/* len = 2 */, int* action/* len = 2 */, int* _out/* len = 2 */) {
  int _tt14[2] = {(pos[0]) + (action[0]), (pos[1]) + (action[1])};
  CopyArr<int >(_out,_tt14, 2, 2);
  return;
}
void transition(int* pos_now/* len = 2 */, int* pos_next/* len = 2 */, int* _out/* len = 2 */) {
  if(!((((pos_now[0])) < (5)) && (((pos_now[0])) >= (0)))){ throw AssumptionFailedException();  };
  if(!((((pos_now[1])) < (5)) && (((pos_now[1])) >= (0)))){ throw AssumptionFailedException();  };
  assert (((((pos_now[0]) + 1)) < (5)) && ((((pos_now[1]) + 1)) >= (0)));;
  assert ((((pos_now[0])) < (5)) && (((pos_now[1])) >= (0)));;
  str::Str*  _out_s25=NULL;
  char _tt15[2] = {1, '\0'};
  str::newStr(2, _tt15, _out_s25);
  str::println(_out_s25);
  str::Str*  _out_s27=NULL;
  char _tt16[2] = {0, '\0'};
  str::newStr(2, _tt16, _out_s27);
  str::println(_out_s27);
  bool _tt17[2] = {1, 0};
  CopyArr<int >(_out,_tt17, 2, 2);
  bool _tt18[2] = {0, 0};
  int*  pos_try_s29= new int [2]; CopyArr<int >(pos_try_s29,_tt18, 2, 2);
  try_transition(pos_now, _out, pos_try_s29);
  assert (((pos_try_s29[0])) == ((pos_next[0])));;
  assert (((pos_try_s29[1])) == ((pos_next[1])));;
  delete[] pos_try_s29;
=======
void main__Wrapper(int posX, int posY) {
  _main(posX, posY);
}
void main__WrapperNospec(int posX, int posY) {}
void _main(int posX, int posY) {
  if(!((posX) > (0))){ throw AssumptionFailedException();  };
  if(!((posY) > (0))){ throw AssumptionFailedException();  };
  if(!((posX) < (5))){ throw AssumptionFailedException();  };
  if(!((posY) < (5))){ throw AssumptionFailedException();  };
  bool _tt0[2] = {0, 0};
  int*  pos_next_s3= new int [2]; CopyArr<int >(pos_next_s3,_tt0, 2, 2);
  int _tt1[2] = {posX, posY};
  bool _tt2[2] = {1, 0};
  int * _tt3= new int [2]; 
  CopyArr<int>(_tt3,_tt2, 2, 2);
  true_transition(_tt1, _tt3, pos_next_s3);
  bool _tt4[2] = {0, 0};
  int*  pos_try_next_s5= new int [2]; CopyArr<int >(pos_try_next_s5,_tt4, 2, 2);
  int _tt5[2] = {posX, posY};
  transition(_tt5, pos_next_s3, pos_try_next_s5);
  bool _tt6[2] = {0, 0};
  int*  pos_try_next_s7= new int [2]; CopyArr<int >(pos_try_next_s7,_tt6, 2, 2);
  int _tt7[2] = {posX, posY};
  try_transition(_tt7, pos_try_next_s5, pos_try_next_s7);
  assert ((((pos_try_next_s7[0])) == ((pos_next_s3[0]))) && (((pos_try_next_s7[1])) == ((pos_next_s3[1]))));;
  char  _out_s9='\0';
  str::intAsChar((pos_try_next_s7[0]), _out_s9);
  str::Str*  _out_s11=NULL;
  char _tt8[2] = {_out_s9, '\0'};
  str::newStr(2, _tt8, _out_s11);
  str::println(_out_s11);
  char  _out_s13='\0';
  str::intAsChar((pos_try_next_s7[1]), _out_s13);
  str::Str*  _out_s15=NULL;
  char _tt9[2] = {_out_s13, '\0'};
  str::newStr(2, _tt9, _out_s15);
  str::println(_out_s15);
  char  _out_s17='\0';
  str::intAsChar((pos_next_s3[0]), _out_s17);
  str::Str*  _out_s19=NULL;
  char _tt10[2] = {_out_s17, '\0'};
  str::newStr(2, _tt10, _out_s19);
  str::println(_out_s19);
  char  _out_s21='\0';
  str::intAsChar((pos_next_s3[1]), _out_s21);
  str::Str*  _out_s23=NULL;
  char _tt11[2] = {_out_s21, '\0'};
  str::newStr(2, _tt11, _out_s23);
  str::println(_out_s23);
}
void true_transition(int* pos/* len = 2 */, int* action/* len = 2 */, int* _out/* len = 2 */) {
  int _tt12[2] = {(pos[0]) + (action[0]), (pos[1]) + (action[1])};
  CopyArr<int >(_out,_tt12, 2, 2);
  return;
}
void transition(int* pos_now/* len = 2 */, int* pos_next/* len = 2 */, int* _out/* len = 2 */) {
  char  _out_s25='\0';
  str::intAsChar(1, _out_s25);
  str::Str*  _out_s27=NULL;
  char _tt13[2] = {_out_s25, '\0'};
  str::newStr(2, _tt13, _out_s27);
  str::println(_out_s27);
  char  _out_s29='\0';
  str::intAsChar(0, _out_s29);
  str::Str*  _out_s31=NULL;
  char _tt14[2] = {_out_s29, '\0'};
  str::newStr(2, _tt14, _out_s31);
  str::println(_out_s31);
  bool _tt15[2] = {0, 0};
  int*  pos_try_s33= new int [2]; CopyArr<int >(pos_try_s33,_tt15, 2, 2);
  bool _tt16[2] = {1, 0};
  int * _tt17= new int [2]; 
  CopyArr<int>(_tt17,_tt16, 2, 2);
  try_transition(pos_now, _tt17, pos_try_s33);
  assert (((pos_try_s33[0])) == ((pos_next[0])));;
  assert (((pos_try_s33[1])) == ((pos_next[1])));;
  bool _tt18[2] = {1, 0};
  CopyArr<int >(_out,_tt18, 2, 2);
  delete[] pos_try_s33;
  delete[] _tt17;
  return;
}
void try_transition(int* pos_now/* len = 2 */, int* action/* len = 2 */, int* _out/* len = 2 */) {
  int _tt19[2] = {(pos_now[0]) + (action[0]), (pos_now[1]) + (action[1])};
  CopyArr<int >(_out,_tt19, 2, 2);
>>>>>>> Stashed changes
  return;
}
void try_transition(int* pos_now/* len = 2 */, int* action/* len = 2 */, int* _out/* len = 2 */) {
  int _tt19[2] = {(pos_now[0]) + (action[0]), (pos_now[1]) + (action[1])};
  CopyArr<int >(_out,_tt19, 2, 2);
  return;
}

}
