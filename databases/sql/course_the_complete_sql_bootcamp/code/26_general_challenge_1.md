# 22 General Challenge 1

## Exercise 1

### Question 1

How many payment transactions were greate than $5.00?

### Solution 1

```sql
SELECT COUNT(*) FROM payment WHERE amount > 5;
```

## Exercise 2

### Question 2

How many actors have a first name that starts with the letter P?

### Solution 2

```sql
SELECT COUNT(*) FROM actor WHERE first_name LIKE 'P%';
```

## Exercise 3

### Question 3

How many unique districts are our customers from?

### Solution 3

```sql
SELECT COUNT(DISTINCT(district)) FROM address;
```

## Exercise 4

### Question 4

Retrieve the list of names for those distinct district from the previous question.

### Solution 4

```sql
SELECT DISTINCT(district) FROM address;
```

## Exercise 5

### Question 5

How many films have rating of R and a replacement cost between $5 and $15?

### Solution 5

```sql
SELECT COUNT(*) FROM film WHERE rating = 'R' AND replacement_cost BETWEEN 5 AND 15;
```

## Exercise 6

### Question 6

How many films have the word Truman somewhere in the title?

### Solution 6

```sql
SELECT COUNT(*) FROM film WHERE title LIKE '%Truman%';
```