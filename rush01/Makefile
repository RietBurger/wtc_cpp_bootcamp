#NB - need SFML library and to 'load library path'

CC = clang++

FLAGS = -Wall -Werror -Wextra -lncurses 
GFLAGS  = -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks

TNAME = ft_gkrellm
GNAME = ft_gkrellm_g

SRC = textDisplay.cpp Classes/IMonitorModule.cpp Classes/IMonitorDisplay.cpp Classes/Hostname.cpp Classes/Dateinfo.cpp \
		 Classes/Osinfo.cpp Classes/RAMinfo.cpp Classes/CPUinfo.cpp Classes/Networkinfo.cpp Classes/Ncurses.cpp \
			Classes/graphicDisplay.cpp
text:
	$(CC) $(FLAGS) $(GFLAGS) $(SRC) -o $(TNAME)
	
graphic:
	$(CC) $(FLAGS) $(GFLAGS) $(SRC) -o $(GNAME)

fclean:
	rm -f $(TNAME)
	rm -f $(GNAME)

re_graphic: fclean graphic
re_text: fclean text