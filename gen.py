
def header(maxState: int, t: int):
    return f"int maxState = {maxState}; \nint t = {t};"

def gen_transitions_helper(movement: str, maxState: int, possible_moves):
    res = f"int {movement}(int state, int move)" + "{{".format()+ "\n"
    res += "\tint nextState;\n"
    for i in range(0, maxState):
        res += "\t"
        if i != 0: res += "} else "
        res += f"if (state == {i}) " + "{{".format() + "\n"
    
        for j in range(0, len(possible_moves)): # we are only allowing 4 movement now
            res += "\t\t"
            if j != 0: res += "} else "
            res += f"if (move == {j}) " "{{".format() + "\n" + "\t\t\tnextState = ??; \n"
            
        res += "\t\t} else { \n\t\t\tassert 0;\n\t\t}\n"
        
    res += "\t} else {\n\t\tassert 0;\n\t}\n"
    res += "\tassert nextState < maxState;\n \treturn nextState;\n} \n\n"
    return res

def gen_transitions(maxState: int, possible_moves: list[str]):
    res = ""
    for move in possible_moves:
        res += gen_transitions_helper(move, maxState, possible_moves)
    return res

def gen_main_fun(init_action: int, true_actions: list[int], possible_moves: list[str], possible_moves_vars: str):
    # main func declaration and initial states
    main_code = "harness void main() {\n"
    main_code += f"int init_action = {init_action};\n"
    main_code += f"int[t] true_actions = {{{','.join(map(str, true_actions))}}};\n"
    
    # generate the initial state for each movement
    for i, a in enumerate(possible_moves_vars):
        main_code += f"int init_state_{a} = {0 if i == init_action else 1};\n"

    # assert statement
    assert_statements = []
    for i, (a, action) in enumerate(zip(possible_moves_vars, possible_moves)):
        main_code += f"int {a} = {action}(init_state_{a}, init_action);\n"
        assert_statements.append(f"({a} == 0 && " + " && ".join([f"{a1} != 0" for a1 in possible_moves_vars if a1 != a]) + ")")

    assert_statements = "assert " + " || ".join(assert_statements) + ";\n"
    main_code += assert_statements

    # if statement for next
    main_code += "int next;\n"
    next_state_code = ""
    for i, a in enumerate(possible_moves_vars):
      if i == 0: next_state_code += f"if ({a} == 0) {{\n\tnext = {i};\n"
      else: next_state_code += f"}} else if ({a} == 0) {{\n\tnext = {i};\n"
    next_state_code += f"}}"
    
    main_code += next_state_code
    #main_code += "\nassert (next == init_action);\n\n"
    main_code += "\nassert (next == true_action[0]);\n\n"

    # true action 1 to t for loop
    main_code += "for (int i=1; i<t; i++) {\n"
    for a, action in zip(possible_moves_vars, possible_moves):
      main_code += f"\t{a} = {action}({a}, next);\n"
    
    main_code += "\t" + assert_statements
    main_code +="\t" + next_state_code.replace('\n','\n\t')
    main_code += "\n\tassert (next == true_actions[i]);\n}"
    return main_code.replace('\n','\n\t') + "\n}"

def main():
    max_states = 4
    true_actions = [0,1,2,3,0,3,2,3]
    time_steps = len(true_actions)
    
    # init_state = 0
    init_action = 1
    
    possible_moves = ["move_left", "move_right", "move_up", "move_down"]
    possible_moves_vars = 'lrud'
    
    transition_code = gen_transitions(max_states, possible_moves)
    main_code = gen_main_fun(init_action, true_actions, possible_moves, possible_moves_vars)
    
    print(f"{header(max_states, time_steps)}\n{transition_code}\n{main_code}")
    
if __name__ == "__main__":
    main()