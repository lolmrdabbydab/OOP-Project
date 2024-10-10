# Variable
m = "Update"

help:
	@echo 'To push all changes with commit message "Update" type: make push'
	@echo 'To push all changes with personal commit message type: make push m="Your commit message"'

run:
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@./$(TARGET)
	@make clean

push:
	git add .
	git commit -m "$(m)"
	git push

clean:
	@rm -f $(TARGET) $(OBJS)

# Automated Run Test