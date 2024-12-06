filename = test
output_folder = output
sketch_install = ./sketch-1.7.6/sketch-frontend/sketch
# export SKETCH_HOME="./sketch-1.7.6"

all:
	make generate && make sketch && make test

generate:
	python3 gen.py > ${output_folder}/${filename}.sk

from_snapshots:
	python3 gen.py $(SNAP) $(MAXSTATE) > ${output_folder}/${filename}.sk

sketch:
	${sketch_install} ${output_folder}/$(filename).sk --fe-output-dir ${output_folder}/ --fe-output-code --fe-output-test -V 5 --bnd-unroll-amnt 100000

test:
#g++ ${filename}_test.cpp ${filename}.cpp -o automata	
	cd ${output_folder} && chmod +x script && ./script

clean:
	rm -rf ${output_folder}

eval:
	g++ ${output_folder}/${filename}.cpp ${output_folder}/${filename}.h ${output_folder}/eval.cpp