# cs370-Lab04

#The Parts that were implemented:
- All of part 1, movement and facing
- All of part 2, adding a weapon
- All of part 3a, an enemy can attack, chase, and dies. Animations play
- All of part 3b, the player can take damage, die, when dead player stops moving and firing
- We couldn't get part 4, the spawn manager to work. The line of code that breaks everything and crashed unreal is:

    ```MyDwarf->SpawnDefaultController();``` 

In SpawnManager.cpp, No idea what is causing the crash. Seems to be a pointer error.

Even without the spawn manager, the gameplay is absolutely rivetting. Had the time of my life being a beta tester for this title.

- Didn't get to the extra credit.



Instructions on how to get this project to its' playable state:
  git clone the project onto your pc

  rebuild the project by double clicking on the .uproject

  compile in the editor

  play

  The engine may crash if you lose and don't press esc or stop the instance of the game shortly after.

