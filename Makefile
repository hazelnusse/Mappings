CXXFLAGS = -Wall -Wextra -Weffc++ -std=c++0x

all: test_mappings

test_mappings : test_mappings.cc

doc :
	doxygen Doxyfile

clean :
	rm -rf test_mappings html Doxyfile.bak

.PHONY : all clean doc
