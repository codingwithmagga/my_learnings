- Timestamps and Extract
    - Date and time data types
        - `TIME`::Contains only time
        - `DATE`::Contains only date
        - `TIMESTAMP`::Contains date and time
        - `TIMESTAMPTZ`::Contains date, time, and timezone 
    - 
    - PostgreSQL Command
        - `SHOW`::show a value of a run-time parameter 
    - 
    - Time related run-time parameter
        - `TIMEZONE`::Show current timezone you are working in
    - 
    - Time related Functions and constants
        - `SELECT NOW()`::PostgreSQL function which returns the current date, time and timezone
        - `SELECT TIMEOFDAY()`::PostgreSQL function which returns day, time and timezone in a more readable way
        - `SELECT CURRENT_TIME`::SQL command that retrieves the current time from the system clock.
        - `SELECT CURRENT_DATE`::SQL command that retrieves the current date from the system's clock.
        - `EXTRACT()`::Function in SQL that retrieves subparts of a date or timestamp, such as year, month, or day.
        - Basic Syntax of `EXTRACT()`→`EXTRACT(field FROM timestamp_column)` where `field=YEAR` for example 
        - `AGE()`::PostgreSQL Function that calculates the interval between two timestamps, returning the difference in years, months, and days. If only one timestamp is provided, it returns the difference between the current time and the given timestamp.
        - Basic Syntax of `AGE()`→`AGE(timestamp_column)` returns the interval since the given timestamp or `AGE(timestamp1_column, timestamp2_column)` returning the difference between the two timestamps. 
        - `TO_CHAR()`::Function in PostgreSQL that converts a date or number to a string in a specified format. General function but especially useful for timestamp formatting.
        - Basic Syntax of `TO_CHAR()`→`TO_CHAR(date_column, format)` for example `format='mm-dd-yyyy'` 
    - 
- Mathematical Functions and Operators
    - [PostgreSQL: Documentation: 17: 9.3. Mathematical Functions and Operators](https://www.postgresql.org/docs/current/functions-math.html)
    - 
- String Functions and Operators
    - [PostgreSQL: Documentation: 17: 9.4. String Functions and Operators](https://www.postgresql.org/docs/17/functions-string.html)
    - 
- SubQuery
    - Describe→A subquery is a query nested inside another query. It allows constructing complex queries, essentially performing a query on the results of another query.
    - Basic Syntax?→But the query which shall be executed first in braces `(QUERY)`. 
    - Explain the `EXISTS()` function→`EXISTS()` is a subquery operator that returns `TRUE` if the subquery returns one or more rows, and `FALSE` otherwise.
    - 
- Self-Join
    - Describe→A self-join is a join where a table is joined to itself, allowing comparison of rows within the same table.
    - Basic syntax→Uses the standard `JOIN` syntax, but requires aliases for the table to distinguish correctly between the columns. 
    - 
