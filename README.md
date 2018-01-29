# Date-Sheet-AI
Mid Term Date Sheet Generator using Genetic Algorithm. 

  #### I coded this whole project from scratch for my undergrad course of Artificial Intelligence (Fall 2016, Fast-Nu Lahore).

Date-Sheet Generator is an application that uses the genetic algorithm to generate a date-sheet with maximum fitness according to our given criteria. Program runs until given generation while keeping track of maximum fitness date-sheet up till the current generation and after every 5 generations we displays the date-sheet (after 7 seconds wait time)of maximum fitness of current generation and then in the end after successfully completion displays the one Best/ideal date-sheet among all generations.

## Initial Parameters

Population = 100

Mutation Rate = 0.01

Total Generations = Given by User.

Time Slots = 5

Days = 3

Rooms in a particular {Day,TimeSlot} = 3

Number of Batch = 4 

Courses per Batch = 5 

That is, 
```
    Batch 10 : {"10-TBW","10-DB","10-OS","10-ATO","10-Prob"}

    Batch 11: {"11-DS","11-LA","11-ASL","11-PHL","11-NUM"}

    Batch 12: {"12-Eng2","12-Cal2","12-CLD","12-CP","12-BE"}

    Batch 13: {"13-ITC","13-Cal","13-PK","13-ISL","13-Eng1"}
   ```

Where in “13-Cal”, 13 is the batch number and Cal is course name (Calculus) and courses are being offered to the allotted batch only.

## Fitness Criteria

```
  Total Score: 100, a date sheet will lose score based on availability of following 3 conditions:

   High Priority: Clash = -30 per clash
  (Same Batch courses in single Time Slot)

   Medium Priority: Consecutive Exams = -3 per consecutive
  (Same Batch Courses in consecutive Time Slots)

   Low Priority: Gap in Exams = -1 per Gap
  (Max 1 gap of Time Slot is allowed, not more than that)
```

## Steps of Genetic Algorithm

1.	Generating Population of 100 DateSheets , random room, timeslot and day is choosen for a randomly picked course from the above course list. This process is completed when all the 20 courses have been allotted to a particular datesheet. ( Here we have handled the case that a Same Course can’t appear more than one in a datesheet). 
For Generation of population we take help of Initialize_TT() function written in population.h that takes an array of string of size 20 that contains courses in the form “13-Cal”, “10-ATO” etc.

2.	Calculating Fitness of generated DateSheets using a helper function CalculateFitness() written in geneticai.h. Fitness is calculated according to the fitness criteria given above.

3.	Building a Mating Pool , for this we iterate over the whole population and for a particular date sheet we get it’s fitness by using getFitness() function and then based on the following criteria we insert its index/id a particular number of times :

### Criteria for Mating pool
```
  0-20,   No of times inserted in pool = 1
  21-40,  No of times inserted in pool = 2
  41-60,  No of times inserted in pool = 3
  61-80,  No of times inserted in pool = 4
  81-100, No of times inserted in pool = 5
   
   ```
where if a particular date sheet has a fitness of lets say 72 then it falls under the range 61-80 which states that the index of this date sheet should be inserted in the pool 4 times. 

4.	Generating New Population using Crossover and Mutation
  * Pick any random two date sheets from the mating pool , and then apply crossover in the following way : Take Batch 10 and 11 courses from Parent A , and Take Batch 12 and 13 courses from Parent B and put then in Child 1 and similarly take Batch 10 and 11 courses from Parent B and take Batch 13 and 13 courses from Parent A and put them in Child 2. 
  
  * Generate a Random number between 0 and 1,and if its less than our mutation rate then apply Mutation to the given child in the following way : pick two random days , two random time slots and two random rooms, and their contents.

5.	Replace the old population with the newly generated one and then perform steps 2 to 5 until given generations.

## Application Detail

Implemented in QT (code is in C++)

Generated an exe file and checked the exe running in a 64 bit computer, Following is a screenshot of the application: 

![Date-Sheet Generator](https://image.ibb.co/dfa4ZG/aiproject.png)

* Each batch has a particular color so that it’s easier to read, i.e. Batch 10 courses have a color Red.

* Coloring also helps in testing the fitness of a date sheet visually as:

  * If Same Color appears more than once in a {Day,TimeSlot} then it means date sheet has a clash.

  * If Same Color appear in consecutive time slots then It means date sheet has consecutive courses.

### To measure Gap easily, do following :

  * As only 1 Gap is allowed , so only see Color/Courses in TimeSlot 1 and 2. 
  
  * For Time Slot 1, if the same color appears in TimeSlot 4 or 5 for a given same day then it means date sheet has a gap.
  
  * For Time Slot 2, if the same color appears in TimeSlot 5 for a given same day then it means date sheet has a gap.

## Files

* dialog.cpp (our main dialog), in this file runGA() is called when green button is clicked so it’s our main.

```
As in our application : A DateSheet has a state which is [3][5] in size because of 3 days and 5 Time Slots and a particular state each state (e.g.  [0][0]) has 3 rooms and a room can contain a single course.
```

* Course.h (contains Batch ID and Course Name)

* Room.h (contains Course)

* State.h (contains Rooms [3])

* Population.h (contains State[3][5]) 

* Geneticai.h  (contains helper functions for our algorithm like CalculateFitness() , Crossover(), Mutation() etc.)


