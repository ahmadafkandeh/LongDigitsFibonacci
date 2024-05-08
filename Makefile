TARGET = Fibonachi
TESTS = Fibo_Tests
OUTDIR = build
BINDIR = bin


# catch2 files and includes
CATCH2_FOLDER = ./catch2
CATCH2_INCLUDES = -I$(CATCH2_FOLDER)/

# All C++ source files
CPP_FILES = main.cpp Fibonacci.cpp
TEST_FILES = Fibo_tests.cpp Fibonacci.cpp 

INCLUDES = -I./ $(CATCH2_INCLUDES)


# Set up compiler and flags
CPP = g++
CPPFLAGS = -std=gnu++17

CPP_OBJS = $(patsubst %.cpp, $(OUTDIR)/%.o, $(CPP_FILES))
TEST_OBJS = $(patsubst %.cpp, $(OUTDIR)/%.o, $(TEST_FILES))

all: $(BINDIR) $(TARGET)

tests: $(BINDIR) $(TESTS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%.o: %.cpp
	@echo Compiling $<
	@mkdir -p '$(@D)'
	@$(CPP) $(CPPFLAGS) $(INCLUDES) -c -o $@ $<

$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET): $(CPP_OBJS)
	@echo Linking $@
	@$(CPP) $(LDFLAGS) $(CPP_OBJS) -o $(BINDIR)/$@

$(TESTS): $(TEST_OBJS)
	@echo Linking $@
	@$(CPP) $(LDFLAGS) $(TEST_OBJS) -o $(BINDIR)/$@

clean:
	-rm -rf $(OUTDIR) $(BINDIR) *~
