# Fillit
### Score 100/100
##### Mandatory
100/100
##### Bonus
Task has no bonus
***
### Challenge

**Algorithms Practice - Fit tetris pieces into the smallest square possible.**

## How to run

`git clone https://github.com/Severno/fillit; cd fillit; make; ./fillit test_tetros.txt`

## What Fillit Does:
Fillit recieves a map text file like this one with pieces.

![Valid Map](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/ExampleMapFile.png?raw=true)

It finds the smallest possible square the pieces can be arranged in and prints out the square like this:

![SolvedSquare](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/ExampleSolution.png?raw=true)


## How does it work?

First the file is read by the parser and all the pieces are checked to make sure they are valid. These are the only valid pieces. 

The `validation.c` file:

* Checks for any invalid characters
* Checks for wrong-length lines ('\n' in an invalid position)
* Counts number of '#' characters (Must be 4)
* Checks for '\n' at end of piece block
* Checks each '#' character to see if it's adjacent to another - A valid piece with 4 '#' characters will either have 6 or 8 adjacencies.)

![PossibleTetriminos](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.38.58%20PM.png?raw=true)

![ArrayToCoords](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/BufArrayToCoords.png?raw=true)


The solver works using recursive **backtracking**. If the piece doesn't overlap any other pieces it places it on the map and then tries to call solve_map on all of the other pieces. If they all fit with the current piece in place then it succeeds. If not it moves the current piece and tries to solve the rest of the pieces with the current piece in it's new place. If it's moved all the pieces and still can't make them fit on the current map then it exits the solver, makes a larger map, and then tries to solve again.

![SolverRecursion](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.40.16%20PM.png?raw=true)

![SampleProblem1](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.42.27%20PM.png?raw=true)

![SampleProblem2](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/Screen%20Shot%202019-03-19%20at%206.42.45%20PM.png?raw=true)

![SampleProblem3](https://github.com/Jemmeh/42-Fillit/blob/master/WorkFiles/ExplainationImages/RecursiveBacktrack.png?raw=true)


## Speed Requirements
This is not on the PDF but is a requirement by the grading scale.

`time ./fillit test1.prm`

    must execute <= 1 second

`time ./fillit test7.prm`

    30 seconds+ -> 0 pts
    20-30 seconds -> 1 pt
    10-20 seconds -> 2 pt
    5-10 seconds -> 3pt
    1-5 seconds -> 4pt
    < 1 second -> 5 pt

Ours scores 0.00s in both cases so we got max score on this part.

------------

## Testing
You can run two test documents **test_tetros.txt** and **test_tetros2.txt**(or write your own).

First of all run command: `make`
It will compile all necessary files.

Then run any test you want like this: `./fillit [test_name]`

**test_testros.txt** should show:
```console
AA.C.
AA.C.
BB.C.
.BBC.
DDDD.
```
And **test_tetros2.txt**:
```console
AABBCCDDEE
AABBCCDDEE
FFGGHHIIJJ
FFGGHHIIJJ
KKLLMMNNOO
KKLLMMNNOO
PPQQRRSSTT
PPQQRRSSTT
UUVVWWXXYY
UUVVWWXXYY
```

------------

Enjoy)
