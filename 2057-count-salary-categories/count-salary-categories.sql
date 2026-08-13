# Write your MySQL query statement below

with temp as(
    select
        account_id,
        case
            when income < 2e4 then "Low Salary"
            when income between 2e4 and 5e4 then "Average Salary"
            else "High Salary"
        end as category
    from
        accounts
),
cats as (
    select 'Low Salary' as category from dual
        union
    select 'Average Salary' as category from dual
        union
    select 'High Salary' as category from dual
)
select
    c.category,
    (
        select count(*) from temp as a where a.category = c.category
    ) as accounts_count
from
    cats as c;

