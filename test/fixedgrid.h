#ifndef FIXEDGRID_H
#define FIXEDGRID_H

#include <cstring>

#include "vops.h"

namespace str{
class Str; 
}
namespace ANONYMOUS{
}
namespace str{
class Str; 
class Str{
  public:
  int  n;
  char  buf[];
  Str(){}
template<typename T_0>
  static Str* create(  int  n_,   T_0* buf_, int buf_len);
  ~Str(){
  }
  void operator delete(void* p){ free(p); }
};
extern void newStr(int n, char* w/* len = n */, Str*& _out);
extern void println(Str* s);
}
namespace ANONYMOUS{
extern void try_transition(int* pos_now/* len = 2 */, int* action/* len = 2 */, int* _out/* len = 2 */);
extern void true_transition(int* pos/* len = 2 */, int* action/* len = 2 */, int* _out/* len = 2 */);
extern void main__Wrapper();
extern void main__WrapperNospec();
extern void _main();
extern void transition(int* pos_now/* len = 2 */, int* pos_next/* len = 2 */, int* _out/* len = 2 */);
}

#endif
