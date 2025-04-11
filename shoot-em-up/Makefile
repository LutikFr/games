# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++14 -I"C:/SFML/include" -I"C:\Users\Ilya\Documents\games\games\shoot-em-up\Include"

# Папка с библиотеками
LIBDIR = "C:/SFML/lib"

# Библиотеки SFML
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

# Исходные файлы
SRCS = $(wildcard Source/*.cpp)  # Все .cpp файлы из папки Source

# Исполняемый файл
TARGET = shoot-em-up.exe

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(SRCS)
	$(CXX) -o $@ $^ -L$(LIBDIR) $(LIBS) $(CXXFLAGS)  # Добавлен CXXFLAGS

# Правило для очистки
clean:
	del /Q $(TARGET)

.PHONY: all clean
