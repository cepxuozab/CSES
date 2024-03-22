# Apartments
**Time limit:** 1.00 s **Memory limit:** 512 MB

There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

## Input
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
The next line contains n integers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.
The last line contains m integers b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>m</sub>: the size of each apartment.

## Output
Print one integer: the number of applicants who will get an apartment.

## Constraints

- 1 &le; n,m &le; 10<sup>5</sup>
-  1 &le; k &le; 10<sup>9</sup>
-  1 &le; a<sub>i</sub>,b<sub>i</sub> &le; 10<sup>9</sup>


## Example
### Input:
```
4 3 5
60 45 80 60
30 60 75
```
### Output:
```
2
```  
