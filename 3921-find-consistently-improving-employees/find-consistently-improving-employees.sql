WITH employee AS
(
    SELECT 
        e.employee_id,
        e.name,
        p.rating,
        p.review_date
    FROM employees e
    JOIN performance_reviews p
    ON e.employee_id = p.employee_id
),

needed AS
(
    SELECT 
        employee_id,
        name,
        rating,

        LEAD(rating,1) OVER
        (
            PARTITION BY employee_id
            ORDER BY review_date DESC
        ) AS r2,

        LEAD(rating,2) OVER
        (
            PARTITION BY employee_id
            ORDER BY review_date DESC
        ) AS r3,

        ROW_NUMBER() OVER
        (
            PARTITION BY employee_id
            ORDER BY review_date DESC
        ) AS rn

    FROM employee
),

score AS
(
    SELECT
        employee_id,
        name,
        rating,
        r3
    FROM needed
    WHERE rn = 1
    AND rating > r2
    AND r2 > r3
)

SELECT
    employee_id,
    name,
    rating - r3 AS improvement_score
FROM score
ORDER BY improvement_score DESC , name asc;