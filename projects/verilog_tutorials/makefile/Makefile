STRING = "Hello"
STRING += "World"

all : echo_string echo_hi echo_imh

echo_string :echo_hi 
	 @echo $(STRING)

echo_hi : echo_imh
	 @echo "hi"

echo_imh :
	 @echo "imh"
