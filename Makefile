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
TEST_SRCS = UnitTest.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp PerishableItem.cpp Milk.cpp Meat.cpp Egg.cpp Soap.cpp Toy.cpp

# Executables
help:
	@echo 'To push all changes with commit message "Update" -> type: make push'
	@echo 'To push all changes with personal commit message -> type: make push m="Your commit message"'
	@echo 'To create .h & .cpp for a new class -> type: make create"'
	@echo 'To compile & run the project's files -> type: make run"'
	@echo 'To removed any files compiled using MakeFile -> type: make clean"'
	@echo 'To run Unit Test -> type: make test"'

data:
	@echo 0 > data.txt

# Shortcut Action to Create .h & .cpp for entered class name
create:
	@echo "Enter the name for the new class:"
	@read CLASS_NAME; \
	echo "Creating $$CLASS_NAME.h and $$CLASS_NAME.cpp files..."; \
	echo "// Header file for $$CLASS_NAME class" > $$CLASS_NAME.h; \
	echo "#ifndef $${CLASS_NAME}_H" >> $$CLASS_NAME.h; \
	echo "#define $${CLASS_NAME}_H" >> $$CLASS_NAME.h; \
	echo "\n\nclass $$CLASS_NAME\n{\npublic:\n\t$$CLASS_NAME();\n\t~$$CLASS_NAME();\n};\n" >> $$CLASS_NAME.h; \
	echo "#endif // $${CLASS_NAME}_H" >> $$CLASS_NAME.h; \
	echo "// Implementation file for $$CLASS_NAME class" > $$CLASS_NAME.cpp; \
	echo "#include \"$$CLASS_NAME.h\"" >> $$CLASS_NAME.cpp; \
	echo "\n$$CLASS_NAME::$$CLASS_NAME()\n{\n\t// Constructor implementation\n}\n" >> $$CLASS_NAME.cpp; \
	echo "\n$$CLASS_NAME::~$$CLASS_NAME()\n{\n\t// Destructor implementation\n}\n" >> $$CLASS_NAME.cpp; \
	echo "$$CLASS_NAME.h and $$CLASS_NAME.cpp have been created."

# Shortcut Action to Compile & Run all project files
run:
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@./$(TARGET)
	@make clean

# Shortcut for Commit & Push
push:
	git add .
	git commit -m "$(m)"
	git push

# Automated Run Test
test:
	@$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TARGET)
	@./$(TARGET)
	@make clean

# Clean compiled binary file
clean:
	@rm -f $(TARGET)