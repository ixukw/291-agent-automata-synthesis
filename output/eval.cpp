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

void trace_actions(int actions[], int t, int maxStates, int maxMoves, int init_states[4], int max_acc[4]) {
  int move = actions[0];
  std::printf("t\t        #\t        l r u d \t      #\n");
  std::printf("init\taction: -\tstates: %d %d %d %d \tnext: %d\n", init_states[0], init_states[1], init_states[2], init_states[3], actions[0]);
  int state[maxStates];
  for (int i=0; i<maxStates; i++) {
    state[i] = init_states[i];
  }

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
    
    std::printf("%d\taction: %d\tstates: %d %d %d %d \t", i, actions[i], state[0], state[1],state[2],state[3]);

    int next;
    for (int j=0; j<maxMoves; j++) {
      if (state[j] <= max_acc[j]) {
        next = j;
        break;
      }
    }
    std::printf("next: %d\n", next);
    if (i < t-1 && next != actions[i+1]) {
      std::printf("t=%d: next action %d did not match expected next action %d\n", next, i, actions[i]);
      return;
    }
  }
}

void gen_actions(int init_action, int t, int maxStates, int maxMoves, int cur_states[], int max_acc[]) {
  std::printf("generating %d actions from given state\nt\t        #\t        l r u d \t      #\n", t);
  std::printf("init\taction: -\tstates: %d %d %d %d \tnext: %d\n\n", cur_states[0], cur_states[1], cur_states[2], cur_states[3], init_action);
  
  int state[maxStates];
  for (int i=0; i<maxStates; i++) {
    state[i] = cur_states[i];
  }

  int action = init_action;
  for (int i=0; i<t; i++) {
    int res;
    try{
      ANONYMOUS::move_left(state[0], action, res);
      state[0] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_left for action #%d %d\n", i, action); }

    try{
      ANONYMOUS::move_right(state[1], action, res);
      state[1] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_right for action #%d %d\n", i, action); }

    try{
      ANONYMOUS::move_up(state[2], action, res);
      state[2] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_up for action #%d %d\n", i, action); }

    try{
      ANONYMOUS::move_down(state[3], action, res);
      state[3] = res;
    }catch(AssumptionFailedException& afe){ std::printf("failed move_down for action #%d %d\n", i, action); }
    
    std::printf("%d\taction: %d\tstates: %d %d %d %d \t", i, action, state[0], state[1],state[2],state[3]);

    int next;
    for (int j=0; j<maxMoves; j++) {
      if (state[j] <= max_acc[j]) {
        next = j;
        break;
      }
    }
    std::printf("next: %d\n", next);
    action = next;
  }
}

int main() {
  int maxStates = 10;
  int maxMoves = 4;
  int t = 80;
  int init_states[] = {0,0,5,0};
  int max_acc[] = {4,4,4,4};

  int train_actions[] = {1,1,1,1,1,3,3,3,3,3,0,0,0,0,0,2,2,2,2,2,1,1,1,1,1,3,3,3,3,3,0,0,0,0,0,2,2,2,2,2,1,1,1,1,1,3,3,3,3,3,0,0,0,0,0,2,2,2,2,2,1,1,1,1,1,3,3,3,3,3,0,0,0,0,0,2,2,2,2,2};
  trace_actions(train_actions, t, maxStates, maxMoves, init_states, max_acc);

  int cur_states[] = {8,0,8,6};
  gen_actions(1, 20, maxStates, maxMoves, cur_states, max_acc);
  //int test_actions[] = {3,3,3,3,3};
  //trace_actions(test_actions, 5, maxStates, maxMoves, init_states, max_acc);

  // enumerate_all(maxStates, maxMoves);
  return 1;
}