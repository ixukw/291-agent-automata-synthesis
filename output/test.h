#ifndef TEST_H
#define TEST_H

#include <cstring>

#include "vops.h"

namespace ANONYMOUS{
}
namespace ANONYMOUS{
extern void main__Wrapper();
extern void main__WrapperNospec();
extern void _main();
extern void move_left(int state, int move, int& _out);
extern void move_right(int state, int move, int& _out);
extern void move_up(int state, int move, int& _out);
extern void move_down(int state, int move, int& _out);
}

#endif
