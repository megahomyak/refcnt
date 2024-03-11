.PHONY: test test_debug

test.out: test.c refcnt/refcnt.c
	gcc test.c refcnt/refcnt.c -o test.out -g

test: test.out
	./test.out

test_debug: test.out
	gdb test.out
