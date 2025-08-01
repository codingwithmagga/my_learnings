# 57 Assessment Test 2

## Exercise 1

How can you retrieve all the information from the cd.facilities table?

```sql
SELECT * FROM cd.facilities;
```

## Exercise 2

You want to print out a list of all of the facilities and their cost to members. How would you retrieve a list of only facility names and costs?

```sql
SELECT name, membercost FROM cd.facilities;
```

## Exercise 3

How can you produce a list of facilities that charge a fee to member?

```sql
SELECT * FROM cd.facilities WHERE membercost > 0;
```

## Exercise 4

How can you produce a list of facilities that charge a fee to members, and that fee is less than 1/50th of the monthly maintenance cost? Return the facid, facility name, member cost, and monthly maintenance of the facilities in question.

```sql
SELECT * FROM cd.facilities WHERE membercost > 0 AND membercost < monthlymaintenance / 50.0;
```

## Exercise 5

How can you produce a list of all facilities with the word 'Tennis' in their name?

```sql
SELECT * FROM cd.facilities WHERE name LIKE '%Tennis%';
```

## Exercise 6

How can you retrieve the details of facilities with ID 1 and 5? Try to do it without using the OR operator.

```sql
SELECT * FROM cd.facilities WHERE facid IN (1,5);
```

## Exercise 7

How can you produce a list of members who joined after the start of September 2012? Return the memid, surname, firstname, and joindate of the members in question.

```sql
SELECT memid, surname, firstname, joindate FROM cd.members WHERE joindate >= '2012-09-01';
```

## Exercise 8

How can you produce an ordered list of the first 10 surnames in the members table? The list must not contain duplicates.

```sql
SELECT DISTINCT(surname) FROM cd.members ORDER BY surname ASC LIMIT 10;
```

## Exercise 9

You'd like to get the signup date of your last member. How can you retrieve this information?

```sql
SELECT joindate FROM cd.members ORDER BY joindate DESC LIMIT 1;
```

## Exercise 10

Produce a count of the number of facilities that have a cost to guests of 10 or more.

```sql
SELECT COUNT(*) FROM cd.facilities WHERE guestcost >= 10;
```

## Exercise 11

Produce a list of the total number of slots booked per facility in the month of September 2012. Produce an output table consisting of facility id and slots, sorted by the number of slots.

```sql
SELECT fac.facid, SUM(bk.slots) AS "Total Slots" FROM cd.facilities AS fac 
INNER JOIN cd.bookings AS bk ON fac.facid = bk.facid 
WHERE bk.starttime > '2012-09-01'
GROUP BY fac.facid;
```

Note: This can be done simpler without even joining the facilities table. I did that a bit too complicated.

## Exercise 12

Produce a list of facilities with more than 1000 slots booked. Produce an output table consisting of facility id and total slots, sorted by facility id.

```sql
SELECT fac.facid, SUM(bk.slots) AS "Total Slots" FROM cd.facilities AS fac 
INNER JOIN cd.bookings AS bk ON fac.facid = bk.facid 
GROUP BY fac.facid
HAVING SUM(bk.slots) > 1000
ORDER BY fac.facid;
```

Note: Same as in Ex. 11: This can be done simpler without even joining the facilities table. I did that a bit too complicated.

## Exercise 13

How can you produce a list of the start times for bookings for tennis courts, for the date '2012-09-21'? Return a list of start time and facility name pairings, ordered by the time.

```sql
SELECT starttime, name FROM cd.bookings AS bk
INNER JOIN cd.facilities AS fac ON fac.facid = bk.facid
WHERE starttime BETWEEN '2012-09-21' AND '2012-09-22' AND cd.facilities.facid IN (0,1)
ORDER BY starttime ASC
```

## Exercise 14

How can you produce a list of the start times for bookings by members named 'David Farrell'?

```sql
SELECT starttime FROM cd.bookings AS bk
INNER JOIN cd.members AS mem ON mem.memid = bk.memid
WHERE mem.surname = 'Farrell' AND mem.firstname = 'David'
ORDER BY starttime ASC
```

Note: Ordering is not necessary since the table is already ordered.
