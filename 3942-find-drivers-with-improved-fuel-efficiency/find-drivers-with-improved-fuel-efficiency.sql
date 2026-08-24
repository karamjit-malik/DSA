WITH driver_efficiency AS
(
    SELECT
        d.driver_id,
        d.driver_name,

        AVG(
            CASE 
                WHEN MONTH(t.trip_date) IN (1,2,3,4,5,6)
                THEN t.distance_km / t.fuel_consumed
            END
        ) AS first_half_avg,

        AVG(
            CASE 
                WHEN MONTH(t.trip_date) IN (7,8,9,10,11,12)
                THEN t.distance_km / t.fuel_consumed
            END
        ) AS second_half_avg

    FROM drivers d
    JOIN trips t
    ON d.driver_id = t.driver_id

    GROUP BY d.driver_id,d.driver_name
)

SELECT
    driver_id,
    driver_name,
    ROUND(first_half_avg,2) as first_half_avg,
    ROUND(second_half_avg,2) as second_half_avg,
    ROUND(second_half_avg - first_half_avg,2) AS efficiency_improvement

FROM driver_efficiency where second_half_avg > first_half_avg order by efficiency_improvement desc , driver_name asc;