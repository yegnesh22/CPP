SRC_DIR:= src
OBJ_DIR:= obj
INC_DIR:= include

# Enable the flag below for debug logging
#CFLAGS = -DDEBUG

TARGET:= $(OBJ_DIR)/app

OBJS:= $(OBJ_DIR)/app.o \
	$(OBJ_DIR)/curve_fit.o

$(TARGET): $(OBJ_DIR) $(OBJS)
	gcc -o $(TARGET) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $^ -I$(INC_DIR) $(CFLAGS) -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o

distclean:
	rm -rf $(OBJ_DIR)
