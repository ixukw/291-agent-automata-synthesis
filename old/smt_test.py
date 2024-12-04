import z3

positions = [[1,0,0],[0,1,0],[0,0,1],[0,1,0],[1,0,0]]
truth = ['r','r','l','l']

mappings = {
  'r': {
    'prev_pos': [[1,0,0],[0,1,0]],
    'post_pos': [[0,1,0],[0,0,1]],
    'prev_action': ['','r']
  },
  'l': {
    'prev_pos': [[0,0,1],[0,1,0]],
    'post_pos': [[0,1,0],[1,0,0]],
    'prev_action': ['r','l']
  }
}

state = [
  { # start [1,0,0]
    'left_wall': True,
    'right_wall': False,
    'matching_prev': False,
    'starting': True
  },
  { # after r to [0,1,0]
    'left_wall': False,
    'right_wall': False,
    'matching_prev': True,
    'starting': False
  },
  { # after r to [0,0,1]
    'left_wall': False,
    'right_wall': True,
    'matching_prev': True,
    'starting': False
  },
  { # after l to [0,1,0]
    'left_wall': False,
    'right_wall': False,
    'matching_prev': False,
    'starting': False
  },
  { # after l to [1,0,0]
    'left_wall': True,
    'right_wall': False,
    'matching_prev': True,
    'starting': False
  }
]
s = z3.Solver()

bools = []
for i,x in enumerate(state):
  temp = []
  for p in x.keys():
    temp.append(z3.Bool(p)) if x[p] else temp.append(z3.Not(z3.Bool(p)))
  bools.append(temp)
print(bools)
s.add(bools[1])
s.add(bools[2])
print(s.check())
print(s.model())