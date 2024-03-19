Fumiya Shinagawa 
2416455
shinagawa@chapman.edu
CPSC-350-01
Assignment 2

Not So Super Mario Bros.

Files:
README.txt, input.txt, Boss.cpp, Boss.h, FileProcessor.cpp, FileProcessor.h, Goomba.cpp, Goomba.h, Koopa.cpp, Koopa.h, Level.cpp, Level.h, main.cpp,
Mario.cpp, Mario.h, Object.cpp, Object.h, Warp.cpp, Warp.h, World.cpp, World.h

Sources Referenced:
https://stackoverflow.com/questions/5891811/generate-random-number-between-1-and-3-in-c
https://cplusplus.com/reference/random/
https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
https://www.codecademy.com/resources/docs/cpp/random
https://stackoverflow.com/questions/14914595/what-is-a-seed-in-terms-of-generating-a-random-number

Struggles:
For this assignment, I most struggled with getting random numbers and inheritance. Unlike Java or Python, I learned that I need to get something called
a seed to get a random number. A seed holds an integer that will determine what random number to give. This was especially confusing because sometimes
two seprate calls of random gave the same exact numbers, and I learned that I have to add a random number to the seed each time a call it to get a 
random number each call. Hence the "+1" or "+counter" after the seed calls. Another thing I had troubles with was the inheritance. Inheritance for 
was a little rusty and especially the object and the children classe sof object was confusing. I learned about forward declaration which declares a 
different class in the .h file. 

Application Explanation:
My application takes in a input.txt file with specifications. Using those specifications, my application will create a level, with the specified levels,
dimensions, starting lifes, and approximate percentage of each object spawning. With that world, Mario will traverse through the slots and interact with
the objects. Some interactions are obtaining a coin, obtaining a mushroom, finding a warp to warp to the next level, and fighting enemies like Goombas,
Koopas, and bosses. If Mario gets through to the last level and beats the boss without losing all lifes, Mario wins, but if Mario loses all lifes on 
the way to the end, then Mario loses. Other game logics include, powerLevel increase and decrease, obtaining 20 coins resulting in an extra life, defeating
7 enemies in one life resulting in an extra life, and rematches against the boss if Mario loses. 