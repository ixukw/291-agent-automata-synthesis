#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "automata.h"
namespace ANONYMOUS{

void main__Wrapper() {
  _main();
}
void main__WrapperNospec() {}
void _main() {
  bool _tt0[6] = {0, 1, 0, 1, 0, 1};
  int*  true_actions= new int [6]; CopyArr<int >(true_actions,_tt0, 6, 6);
  int  l_s1=0;
  left(0, 1, l_s1);
  int  l=0;
  l = l_s1;
  int  r_s3=0;
  right(1, 1, r_s3);
  int  r=0;
  r = r_s3;
  assert ((((l_s1) == (0)) && ((r_s3) != (0))) || (((r_s3) == (0)) && ((l_s1) != (0))));;
  int  next=0;
  if ((l_s1) == (0)) {
    next = 0;
  } else {
    if ((r_s3) == (0)) {
      next = 1;
    }
  }
  assert ((next) == (1));;
  for (int  i=0;(i) < (6);i = i + 1){
    int  l_s5=0;
    left(l, next, l_s5);
    l = l_s5;
    int  r_s7=0;
    right(r, next, r_s7);
    r = r_s7;
    assert ((((l_s5) == (0)) && ((r_s7) != (0))) || (((r_s7) == (0)) && ((l_s5) != (0))));;
    if ((l_s5) == (0)) {
      next = 0;
    } else {
      if ((r_s7) == (0)) {
        next = 1;
      }
    }
    assert ((next) == ((true_actions[i])));;
  }
  delete[] true_actions;
}
void left(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 1;
    } else {
      assert ((move) == (1));;
      _out = 1;
    }
  } else {
    assert ((state) == (1));;
    if ((move) == (0)) {
      _out = 0;
    } else {
      assert ((move) == (1));;
      _out = 0;
    }
  }
  assert ((_out) < (2));;
  return;
}
void right(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 0;
    } else {
      assert ((move) == (1));;
      _out = 1;
    }
  } else {
    assert ((state) == (1));;
    if ((move) == (0)) {
      _out = 0;
    } else {
      assert ((move) == (1));;
      _out = 0;
    }
  }
  assert ((_out) < (2));;
  return;
}

}
