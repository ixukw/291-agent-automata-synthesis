#filepath = ../fixedgrid.sk
filename = automata

all:
	make sketch && make automata

automata: ${filename}_test.cpp
	g++ ${filename}_test.cpp ${filename}.cpp -o automata 

sketch:
	./../sketch-1.7.6/sketch-frontend/sketch ../$(filename).sk --fe-output-dir ./ --fe-output-code --fe-output-test -V 5 --bnd-unroll-amnt 15