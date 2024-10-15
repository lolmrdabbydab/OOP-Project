# Variable
m = Update

# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++11 #-Wall -Wextra

# Executable name
TARGET = a

# Source files
SRCS = main.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp

# Executables
help:
	@echo 'To push all changes with commit message "Update" type: make push'
	@echo 'To push all changes with personal commit message type: make push m="Your commit message"'

data:
	@echo 0 > data.txt

run:
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@./$(TARGET)
	@make clean

push:
	git add .
	git commit -m "$(m)"
	git push

clean:
	@rm -f $(TARGET)

# Automated Run Test
test: test.cpp
	@$(CXX) $(CXXFLAGS) test.cpp -o $(TARGET)
	@./$(TARGET)
	@make clean