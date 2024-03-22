# Hotel Queries

**Time limit:** 1.00 s **Memory limit:** 512 MB

There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.
The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.

## <span style = "color:blue">Input<span>
The first input line contains two integers n and m: the number of hotels and the number of groups. The hotels are numbered 1,2,...,n.
The next line contains n integers h<sub>1</sub>,h<sub>2</sub>,...,h<sub>n</sub>: the number of free rooms in each hotel.
The last line contains m integers r<sub>1</sub>,r<sub>2</sub>,...,r<sub>m</sub>: the number of rooms each group requires.

## <span style = "color:blue">Output<span>

## Constraints  
- 1 <= n,m <= 2*10^5
- 1 <= h<sub>i</sub> <= 10<sop>9</sup>
- 1 <= r<sub>i</sub> <= 10<sop>9</sup>

## <span style = "color:green">Example<span>
### Input:
```
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
```
### Output:
```
3 5 0 1 1
```