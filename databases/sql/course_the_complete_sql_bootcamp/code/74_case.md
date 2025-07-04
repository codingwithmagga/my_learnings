# 74 CASE

## Exercise 1

We want to know and compare the various amounts of films we have per movie rating.

```sql
SELECT 
SUM(CASE rating
    WHEN 'R' THEN 1
    ELSE 0
END) AS r,
SUM(CASE rating
    WHEN 'PG' THEN 1
    ELSE 0
END) AS pg,
SUM(CASE rating
    WHEN 'PG-13' THEN 1
    ELSE 0
END) AS pg13
FROM film
```
