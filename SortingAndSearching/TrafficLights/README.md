# Traffic Lights
**Time limit:** 1.00 s **Memory limit:** 512 MB

There is a street of length x whose positions are numbered 0,1,...,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.

## Input

The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
Then, the next line contains n integers p<sub>1</sub>,p<sub>2</sub>,...,p<sub>n</sub>: the position of each set of traffic lights. Each position is distinct.

## Output
Print the length of the longest passage without traffic lights after each addition.

## Constraints

- 1 &le; x &le; 10<sup>9</sup>
- 1 &le; n &le; 2* 10<sup>5</sup>
- 0 < p<sub>i</sub> < x



## Example
### Input:
```
8 3
3 6 2
```
### Output:
```
5 3 3
```  
