# Book Shop II  

You are in a bookshop which sells n different books. You know the price, the number of pages and the number of copies of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy several copies of the same book.

## Input

The first input line contains two integers n and x: the number of book and the maximum total price.
The next line contains n integers h<sub>1</sub>,h<sub>2</sub>,&hellip;,h<sub>n</sub>: the price of each book.
The next line contains n integers s<sub>1</sub>,s<sub>2</sub>,&hellip;,s<sub>n</sub>: the number of pages of each book.
The last line contains n integers k<sub>1</sub>,k<sub>2</sub>,&hellip;,k<sub>n</sub>: the number of copies of each book.

## Output

Print one integer: the maximum number of pages.

## Constraints

* 1 &le; n &le; 100  
* 1 &le; x &le; 10<sup>5</sup>  
* 1 &le; h<sub>i</sub>,s<sub>i</sub>,k<sub>i</sub> &le; 1000  

## Example

**Input:**
```c++
3 10
2 6 3
8 5 4
3 5 2
```

**Output:**
```c++
28
```

## Explanation:  

You can buy three copies of book 1 and one copy of book 3. The price is 3 &middot; 2 + 3 = 9 and the number of pages is 3 &middot; 8 + 4 = 28.
