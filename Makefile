all : clean main

main :
	mkdir build 2> /dev/null ;\
	cd build ; \
	cmake .. ; \
	make ; \

checkexec : main
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder --sy -f ../style_lines ../test2.html ../test3.css
#Force an argument if 'mf' or 'sy' on --d and -c 

test : main
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder ${OPT0} ${OPT} ${ARG1} ${ARG2} ${ARG3}

testconstruction : main 
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder --ts ${OPT} ${ARG1} ${ARG2}

testmodification : main 
	cd build ; \
	./htmlbuilder --mf ${OPT} ${ARG1} ${ARG2}

testmodificationstyle : main 
	cd build ; \
	./htmlbuilder --sy ${OPT} ${ARG1} ${ARG2} ${ARG3}

teststyleinheritance : main 
	cd build ; \
	./htmlbuilder --sy ${OPT} ${ARG1} ${ARG2} ${ARG3}

clean : 
	-$(RM) -r build test