# Library related
LIBBASENAME=DLList
LIBSRC=$(LIBBASENAME).c
LIBHDR=$(LIBBASENAME).h
SHLIBBASENAME=dllist
SHLIBNAME=lib$(SHLIBBASENAME).so

# Tests related
TESTNAME=DLList_test
TESTSRC=$(TESTNAME).c

# Rules
default: $(SHLIBNAME) $(TESTNAME)

$(TESTNAME): $(TESTSRC) $(LIBNAME)
	gcc -I. -L. -o $@ $< -l$(SHLIBBASENAME)

$(SHLIBNAME): $(LIBBASENAME).o
	gcc -fPIC -shared -L. -o $@ $<

$(LIBBASENAME).o: $(LIBSRC)
	gcc -fPIC -c -I. -o $@ $<

clean:
	rm -f $(TESTNAME) $(SHLIBNAME) $(LIBBASENAME).o

