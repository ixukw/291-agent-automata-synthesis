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
    x, y = pos
    dx, dy = direction
    new_pos = (x + dx, y + dy)
    if grid[x][y] != "1":
        raise Exception("wron pos")
    grid[x][y] = '0'
    grid[new_pos[0]][new_pos[1]] = '1'
    return new_pos
    
# return the first transition edge that evaluates to true
def get_next_state_name(aut, cur_state, cond):
    print("printing aut", aut)
    for transition in aut["states"].get(cur_state).get("transitions"):
        if transition.get("cond"): # condition check against cur_state, for now just put a true
            return transition.get("to")
            

def verify(aut, grids):
    curr_pos = find_position(grids[0])
    start_state = "0"
    print("aut", aut)
    states = aut['states'].keys()
    print("state", states)
    #if nextState not in state.transitions.to or (nextState in state.transitions.to and not state.transitions.cond):
    
    # for grid[0]
    cur_state = get_next_state_name(aut, start_state, True)
    
    for cur_snap in grids:
        action = aut.get("states").get(cur_state).get("action")
        dx, dy = aut.get("actions").get(action)
        print("current position", curr_pos)
        print("action", action)
        next_pos = (curr_pos[0] + dx, curr_pos[1] + dy)

        if not (0 <= next_pos[0] < len(cur_snap) and 0 <= next_pos[1] < len(cur_snap[0])):
            print("next_pos", next_pos)
            raise Exception("Move out of bounds")
        
        if cur_snap[next_pos[0]][next_pos[1]] != '0':
            raise Exception("Move blocked or invalid")
        
        curr_pos = move_agent(cur_snap, curr_pos, (dx, dy))
        print("curr_pos", curr_pos)
        cur_state = get_next_state_name(aut, cur_state, True)

    print("Verification complete: All transitions are valid.")

        
        
        

    # for aut_state, cur_snap in zip()


def main():
    aut = read_json("./data/simple/simple.json")
    grids = read_csvs("./data/simple/snapshot")
    print(grids[0])
    verify(aut, grids)

if __name__ == "__main__":
    main()