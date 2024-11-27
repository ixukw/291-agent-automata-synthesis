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
  _main();
}
void main__WrapperNospec() {}
void transition__Wrapper(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */) {
  int  _out_s5=0;
  transition(grid, pos, true_next_pos, _out_s5);
}
void transition__WrapperNospec(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */) {}
void _main() {
  bool _tt0[1] = {0};
  bool*  __sa7= new bool [2 * 1]; CopyArr<bool >(__sa7,_tt0, 2 * 1, 1);
  bool _tt1[2] = {1, 0};
  CopyArr<bool >((__sa7+ 0),_tt1, 2, 2);
  bool _tt2[3] = {0, 0, 0};
  bool*  __sa6= new bool [(2 * 1) * 3]; CopyArr<bool >(__sa6,_tt2, (2 * 1) * 3, 3);
  CopyArr<bool >((__sa6+ 0),__sa7, 2, 2 * 1);
  bool _tt3[1] = {0};
  bool*  __sa8= new bool [2 * 1]; CopyArr<bool >(__sa8,_tt3, 2 * 1, 1);
  bool _tt4[2] = {0, 1};
  CopyArr<bool >((__sa8+ 0),_tt4, 2, 2);
  CopyArr<bool >((__sa6+ 2),__sa8, 2, 2 * 1);
  bool _tt5[1] = {0};
  bool*  __sa9= new bool [2 * 1]; CopyArr<bool >(__sa9,_tt5, 2 * 1, 1);
  bool _tt6[2] = {1, 0};
  CopyArr<bool >((__sa9+ 0),_tt6, 2, 2);
  CopyArr<bool >((__sa6+ 4),__sa9, 2, 2 * 1);
  Grid*  g=NULL;
  g = Grid::create(__sa6, (2 * 1) * 3);
  bool _tt7[3] = {0, 0, 0};
  bool*  __sa12= new bool [2 * 3]; CopyArr<bool >(__sa12,_tt7, 2 * 3, 3);
  bool _tt8[2] = {1, 0};
  CopyArr<bool >((__sa12+ 0),_tt8, 2, 2);
  bool _tt9[2] = {0, 1};
  CopyArr<bool >((__sa12+ 2),_tt9, 2, 2);
  bool _tt10[2] = {1, 0};
  CopyArr<bool >((__sa12+ 4),_tt10, 2, 2);
  bool _tt11[3] = {0, 0, 0};
  int*  pos= new int [2 * 3]; CopyArr<int >(pos,_tt11, 2 * 3, 3);
  for (int  __sa10=0;(__sa10) < (3);__sa10 = __sa10 + 1){
    assert (((__sa10) >= (0)) && ((__sa10) < (3)));;
    assert (((__sa10) >= (0)) && ((__sa10) < (3)));;
    CopyArr<int >((pos+ 2 * __sa10),(__sa12+ 2 * __sa10), 2, 2);
  }
  int _tt12[3] = {0, 2, 1};
  int*  actions= new int [3]; CopyArr<int >(actions,_tt12, 3, 3);
  check_all(g->grid, pos, actions);
  delete[] __sa7;
  delete[] __sa6;
  delete[] __sa8;
  delete[] __sa9;
  delete[] __sa12;
  delete[] pos;
  delete[] actions;
}
void transition(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */, int& _out) {
  if(!(1)){ throw AssumptionFailedException();  };
  if(!(1)){ throw AssumptionFailedException();  };
  _out = 2;
  if(!(1)){ throw AssumptionFailedException();  };
  if(!(1)){ throw AssumptionFailedException();  };
  for (int  i=0;(i) < (1);i = i + 1){
    for (int  j=0;(j) < (2);j = j + 1){
      assert (((i) >= (0)) && ((i) < (1)));;
      assert (((j) >= (0)) && ((j) < (2)));;
      if(!(((grid[((2 * i) + j)])) <= (1))){ throw AssumptionFailedException();  };
      assert (((i) >= (0)) && ((i) < (1)));;
      assert (((j) >= (0)) && ((j) < (2)));;
      assert (((grid[((2 * i) + j)])) <= (1));;
    }
  }
  bool _tt13[2] = {0, 0};
  int*  change_s3= new int [2]; CopyArr<int >(change_s3,_tt13, 2, 2);
  action_map(2, change_s3);
  assert (((change_s3[0])) <= (1));;
  assert (((change_s3[1])) <= (1));;
  delete[] change_s3;
  return;
}
void check_all(int* grids/* len = (2 * 1) * 3 */, int* pos/* len = 2 * 3 */, int* actions/* len = 3 */) {
  check((grids+ 2), (pos+ 0), (pos+ 2), (actions[1]));
}
void action_map(int action, int* _out/* len = 2 */) {
  bool _tt14[2] = {0, 0};
  CopyArr<int >(_out,_tt14, 2, 2);
  if ((action) == (1)) {
    int _tt15[2] = {0, -1};
    CopyArr<int >(_out,_tt15, 2, 2);
  } else {
    if ((action) == (2)) {
      bool _tt16[2] = {0, 1};
      CopyArr<int >(_out,_tt16, 2, 2);
    }
  }
  return;
}
void check(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* next_pos/* len = 2 */, int true_action) {
  int  synthesized_action_s1=0;
  transition(grid, pos, next_pos, synthesized_action_s1);
  assert ((synthesized_action_s1) == (true_action));;
}

}
