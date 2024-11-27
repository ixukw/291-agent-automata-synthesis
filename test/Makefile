filepath = ../fixedgrid.sk
filename = fixedgrid
automata: ${filename}_test.cpp
	g++ ${filename}_test.cpp ${filename}.cpp -o automata 

sketch:
	./../sketch-1.7.6/sketch-frontend/sketch $(filepath) --fe-output-dir ./ --fe-output-code --fe-output-test -V 5 --bnd-unroll-amnt 15