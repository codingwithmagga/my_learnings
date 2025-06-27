# 33 Challenge Timestamp and Extract

## Exercise 1

### Question 1

During which months did payments occur? Answer should be formatted to return back the full month name.

### Solution 1

```sql
SELECT DISTINCT(TO_CHAR(payment_date, 'MONTH')) FROM payment
```

## Exercise 2

### Question 2

How many payments occured on a Monday?

### Solution 2

My solution, because of the hint before tis lecture I was focused on using `TO_CHAR()`. I added the spaces in the end beacuse the output of `TO_CHAR()` is padded to 9 characters. Others solution use `LIKE/ILIKE` which may be better here.

```sql
SELECT COUNT(*) FROM payment WHERE TO_CHAR(payment_date, 'DAY') = 'MONDAY   '
```

With the hint I checkd to use `EXTRACT()`

```sql
SELECT COUNT(*) FROM payment WHERE EXTRACT(DOW FROM payment_date) = 1
```
