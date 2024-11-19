#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "test.h"
namespace ANONYMOUS{

template<typename T_0>
Grid* Grid::create(T_0* grid_, int grid_len){
  int tlen_grid = (2 * 1) * 3; 
  void* temp= malloc( sizeof(Grid)   + sizeof(int )*tlen_grid); 
  Grid* rv = new (temp)Grid();
  CopyArr(rv->grid, grid_, tlen_grid, grid_len ); 
  return rv;
}
void main__Wrapper() {
  bool _tt0[3] = {0, 0, 0};
  int*  pos__ANONYMOUS_s11= new int [2 * 3]; CopyArr<int >(pos__ANONYMOUS_s11,_tt0, 2 * 3, 3);
  glblInit_pos__ANONYMOUS_s19(pos__ANONYMOUS_s11);
  Grid*  g__ANONYMOUS_s13=NULL;
  glblInit_g__ANONYMOUS_s17(g__ANONYMOUS_s13);
  bool _tt1[3] = {0, 0, 0};
  int*  actions__ANONYMOUS_s12= new int [3]; CopyArr<int >(actions__ANONYMOUS_s12,_tt1, 3, 3);
  glblInit_actions__ANONYMOUS_s15(actions__ANONYMOUS_s12);
  _main(actions__ANONYMOUS_s12, g__ANONYMOUS_s13, pos__ANONYMOUS_s11);
  delete[] pos__ANONYMOUS_s11;
  delete[] actions__ANONYMOUS_s12;
}
void main__WrapperNospec() {}
void glblInit_actions__ANONYMOUS_s15(int* actions__ANONYMOUS_s14/* len = 3 */) {
  int _tt2[3] = {0, 2, 1};
  CopyArr<int >(actions__ANONYMOUS_s14,_tt2, 3, 3);
}
void glblInit_g__ANONYMOUS_s17(Grid*& g__ANONYMOUS_s16) {
  bool _tt3[1] = {0};
  bool*  __sa21= new bool [2 * 1]; CopyArr<bool >(__sa21,_tt3, 2 * 1, 1);
  bool _tt4[2] = {1, 0};
  CopyArr<bool >((__sa21+ 0),_tt4, 2, 2);
  bool _tt5[3] = {0, 0, 0};
  bool*  __sa20= new bool [(2 * 1) * 3]; CopyArr<bool >(__sa20,_tt5, (2 * 1) * 3, 3);
  CopyArr<bool >((__sa20+ 0),__sa21, 2, 2 * 1);
  bool _tt6[1] = {0};
  bool*  __sa22= new bool [2 * 1]; CopyArr<bool >(__sa22,_tt6, 2 * 1, 1);
  bool _tt7[2] = {0, 1};
  CopyArr<bool >((__sa22+ 0),_tt7, 2, 2);
  CopyArr<bool >((__sa20+ 2),__sa22, 2, 2 * 1);
  bool _tt8[1] = {0};
  bool*  __sa23= new bool [2 * 1]; CopyArr<bool >(__sa23,_tt8, 2 * 1, 1);
  bool _tt9[2] = {1, 0};
  CopyArr<bool >((__sa23+ 0),_tt9, 2, 2);
  CopyArr<bool >((__sa20+ 4),__sa23, 2, 2 * 1);
  g__ANONYMOUS_s16 = Grid::create(__sa20, (2 * 1) * 3);
  delete[] __sa21;
  delete[] __sa20;
  delete[] __sa22;
  delete[] __sa23;
}
void glblInit_pos__ANONYMOUS_s19(int* pos__ANONYMOUS_s18/* len = 2 * 3 */) {
  bool _tt10[3] = {0, 0, 0};
  bool*  __sa26= new bool [2 * 3]; CopyArr<bool >(__sa26,_tt10, 2 * 3, 3);
  bool _tt11[2] = {0, 0};
  CopyArr<bool >((__sa26+ 0),_tt11, 2, 2);
  bool _tt12[2] = {0, 1};
  CopyArr<bool >((__sa26+ 2),_tt12, 2, 2);
  bool _tt13[2] = {1, 0};
  CopyArr<bool >((__sa26+ 4),_tt13, 2, 2);
  for (int  __sa24=0;(__sa24) < (3);__sa24 = __sa24 + 1){
    assert (((__sa24) >= (0)) && ((__sa24) < (3)));;
    assert (((__sa24) >= (0)) && ((__sa24) < (3)));;
    CopyArr<int >((pos__ANONYMOUS_s18+ 2 * __sa24),(__sa26+ 2 * __sa24), 2, 2);
  }
  delete[] __sa26;
}
void _main(int* actions__ANONYMOUS_s4/* len = 3 */, Grid*& g__ANONYMOUS_s5, int* pos__ANONYMOUS_s6/* len = 2 * 3 */) {
  int*  actions__ANONYMOUS_s7_s83= new int [3]; CopyArr<int >(actions__ANONYMOUS_s7_s83,actions__ANONYMOUS_s4, 3, 3);
  int*  pos__ANONYMOUS_s8_s84= new int [2 * 3]; CopyArr<int >(pos__ANONYMOUS_s8_s84,pos__ANONYMOUS_s6, 2 * 3, 2 * 3);
  check_all(g__ANONYMOUS_s5->grid, pos__ANONYMOUS_s6, actions__ANONYMOUS_s4, actions__ANONYMOUS_s7_s83, pos__ANONYMOUS_s8_s84);
  CopyArr<int >(actions__ANONYMOUS_s4,actions__ANONYMOUS_s7_s83, 3, 3);
  CopyArr<int >(pos__ANONYMOUS_s6,pos__ANONYMOUS_s8_s84, 2 * 3, 2 * 3);
  delete[] actions__ANONYMOUS_s7_s83;
  delete[] pos__ANONYMOUS_s8_s84;
}
void check_all(int* grids/* len = (2 * 1) * 3 */, int* pos/* len = 2 * 3 */, int* actions/* len = 3 */, int* actions__ANONYMOUS_s7/* len = 3 */, int* pos__ANONYMOUS_s8/* len = 2 * 3 */) {
  for (int  i=1;(i) < (3);i = i + 1){
    assert (((i) >= (0)) && ((i) < (3)));;
    assert ((((i - 1)) >= (0)) && (((i - 1)) < (3)));;
    assert (((i) >= (0)) && ((i) < (3)));;
    check((grids+ 2 * i), (pos+ 2 * (i - 1)), (pos+ 2 * i), (actions[i]), pos__ANONYMOUS_s8);
  }
}
void check(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* next_pos/* len = 2 */, int true_action, int* pos__ANONYMOUS_s10/* len = 2 * 3 */) {
  int  synthesized_action_s1=0;
  transition(grid, pos, next_pos, synthesized_action_s1, pos__ANONYMOUS_s10);
}
void transition(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */, int& _out, int* pos__ANONYMOUS_s9/* len = 2 * 3 */) {
  _out = 0;
  bool _tt14[2] = {0, 0};
  int*  change_s3= new int [2]; CopyArr<int >(change_s3,_tt14, 2, 2);
  action_map(0, change_s3);
  delete[] change_s3;
  return;
}
void action_map(int action, int* _out/* len = 2 */) {
  bool _tt15[2] = {0, 0};
  CopyArr<int >(_out,_tt15, 2, 2);
  if ((action) == (1)) {
    (_out[0]) = 0;
    (_out[1]) = -1;
  } else {
    if ((action) == (2)) {
      (_out[0]) = 0;
      (_out[1]) = 1;
    }
  }
  return;
}

}
