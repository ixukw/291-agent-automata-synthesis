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
  int state[4] = {2,0,1,1};
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

void check_traces(int actions[], int initial_action, int t, int maxStates, int maxMoves) {
  int state[4] = {1,0,1,1};
  int action = initial_action;

  std::printf("Checking traces...\n");
  std::printf("i: action: #, states: l r u d\n");
  std::printf("-: action: %d, states: %d %d %d %d\n", action, state[0], state[1], state[2], state[3]);

  for (int i = 0; i < t; i++) {
    int res[4] = {0};

    try {
      ANONYMOUS::move_left(state[0], action, res[0]);
    } catch (AssumptionFailedException &afe) {
      std::printf("failed move_left for action #%d %d\n", i, action);
    }

    try {
      ANONYMOUS::move_right(state[1], action, res[1]);
    } catch (AssumptionFailedException &afe) {
      std::printf("failed move_right for action #%d %d\n", i, action);
    }

    try {
      ANONYMOUS::move_up(state[2], action, res[2]);
    } catch (AssumptionFailedException &afe) {
      std::printf("failed move_up for action #%d %d\n", i, action);
    }

    try {
      ANONYMOUS::move_down(state[3], action, res[3]);
    } catch (AssumptionFailedException &afe) {
      std::printf("failed move_down for action #%d %d\n", i, action);
    }

    // Verify if any function returns 0 and check the true action
    int synthesized_action;
    if (res[0] == 0) {
      synthesized_action = 0;
      if (actions[i] != 0)
        std::printf("Error: Mismatch at step %d: move_left returned 0 but action was %d\n", i, actions[i]);
    }
    // if (res[1] == 0 && actions[i] != 1) {
    if (res[1] == 0) {
      synthesized_action = 1;
      if (actions[i] != 1)
        std::printf("Error: Mismatch at step %d: move_right returned 0 but action was %d\n", i, actions[i]);
    }
    if (res[2] == 0) {
      synthesized_action = 2;
      if (actions[i] != 2)
        std::printf("Error: Mismatch at step %d: move_up returned 0 but action was %d\n", i, actions[i]);
    }
    if (res[3] == 0) {
      synthesized_action = 3;
      if (actions[i] != 3)
        std::printf("Error: Mismatch at step %d: move_down returned 0 but action was %d\n", i, actions[i]);
    }

    if (synthesized_action != actions[i]) {
      std::printf("Error: Mismatch at step %d: expected action %d but got %d\n", i, actions[i], synthesized_action);
    }

    state[0] = res[0];
    state[1] = res[1];
    state[2] = res[2];
    state[3] = res[3];

    action = actions[i];
    std::printf("%d: action: %d, states: %d %d %d %d\n", i, action, state[0], state[1], state[2], state[3]);
  }

  std::printf("Trace verification complete.\n");
}


int main() {
  int maxStates = 4;
  int maxMoves = 4;

  int t = 9;
  int actions[9] = {1,0,1,2,3,0,3,2,3};
  int true_actions[8] = {0,1,2,3,0,3,2,3};
  int initial_action = 1;

  // trace_actions(actions, t, maxStates, maxMoves);
  check_traces(true_actions, initial_action, t-1, maxStates, maxMoves);
  // enumerate_all(maxStates, maxMoves);
  return 1;
}