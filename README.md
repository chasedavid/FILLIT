# FILLIT

     Updated: 2017/10/25 20:45:31 by aho              ###   ########.fr         

TASKS

- [X] [AH] Ability to read text file and store pieces into *linked_list

- [ ] [AH] edit lstappend() to assign a char ('A') to each tetrimino *10/25 Current Task*

- [ ] [CD] lstpop() function - this will pop first link (piece) in list and append to end so that algorithm can try fitting pieces by placing the next piece in the top left corner

NOTES

10.25
- CD: We can maybe implement a counter, create a function that iterates through to make sure there are no invalid inputs in isvalid piece. also repush so I can pull the working file. ;)


DOCUMENTATION

1. main()

- reads text file 

- calls `isvalidpiece(buf)` and checks if piece is valid 

- `ft_lstappend(&linked_list, ft_lstnew(buf,22))` - stores valid piece into linked list

- should call `fillit(linkedlist)` to solve

2. fillit()

- `grid` variable created and initialized as smallest possible square

- `placepiece(current, grid, counter)` 