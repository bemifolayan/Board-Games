Bemi Folayan
Regan Williamson

Lab 4

Errors/Warnings:
1. vector out of range
2. pure virtual print() method not overriden

Case 1: 5 in a diagonal up to the right
    We input B in coordinates (1,1), (2,2), (2,1), (1,2), (3,1) and W in (9,9), (10,10), (11,11), (12,12), and (13,13)
    The program returned that Player W won.
Case 2: 5 in a diagonal up to the left
    We input W in coordinates (19,1), (18,2), (17,3), (16,4), (15,5), and B in coordinates (1,1), (18,1), (17,1), (16,1), and (15,1).
    The program returned that Player W won.
Case 3: 5 in a row
    We input B in coordinates (5,5), (6,5), (7,5), (8,5), and (9,5), and W in coordinates (1,9), (10,10), (11,8), and (2,2)
    The program returned that Player B won.
Case 4: 5 in a column
    We input B in coordinates (1,1), (1,2), (2,1), (2,2), and (3,3), and W in coordinates (19,8), (19,7), (19,6), (19,5), and (19,4)
    The program returned that Player W won.
Case 5: Game is quit.
    The player input quit.
    The program returned "Player has quit 0 turns were made."
Case 6: Invalid input
    The player input (20,20) and the program continued to prompt the user for "Input Coordinate or quit".
Case 7: No program arguments
    When there are no program arguments, the program outputs "Please make the program argument TicTacToe or Gomoku"
Case 8: Badly formed command lines
    When the program argument is "TicTac", the program returns "Please make the program argument TicTacToe or Gomoku"
Case 9: Player tries to input an already occupied coordinate
    When the player tries to input (1,1) twice, the program prompts the user to input another coordinate or quit after the second try.
