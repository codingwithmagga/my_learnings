# 30 Challenge GROUP BY

## Exercise 1

### Question 1

How many payments did each staff member handle and who gets the bonus?

### Solution 1

```sql
SELECT staff_id, COUNT(*) FROM payment GROUP BY staff_id ORDER BY COUNT(*) DESC;
```

Note that in the solution in the course they didn't sort since there were only two different values in `staff_id`.

## Exercise 2

### Question 2

What is the average replacement cost per MPAA rating?

### Solution 2

```sql
SELECT rating, ROUND(AVG(replacement_cost), 2) FROM film GROUP BY rating ORDER BY AVG(replacement_cost) DESC;
```

Note that in the solution in the course they did not sort the result.

## Exercise 3

### Question 3

What are the customers ids of the top 5 customers by total spend?

### Solution 3

```sql
SELECT customer_id, SUM(amount) FROM payment GROUP BY customer_id ORDER BY SUM(amount) DESC LIMIT 5; 
```
