#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "test.h"
namespace ANONYMOUS{

void main__Wrapper() {
  _main();
}
void main__WrapperNospec() {}
void _main() {
  int _tt0[7] = {3, 1, 3, 1, 3, 1, 3};
  int*  true_actions= new int [7]; CopyArr<int >(true_actions,_tt0, 7, 7);
  int  l_s1=0;
  move_left(0, 1, l_s1);
  int  l=0;
  l = l_s1;
  int  r_s3=0;
  move_right(1, 1, r_s3);
  int  r=0;
  r = r_s3;
  int  u_s5=0;
  move_up(1, 1, u_s5);
  int  u=0;
  u = u_s5;
  int  d_s7=0;
  move_down(1, 1, d_s7);
  int  d=0;
  d = d_s7;
  assert ((((((((l_s1) <= (0)) && ((r_s3) > (0))) && ((u_s5) > (0))) && ((d_s7) > (0))) || (((((r_s3) <= (0)) && ((l_s1) > (0))) && ((u_s5) > (0))) && ((d_s7) > (0)))) || (((((u_s5) <= (0)) && ((l_s1) > (0))) && ((r_s3) > (0))) && ((d_s7) > (0)))) || (((((d_s7) <= (0)) && ((l_s1) > (0))) && ((r_s3) > (0))) && ((u_s5) > (0))));;
  int  next=0;
  if ((l_s1) <= (0)) {
    next = 0;
  } else {
    if ((r_s3) <= (0)) {
      next = 1;
    } else {
      if ((u_s5) <= (0)) {
        next = 2;
      } else {
        if ((d_s7) <= (0)) {
          next = 3;
        }
      }
    }
  }
  assert ((next) == ((true_actions[0])));;
  for (int  i=1;(i) < (7);i = i + 1){
    int  l_s9=0;
    move_left(l, next, l_s9);
    l = l_s9;
    int  r_s11=0;
    move_right(r, next, r_s11);
    r = r_s11;
    int  u_s13=0;
    move_up(u, next, u_s13);
    u = u_s13;
    int  d_s15=0;
    move_down(d, next, d_s15);
    d = d_s15;
    assert ((((((((l_s9) <= (0)) && ((r_s11) > (0))) && ((u_s13) > (0))) && ((d_s15) > (0))) || (((((r_s11) <= (0)) && ((l_s9) > (0))) && ((u_s13) > (0))) && ((d_s15) > (0)))) || (((((u_s13) <= (0)) && ((l_s9) > (0))) && ((r_s11) > (0))) && ((d_s15) > (0)))) || (((((d_s15) <= (0)) && ((l_s9) > (0))) && ((r_s11) > (0))) && ((u_s13) > (0))));;
    if ((l_s9) <= (0)) {
      next = 0;
    } else {
      if ((r_s11) <= (0)) {
        next = 1;
      } else {
        if ((u_s13) <= (0)) {
          next = 2;
        } else {
          if ((d_s15) <= (0)) {
            next = 3;
          }
        }
      }
    }
    assert ((next) == ((true_actions[i])));;
  }
  delete[] true_actions;
}
void move_left(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 1;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  } else {
    assert ((state) == (1));;
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 1;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 1;
        }
      }
    }
  }
  assert ((_out) < (2));;
  return;
}
void move_right(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 1;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 1;
        }
      }
    }
  } else {
    assert ((state) == (1));;
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 1;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  }
  assert ((_out) < (2));;
  return;
}
void move_up(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 0;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  } else {
    assert ((state) == (1));;
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 1;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 1;
        }
      }
    }
  }
  assert ((_out) < (2));;
  return;
}
void move_down(int state, int move, int& _out) {
  if ((state) == (0)) {
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 0;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 1;
        }
      }
    }
  } else {
    assert ((state) == (1));;
    if ((move) == (0)) {
      _out = 0;
    } else {
      if ((move) == (1)) {
        _out = 0;
      } else {
        if ((move) == (2)) {
          _out = 0;
        } else {
          assert ((move) == (3));;
          _out = 0;
        }
      }
    }
  }
  assert ((_out) < (2));;
  return;
}

}
