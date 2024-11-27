#ifndef TEST_H
#define TEST_H

#include <cstring>

#include "vops.h"

namespace ANONYMOUS{
class Grid; 
}
namespace ANONYMOUS{
class Grid; 
class Grid{
  public:
  int  grid[];
  Grid(){}
template<typename T_0>
  static Grid* create(  T_0* grid_, int grid_len);
  ~Grid(){
  }
  void operator delete(void* p){ free(p); }
};
extern void main__Wrapper();
extern void main__WrapperNospec();
extern void transition__Wrapper(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */);
extern void transition__WrapperNospec(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */);
extern void _main();
extern void transition(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */, int& _out);
extern void check_all(int* grids/* len = (2 * 1) * 3 */, int* pos/* len = 2 * 3 */, int* actions/* len = 3 */);
extern void action_map(int action, int* _out/* len = 2 */);
extern void check(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* next_pos/* len = 2 */, int true_action);
}

#endif
