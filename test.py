import csv
import os
import json

def read_csvs(dir : str):
    res = []
    for file in sorted(os.listdir(dir)):
        with open(dir + '/' + file, mode ='r', newline = '') as csvfile:
            reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
            res.append(list(reader))
            #list(map( lambda l: list(map (int, )), list(reader)))
            #res.append([int(x) for row in reader for x in row])
    return res


def read_json(path: str):
    with open(path) as f:
        d = json.load(f)
        return d


def find_position(grid):
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            print(grid[i][j], (i, j))
            if grid[i][j] == '1':
                return (i, j)
    raise Exception("start pos not found")   


def move_agent(grid, pos, direction):
    if grid[pos[0]][pos[1]] != "1":
        raise Exception("wron pos")
    grid[pos[0]][pos[1]] = 0
    grid[pos[0] + direction[0]][pos[1] + direction[1]] = 1
    
# return the first transition edge that evaluates to true
def get_next_state_name(aut, cur_state, cond):
    for transition in aut.get(cur_state).get("transitions"):
        if transition.get("cond"): # condition check against cur_state, for now just put a true
            return transition.get("to")
            

def verify(aut, grids):
    curr_pos = start_position(grids[0])
    start_state = "0"
    print(aut)
    states = aut['states'].keys()
    print(states)
    #if nextState not in state.transitions.to or (nextState in state.transitions.to and not state.transitions.cond):
    
    # for grid[0]
    cur_state = get_next_state_name(aut, start_state)
    for cur_snap in grids:
        action = aut.get(cur_state).get("action")
        dx, dy = aut.get("actions").get(action)

        cur_pos = find

        grid[]

        
        
        

    # for aut_state, cur_snap in zip()


def main():
    aut = read_json("./data/simple/simple.json")
    grids = read_csvs("./data/simple/snapshot")
    print(grids[0])
    verify(aut, grids)

if __name__ == "__main__":
    main()