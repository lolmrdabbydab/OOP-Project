.PHONY: create-%, run-%

# Variable
m = "Update"

help:
	@echo "To create (.cpp) and (.H) with the same name type: 'make create-FILE_NAME'"
	@echo "To push all changes with commit message "Update" type: 'make push'"
	@echo "To push all changes with personal commit message type: 'make push m="Your commit message"'"

# Rule to create files
create-%:
	@touch $*.h $*.cpp

# Rule to compile and run
run: 
	clang++ -std=c++17 main.cpp StoreBase.cpp Store.cpp Suppliant.cpp Item.cpp Milk.cpp Meat.cpp Egg.cpp Printable.cpp -o a
	@./a
	@rm a

push:
	git add .
	git commit -m "$(m)"
	git push