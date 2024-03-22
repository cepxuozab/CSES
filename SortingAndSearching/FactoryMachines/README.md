# Factory Machines
**Time limit:** 1.00 s **Memory limit:** 512 MB

A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?

## Input

The first input line has two integers n and t: the number of machines and products.
The next line has n integers k<sub>1</sub>,k<sub>2</sub>,...,k<sub>n</sub>: the time needed to make a product using each machine.

## Output
Print one integer: the minimum time needed to make t products.

## Constraints

- 1 &le; n &le; 2* 10<sup>5</sup>
- 0 &le; t &le; 10<sup>9</sup>
- 0 &le; k<sub>i</sub> &le; 10<sup>9</sup>


## Example
### Input:
```
3 7
3 2 5
```
### Output:
```
8
```  

## <span style ="color:blue"> Explanation:<span>
Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
