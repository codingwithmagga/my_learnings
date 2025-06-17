# 22 Challenge ORDER BY

## Exercise 1

### Question 1

What are the customer ids of the first 10 customers who created a payment?

### Solution 1

```sql
SELECT customer_id FROM payment ORDER BY payment_date ASC LIMIT 10; 
```

I thought you may have to use `DISTINCT` here since customers can do multiple payments (or in other words, `customer_id` values occur multiple times), but the solution shown was the one above.

From the commentary section:

```sql
    SELECT  DISTINCT(customer_id) from (SELECT customer_id FROM payment WHERE amount != 0.00 ORDER BY payment_date ASC) LIMIT 10;
```

## Exercise 2

### Question 2

What are the titles of the 5 shortes (in length of runtime) movies?

### Solution 2

```sql
SELECT title,length FROM film ORDER BY length ASC LIMIT 5; 
```

## Bonus

### Question 3

How many options does a customer have to watch a movie that is 50 minutes or less in run time?

### Solution 3

```sql
SELECT COUNT(*) FROM film WHERE length <= 50; 
```