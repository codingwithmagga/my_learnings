# 35 Assessment Test 1

## Exercise 1

### Question 1

Return the customer IDs of customers who have spent at least $110 with the staff member who has an ID of 2.

### Solution 1

```sql
SELECT customer_id, SUM(amount) FROM payment WHERE staff_id=2 GROUP BY customer_id HAVING SUM(amount) > 110;
```

## Exercise 2

### Question 2

How many films begin with the letter J?

### Solution 2

```sql
SELECT COUNT(title) FROM film WHERE title LIKE 'J%';
```

## Exercise 3

### Question 3

What customer has the highest customer ID number whose name starts with an 'E' and has an address ID lower than 500?

### Solution 3

```sql
SELECT first_name, last_name FROM customer WHERE first_name LIKE 'E%' AND address_id < 500 ORDER BY customer_id DESC LIMIT 1;
```
