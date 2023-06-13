all : main

main : clean
	mkdir build 2> /dev/null ;\
	cd build ; \
	cmake .. ; \
	make ; \

exec : clean main 
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder --d ../test2.html ;\

execstyle : clean main 
	cd build ; \
	./htmlbuilder -s ../test2.html _ ;\

test : clean main
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder ${ARG1} ${ARG2} ${ARG3}

clean : 
	-$(RM) -r build test