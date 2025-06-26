# 45 JOIN Challenge

## Exercise 1

### Question 1

What are the emails of the customers who live in California?

### Solution 1

```sql
SELECT district, email FROM address INNER JOIN customer ON address.address_id = customer.address_id WHERE district='California'
```

## Exercise 2

### Question 2

Get a list of all the movies "Nick Wahlberg" has been in.

### Solution 2

```sql
SELECT title, first_name, last_name FROM film_actor 
INNER JOIN actor ON film_actor.actor_id = actor.actor_id
INNER JOIN film ON film_actor.film_id = film.film_id
WHERE first_name = 'Nick' AND last_name = 'Wahlberg'
```