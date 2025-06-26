# 33 Challenge HAVING

## Exercise 1

### Question 1

What customer_ids have 40 or more transaction payments?

### Solution 1

```sql
SELECT customer_id, COUNT(*) FROM payment GROUP BY customer_id HAVING COUNT(*) >= 40
```

## Exercise 2

### Question 2

What are the customer ids of customers who have spent more than 100$ in payment transactions with our staff_id member 2?

### Solution 2

```sql
SELECT customer_id, SUM(amount) FROM payment WHERE staff_id=2 GROUP BY customer_id HAVING SUM(amount) > 100
```