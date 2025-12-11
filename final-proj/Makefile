# COMMENTS BEGIN WITH A HASH

# THE NAME OF YOUR PROJECT
PROJECT = FINAL_PROJ
# ALL CPP COMPILABLE IMPLEMENTATION FILES THAT MAKE UP THE PROJECT
SRC_FILES = main.cpp TodoManager.cpp Task.cpp
# ALL HEADER FILES THAT ARE PART OF THE PROJECT
H_FILES = TodoManager.h Task.h Color.h CliUtils.h
# ANY OTHER RESOURCES FILES THAT ARE PART OF THE PROJECT
REZ_FILES = final.txt assets/* REAMDME.md
# YOUR USERNAME
USERNAME = jingchun_chiu

# NO EDITS BELOW THIS LINE
CXX = g++
CXXFLAGS_DEBUG = -g
CXXFLAGS_WARN = -Wall -Wextra -Wconversion -Wdouble-promotion -Wunreachable-code -Wshadow -Wpedantic
CPPVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ARCHIVE_EXTENSION = zip

ifeq ($(shell echo "Windows"), "Windows")
	TARGET = $(PROJECT).exe
	DEL = del
	ZIPPER = tar -a -c -f
	ZIP_NAME = $(PROJECT)_$(USERNAME).$(ARCHIVE_EXTENSION)
	Q =
	INC_PATH = C:/mingw64/include/
	LIB_PATH = C:/mingw64/lib/
	RPATH =
else
	TARGET = $(PROJECT)
	DEL = rm -f
	ZIPPER = tar -acf
	Q= "
	INC_PATH = /usr/local/include/
	LIB_PATH = /usr/local/lib/

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CXXFLAGS += -D LINUX
		RPATH =
	endif
	ifeq ($(UNAME_S),Darwin)
		CXXFLAGS += -D OSX
		RPATH = -Wl,-rpath,/Library/Frameworks -Wl,-rpath,$(LIB_PATH)
	endif

	ifeq ($(shell tar --version | grep -o "GNU tar"), GNU tar)
		ARCHIVE_EXTENSION = tar.gz
	endif

	ZIP_NAME = $(PROJECT)_$(USERNAME).$(ARCHIVE_EXTENSION)
endif

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(RPATH) -L$(LIB_PATH) $(LIBS)

.cpp.o:
	$(CXX) $(CPPVERSION) $(CXXFLAGS_DEBUG) $(CXXFLAGS_WARN) -o $@ -c $< -I$(INC_PATH)

clean:
	$(DEL) $(TARGET) $(OBJECTS)

depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

submission:
	@echo "Creating submission file $(ZIP_NAME) ..."
	@echo "...Zipping source files:   $(SRC_FILES) ..."
	@echo "...Zipping header files:   $(H_FILES) ..."
	@echo "...Zipping resource files: $(REZ_FILES)..."
	@echo "...Zipping Makefile..."
	$(ZIPPER) $(ZIP_NAME) $(SRC_FILES) $(H_FILES) $(REZ_FILES) Makefile
	@echo "...$(ZIP_NAME) done!"

.PHONY: all clean depend submission

# DEPENDENCIES
main.o: main.cpp Color.h CliUtils.h TodoManager.h Task.h
TodoManager.o: TodoManager.cpp TodoManager.h Task.h CliUtils.h Color.h \
  /usr/local/include/SFML/Graphics.hpp \
  /usr/local/include/SFML/Graphics/BlendMode.hpp \
  /usr/local/include/SFML/Graphics/Export.hpp \
  /usr/local/include/SFML/Config.hpp \
  /usr/local/include/SFML/Graphics/CircleShape.hpp \
  /usr/local/include/SFML/Graphics/Shape.hpp \
  /usr/local/include/SFML/Graphics/Color.hpp \
  /usr/local/include/SFML/Graphics/Color.inl \
  /usr/local/include/SFML/Graphics/Drawable.hpp \
  /usr/local/include/SFML/Graphics/PrimitiveType.hpp \
  /usr/local/include/SFML/Graphics/Rect.hpp \
  /usr/local/include/SFML/System/Vector2.hpp \
  /usr/local/include/SFML/System/Export.hpp \
  /usr/local/include/SFML/System/Angle.hpp \
  /usr/local/include/SFML/System/Angle.inl \
  /usr/local/include/SFML/System/Vector2.inl \
  /usr/local/include/SFML/Graphics/Rect.inl \
  /usr/local/include/SFML/Graphics/RenderStates.hpp \
  /usr/local/include/SFML/Graphics/CoordinateType.hpp \
  /usr/local/include/SFML/Graphics/StencilMode.hpp \
  /usr/local/include/SFML/Graphics/Transform.hpp \
  /usr/local/include/SFML/Graphics/Transform.inl \
  /usr/local/include/SFML/Graphics/Transformable.hpp \
  /usr/local/include/SFML/Graphics/VertexArray.hpp \
  /usr/local/include/SFML/Graphics/Vertex.hpp \
  /usr/local/include/SFML/Graphics/ConvexShape.hpp \
  /usr/local/include/SFML/Graphics/Font.hpp \
  /usr/local/include/SFML/Graphics/Glyph.hpp \
  /usr/local/include/SFML/Graphics/Texture.hpp \
  /usr/local/include/SFML/Window/GlResource.hpp \
  /usr/local/include/SFML/Window/Export.hpp \
  /usr/local/include/SFML/Graphics/Image.hpp \
  /usr/local/include/SFML/Graphics/RectangleShape.hpp \
  /usr/local/include/SFML/Graphics/RenderTarget.hpp \
  /usr/local/include/SFML/Graphics/View.hpp \
  /usr/local/include/SFML/Graphics/RenderTexture.hpp \
  /usr/local/include/SFML/Window/ContextSettings.hpp \
  /usr/local/include/SFML/Graphics/RenderWindow.hpp \
  /usr/local/include/SFML/Window/VideoMode.hpp \
  /usr/local/include/SFML/Window/Window.hpp \
  /usr/local/include/SFML/Window/WindowBase.hpp \
  /usr/local/include/SFML/Window/Vulkan.hpp \
  /usr/local/include/SFML/Window/WindowEnums.hpp \
  /usr/local/include/SFML/Window/WindowHandle.hpp \
  /usr/local/include/SFML/System/Time.hpp \
  /usr/local/include/SFML/System/Time.inl \
  /usr/local/include/SFML/Window/WindowBase.inl \
  /usr/local/include/SFML/Window/Event.hpp \
  /usr/local/include/SFML/Window/Joystick.hpp \
  /usr/local/include/SFML/System/String.hpp \
  /usr/local/include/SFML/System/Utf.hpp \
  /usr/local/include/SFML/System/Utf.inl \
  /usr/local/include/SFML/System/String.inl \
  /usr/local/include/SFML/Window/Keyboard.hpp \
  /usr/local/include/SFML/Window/Mouse.hpp \
  /usr/local/include/SFML/Window/Sensor.hpp \
  /usr/local/include/SFML/System/Vector3.hpp \
  /usr/local/include/SFML/System/Vector3.inl \
  /usr/local/include/SFML/Window/Event.inl \
  /usr/local/include/SFML/System/Clock.hpp \
  /usr/local/include/SFML/Graphics/Shader.hpp \
  /usr/local/include/SFML/Graphics/Glsl.hpp \
  /usr/local/include/SFML/Graphics/Glsl.inl \
  /usr/local/include/SFML/Graphics/Sprite.hpp \
  /usr/local/include/SFML/Graphics/Text.hpp \
  /usr/local/include/SFML/Graphics/VertexBuffer.hpp \
  /usr/local/include/SFML/Window.hpp \
  /usr/local/include/SFML/Window/Clipboard.hpp \
  /usr/local/include/SFML/Window/Context.hpp \
  /usr/local/include/SFML/Window/Cursor.hpp \
  /usr/local/include/SFML/Window/Touch.hpp \
  /usr/local/include/SFML/System.hpp \
  /usr/local/include/SFML/System/Err.hpp \
  /usr/local/include/SFML/System/Exception.hpp \
  /usr/local/include/SFML/System/FileInputStream.hpp \
  /usr/local/include/SFML/System/InputStream.hpp \
  /usr/local/include/SFML/System/MemoryInputStream.hpp \
  /usr/local/include/SFML/System/Sleep.hpp
Task.o: Task.cpp Task.h
