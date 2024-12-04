from z3 import *

sara_height, joe_height, total_height = Reals('sara_height joe_height total_height')

total_height_constraint = And(total_height == 120, sara_height + joe_height == total_height)
sara_height_constraint = And(True)#And((joe_height - 6) * 0.5 == sara_height, sara_height > 0)
joe_height_constraint = And(2 * sara_height + 6 == joe_height, joe_height > 0)

solve([sara_height_constraint, joe_height_constraint, total_height_constraint])