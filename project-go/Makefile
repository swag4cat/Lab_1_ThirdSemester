BINARY=project
SRC=main.go commands.go io.go slist.go dlist.go stack.go queue.go help.go

all: build

build:
	go build -o $(BINARY) $(SRC)

run: build
	./$(BINARY)

clean:
	rm -f $(BINARY)
