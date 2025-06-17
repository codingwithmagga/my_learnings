# 19 Challenge SELECT WHERE

## Exercise 1

### Question 1

What is the email for the customer with the name Nancy Thomas?

### Solution 1

```sql
SELECT email FROM customer WHERE first_name = 'Nancy' AND last_name = 'Thomas';
```

## Exercise 2

### Question 2

A customer wants to know what the movie "Outlaw Hanky" is about. Could give them the description for the movie?

### Solution 2

```sql
SELECT description FROM film WHERE title = 'Outlaw Hanky'; 
```

## Exercise 3

### Question 3

Can you get the phone number for the customer who lives at "259 Ipoh Drive"?

### Solution 3

```sql
SELECT phone FROM address WHERE address = '259 Ipoh Drive'; 
```

