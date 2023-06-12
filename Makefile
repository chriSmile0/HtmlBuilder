all : main

main : clean
	mkdir build 2> /dev/null ;\
	cd build ; \
	cmake .. ; \
	make ; \

exec : clean main 
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder --d just_past_option ;\

test : clean main
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder ${ARG1} ${ARG2} 

clean : 
	-$(RM) -r build test