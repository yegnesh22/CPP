BTYPE:= Debug
TARGET:= LargestRectangleArea
OBJ_DIR:= $(BTYPE)/objs
SRC_DIR:=src
INC_DIR:=include
OBJS:= $(OBJ_DIR)/Basic.o \
	$(OBJ_DIR)/O1.o \
	$(OBJ_DIR)/main.o

CFLAGS := -I$(INC_DIR)

$(TARGET): $(OBJ_DIR) $(OBJS)
	g++ -o $(OBJ_DIR)/$(TARGET) $(OBJS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c -g -fPIC $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
