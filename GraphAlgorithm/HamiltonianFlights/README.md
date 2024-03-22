# Hamiltonian Flights

There are n cities and m flight connections between them. You want to travel from Syrjälä to Lehmälä so that you visit each city exactly once. How many possible routes are there?  


## Input  
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,&hellip;,n. City 1 is Syrjälä, and city n is Lehmälä.
Then, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.

## Output
Print one integer: the number of routes modulo 10<sup>9</sup>+7.

## Constraints

- 2 &le; n &le; 20
- 1 &le; a, b &le; n
- 1 &le; m &le; n<sup>2</sup>


## Example
<font color="blue">**Input:**</font>
```c++
4 6
1 2
1 3
2 3
3 2
2 4
3 4
```
<font color="blue">**Output:**</font>
```c++
2
``` 
