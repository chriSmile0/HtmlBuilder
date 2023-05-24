all : main

main : clean
	mkdir build 2> /dev/null ;\
	cd build ; \
	cmake .. ; \
	make ; \

exec : clean main 
	mkdir test 2> /dev/null ; \
	cd build ; \
	./htmlbuilder \

clean : 
	-$(RM) -r build test

