# FILLIT

     Updated: 2017/10/26 02:19:33 by aho              ###   ########.fr         

## TASKS

- [X] [AH] Ability to read text file and store pieces into *linked_list

- [X] [AH] Edit lstnew() and t_list struct to assign a char ('A') to each tetrimino *Completed 10/25*

- [ ] [AH] Edit checkpiece() function to place piece on grid  *10/25 Current Task*

- [ ] [CD] lstpop() function - this will pop first link (piece) in list and append to end so that algorithm can try fitting pieces by placing the next piece in the top left corner

## NOTES

10.25
- CD: We can maybe implement a counter, create a function that iterates through to make sure there are no invalid inputs in isvalid piece. also repush so I can pull the working file. ;)


## DOCUMENTATION

### 1. main()

- reads text file 

- calls `isvalidpiece(buf)` and checks if piece is valid 

- `ft_lstappend(&linked_list, ft_lstnew(buf,22))` - stores valid piece into linked list

- should call `fillit(linkedlist)` to solve

### 2. fillit()

- `grid` variable created and initialized as smallest possible square

### 3. checkpiece()

- this function is where the magic will be happening
- AH: currently working on placing pieces into the grid