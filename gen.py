
def header(maxState: int, t: int):
    return f"int maxState = {maxState}; \nint t = {t};"

def gen_transitions_helper(movement: str, maxState: int):
    res = f"int {movement}(int state, int move)" + "{{".format()+ "\n"
    res += "int nextState;"
    for i in range(0, maxState):
        if i != 0: res += "} else { \n assert 0;\n}"
        res += f"if (state == {i})" + "{{".format() + "\n"
        for j in range(0, 4): # we are only allowing 4 movement now
            if j != 0: res += "} else "
            res += f"if (move == {j})" "{{".format() + "\n" + "nextState = ??; \n"
        res += "} else { \n assert 0;\n}"
    res += "assert nextState < maxState;\n return nextState;\n }"

def gen_transitions(maxState: int):
    for move in ["eft", ""]

def main(true_actions: list[int], init_state: int, init_action: int):
    code = f"""int[t] true_actions = {{{','.join(map(str, true_actions))}}};
int init_state = {init_state};
int init_action = {init_action};
int l = left({init_state}, {init_action});
int r = right(1, {init_action});
  """

    f"""
    for (int i=0; i<t; i++) {{
      l = {transition_func_name}(l, {init_action});
      r = {transition_func_name_2}(r, {init_action});
    }}
    """

if __name__ == "__main__":
    main()

# int left(int state, int move) {
# int nextState;
# if (state == 0) {
#     if (move == 0) {
#       nextState = ??;
#     } else if (move == 1) {
#       nextState = ??;
#     } else {
#       assert (0 == 1);
#     }
#   } else if (state == 1) {
#     if (move == 0) {
#       nextState = ??;
#     } else if (move == 1) {
#       nextState = ??;
#     } else {
#       assert (0 == 1);
#     }
#   } else {
#     assert (0 == 1);
#   }
# assert nextState < maxState;
# return nextState;
# }