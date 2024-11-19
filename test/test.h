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
extern void glblInit_actions__ANONYMOUS_s15(int* actions__ANONYMOUS_s14/* len = 3 */);
extern void glblInit_g__ANONYMOUS_s17(Grid*& g__ANONYMOUS_s16);
extern void glblInit_pos__ANONYMOUS_s19(int* pos__ANONYMOUS_s18/* len = 2 * 3 */);
extern void _main(int* actions__ANONYMOUS_s4/* len = 3 */, Grid*& g__ANONYMOUS_s5, int* pos__ANONYMOUS_s6/* len = 2 * 3 */);
extern void check_all(int* grids/* len = (2 * 1) * 3 */, int* pos/* len = 2 * 3 */, int* actions/* len = 3 */, int* actions__ANONYMOUS_s7/* len = 3 */, int* pos__ANONYMOUS_s8/* len = 2 * 3 */);
extern void check(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* next_pos/* len = 2 */, int true_action, int* pos__ANONYMOUS_s10/* len = 2 * 3 */);
extern void transition(int* grid/* len = 2 * 1 */, int* pos/* len = 2 */, int* true_next_pos/* len = 2 */, int& _out, int* pos__ANONYMOUS_s9/* len = 2 * 3 */);
extern void action_map(int action, int* _out/* len = 2 */);
}

#endif
