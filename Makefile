PROJ_HOME	= `pwd`

TARGET_APP	= aquarius_test

INCDIR	+= -I$(PROJ_HOME)

# LIBDIR  += -L$(CROSS_LIB)
# LIBS	+= -lpthread


#CXXFLAGS = -g -o3
CFLAGS  = -g -pipe -W

OBJECTS= main.o\

$(TARGET_APP) : $(OBJECTS)
	$(CC) -o $(TARGET_APP) $(OBJECTS)
#	$(CXX) -o $(TARGET_APP) $(OBJECTS)

clean:
	$(RM) -f *.o $(TARGET_APP)


