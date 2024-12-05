#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "vops.h"
#include "test.h"

void enumerate_all(int maxStates, int maxMoves) {
  for (int i=0; i<maxStates; i++) {
    for (int j=0; j<maxMoves; j++) {
      int res;
      ANONYMOUS::move_left(i, j, res);
      std::printf("l: state %d, move %d: next %d\n", i,j,res);

      ANONYMOUS::move_right(i, j, res);
      std::printf("r: state %d, move %d: next %d\n", i,j,res);

      ANONYMOUS::move_up(i, j, res);
      std::printf("u: state %d, move %d: next %d\n", i,j,res);

      ANONYMOUS::move_down(i, j, res);
      std::printf("d: state %d, move %d: next %d\n", i,j,res);
    }
  }
}

void trace_actions(int actions[], int t, int maxStates, int maxMoves) {
  int move = actions[0];
  int state[4] = {1,0,1,1};
  std::printf("i: action: #, states: l r u d\n");
  for (int i=0; i<t; i++) {
    int res;
    try{
      ANONYMOUS::move_left(state[0], actions[i], res);
      state[0] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_left for action #%d %d\n", i, actions[i]); }

    try{
      ANONYMOUS::move_right(state[1], actions[i], res);
      state[1] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_right for action #%d %d\n", i, actions[i]); }

    try{
      ANONYMOUS::move_up(state[2], actions[i], res);
      state[2] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_up for action #%d %d\n", i, actions[i]); }

    try{
      ANONYMOUS::move_down(state[3], actions[i], res);
      state[3] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_down for action #%d %d\n", i, actions[i]); }
    
    std::printf("%d: action: %d, states: %d %d %d %d\n", i, actions[i], state[0], state[1],state[2],state[3]);
  }
}

int main() {
  int maxStates = 4;
  int maxMoves = 4;

  int t = 4;
  // int actions[9] = {1,0,1,2,3,0,3,2,3};
  int actions[4] = {1,3,0,2};

  trace_actions(actions, t, maxStates, maxMoves);
  // enumerate_all(maxStates, maxMoves);
  return 1;
}